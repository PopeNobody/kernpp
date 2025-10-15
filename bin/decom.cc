#include <syscall.hh>
using namespace sys;
union magic_t {
  char  b[2];
  short s;
};
template<char ch1, char ch2>
constexpr magic_t magic() {
  return magic_t{ ch1,ch2 }   ;
};
const char* choose_decompressor(short magic) {
  switch(magic) {
    case 0x1f8b:       
      return "gzip";
    case 'B'+256*'Z':  
      return "bzip2";
    case 0x28b5:       
      return "zstd";
    case 0x0422:       
      return "lz4";
    default:
      return nullptr;  
  };
}

int main(int argc, char** argv, char **envp) {
    if (argc != 2) {
      write(2, "Usage: ");
      write(2, "%s");
      write(2," <compressed-file>\n", argv[0]);
      return 1;
    }

    const char* filename = argv[1];
    int fd = open(filename, o_rdonly);
    if (fd < 0) {
        perror("open");
        return 1;
    }
    
    magic_t magic;
    ssize_t n = read(fd, (char*)&magic.b, 2);
    if (n != 2) {
        perror("read");
        return 1;
    }

    const char* decomp = choose_decompressor(magic.s);
    if (!decomp) {
        write(2, "Unknown compression format\n");
        return 1;
    }

    fd_t pipefd[2];
    if (pipe(pipefd) < 0) {
        perror("pipe");
        return 1;
    }

    // write the magic bytes into the pipe
    if (write(pipefd[1], magic.b, 2) != 2) {
        perror("write");
        return 1;
    }

    // splice remaining file contents into the pipe
    while (true) {
        ssize_t spliced = splice(fd, nullptr, pipefd[1], nullptr, 65536, 0);
        if (spliced == 0) break; // EOF
        if (spliced < 0) {
            perror("splice");
            return 1;
        }
    }

    close(pipefd[1]); // finished writing to pipe

    // Replace stdin with the pipe’s read end
    dup2(pipefd[0], 0);
    close(pipefd[0]);

    const char * const cmd[]={ "/bin/bash", "-c", decomp, 0 };
    sys::execve(cmd[0], (char*const*)cmd, envp);
    perror("execlp"); // should not return
    return 127;
}

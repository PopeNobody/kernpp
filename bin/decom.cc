#include <syscall.hh>
using namespace sys;
union magic_t {
  char  b[2];
  short s;
};
template<char ch1, char ch2>
constexpr magic_t magic() {
   
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

int main(int argc, char** argv) {
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
    ssize_t n = read(fd, (ostr)&magic, 2);
    if (n != 2) {
        perror("read");
        return 1;
    }

    const char* decomp = choose_decompressor(magic);
    if (!decomp) {
        fprintf(stderr, "Unknown compression format\n");
        return 1;
    }

    int pipefd[2];
    if (pipe(pipefd) < 0) {
        perror("pipe");
        return 1;
    }

    // write the magic bytes into the pipe
    if (write(pipefd[1], magic.data(), 2) != 2) {
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
    dup2(pipefd[0], STDIN_FILENO);
    close(pipefd[0]);

    execlp(decomp, decomp, nullptr);
    perror("execlp"); // should not return
    return 127;
}

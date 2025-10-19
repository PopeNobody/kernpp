#include <syscall.hh>
using namespace sys;
const char* choose_decompressor(unsigned m1, unsigned m2) {
//     write(2,fmt::fmt_t(m1));
//     write(2,"\n");
//     write(2,fmt::fmt_t(m2));
//     write(2,"\n");
  if(m1==0x1f && m2==0x8b) {
    return "gunzip";
  } else if ( m1=='B' and m2=='Z' ) {
    return "bunzip2";
  } else if ( m1==0x28 and m2==0xb5 ) {
    return "zstdcat";
  } else if ( m1==0x04 and m2==0x22 ) {
    return "lz4cat";
  } else {
    return "cat";
  };
}

int main(int argc, char** argv, char**envp) {
    const char* filename = argv[1];
    if(argc==1) {
    } else if ( argc==2 ){
      int fd = open(filename, o_rdonly);
      if (fd < 0) {
        perror("open");
        return 1;
      }
      if(fd!=0) {
        dup2(fd,0);
        close(fd);
      };
    } else {
      write(2,"usage: ");
      write(2,argv[0]);
      write(2," <file>\n");
      exit(1);
    };
    
    unsigned char magic[2];
    ssize_t n = read(0, (char*)magic, 2);
//       write(2,"read ");
//       write(2,fmt::fmt_t(n));
//       write(2," bytes\n");
//       if(n!=2){
//         exit(1);
//       };
//       write(2,"value: ");
//       write(2,fmt::fmt_t(magic[0]&0xff,16));
//       write(2,"\n");
//       write(2,"value: ");
//       write(2,fmt::fmt_t(magic[1]&0xff,16));
//       write(2,"\n");

    const char* decomp = choose_decompressor(magic[0],unsigned(magic[1]));
    if (!decomp) {
      decomp="bin/cat";
    }

    fd_t pipefd[2];
    if (pipe(pipefd) < 0) {
        perror("pipe");
        return 1;
    }

    // write the magic bytes into the pipe
    if (write(pipefd[1], (char*)magic, 2) != 2) {
        perror("write");
        return 1;
    }

    // splice remaining file contents into the pipe
    while (true) {
        ssize_t spliced = splice(0, nullptr, pipefd[1], nullptr, 65536, 0);
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
    const char *args[] = { "/bin/sh", "-c", 0, 0 };
    args[2]=decomp;
    execve(args[0], (char * const *)args, (char * const *)envp);
    perror("execlp"); // should not return
    return 127;
}

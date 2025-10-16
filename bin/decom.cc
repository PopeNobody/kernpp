#include <syscall.hh>
using namespace sys;
union magic_t {
  char  b[2];
  short s;
  magic_t(short s=0)
    :s(s)
  {
  };
  magic_t(char b0, char b1)
    : b{b0,b1}
  {
  };
};
struct hex_t {
  static constexpr char dig[]="0123456789abcdef";
  char buf[256*4];
  hex_t() 
  {
    char *pos=buf;
    for(int i=0;i<16;i++){
      for(int j=0;j<16;j++) {
        *pos++=dig[i];
        *pos++=dig[j];
        *pos++=0;
        *pos++=0;
      };
    };
  };
  char *get(short val)
  {
    return buf+val*4;
  };
} hex;
const char* choose_decompressor(short magic) {
  write(1,hex.get(magic/256));
  write(1,hex.get(magic%256));
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
      return "cat";  
  };
}

ssize_t read2(char buf[2]){
  buf[0]=buf[1]=0;
  if(!read(0,&buf[0],1,err_fatal))
    return 0;
  if(!read(0,&buf[1],1,err_fatal))
    return 1;
  return 2;
};
int main(int argc, char** argv, char **envp) {
  if(argc>1) {
    const char* filename = argv[1];
    fd_t fd;
    if(fd=open(filename, o_rdonly,err_fatal)){
      dup2(fd,0);
      close(fd);
    };
  };
  magic_t magic;
  ssize_t n=read2(magic.b);
  switch(n) {
    case 0: return 0;
    case 1: write(1,&magic.b[0],1); return 0;
  };
  const char* decomp = choose_decompressor(magic.s);
  fd_t pipefd[2];
  pipe(pipefd,err_fatal);
  if(write(pipefd[1],&magic.b[0],2,err_fatal)!=2)
    pexit("write");
  while (true) {
    ssize_t spliced = splice(0, nullptr, pipefd[1], nullptr, 65536, 0,err_fatal);
    if (spliced == 0) break; // EOF
  }
  close(pipefd[1]); // finished writing to pipe
  dup2(pipefd[0], 0);
  close(pipefd[0]);

  const char * const cmd[]={ "/bin/bash", "-c", decomp, 0 };
  sys::execve(cmd[0], (char*const*)cmd, envp);
  perror("execlp"); // should not return
  return 127;
}

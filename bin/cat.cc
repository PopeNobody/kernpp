#include "syscall.hh"
using namespace sys;
void cat(const char *file) {
  int fd=open(file,o_rdonly);
  char buf[4096];
  while(1){
    ssize_t nr=read(fd,buf,sizeof(buf));
    if(!nr)
      return;
    if(nr<0) {
      sys::perror("read");
      return;
    };
    for(char *pos=buf;pos<buf+nr;pos++){
      int nw=write(1,pos,buf+nr-pos);
      if(nw<0) {
        perror("write");
        return;
      };
      pos+=nw;
    };
  };
};
extern "C" {
  int main(int argc,char *const*argv,char *const*envp) {
    for(int i=1;i<argc;i++){
      cat(argv[i]);
    };
    return 0;
  };
}


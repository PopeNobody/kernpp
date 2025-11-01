#include "syscall.hh"
using namespace sys;
static char buf[4096];
void cat(fd_t fd) {
  while(1){
    ssize_t nr=read(fd,buf,sizeof(buf),err_fatal);
    if(!nr)
      return;
    for(char *pos=buf;pos<buf+nr;pos++){
      int nw=write(1,pos,buf+nr-pos,err_fatal);
      pos+=nw;
    };
  };
};
void cat(const char *file) {
  int fd=open(file,o_rdonly,err_fatal);
  cat(fd_t(fd));
};
extern "C" {
  int main(int argc,char *const*argv,char *const*envp) {

    if(argc>1) {
      for(int i=1;i<argc;i++){
        cat(argv[i]);
      };
    } else {
      cat(fd_t(0));
    }
    return 0;
  };
}


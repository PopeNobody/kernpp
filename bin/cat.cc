#include "syscall.hh"
using namespace sys;
static char buf[4096];
// ssize_t sys::read(fd_t fd, char *buf, size_t len, errhand_t hand)
// {
//   return 0;
// };
void cat(fd_t fd) {
  while(1){
    ssize_t nr=read(fd,buf,sizeof(buf),err_log);
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
void cat(const char *file) {
  int fd=open(file,o_rdonly);
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


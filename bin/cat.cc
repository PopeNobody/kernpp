#include <syscall.hh>
#include <fatal.hh>
#include <fmt.hh>
using sys::write;
using sys::read;
using sys::exit;
extern "C" {
  int main(int argc, const char**argv, const char**envp);
};
static void die(int res,const char *msg) {
  write(2,msg);
  exit(res);
};
static char buf[65535];
int copy(fd_t ifd, fd_t ofd){
  while(int nr=read(ifd,buf,sizeof(buf))){
    if(nr<0){
      write(2,"error: read: ");
      fmt::write_dec(2,ifd);
      write(2,"\n");
      sys::close(ifd);
      return 1;
    };
    int nw;
    for(int i=0;i<nr;i+=nw){
      nw=write(ofd,buf+i,nr-i);
      if(nw<0) {
        write(2,"error: write: ");
        fmt::write_dec(2,ofd);
        write(2,"\n");
        sys::close(ifd);
        return 1;
      };
    };
  };
  return 0;
};
int copy(const char *path,int ofd){
  int ifd=fatal::open(path,sys::o_rdonly);
  return copy(ifd,ofd);
};
int main(int argc, const char**argv, const char **envp) {
  if(*++argv) {
    while(*argv){
      copy(*argv++,1);
    };
  } else {
    copy(fd_t(0),fd_t(1));
  };
  return 0;
};

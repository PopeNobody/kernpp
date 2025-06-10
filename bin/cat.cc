#include <syscall.hh>
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
int copy(const char *path,int ofd){
  int ifd = open(path,sys::o_rdonly);
  if(ifd<0){
    write(2,"error: open: ");
    write(2,path);
    write(2,"\n");
    return 1;
  }
  while(int nr=read(ifd,buf,sizeof(buf))){
    if(nr<0){
      write(2,"error: read: ");
      write(2,path);
      write(2,"\n");
      sys::close(ifd);
      return 1;
    };
    int nw;
    for(int i=0;i<nr;i+=nw){
      nw=write(ofd,buf+i,nr-i);
      if(nw<0) {
        write(2,"error: write: ");
        write(2,path);
        write(2,"\n");
        sys::close(ifd);
        return 1;
      };
    };
  };
  return 0;
};
int main(int argc, const char**argv, const char **envp) {
  while(*++argv){
    copy(*argv,1);
  };
  return 0;
};

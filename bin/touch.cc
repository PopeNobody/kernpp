#include "time.hh"
#include "syscall.hh"
#include "fmt.hh"

using namespace sys;

int touch(const char *path){
  timespec_t times[2];
  times[0].tv_nsec=times[1].tv_nsec=UTIME_NOW;
  unlink(path);
  int res=utimensat(AT_FDCWD,path,times,0);
  if(!res)
    return 0;
  perror("utimensat");
  if(errno==ENOENT) {
    int fd=open(path,o_creat|o_wronly|o_trunc,0644);
    if(fd==-1)
      pexit(4,"open");
    close(fd);
  };
  
  return 0;  
};
extern "C" {
int main(int argc,char *const*argv,char *const*envp) {
    int ch, longidx;
    for(int i=1;i<argc;i++)
      touch(argv[i]);
    return 0;
  };
}

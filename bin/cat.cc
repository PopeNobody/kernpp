#include <syscall.hh>
#include <fmt.hh>

using namespace fmt;
ssize_t min(ssize_t lhs, ssize_t rhs) {
  return lhs<rhs?lhs:rhs;
};
#if 0
#define show_val(x) do{ \
  write(2,L(#x " => ")); \
  write_dec(2,(x)); \
  write(2,L("\n")); \
}  while(false);
#define show_ptr(x) do{ \
  write(2,L(#x " => ")); \
  write_ptr(2,(x)); \
  write(2,L("\n")); \
}  while(false);
#define show_hex(x) do{ \
  write(2,L(#x " => ")); \
  write_hex(2,(x)); \
  write(2,L("\n")); \
}  while(false);
#endif
void sleepy(size_t secs, size_t nano){
  timespec tm;
  tm.tv_sec=secs;
  tm.tv_nsec=nano;
  nanosleep(&tm,0);
}
template<size_t size_>
struct buf_t {
  enum { size=size_ };
  char buf[size-1];
  char end[1];
};
buf_t<1024*10> buf;
bool catfile(int fd)
{
  ssize_t res=0;
  while(true)
  {
    sleepy(0,1000000);
    res=read(fd,buf.buf,sizeof(buf.buf));
    if(res==0)
      return true;
    if(res<0){
      write(2,L("error\n"));
      return false;
    };
    typedef char* char_p;
    char_p beg=buf.buf;
    char_p end=beg+res;
    while(beg<end){
      ssize_t tmp=write(1,beg,end-beg);
      if(tmp<0)
        return false;
      beg+=tmp;
    };
  }
  if(res<0)
    write(2,L("read error\n"));
  return !res;
};
inline open_mode operator|(open_mode lhs, open_mode rhs) {
  return open_mode(int(lhs)|int(rhs));
};
int main(int argc, char**argv) {
  ++argv;
  if(*argv) {
    while(*argv)
    {
      if(argv[0][0]=='-' && argv[0][1]=='o'){
        char *fname;
        if(argv[0][2]){
          fname=&argv[0][2];
        } else if (*++argv) {
          fname=*argv++;
        } else {
          write(2,L("-o given without another arg\n"));
        };
        sys_close(1);
        int fd=open(fname,open_flags(o_creat|o_append|o_wronly));
        if(fd!=1){
          dup2(fd,1);
          sys_close(fd);
        };
      } else {
        int fd=-1;
        if(argv[0][0] == '-' && argv[0][1]==0) {
          fd=0;
        } else {
          fd=open(*argv,o_rdonly);
          if(fd<0){
            write(2,L("open error\n"));
            return 1;
          };
        };
        catfile(fd);
        sys_close(fd);
        ++argv;
      } 
    }
  } else {
    catfile(0);
  };
  return 0;
};

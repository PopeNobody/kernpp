#include <syscall.hh>

extern "C" {
  int main(int argc, char**argv, char**envp);
};
using namespace sys;
char **envv;

static fd_t run_xxd() {
  fd_t fds[2];
  pipe(fds);
  if(fork()){
    close(fds[0]);
    return fds[1];
  }
  dup2(fds[0],0);
  close(fds[0]);
  close(fds[1]);
  const char *argv[3]={
    "/opt/bin/xxd","xxd",0
  }; 
  execve(argv[0],(char*const*)argv,envv);
  pexit(3,"exec:xxd");
};
struct buf_t {
  char buf[61];
  char nul[1];
  char off;
  void format(unsigned long val, int base, bool neg) {
    nul[0]=0;
    off=(nul-buf);
    do {
      buf[--off]=digits[val%base];
      val/=base;
    } while(val);
  };
  buf_t(unsigned long val,int base=10,bool neg=false)
    {
      format(val,base,neg);
    };
  buf_t(unsigned long val,bool neg=false)
    {
      format(val,10,neg);
    };
  operator c_str() const {
    return c_str(buf+off,nul-buf-off);
  };
  static constexpr const char digits[]="0123456789abcdef";
};

size_t str_len(const char *str) {
  const char *pos=str;
  while(*pos)
    ++pos;
  return pos-str;
};
int main(int argc, char**argv, char**envp) {
  envv=envp;
  char *beg=argv[0];
  char *end=envp[0];
  while(beg!=end) {
    if(!*beg)
      *beg=' ';
    beg++;
  }
  *--beg='\n';
  write(1,argv[0],end-argv[0]);
  return 0;
};

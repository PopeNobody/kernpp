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
  char end[1];
  char off;
  char len;
  static buf_t bufs[1024];
  buf_t()
    : buf{},end{},off(end-buf),len(0)
    {
    };
  operator c_str() const {
    return c_str(&buf[off],len);
  };
  buf_t &itoa(unsigned long val) {
    static int idx=0;
    buf_t &buf=bufs[idx++];
    buf=buf_t();
    return buf;  
  };
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
//     write(itoa
//     {
//       return sys::sys_write(fd, str.begin(), str.size());
//     };
  return 0;
};

#include<syscall.hh>

extern "C" {
  int main(int argc, char* const* argv, char * const *envp);
};
using sys::write;
#define wifexited(res) (wtermsig(res)==0)
#define wtermsig(res) (res&0x7f)
#define wexitstatus(res) ((res&0xff00)>>8)
struct status_t {
  int res;
  bool exited() const {
    return sig()==0;
  };
  unsigned short sig() const {
    return res&0x7f;
  };
  unsigned short ret() const {
    return res/256%256;
  };
  operator int32_p() {
    return &res;
  };
};

typedef char * str_t;
typedef const char *str_c;
using sys::exit;
namespace fatal {
  inline pid_t fork() {
    pid_t res = sys::fork();
    if(res<0)
      sys::pexit("fork");
    else if (res)
      write(2,"forked %d\n");
    return res;
  };
  inline auto wait(int *status) {
    auto pid=sys::wait(status);
    if(pid<0)
      sys::pexit("wait");
    return pid;
  };
  inline void execve(const char *argv0, char * const *argv, char * const *envp)
  {
    sys::execve(argv0,argv,envp);
    sys::pexit("execve");
  };
}
struct fmt_int {
  char buf[16];
  char *pos;
  const char *end() const { return buf+sizeof(buf)-1; }
  const char *beg() const { return pos; };
  fmt_int(int val)
    : buf{ "" }, pos(buf+sizeof(buf)-1)
  {
    *pos--=0;
    do {
     *--pos='0'+(val%10);
     val/=10 ;
    } while(val);
  };
};
template<class iitr, class oitr>
oitr copy( iitr ib, iitr ie, oitr &ob, oitr oe )
{
  while(true) {
    if(ib==ie)
      return ob==oe?ob:0;
    if(ob==oe)
      return 0;
    *ob++=*ib++;
  };
};
template<class itr_t>
itr_t find_end(itr_t end){
  while(*end)
    ++end;
  return end;
};
int main(int argc, char* const* argv, char * const *envp)
{
  char *pos;
  ++argv;
  argc--;
  if(!*argv) {
    write(2,"oops\n");
    exit(1);
  };
  pid_t pid=fatal::fork();
  if(!pid) {
    fatal::execve(argv[0],argv,envp);
    exit(1);
  };

  status_t res;
  fatal::wait(res);

  for(pos=(char*)argv[0]; pos<argv[argc-1] || *pos; pos++)
    if(!*pos)
      *pos++=' ';
  *pos++='\n';
  write(2,argv[0],pos-argv[0]);
  fmt_int pid_f=pid;
  write(2, pid_f.beg(),pid_f.end());
  if(res.ret()) {
    const char *desc = " returned ";
    write(2,desc);
    fmt_int ret_f=res.ret();;
    write(2, ret_f.beg(),ret_f.end());
  } else if (res.sig()) {
    const char *desc = " killed with ";
    write(2,desc);
    fmt_int sig_f=res.sig();;
    write(2, sig_f.beg(),sig_f.end());
  } else {
    write(2," exited normally");
  };
  write(2,"\n\n\n");


//     write(2,pid_f.beg(),pid_f.end()-pid_f.beg());
//     write(2,pid_f.beg(),pid_f.end()-pid_f.beg());
//     *pid_f
//     write(2,"\n");
//     write(2,pid_f.beg(),pid_f.end()-pid_f.beg());
//     write(2,"\n");
//     write(2,pid_f.beg(),pid_f.end()-pid_f.beg());
//     write(2,"\n");
//     write(2,pid_f.beg(),pid_f.end()-pid_f.beg());
//     write(2,"\n");
//     if(num) {
//       desc=" killed with ";
//     } else {
//       num=res.ret();
//     };
  exit(res.res);
};

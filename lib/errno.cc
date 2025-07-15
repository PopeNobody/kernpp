#include "syscall.hh"
#include "die.hh"
#include "errno.hh"
#include "fmt.hh"
#include "itr_ops.hh"
struct set_bool {
  bool &val;
  set_bool(bool &val)
    : val(val)
  {
    val=true;
  }
  ~set_bool()
  {
    val=false;
  };
};
void sys::err_ignore(sys::errno_t err)
{
};
void sys::err_log(sys::errno_t err)
{
  static bool recurse=false;
  if(recurse)
    return;
  set_bool setter(recurse);
  sys::write(2,"setting error to: ");
  sys::write(2,fmt::fmt_t((long)err));
  sys::write(2,"\n\n");
};
void sys::err_fatal(errno_t err) {
  sys::write(2,"FROM: ");
  sys::write(2,fmt::fmt_t(getpid()));
  sys::write(2,"  FATAL ERROR: ");
  sys::write(2,fmt::fmt_t(err));
  sys::write(2,"\n");
  sys::write(2,strerror(err));
  sys::write(2,"\n");
  pexit(5,"err_fatal");
  std::abort();
  kill(getpid(),9);
};
void sys::set_errno(errno_t err, errhand_t hand)
{
  if(err<0 && err>-4096) {
    err=(errno_t)-err;
  } else if (err>uint64_t(-4096)) {
    err=(errno_t)-err;
  };
  errno=err;
  hand(err);
}
namespace sys {
  void throw_errno(errno_t err);
};
void sys::throw_errno(errno_t err){
  sys::set_errno(err);
  char buf[1023]="setting error to: ";
  char *pos=buf+itr::len(buf);
  char *end=buf+sizeof(buf)-1;
  *--end=0;
  pos=itr::copy(pos,end,fmt::fmt_t(err));
  pos=itr::copy(pos,end," ( ");
  pos=itr::copy(pos,end,sys::strerror(sys::errno));
  pos=itr::copy(pos,end," )\n");
  exit(-1);
};
namespace sys {
  errno_t errno;
  void perror(const c_str &msg)
  {
    static c_str null;
    perror(null,msg);
  };
  void die(int err, const c_str &msg1, const c_str &msg2)
  {
    perror(msg1,msg2);
    exit(err);
  };
  void die(int err, const c_str &msg)
  {
    perror(msg);
    exit(err);
  };
  void pexit(int err, const c_str &msg1, const c_str &msg2)
  {
    perror(msg1,msg2);
    exit(err);
  };
  void pexit(int err, const c_str &msg)
  {
    perror(msg);
    exit(err);
  };
  void perror(const c_str &msg1, const c_str &msg2)
  {
    if(msg1) {
      write(2,msg1);
      write(2,":");
    };
    if(msg2) {
      write(2,msg2);
      write(2,":");
    };
    write(2,fmt::fmt_t(errno));
    write(2,"  --  ",6);
    write(2,strerror(errno));
  };
  void pexit(const c_str &msg1, const c_str &msg2)
  {
    perror(msg1,msg2);
    exit(1);
  };
  void assert_fail(const char *cond, const char *file, unsigned line){
    write(2,file);
    write(2,":");
    write(2,fmt::fmt_t(line));
    write(2,": assertion (");
    write(2,cond);
    write(2,") failed");
    exit(1);
  };
};

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
void sys::set_errno(uint64_t err)
{
  static bool recurse=false;
  if(recurse)
    return;
  set_bool setter(recurse);
  sys::write(2,"setting error to: ");
  sys::write(2,fmt::fmt_t(err));
  sys::write(2,"\n\n");
}
void die::throw_errno(uint64_t err){
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
<<<<<<< HEAD
  ssize_t write(fd_t fd,const c_str &str) {
    return write(fd, str.beg(), str.len());
  };
  ssize_t write(fd_t fd,const fmt::fmt_t &fmt){
    c_str text=fmt;
    return write(fd, text.beg(), text.len());
  };
  long set_errno(long err)
  {
    if(err>=0)
      return err;
    {
      sys::write(2,"setting error to: ");
      sys::write(2,fmt::fmt_t(err));
//         buf_ns::buf_t<80> buf(2);
      // XXX why is 11 a special case?
      if(err!=11)
        write(2,"setting error to=",err);
    };
    errno=-err;
    return -1;
  }
||||||| 2359da4
  ssize_t write(fd_t fd,const c_str &str) {
    return write(fd, str.beg(), str.len());
  };
  ssize_t write(fd_t fd,const fmt::fmt_t &fmt){
    c_str text=fmt;
    return write(fd, text.beg(), text.len());
  };
  ssize_t set_errno(ssize_t err)
  {
    if(err>=0)
      return err;
    {
      sys::write(2,"setting error to: ");
      sys::write(2,fmt::fmt_t(err));
//         buf_ns::buf_t<80> buf(2);
      // XXX why is 11 a special case?
      if(err!=11)
        write(2,"setting error to=",err);
    };
    errno=-err;
    return -1;
  }
=======
>>>>>>> limited
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

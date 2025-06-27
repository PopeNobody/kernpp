#include "errno.hh"
#include "syscall.hh"
//   #include <buf.hh>
#include "fmt.hh"
namespace sys {
  ssize_t write(fd_t fd,const fmt::fmt_t &fmt);
  ssize_t write(fd_t fd,const c_str &str);
};
namespace sys {
  errno_t errno;
  ssize_t write(fd_t fd,const c_str &str) {
    return write(fd, str.beg(), str.len());
  };
  ssize_t write(fd_t fd,const fmt::fmt_t &fmt){
    c_str text=fmt;
    return write(fd, text.beg(), text.len());
  };
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
  ssize_t set_errno(ssize_t err)
  {
    if(err>=0)
      return err;
    {
      static bool recurse=false;
      if(recurse)
        return -1;
      set_bool setter(recurse);
      sys::write(2,"setting error to: ");
      sys::write(2,fmt::fmt_t(err));
    };
    errno=-err;
    return -1;
  }
  void perror(const c_str &msg)
  {
    static c_str null;
    perror(null,msg);
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
//       buf_ns::buf_t<256> buf(2);
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
};

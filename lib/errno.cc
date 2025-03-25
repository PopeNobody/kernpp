#include <errno.hh>
#include <syscall.hh>
#include <buf.hh>

namespace sys {
  errno_t errno;
  ssize_t set_errno(errno_t err)
  {
    if(err>=0)
      return err;
    {
      buf_ns::buf_t buf(2);
      if(err!=11)
        buf.println("setting error to=",err);
    };
    errno=-err;
    return -1;
  }
  void perror(const c_str &msg)
  {
    static c_str null;
    perror(null,msg);
  };
  void pexit(const c_str &msg)
  {
    perror(msg);
    exit(1);
  };
  void perror(const c_str &msg1, const c_str &msg2)
  {
    buf_ns::buf_t buf(2);
    if(msg1) {
      buf.print(msg1);
      buf.print(":");
    };
    if(msg2) {
      buf.print(msg2);
      buf.print(":");
    };
    buf.println(strerror(errno));
  };
  void pexit(const c_str &msg1, const c_str &msg2)
  {
    perror(msg1,msg2);
    exit(1);
  };
};

#include <errno.hh>
#include <syscall.hh>
#include <buf.hh>

namespace sys {
  errno_t errno;
  ssize_t set_errno(ssize_t err)
  {
    if(err>=0)
      return err;
    {
      buf_ns::buf_t<80> buf(2);
      // XXX why is 11 a special case?
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
    buf_ns::buf_t<256> buf(2);
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

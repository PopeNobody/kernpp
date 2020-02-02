#include <errno.hh>
#include <syscall.hh>
#include <write_buf.hh>

namespace sys {
  errno_t errno;
  ssize_t set_errno(errno_t err)
  {
    if(err>=0)
      return err;
    {
      write_buf<> buf(2);
      buf.put("errno=");
      buf.fmtln(err);
    };
    abort();
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
    write_buf<> buf(2);
    if(msg1) {
      buf.put(msg1);
      buf.put(":");
    };
    if(msg2) {
      buf.put(msg2);
      buf.put(":");
    };
    buf.putln(strerror(errno));
  };
  void pexit(const c_str &msg1, const c_str &msg2)
  {
    perror(msg1,msg2);
    exit(1);
  };
};

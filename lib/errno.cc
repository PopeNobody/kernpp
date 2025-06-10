#include <errno.hh>
#include <syscall.hh>

namespace sys {
  errno_t errno;
  ssize_t set_errno(ssize_t err)
  {
    if(err>=0)
      return err;
    errno=-err;
    return -1;
  }
  void perror(const char *msg)
  {
    static c_str null;
    perror(null,msg);
  };
  void pexit(const char *msg)
  {
    perror(msg);
    exit(1);
  };
  void perror(const char * msg1, const char * msg2)
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
  void pexit(const char *msg1, const char *msg2)
  {
    perror(msg1,msg2);
    exit(1);
  };
};

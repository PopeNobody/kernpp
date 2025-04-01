#ifndef errno_hh
#define errno_hh errno_hh

#include <types.hh>
#include <error_t.hh>

struct c_str;
namespace sys {
  typedef int errno_t;
  extern errno_t errno;
  ssize_t set_errno(long err);
  const c_str &strerror(errno_t err=errno);
  void perror(const c_str &msg1, const c_str &msg2);
  void pexit(const c_str &msg1, const c_str &msg2);
  void perror(const c_str &msg1);
  void pexit(const c_str &msg1);
};

#endif

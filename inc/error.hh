
namespace c_str {
  struct c_str;
};
#include <errno.hh>
namespace err {
  using c_str::c_str;
  extern errno_t errno;
  ssize_t set_errno(ssize_t err);
  const c_str &strerror(errno_t err);
  const c_str &strerror();
  void pexit(int, const c_str &msg1, const c_str &msg2);
  void pexit(int, const c_str &msg1);
  void pexit(int);
  void pexit(const c_str &msg1, const c_str &msg2);
  void pexit(const c_str &msg1);

  void perror(const c_str &msg1, const c_str &msg2);
  void perror(const c_str &msg1);
};

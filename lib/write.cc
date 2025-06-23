#include "syscall.hh"
#include "fmt.hh"
namespace sys {
  using fmt::fmt_t;
  ssize_t write(fd_t fd, const c_str &fmt) {
    return write(fd,(c_str)fmt);
  };
  ssize_t write(fd_t fd, const fmt_t &fmt) {
    return write(fd,(c_str)fmt);
  };
}

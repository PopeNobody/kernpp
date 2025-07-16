#include "syscall.hh"


namespace sys {
  template <typename Arg1, typename... Args>
    ssize_t write(fd_t fd, Arg1 arg1, Args&&... args) {
      ssize_t val = 0;//write(fd,arg1,err_log);
//      val+=write(fd, std::forward<Args...>(args...));
      return val;
    }
}
void sys::log_syscall4(uint64_t n, uint64_t a1, uint64_t a2,
    uint64_t a3, uint64_t a4 )
{
  using fmt::fmt_t;
  write(2,"syscall4(",fmt_t(n),", ", fmt_t(a1), ", ", fmt_t(a2), ", ",
      fmt_t(a3), ", ", fmt_t(a4));
};

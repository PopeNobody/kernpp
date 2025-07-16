#include "syscall.hh"


namespace sys {
  template <typename... Args>
    ssize_t write(fd_t fd, Args&&... args) {
      auto tup = std::forward_as_tuple(std::forward<Args>(args)...);

      constexpr std::size_t N = sizeof...(Args);
      if constexpr (N > 0 && std::is_convertible_v<
          std::tuple_element_t<N-1, decltype(tup)>, sys::errhand_t>)
      {
        auto hand = std::get<N-1>(tup);
        auto data = std::tuple_slice<0, N-1>(tup);
        return write(fd, data, hand);
      } else {
        return write(fd, tup, sys::err_log );
      }
    }
}
void sys::log_syscall4(uint64_t n, uint64_t a1, uint64_t a2,
    uint64_t a3, uint64_t a4 )
{
  using fmt::fmt_t;
  write(2,"syscall4(",fmt_t(n),", ", fmt_t(a1), ", ", fmt_t(a2), ", ",
      fmt_t(a3), ", ", fmt_t(a4));
};

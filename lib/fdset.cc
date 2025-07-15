#include "bitset.hh"

sys::fdset_t::fdset_t( fd_t fd1, fd_t fd2, fd_t fd3,
    fd_t fd4, fd_t fd5, fd_t fd6,
    fd_t fd7, fd_t fd8, fd_t fd9
    )
{
  fd_t fds[] = { fd1, fd2, fd3, fd4, fd5, fd6, fd7, fd8, fd9 };
  for(auto fd: fds) {
    if(fd<0)
      continue;
    set(fd);
  };
};

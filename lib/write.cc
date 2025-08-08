#include "syscall.hh"
#include "fmt.hh"

//ssize_t sys::write(fd_t fd, const char *buf, size_t len, sys::errhand_t hand)
//{
//  return 0;
//};
ssize_t sys::write(fd_t fd, const fmt::fmt_t &fmt, sys::errhand_t hand){
  iovec vec=(iovec)fmt;
  return write(fd,vec,hand);
};

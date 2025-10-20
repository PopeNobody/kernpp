#include "syscall.hh"
#include "fmt.hh"
#include "itr-ops.hh"

//ssize_t sys::write(fd_t fd, const char *buf, size_t len, sys::errhand_t hand)
//{
//  return 0;
//};
ssize_t sys::write(fd_t fd, const char *buf, errhand_t hand)
{
  iovec vec;
  vec.iov_base=(void*)buf;
  vec.iov_len=itr::len(buf);
  return write(fd,vec,hand);
};
ssize_t sys::write(fd_t fd, const char *buf, const char *end, errhand_t hand)
{
  iovec vec;
  vec.iov_base=(void*)buf;
  vec.iov_len=ssize_t(end-buf);
  return write(fd,vec,hand);
};
ssize_t sys::write(fd_t fd, const iovec &fmt, sys::errhand_t hand){
  return write(fd,(char*)fmt.iov_base, fmt.iov_len,hand);
};
ssize_t sys::write(fd_t fd, const str::c_str &fmt, sys::errhand_t hand){
  iovec vec=(iovec)fmt;
  return write(fd,vec,hand);
};

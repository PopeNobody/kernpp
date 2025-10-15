#include <iostream.hh>

stream::ostream::ostream(fd_t fd)
  :fd(fd)
{
//     *this << fd << endl;
}

stream::ostream::~ostream() {
  sys::close(fd);
}
namespace stream {
  ssize_t ostream::write(const char *buf, ssize_t len) {
    return sys::write(fd,buf,len);
  }
  ssize_t ostream::write(const sys::iovec_t &vec) {
    return 0;
  }
}

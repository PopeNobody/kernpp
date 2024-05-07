#pragma once

struct ostream_t {
  int fd;
  ostream_t(int fd)
    : fd(fd)
  {
  }
  size_t error() const {
    return -1;
  }
  size_t write(const char *beg, const char *end) const{
    size_t res=sys::write(fd,beg,end-beg);
    if(res>=0)
      return res;
    return error();
  }
};

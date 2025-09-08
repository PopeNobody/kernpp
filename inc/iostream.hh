#pragma once
#include "syscall.hh"
namespace stream {
  using sys::fd_t;
  struct ostream {
    fd_t fd;
    ostream(fd_t fd=1);
    virtual ssize_t write(const char *buf, ssize_t len);
    virtual ssize_t write(const iovec_t &vec);
    virtual ~ostream();
    static ostream &get_cerr() {
      static ostream cerr(2);
      return cerr;
    };
    static ostream &get_cout() {
      static ostream cout(1);
      return cout;
    };
  };
  struct endl_t {
    endl_t() {
    }
    ~endl_t() {
    };
  };
  static ostream &cout=ostream::get_cout();;
  static endl_t endl;
  template<class T>
    inline ostream &operator<<(ostream &lhs, const T &rhs) {
      sys::write(lhs.fd, fmt::fmt_t(rhs));
      return lhs;
    };
  template<>
    inline ostream &operator<<<endl_t>(ostream &lhs, const endl_t &rhs) {
      sys::write(lhs.fd, "\n");
      return lhs;
    };
  template<>
    inline ostream &operator<<<char *>(ostream &lhs, char * const &rhs) {
      sys::write(lhs.fd, rhs);
      return lhs;
    };
  template<>
    inline ostream &operator<<<const char *>(ostream &lhs, const char * const &rhs) {
      sys::write(lhs.fd, rhs);
      return lhs;
    };
}

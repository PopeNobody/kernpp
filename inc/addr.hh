#pragma once
#include "hand.hh"
#include "ptr.hh"
#include <boost/array.hpp>

struct sockaddr;
struct sockaddr_in;
struct sockaddr_un;
namespace x {
  union sockaddr_u;
  class addr_t {
    struct buf_t {
      char buf[128];
      size_t size;
      buf_t()
      {
        for(auto b(buf), e(buf); b!=e; b++)
        {
          *b=0;
        };
      }
    };
    buf_t buf;
    const sockaddr_u *get()const  {
      return (sockaddr_u*)&buf;
    };
    sockaddr_u *get() {
      return (sockaddr_u*)&buf;
    };

    public:
    addr_t()
    {
    }
    addr_t(const addr_t &rhs)
      :buf(rhs.buf)
    {
    };
    addr_t(const sockaddr_in &sin);
    addr_t(const sockaddr_un &sun);
    addr_t &operator=(addr_t rhs){
      std::swap(*this,rhs);      
      return *this;
    };
    size_t size() const {
      return buf.size;
    };
    void sun(const sockaddr_un &sun);
    void sin(const sockaddr_in &sin);
    const sockaddr_un &sun()const ;
    const sockaddr_in &sin()const ;
    const char *path() const;
    operator sockaddr *();
    operator const sockaddr *() const;
    int bind(int fd, handler_t = err_fail) const;
    static addr_t unix(const char *);
    static addr_t inet(const char *);
  };
  int unix_stream( handler_t hand=err_fail );
};

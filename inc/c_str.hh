#ifndef c_str_hh
#define c_str_hh c_str_hh

#include <syscall.hh>
#include <dbg.hh>
#include <cmp.hh>
#include <itr.hh>
class c_str {
  struct body_t {
    char *beg;
    char *end;
    body_t(char *beg, char*end)
      :beg(beg),end(end)
    {
    };
  } body;
  static const char null_str[1];
  static const char colon[2];
  static const char newline[2];
  public:
  c_str(char *b, char *e = 0)
    :body(b,e)
  {
    if(!body.beg)
      body.end=0;
    if(!body.end)
      body.end=body.beg+true_n(body.beg);
  };
  c_str(const char *b=0, const char *e=0)
    : body((char*)b,(char*)(e))
  {
  };
  c_str(const char *b, size_t l)
    : body((char*)b,(char*)(b+l))
  {
  };
  c_str(char *b, size_t l)
    : body(b,b+l)
  {
  };
  template<size_t n>
    c_str(char(b)[n], bool i)
    :body(b,b+n-i?0:1)
    {
    }
  c_str(const c_str &lhs)
    : body(lhs.body.beg,lhs.body.end)
  {
  };
  size_t len() const
  {
    return body.end-body.beg;
  };
  size_t size() const {
    return body.end-body.beg;
  };
  char operator[](size_t pos) const
  {
    return body.beg[pos];
  };
  operator bool() const
  {
    return body.beg<body.end;
  }
  c_str operator++(int) 
  {
    c_str res(*this);
    if(body.beg<body.end)
      ++body.beg;
    return res;
  };
  c_str &operator++()
  {
    if(body.beg<body.end)
      ++body.beg;
    return *this;
  };
  char operator*() const {
    return *body.beg;
  };
  const char *begin() const {
    return body.beg;
  };
  char *begin() {
    return body.beg;
  };
  const char *end() const {
    return body.end;
  };
  char *end() {
    return body.end;
  };
  friend auto cmp(const c_str &lhs, const c_str &rhs)
  {
    auto msize=min(lhs.size(),rhs.size());
    auto r=seq_cmp(lhs.begin(),rhs.begin(),msize);
    return r!=(0<=>0) ? r : (lhs.size()<=>rhs.size());
  };
};

inline ssize_t write(fd_t fd, const c_str &str) {
  return sys::sys_write(fd, str.begin(), str.size());
};

#endif

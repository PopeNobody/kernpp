#ifndef c_str_hh
#define c_str_hh c_str_hh

#include <syscall.hh>

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
  public:
  c_str()
    : body((char*)null_str,(char*)null_str)
  {
  };
  c_str(const char *b, const char *e = 0)
    : body((char*)b,(char*)e)
  {
    if(body.end)
      return;
    body.end=body.beg;
    while(*body.end)
      ++body.end;
  };
  c_str(char *b, char *e = 0)
    : body(b,e)
  {
    if(body.end)
      return;
    body.end=body.beg;
    while(*body.end)
      ++body.end;
  };
  c_str(const char *b, size_t l)
    : body((char*)b,(char*)(b+l))
  {
  };
  c_str(char *b, size_t l)
    : body(b,b+l)
  {
  };
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
  static int cmp(size_t lhs, size_t rhs);
  static int cmp(const c_str &lhs, const c_str &rhs);
  static const c_str colon;
  static const c_str newline;
};
#define cmp_op(x) \
  inline bool operator x(const c_str &lhs, const c_str &rhs) { \
    return c_str::cmp(lhs,rhs) x 0; \
  };
cmp_op(<);
cmp_op(>);
cmp_op(<=);
cmp_op(>=);
cmp_op(==);
cmp_op(!=);

inline ssize_t write(fd_t fd, const c_str &str) {
  return sys::write(fd, str.begin(), str.size());
};

#endif

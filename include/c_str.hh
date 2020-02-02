#ifndef c_str_hh
#define c_str_hh c_str_hh

#include <syscall.hh>
#include <assert.hh>

struct c_str {
  char *beg;
  char *end;
  static const char null_str[1];
  c_str()
    : beg((char*)null_str), end((char*)null_str)
  {
  };
  c_str(const char *b, const char *e = 0)
    : beg((char*)b), end((char*)e)
  {
    if(end)
      return;
    end=beg;
    while(*end)
      ++end;
  };
  c_str(char *b, char *e = 0)
    : beg(b), end(e)
  {
    if(end)
      return;
    end=beg;
    while(*end)
      ++end;
  };
  c_str(const char *b, size_t l)
    : beg((char*)b), end((char*)b+l)
  {
  };
  c_str(char *b, size_t l)
    : beg(b), end(b+l)
  {
  };
  c_str(const c_str &lhs)
    : beg(lhs.beg), end(lhs.end)
  {
  };
  size_t len() const
  {
    return end-beg;
  };
  char operator[](size_t pos) const
  {
    return beg[pos];
  };
  operator bool() const
  {
    return beg<end;
  }
  c_str operator++(int) 
  {
    c_str res(*this);
    if(beg<end)
      ++beg;
    return res;
  };
  c_str &operator++()
  {
    if(beg<end)
      ++beg;
    return *this;
  };
  char operator*() const {
    return *beg;
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
  return sys::sys_write(fd, str.beg, str.end-str.beg);
};

#endif

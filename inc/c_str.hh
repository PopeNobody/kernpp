#pragma once
#include "types.hh"
#include "strong_ordering.hh"

namespace str {
  using strong_ordering = std::strong_ordering;

  struct c_str {
    struct body_t {
      char *beg;
      char *end;
      body_t(char *beg, char*xend)
        :beg(beg),end(xend)
      {
        if(end)
          return;
        if(!beg)
          return;
        end=beg;
        while(*end)
          end++;
      };
      body_t(char *beg, size_t len)
        : beg(beg),end(beg+len)
      {
      };
    } body;
    static const c_str null_str;
    static const c_str colon;
    static const c_str newline;
    public:
    c_str(char *b, char *e = 0)
      : body(b,e)
    {
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
      :body(b,b+n-(b[n-1]?0:1))
      {
      }
    c_str(const iovec_t &vec)
      : body((char*)vec.iov_base, vec.iov_len)
    {
    };
    c_str(const c_str &lhs)
      : body(lhs.body.beg,lhs.body.end)
    {
    };
    operator iovec_t() const {
      return iovec_t{ (void*)beg(), size() };
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
    char &operator[](size_t pos) {
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
    const char *beg() const {
      return body.beg;
    };
    char *beg() {
      return body.beg;
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
    friend strong_ordering cmp(size_t sz1, size_t sz2 );
    friend strong_ordering cmp(char ch1, char ch2);
    friend bool lt(const c_str &lhs, const c_str &rhs);
    friend bool gt(const c_str&lhs, const c_str &rhs);
    friend bool eq(const c_str&lhs, const c_str &rhs);
  };
  bool lt(const c_str&lhs, const c_str &rhs);
  bool gt(const c_str&lhs, const c_str &rhs);
  bool eq(const c_str&lhs, const c_str &rhs);
  strong_ordering cmp(size_t sz1, size_t sz2 );
  strong_ordering cmp(char ch1, char ch2);
  strong_ordering cmp(const c_str &lhs, const c_str &rhs);
}


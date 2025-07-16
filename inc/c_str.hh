#pragma once
#include "syscall.hh"
#include "template-glue.hh"
#include "dbg.hh"
#include "itr_ops.hh"
namespace str {
  class c_str {
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
        body.end=body.beg+itr::len(body.beg);
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
    c_str(const iovec &vec)
      : body((char*)vec.iov_base, vec.iov_len)
    {
    };
    c_str(const c_str &lhs)
      : body(lhs.body.beg,lhs.body.end)
    {
    };
    operator iovec() const {
      return iovec{ (void*)beg(), size() };
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
    friend bool lt(const c_str &lhs, const c_str &rhs) {
      auto msize=std::min(lhs.size(),rhs.size());
      for(auto i=0*msize;i<msize;i++){
        if(lhs[i]!=rhs[i])
          return lhs[i]<rhs[i]?true:false;
      };
      return lhs.size()<rhs.size();
    };
  };
}
namespace sys {
  using str::c_str;
  ssize_t write(fd_t fd, const char *beg, const char *end);
  inline ssize_t write(fd_t fd, const c_str &str) {
    return write(fd,str.begin(),str.end());
  };
};
namespace itr {
  using str::c_str;
  inline char *copy(char *db, char *de, c_str str) {
    if(db+str.len()>=de)
      return 0;
    for(int i=0;i<str.len();i++)
      *db++=str[i];
    return db;
  };
  char *copy(char *db, char *de, iovec vec);
};


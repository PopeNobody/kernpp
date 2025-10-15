#pragma once
#include "syscall.hh"
namespace sys {
  struct timeval_t;
};
namespace collect {
  template<size_t sz>
    struct bitset_t;
};
namespace fmt {
  using std::uint64_t;
  using collect::bitset_t;

  
  struct int_t {
    unsigned long abs;
    bool neg;
    static unsigned long get_abs(long val)
    {
      return val<0?-val:val;
    };
    static bool get_neg(long val) {
      return val<0;
    };
    int_t(unsigned long abs)
      :abs(abs),neg(false)
    {
    }
    int_t(long val)
      :abs(get_abs(val)),neg(get_neg(val))
    {
    }
    int_t(unsigned abs)
      :abs(abs),neg(false)
    {
    }
    int_t(int val)
      :abs(get_abs(val)),neg(get_neg(val))
    {
    }
    int_t(unsigned short abs)
      :abs(abs),neg(false)
    {
    }
    int_t(short val)
      :abs(get_abs(val)),neg(get_neg(val))
    {
    }
    int_t(unsigned char abs)
      :abs(abs),neg(false)
    {
    }
    int_t(char val)
      :abs(get_abs(val)),neg(get_neg(val))
    {
    };
  };
  struct float_t {
    long double val;
    float_t(long double val)
      : val(val)
    {
    };
  };
  struct bool_t {
    bool val;
    explicit bool_t(bool val)
      :val(val)
    {
    };
    operator bool&() {
      return val;
    };
    operator const bool&() const {
      return val;
    };
  };
  struct ptr_t {
    void *val;
    template<class val_t>
      ptr_t(val_t *val)
      :val(val)
      {
      };
  };
  struct fmt_t
  {
    struct body_t {
      char buf[68]={};
      char nul[1]={};
      char off=0;
      char len=0;
      body_t()
      {
      };
      ~body_t() {
      };
    } body;
    void int_fmt(int_t wrap, int base, int width, char fill);
    void float_fmt(float_t val, int width, int prec=6);
    void ptr_fmt(ptr_t ptr, int width=16);
    void bool_fmt(bool_t val);
    
//       fmt_t(const int_t &val,int base=10, int width=1, char fill='0')
//       {
//         int_fmt(val,base,width,fill);
//       };
//       fmt_t(const float_t &f,int width=0, int prec=6, char fill=' ')
//       {
//         float_fmt(f,width,prec);
//       };
//       fmt_t(const ptr_t &ptr, int width=16)
//       {
//         ptr_fmt(ptr,width);
//       };
//       fmt_t(const sys::errno_t &errno);
//       explicit fmt_t(const bool_t &val)
//       {
//         bool_fmt(val);
//       };
//       fmt_t(const std::timeval_t &val);
//       fmt_t(const std::timespec_t &val);
//       template<size_t sz>
//         fmt_t(const bitset_t<sz> &val);
    size_t len() const {
      if(body.nul[0]) {
        const char *tmp=beg();
        size_t i=0;
        while(tmp[i])
          ++i;
        return i;
      }
      return body.len;
    };
    const char *beg() const {
      if(body.nul[0]) {
        return *(const char**)body.buf;
      } else {
        return body.buf+body.off;
      };
    };
    const char *end() const {
      return beg()+len();
    };
    char *beg() {
      if(body.nul[0]) {
        return *(char**)body.buf;
      } else {
        return body.buf+body.off;
      };
    };
    char *end() {
      return beg()+len();
    };
    operator iovec_t() const {
      return { (void*)beg(), len() };
    };
    static constexpr const char digits[]="0123456789abcdef";
    char operator[](size_t idx) const {
      return beg()[idx];
    }
    char &operator[](size_t idx) {
      return ((char*)beg())[idx];
    }
    void push_back(char ch) {
      if(end()==body.nul){
        if(beg()==body.buf) {
          sys::pexit(2,"push_back: full");
        }
        char *pos=body.buf;
        for(char *b(beg()), *e(end()); b!=e; b++) {
          *pos++=*b++;
        };
        while(pos!=end())
          *pos++=0;
        body.off=0;
      };
      body.buf[body.len++]=ch;
    };
//       template<class T>
//       fmt_t(const std::wrap_t<T> &val)
//       {
//         T t=val;
//         int base=10;
//         int width=0;
//         int fill=0;
//         format(val,base,width,fill);
//       };;

//       fmt_t(char *val)
//       {
//         *(char **)body.buf=val;
//         body.nul[0]=1;
//       };
//       fmt_t(const char *val)
//       {
//         *(const char **)body.buf=val;
//         body.nul[0]=1;
//       };
  };
  inline bool isspace(int i){
    switch(i){
      case 9:
      case 10:
      case 11:
      case 12:
      case 13:
      case 14:
      case 32:
        return true;
      default:
        return false;
    }
  };
  inline std::int64_t atoi(const char *pos){
    uint64_t res=0;
    while(isspace(*pos))
      pos++;
    while(*pos>='0' && *pos<='9') {
      res*=10;
      res+=(*pos-'0');
      ++pos;
    };
    return res;
  }
}


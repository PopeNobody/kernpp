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
  struct fmt_t
  {
    void format_int(uint64_t wrap, int base, int width, char fill);
    void format_float(float val, int width, int prec=6);
    void format_ptr(void *ptr, int width=16);
    void format_timespec(const timespec_t &val);
    struct body_t {
      iovec_t vec;
      char buf[256];
      body_t()
        :vec{buf,0}
      {
      };
    };
    body_t body;
    fmt_t(const timespec_t &val)
    {
      format_timespec(val);
    };
    fmt_t(uint64_t wrap, int base=10, int width=0, char fill='0')
    {
      format_int(wrap,base,width,fill);
    };
    fmt_t(void *val, int width=16)
    {
      format_ptr(val,width);
    };
    size_t len() const {
      return body.vec.iov_len;
    };
    const char *beg() const {
      return (const char*)body.vec.iov_base;
    };
    const char *end() const {
      return beg()+body.vec.iov_len;
    };
    char *beg() {
      return (char*)body.vec.iov_base;
    };
    char *end() {
      return beg()+body.vec.iov_len;
    };
    operator iovec_t() const {
      return body.vec;
    };
    static constexpr const char digits[]="0123456789abcdef";
    char operator[](size_t idx) const {
      return beg()[idx];
    }
    char &operator[](size_t idx) {
      return ((char*)beg())[idx];
    }
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


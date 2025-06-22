#pragma once
#include "types.hh"
namespace sys {
  struct timeval;
};
namespace fmt {
  struct int_t {
    unsigned long val;
    bool sign;
    int_t(unsigned long val)
      :val(val)
    {
    }
  };
  using sys::timeval;
  struct fmt_t {
    char buf[61];
    char nul[1];
    char off;
    void format(unsigned long val, int base, bool neg) {
      nul[0]=0;
      off=(nul-buf);
      do {
        buf[--off]=digits[val%base];
        val/=base;
      } while(val);
    };
    fmt_t(uint64_t val,int base)
    {
      format(val,base,false);
    };
    fmt_t(uint64_t val,bool neg)
    {
      format(val,10,neg);
    };
    fmt_t(uint64_t val)
    {
      format(val,10,false);
    };
    fmt_t(const timeval &rhs);
    operator c_str() const {
      return c_str(buf+off,nul-buf-off);
    };
    static constexpr const char digits[]="0123456789abcdef";
  };
}


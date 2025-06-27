#pragma once
#include "types.hh"
namespace sys {
  struct timeval;
};
namespace fmt {
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
    }
  };
  using sys::timeval;
  struct fmt_t {
    char buf[50];
    char nul[1];
    char off;
    void format(unsigned long val, int base, int width, bool neg) {
      nul[0]=0;
      off=(nul-buf);
      do {
        buf[--off]=digits[val%base];
        val/=base;
      } while(val);
      if(neg)
        buf[--off]='-';
      if(nul[0])
        sys::exit(1);
    };
    fmt_t(const int_t &val,int base=10)
    {
      format(val.abs,base,1,val.neg);
    };
    fmt_t(const timeval &rhs);
    fmt_t(const timespec &rhs);
    fmt_t(const fdset_t &rhs);
    operator c_str() const {
      return c_str(buf+off,nul-buf-off);
    };
    static constexpr const char digits[]="0123456789abcdef";
  };
}


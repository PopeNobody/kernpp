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
    operator iovec() const = delete;
  };
  template<size_t sz>
    struct buf_t {
      char buf[sz];
      char nul[1];
      char off;
      buf_t()
        :buf{}, nul{0}, off{0}
      {
      }
      operator iovec() const {
        return { (void*)(buf+off), size_t(nul-(buf+off)) };
      };
      static constexpr const char digits[]="0123456789abcdef";
      void fmt(int_t vval, int base=10, int width=1, int fill='0')
      {
        auto val=vval.abs;
        auto neg=vval.neg;
        //       if(buf.buf+width>=buf.nul) {
        //         sys::write(2,"Warning: width > ");
        //         sys::write(2,fmt_t(sizeof(buf)));
        //         sys::write(2,"\n");
        //         width=sizeof(buf);
        //       };
        nul[0]=0;
        off=(nul-buf);
        do {
          buf[--off]=digits[val%base];
          val/=base;
        } while(val);
        while(off>(nul-buf)-width)
          buf[--off]='0';
        if(neg)
          buf[--off]='-';
        if(nul[0])
          sys::die(1,"Internal error, nul[0] was written");
        if(off>=sizeof(buf))
          sys::die(1,"Internal error, off>=sizeof(buf)");
      };
    };
  template<class val_t>
    struct tfmt_t;
  template<>
    struct tfmt_t<int_t> : public buf_t<70>
    {
      tfmt_t(const int_t &val, int base=10, int width=1, char fill='0')
      {
        fmt(val, base, width, fill);
      }
    };
  template<>
    struct tfmt_t<timeval> : public buf_t<70> {
      tfmt_t(const timeval &rhs);
    };
  template<>
    struct tfmt_t<timespec> : public buf_t<70> {
      tfmt_t(const timespec &rhs);
    };
  template<>
    struct tfmt_t<fdset_t>
    {
      tfmt_t(const fdset_t &rhs);
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
  inline uint64_t atoi(const char *pos){
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
  template<class T>
    tfmt_t<int_t> mk_fmt(const T &t) {
      return tfmt_t<int_t>(t);
    };
  template<class T>
    tfmt_t<T> mk_fmt(const T &t, int base, int width=1);
  template<class T>
    ssize_t write(fd_t fd, const tfmt_t<T> &t) {
      sys::write(fd,(iovec)t);
    };
}


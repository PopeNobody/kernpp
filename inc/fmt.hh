#pragma once
#include "types.hh"
#include "c_str.hh"
namespace sys {
  struct timeval;
  inline ssize_t write(fd_t fd, const c_str &str){
    return write(fd,str.begin(),str.end());
  };
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
  struct fmt_t
  {
    char buf[68];
    char nul[1];
    char off;
    void format(int_t wrap, int base, int width, char fill) {
      unsigned long val=wrap.abs;
      unsigned long neg=wrap.neg;
      if(width>=sizeof(buf)){
        sys::write(2,"Error: width > ");
        sys::write(2,fmt_t(sizeof(buf)));
        sys::write(2,"\n");
        width=sizeof(buf);
      };
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
        sys::exit(1);
    };
    void format(float val, int width, int base, char fill=' ');
    fmt_t(const int_t &val,int base=10, int width=1, char fill='0')
    {
      format(val,base,width,fill);
    };
    fmt_t(float f)
    {
    };
    fmt_t(const timeval_t &val)
    {
      fmt_t fsec(val.tv_sec);
      str::c_str sec=(iovec)fsec;
      fmt_t fusec(val.tv_nsec);
      str::c_str usec=(iovec)fusec;
      char *pos=buf;
      char *end=&nul[0];
      pos=itr::copy(pos,end,"timeval_t{");
      assert(!*pos);
      pos=itr::copy(pos,end,sec.beg(),sec.end());
      assert(!*pos);
      pos=itr::copy(pos,end,",");
      assert(!*pos);
      pos=itr::copy(pos,end,usec.beg(),usec.end());
      assert(!*pos);
      pos=itr::copy(pos,end,"}");
      assert(!*pos);
    };
    operator iovec() const {
      return { (void*)(buf+off), (size_t)(nul-buf-off) };
    };
    static constexpr const char digits[]="0123456789abcdef";
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
  struct form_t : public iovec {
    form_t(void *base, size_t len)
      : iovec{base,len}
    {
    }
  };
}


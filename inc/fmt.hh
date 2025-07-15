#pragma once
#include "syscall.hh"
namespace sys {
  struct timeval_t;
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
  
  struct fmt_t
  {
    char buf[68];
    char nul[1];
    char off;
    char len;
    void format(int_t wrap, int base, int width, char fill);
    void format(float val, int width, int prec=6);
    void format(void *ptr, int width=16);
    fmt_t(unsigned long val,int base=10, int width=1, char fill='0')
    {
      format(val,base,width,fill);
    };
    fmt_t(long val,int base=10, int width=1, char fill='0')
    {
      format(val,base,width,fill);
    };
    fmt_t(unsigned int val,int base=10, int width=1, char fill='0')
    {
      format(val,base,width,fill);
    };
    fmt_t(int val,int base=10, int width=1, char fill='0')
    {
      format(val,base,width,fill);
    };
    fmt_t(unsigned short val,int base=10, int width=1, char fill='0')
    {
      format(val,base,width,fill);
    };
    fmt_t(short val,int base=10, int width=1, char fill='0')
    {
      format(val,base,width,fill);
    };
    fmt_t(unsigned char val,char base=10, char width=1, char fill='0')
    {
      format(val,base,width,fill);
    };
    fmt_t(char val,char base=10, char width=1, char fill='0')
    {
      format(val,base,width,fill);
    };
    fmt_t(float f,int width=0, int prec=6, char fill=' ')
    {
      format(f,width,prec);
    };
    fmt_t(void *ptr, int width=16)
    {
      format(ptr,width);
    };
    fmt_t(enum sys::errno_t err);
    template<class val_t>
      fmt_t(const val_t &val)
      {
        char *pos=val.format(buf,nul);
        off=0;
        len=pos-buf;
      };
    fmt_t(bool val);
    fmt_t(const timeval_t &val);
    operator iovec() const {
      return { (void*)(buf+off), (size_t)(len) };
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


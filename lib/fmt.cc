#include "fmt.hh"

namespace fmt {
  fmt_t::fmt_t(const timeval_t &val)
  {
    fmt_t fsec(val.tv_sec);
    str::c_str sec=(iovec)fsec;
    fmt_t fusec(val.tv_usec);
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
  fmt_t::fmt_t(bool val) {
    char *str=(char*)(val?"-true":"false");
    char *pos=nul;
    *pos=0;
    memcpy(pos-5,str,5);
    pos-=5;
    off=pos-buf;
    len=5;
  };
  fmt_t::fmt_t(sys::errno_t err) {
    format((int64_t)err,10,20,'-');
  };
  void fmt_t::format(void *val, int width) {
    fmt_t fmt(uint64_t(val),16,16,'o');
    char *pos=buf;
    pos=itr::copy(pos,nul,"0x");
    pos=itr::copy(pos,nul,fmt);
    off=0;
    len=pos-buf;
  };
  void fmt_t::format(float val, int width, int precision) {
    format(uint64_t(val),10,width,'*');
  }
  void fmt_t::format(int_t wrap, int base, int width, char fill)
  {
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
    len=sizeof(buf)-off;
    if(nul[0])
      std::abort();
  };
};
char *timeval::format(char *buf, char *end) const {
  assert((buf<end) && (buf>end-100));
  fmt::fmt_t fu(tv_usec);
  fmt::fmt_t fs(tv_sec);
  char *pos(buf);
  pos=itr::copy(pos,end,"timeval{");
  pos=itr::copy(pos,end,fs);
  pos=itr::copy(pos,end,",");
  pos=itr::copy(pos,end,fu);
  pos=itr::copy(pos,end,"}");
  return pos;
};
char *timespec::format(char *buf, char *end) const {
  assert((buf<end) && (buf>end-100));
  fmt::fmt_t fu(tv_nsec);
  fmt::fmt_t fs(tv_sec);
  char *pos(buf);
  pos=itr::copy(pos,end,"timespec{");
  pos=itr::copy(pos,end,fs);
  pos=itr::copy(pos,end,",");
  pos=itr::copy(pos,end,fu);
  pos=itr::copy(pos,end,"}");
  return pos;
};

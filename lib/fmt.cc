#include "fmt.hh"
#include "bitset.hh"

namespace fmt {
  using collect::bitset_t;
  template<size_t sz>
  fmt_t::fmt_t(const bitset_t<sz> &val)
  {
  }
  fmt_t::fmt_t(const timeval_t &val)
  {
    fmt_t fsec(val.tv_sec);
    str::c_str sec=(iovec)fsec;
    fmt_t fusec(val.tv_usec);
    str::c_str usec=(iovec)fusec;
    char *pos=body.buf;
    char *end=&body.nul[0];
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
    body.len=pos-body.buf;
  };
  fmt_t::fmt_t(bool val) {
    char *str=(char*)(val?"-true":"false");
    char *pos=body.nul;
    *pos=0;
    memcpy(pos-5,str,5);
    pos-=5;
    body.off=pos-body.buf;
    body.len=5;
  };
  fmt_t::fmt_t(sys::errno_t err) {
    eformat((int64_t)err,10,20,'-');
  };
  void fmt_t::pformat(void *val, int width) {
    fmt_t fmt(uint64_t(val),16,16,'o');
    char *pos=body.buf;
    pos=itr::copy(pos,body.nul,"0x");
    pos=itr::copy(pos,body.nul,fmt);
    body.off=0;
    body.len=pos-body.buf;
  };
  void fmt_t::fformat(float val, int width, int precision) {
    format(uint64_t(val),10,width,'*');
  }
  void fmt_t::iformat(int_t wrap, int base, int width, char fill)
  {
    unsigned long val=wrap.abs;
    unsigned long neg=wrap.neg;
    if(width>=sizeof(body.buf)){
      sys::write(2,"Error: width > ");
      sys::write(2,fmt_t(sizeof(body.buf)));
      sys::write(2,"\n");
      width=sizeof(body.buf);
    };
    body.nul[0]=0;
    body.off=(body.nul-body.buf);
    do {
      body.buf[--body.off]=digits[val%base];
      val/=base;
    } while(val);
    while(body.off>(body.nul-body.buf)-width)
      body.buf[--body.off]='0';
    if(neg)
      body.buf[--body.off]='-';
    body.len=sizeof(body.buf)-body.off;
    if(body.nul[0])
      std::abort();
  };
  fmt_t::fmt_t(const timespec_t &val)
  {
    fmt_t fsec(val.tv_sec);
    str::c_str sec=(iovec)fsec;
    fmt_t fusec(val.tv_nsec);
    str::c_str usec=(iovec)fusec;
    char *pos=body.buf;
    char *end=&body.nul[0];
    pos=itr::copy(pos,end,"timespec_t{");
    assert(!*pos);
    pos=itr::copy(pos,end,sec.beg(),sec.end());
    assert(!*pos);
    pos=itr::copy(pos,end,",");
    assert(!*pos);
    pos=itr::copy(pos,end,usec.beg(),usec.end());
    assert(!*pos);
    pos=itr::copy(pos,end,"}");
    assert(!*pos);
    body.len=pos-body.buf;
  };
};

#if 0
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
#endif

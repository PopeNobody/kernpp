#include "time.hh"
#include "fmt.hh"
#include "itr-ops.hh"
#include "bitset.hh"

//   namespace fmt {
//     void fmt_t::format_int(uint64_t wrap, int base, int width, char fill) {
//       char *end=body.buf+sizeof(body.buf);
//       char *beg=end;
//       *--beg=0;
//       do {
//         *--beg=digits[wrap%base];
//         wrap/=base;
//       } while(wrap);
//       while(end-beg < width) {
//         *--beg=fill;
//       };
//       body.vec.iov_base=beg;
//       body.vec.iov_len=end-beg;
//     };
//     void fmt_t::format_float(float val, int width, int prec) {
//       sys::abort();
//     };
//     void fmt_t::format_ptr(void *ptr, int width) {
//       format_int((uint64_t)ptr,16,16,'0');
//       char *beg=((char*)body.vec.iov_base);
//       *beg--='x';
//       *beg--='0';
//       body.vec.iov_base=beg;
//       body.vec.iov_len+=2;
//     };
//     void fmt_t::format_timespec(const timespec_t &val) {
//       fmt_t wsec=fmt_t(val.tv_sec);
//       fmt_t nsec=fmt_t(val.tv_nsec,10,6);
//       char *pos=body.buf;
//       char *end=body.buf+sizeof(body.buf)-1;
//       pos=itr::copy(pos,end,"timespec{");
//       pos=itr::copy(pos,end,wsec.beg(),wsec.end());
//       *pos++=' ';
//       *pos++=',';
//       pos=itr::copy(pos,end,nsec.beg(),nsec.end());
//       *pos++='}';
//       body.vec.iov_base=body.buf;
//       body.vec.iov_len=pos-body.buf;
//     };
//   };
//   namespace fmt {
//     using collect::bitset_t;
//     using std::timeval_t;
//     using std::timespec_t;
//     fmt_t::fmt_t(const timeval_t &val)
//     {
//       fmt_t fsec(int_t(val.tv_sec));
//       str::c_str sec=(iovec_t)fsec;
//       fmt_t fusec(int_t(val.tv_usec));
//       str::c_str usec=(iovec_t)fusec;
//       char *pos=body.buf;
//       char *end=&body.nul[0];
//       pos=itr::copy(pos,end,"timeval_t{");
//       assert(!*pos);
//       pos=itr::copy(pos,end,sec.beg(),sec.end());
//       assert(!*pos);
//       pos=itr::copy(pos,end,",");
//       assert(!*pos);
//       pos=itr::copy(pos,end,usec.beg(),usec.end());
//       assert(!*pos);
//       pos=itr::copy(pos,end,"}");
//       assert(!*pos);
//       body.len=pos-body.buf;
//     };
//     fmt_t::fmt_t(const bool_t &val) {
//       char *str=(char*)(val?"-true":"false");
//       char *pos=body.nul;
//       *pos=0;
//       memcpy(pos-5,str,5);
//       pos-=5;
//       body.off=pos-body.buf;
//       body.len=5;
//     };
//     fmt_t::fmt_t(const sys::errno_t &err) {
//       format((std::int64_t)err,10,20,'-');
//     };
//     void fmt_t::format(void *val, int width) {
//       fmt_t fmt(uint64_t(val),16,16,'o');
//       char *pos=body.buf;
//       pos=itr::copy(pos,body.nul,"0x");
//       pos=itr::copy(pos,body.nul,fmt.beg(),fmt.end());
//       body.off=0;
//       body.len=pos-body.buf;
//     };
//     void fmt_t::format(float val, int width, int precision) {
//       format(uint64_t(val),10,width,'*');
//     }
//     void fmt_t::format(int_t wrap, int base, int width, char fill)
//     {
//       unsigned long val=wrap.abs;
//       unsigned long neg=wrap.neg;
//       if(width>=sizeof(body.buf)){
//         sys::write(2,"Error: width > ");
//         sys::write(2,fmt_t(int_t(sizeof(body.buf))));
//         sys::write(2,"\n");
//         width=sizeof(body.buf);
//       };
//       body.nul[0]=0;
//       body.off=(body.nul-body.buf);
//       do {
//         body.buf[--body.off]=digits[val%base];
//         val/=base;
//       } while(val);
//       while(body.off>(body.nul-body.buf)-width)
//         body.buf[--body.off]='0';
//       if(neg)
//         body.buf[--body.off]='-';
//       body.len=sizeof(body.buf)-body.off;
//       if(body.nul[0])
//         std::abort();
//     };
//     fmt_t::fmt_t(const timespec_t &val)
//     {
//       fmt_t fsec(int_t(val.tv_sec));
//       str::c_str sec=(iovec_t)fsec;
//       fmt_t fusec(int_t(val.tv_nsec));
//       str::c_str usec=(iovec_t)fusec;
//       char *pos=body.buf;
//       char *end=&body.nul[0];
//       pos=itr::copy(pos,end,"timespec_t{");
//       assert(!*pos);
//       pos=itr::copy(pos,end,sec.beg(),sec.end());
//       assert(!*pos);
//       pos=itr::copy(pos,end,",");
//       assert(!*pos);
//       pos=itr::copy(pos,end,usec.beg(),usec.end());
//       assert(!*pos);
//       pos=itr::copy(pos,end,"}");
//       assert(!*pos);
//       body.len=pos-body.buf;
//     };
//   };


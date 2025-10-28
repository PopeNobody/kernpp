#pragma once
#include "syscall.hh"
#include "itr-ops.hh"
#include "new.hh"
namespace sys {
  struct timeval_t;
};
namespace fmt {
  using std::uint64_t;
  using sys::fd_t;
  template<size_t N>
    struct buf_t {
      fd_t fd;
      const size_t cap;
      size_t len={};
      char buf[N]={};
      buf_t(fd_t fd)
        :fd(fd),cap(N),len(0)
      {
      };
      buf_t(const buf_t &rhs)
        :fd(rhs.fd),cap(rhs.cap),len(rhs.len)
      {
        memcpy(buf,rhs.buf,len);
        memset(buf+len,0,cap-len);
      }
      virtual ~buf_t() {
        write();
      };
      buf_t &operator=(const buf_t &rhs)
      {
        this->~buf_t();
        new((void*)this)buf_t(rhs);
        return *this;
      };
      operator iovec_t() const {
        return {buf,len};
      };
      buf_t &a_str(const char *beg, const char *end=0) {
        if(!end)
          end=beg+itr::len(beg);
        size_t need=end-beg;
        size_t have=sizeof(buf)-(len);
        assert(need<sizeof(buf));
        if(need>have)
          write();
        for(int i=0;i<need;i++) {
          buf[len++]=*beg++;
        };
        return *this;
      };
      buf_t &a_str(const char *beg, size_t len) {
        return a_str(beg,beg+len);
      };
      buf_t &a_int(uint64_t val, bool neg=false, int base=16, int width=16, char fill='0') {
        char buf[24];
        char *end=buf+sizeof(buf)-1;
        char *beg=end;
        *--beg=0;
        do {
          *--beg=val%base;
          val/=base;
        } while(val);
        if(neg){
          *--beg='-';
        } else {
          *--beg=' ';
        }
        return a_str(beg,end);
      };
      buf_t & a_float(float val,int width,int prec=6);
      buf_t &a_ptr(void *ptr,int width=16) {
        return a_str("0x").a_int((size_t)ptr,false,16,32);
      };
      buf_t &a_tspec(const timespec_t &val) {
        buf_t<64> tmp(-1);
        tmp
          .a_str("timespec{")
          .a_int(val.tv_sec,false)
          .a_str(",")
          .a_int(val.tv_nsec,false)
          .a_str("}");
        return a_str(tmp);
      };
      buf_t &a_tval(const timeval_t &val) {
        buf_t<512> buf(-1);
        buf
          .a_str("timeval{")
          .a_int(val.tv_sec,false)
          .a_str(",")
          .a_int(val.tv_usec,false)
          .a_str("}");
        a_str(buf.buf,buf.len);
      };
      buf_t &a_nl() {
       return a_str("\n");
      }; 
      buf_t &a_str(const str::c_str &str){
        return a_str(str.beg(),str.end());
      };
      template<size_t sz>
        buf_t &a_str(const buf_t<sz> &str){
          return a_str(str.buf,str.len);
        };
      bool write() {
        size_t nr=0;
        while(nr<len) {
          ssize_t n=sys::write(fd,buf+nr,len-nr);
          nr+=n;
        };
        memset(buf,sizeof(buf),sizeof(buf));
        len=0;
        return true;
      };
    };

//     struct fmt_t
//     {
//       void format_int(uint64_t wrap, int base, int width, char fill) {
//       };
//       void format_float(float val, int width, int prec=6) {
//       };
//       void format_ptr(void *ptr, int width=16) {
//       };
//       void format_timespec(const timespec_t &val) {
//       };
//       struct body_t {
//         iovec_t vec;
//         buf_t<256> buf;
//         body_t()
//           :buf(-1), vec((iovec_t)buf)
//         {
//         };
//       };
//       body_t body;
//       fmt_t(const timespec_t &val)
//       {
//         format_timespec(val);
//       };
//       fmt_t(uint64_t wrap, int base=10, int width=0, char fill='0')
//       {
//         format_int(wrap,base,width,fill);
//       };
//       fmt_t(void *val, int width=16)
//       {
//         format_ptr(val,width);
//       };
//       size_t len() const {
//         return body.vec.iov_len;
//       };
//       const char *beg() const {
//         return (const char*)body.vec.iov_base;
//       };
//       const char *end() const {
//         return beg()+body.vec.iov_len;
//       };
//       char *beg() {
//         return (char*)body.vec.iov_base;
//       };
//       char *end() {
//         return beg()+body.vec.iov_len;
//       };
//       operator iovec_t() const {
//         return body.vec;
//       };
//       static constexpr const char digits[]="0123456789abcdef";
//       char operator[](size_t idx) const {
//         return beg()[idx];
//       }
//       char &operator[](size_t idx) {
//         return ((char*)beg())[idx];
//       }
//     };
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


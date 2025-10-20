#include "fmt.hh"


#include "cstdint"
#include "cassert"
#include "vector.hh"
#include "types.hh"
#include "c_str.hh"
#include "itr-ops.hh"
#include "syscall.hh"
typedef unsigned char uint8_t;
//   
namespace str {
  class str_t {
    struct body_t {
      size_t cnt;
      size_t cap;
      size_t len;
      char arr[];
      void dump() const {
        fmt::buf_t<4096> buf(1);
        buf.a_str("cnt: ");
        buf.a_int(cnt,false,10,18,'0');
        buf.a_nl();
        sys::write(2,buf);
      };
    };
    body_t *body;
    static constexpr size_t chunk(size_t len){
      size_t res=len?len:1;
      res+=31;
      res-=(res%32);
      return res;
    };
    static auto mkbody(size_t cap)
    {
      cap=chunk(cap);
      using sys::write;
      size_t size=sizeof(body_t)+cap;
      body_t *res=(body_t*)new char[size];
      memset(res,0,size);
      res->cap=cap;
      res->cnt=1;
      return res;
    };
    static const char *str_end(const char *beg, const char *end)
    {
      if(beg==end)
        return beg;
      if(end)
        return end;
      if(beg)
        end=beg+strlen(beg);
      return end;
    };
    static auto mkbody(size_t cap, const char * beg, const char * end) {
      auto res=mkbody(cap);
      cap=res->cap;
      if(!end)
        end=str_end(beg,end);
      assert(beg<=end);
      size_t n=end-beg, i=0;
      for(i=0;i<n;i++){
        res->arr[i]=beg[i];
      };
      while(i<cap)
        res->arr[i++]=0;
      return res;
    };
    static auto mkbody(const char *beg, const char *end)
    {
      if(beg==0 && end==0){
        return mkbody(0);
      } else if ( beg==0 ) {
        assert(!"beg is zero, end is not?");
      } else if ( end==0 ) {
        end=itr::len(beg)+beg;
      }
      size_t cap=end-beg;
      auto res=mkbody(cap,beg,end);
      return res;
    };
    public:
    str_t(const char *beg=0, const char *end=0)
      : body(mkbody(beg,end))
    {
    };
    const char *beg() const {
      return body->arr;
    };
    char *beg() {
      return body->arr;
    };
    const char *end() const {
      return beg()+body->len;
    };
    char *end() {
      return beg()+body->len;
    };
  };
}
using str::str_t;
namespace sys {
  ssize_t write(fd_t fd, const str_t &str)
  {
    return write(fd,str.beg(),str.end());
  };
};
static char chars[]="this is a test";
int main(int argc, char const * const *argv, char const *const *envp) {
  using fmt::buf_t;
  using sys::write;
  buf_t<32> buf(1);
  buf.a_int(10,false,10);
  buf.write();
  return 0;
#if 0
  buf.a_str(chars);
  buf.a_nl();
  for(int i=0;i<10;i++) {
    if(!buf.a_int(i,false)) {
      buf.write(1);
      buf.a_int(i,false);
    };
    if(!buf.a_str("...")){
      buf.write(1);
      buf.a_int(i,false);
    };
  };
  buf.a_nl();
  write(2,buf);
  return 0;
#endif
};

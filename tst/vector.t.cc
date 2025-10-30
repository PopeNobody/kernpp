#include "vector.hh"
#include "syscall.hh"
#include "fmt.hh"
#define show(x) do_show(#x,x)
extern "C" { 
  int main(int argc,char *const*argv,char *const*envp) ;
}
static int imul=1;;
using sys::write;
using sys::fd_t;
template<class val_t>
ssize_t writeln(fd_t fd, const val_t &val)
{
  ssize_t res=write(fd,val);
  res+=write(fd,"\n");
  return res;
};
struct xbuf_t{
  char buf[39];
  char end[1];
  xbuf_t()
  {
    memset(this,0x20,sizeof(*this));
  }
} xbuf;

using str::c_str;
long neg_one(-1);
fmt::fmt_t fmt_len(neg_one);
template<class val_t>
size_t do_show(c_str str, val_t val) {
  char buf[30];
  for(int i=0,j=0;i<sizeof(buf);i++){
    fmt_len=fmt::fmt_t(strlen(buf));
    writeln(1,fmt_len);
    if(str[j]) {
      buf[i++]=str[j++];
    } else {
      buf[i++]=' ';
    };
  };
  writeln(1,fmt::fmt_t(strlen(buf)));
  size_t res=write(1,fmt::fmt_t(val)); \
  res+=write(1,"\n"); \
  return res;
}
static int cnt=0;
struct data_t {
  static int nId;
  int id;
  data_t()
    :id(0)
  {
    writeln(2,__PRETTY_FUNCTION__);
  };
  data_t(int id)
    :id(id)
  {
    writeln(2,__PRETTY_FUNCTION__);
  };
  ~data_t() {
    writeln(2,__PRETTY_FUNCTION__);
  };
};
int data_t::nId=0;
using cont::array_t;
typedef array_t<data_t> data_vec_t;
using sys::write;
using fmt::fmt_t;
int main(int argc,char *const*argv,char *const*envp) {
  size_t cap=16;
  size_t len=12;
  data_vec_t *data_vec=0;
  data_t data[8];
  for(int i=0;i<countof(data);i++) {
    data[i]=data_t(i);
  };
  {
    data_t *beg=data;
    data_t *end=beg+countof(data);
    data_vec = data_vec_t::mk_arr(cap,len,beg,end);
  }

  show(data_vec->cap);
  show(data_vec->len);
  for(int i=0;i<data_vec->cap;i++){
    show(i);
    show(data_vec->arr[i].id);
  };
  return 0;
};



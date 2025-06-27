extern "C" { int main(int argc,char *const*argv,char *const*envp); };
#include "syscall.hh"
#include "vpipe.hh"
#include "fmt.hh"
using fmt::fmt_t;
namespace sys {
  inline ssize_t write(fd_t fd, const c_str &fmt) {
    return write(fd,(c_str)fmt);
  };
  inline ssize_t write(fd_t fd, const fmt_t &fmt) {
    return write(fd,(c_str)fmt);
  };
}
uint64_t atoi(const char *pos){
  uint64_t res=0;
  while(*pos>='0' && *pos<='9') {
    res*=10;
    res+=(*pos-'0');
    ++pos;
  };
  return res;
};
 int main(int argc,char *const*argv,char *const*envp) {
  uint16_t rows;
  uint16_t cols;
  if(argc==1) {
    if(vpipe::get_term_size(0,rows, cols)) {
      sys::pexit(4,"get_term_size");
    } else {
      sys::write(1,"rows: ");
      sys::write(1,(c_str)fmt_t(rows));
      sys::write(1,"\n");
      sys::write(1,"cols: ");
      sys::write(1,(c_str)fmt_t(cols));
      sys::write(1,"\n");
    };
  } else if ( argc==3) {
    sys::write(1,"rows: ");
    sys::write(1,(c_str)fmt_t(rows));
    sys::write(1,"cols: ");
    sys::write(1,(c_str)fmt_t(cols));
    rows=atoi(argv[1]);
    cols=atoi(argv[2]);
    if(vpipe::set_term_size(0,rows,cols)) {
      sys::pexit(4,"set_term_size");
    };
  }
  return 0;
};

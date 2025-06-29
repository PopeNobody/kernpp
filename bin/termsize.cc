extern "C" { int main(int argc,char *const*argv,char *const*envp); };
#include "syscall.hh"
#include "vpipe.hh"
#include "fmt.hh"
#include "c_str.hh"
using str::c_str;
using fmt::fmt_t;
using fmt::atoi;
namespace std {
  template<class T>
  class vector {
    struct body_t {
      T *vec;
      size_t len;
    } body;
    public:
    const T *data() const;
    size_t size() const;
  };
};
namespace sys {
  template<class ... Ts>
    ssize_t write(fd_t fd, Ts ... args) {
      std::vector<iovec> vec;
      return sys::write(fd,vec.data(),vec.size()); 
    };
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

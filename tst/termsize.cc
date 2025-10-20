#include "syscall.hh"



namespace vpipe {
  using std::uint16_t;
  void setup_term_and_pty(bool);
  using sys::fd_t;
  int get_term_size(fd_t fd, uint16_t &rows, uint16_t &cols);
  int set_term_size(fd_t fd, uint16_t rows, uint16_t cols);
  int term_set_raw(fd_t fd);
  int term_set_sane(fd_t fd);
  using sys::isatty;
};


namespace vpipe {
  void setup_term_and_pty(bool);
  int get_term_size(fd_t fd, uint16_t &rows, uint16_t &cols);
  int set_term_size(fd_t fd, uint16_t rows, uint16_t cols);
  int term_set_raw(fd_t fd);
  int term_set_sane(fd_t fd);
  using sys::isatty;
};


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
//     template<class ... Ts>
//       ssize_t write(fd_t fd, Ts ... args) {
//         td::vector<iovec> vec;
//         return sys::write(fd,vec.data(),vec.size());
//       };
};
void show_size(int rows, int cols){
  fmt::buf_t<1024> buf(1);
  buf.a_str("LINES=").a_int(rows).a_nl();
  buf.a_str("COLUMNS=").a_int(cols).a_nl();
};
int main(int argc,char *const*argv,char *const*envp) {
  using namespace sys;
  uint16_t rows;
  uint16_t cols;
  fmt::buf_t<1024> buf(1);
  if(argc==1) {
    if(vpipe::get_term_size(0,rows, cols)) {
      sys::pexit(4,"get_term_size");
    }
    show_size(rows,cols);
  } else if ( argc==3) {
    rows=atoi(argv[1]);
    cols=atoi(argv[2]);
    show_size(rows,cols);
    if(vpipe::set_term_size(0,rows,cols)) {
      sys::pexit(4,"set_term_size");
    };
  }
  return 0;
};

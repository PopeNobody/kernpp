#include "syscall.hh"

namespace vpipe {
  void setup_term_and_pty(bool);
  using sys::fd_t;
  int get_term_size(fd_t fd, uint16_t &rows, uint16_t &cols);
  int set_term_size(fd_t fd, uint16_t rows, uint16_t cols);
  int term_set_raw(fd_t fd);
  int term_set_sane(fd_t fd);
  using sys::isatty;
};

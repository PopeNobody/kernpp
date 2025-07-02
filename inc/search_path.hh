#include "types.hh"
#include "array.hh"

namespace shell_ns {
  extern istr_t *environ;
  istr_t get_env(istr_t name);
  istr_p split_path(istr_t path);
  istr_t search_path(istr_t prog, istr_t name);
  istr_t search_path(istr_t prog, istr_v path);
}

#include <types.hh>
namespace shell_ns {
  extern istr_t *environ;
  istr_t get_env(istr_t name);
  istr_t  search_path(istr_t prog,istr_t name,bool deep);
}

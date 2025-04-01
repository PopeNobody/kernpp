#include <types.hh>

extern "C" {

// __NR__ finit_module = 313 
inline int finit_module(fd_t fd, istr_t uargs, int flags);
}

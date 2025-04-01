#include <types.hh>

extern "C" {

// __NR__ fremovexattr = 199 
inline int fremovexattr(fd_t fd, istr_t name);
}

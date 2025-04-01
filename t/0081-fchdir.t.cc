#include <types.hh>

extern "C" {

// __NR__ fchdir = 81 
inline int fchdir(fd_t fd);
}

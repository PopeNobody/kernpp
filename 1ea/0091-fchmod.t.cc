#include <types.hh>

extern "C" {

// __NR__ fchmod = 91 
inline int fchmod(fd_t fd, mode_t mode);
}

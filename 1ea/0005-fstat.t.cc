#include <types.hh>

extern "C" {

// __NR__ fstat = 5 
inline int fstat(fd_t fd, stat_p statbuf);
}

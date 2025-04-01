#include <types.hh>

extern "C" {

// __NR__ flock = 73 
inline int flock(fd_t fd, unsigned cmd);
}

#include <types.hh>

extern "C" {

// __NR__ fcntl = 72 
inline int fcntl(fd_t fd, unsigned cmd, uint64_t arg);
}

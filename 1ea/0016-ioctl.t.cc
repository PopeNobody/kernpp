#include <types.hh>

extern "C" {

// __NR__ ioctl = 16 
inline int ioctl(fd_t fd, unsigned cmd, uint64_t arg);
}

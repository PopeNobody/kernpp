#include <types.hh>

extern "C" {

// __NR__ lseek = 8 
inline int lseek(fd_t fd, off_t offset, unsigned origin);
}

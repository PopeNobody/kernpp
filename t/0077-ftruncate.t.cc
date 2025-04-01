#include <types.hh>

extern "C" {

// __NR__ ftruncate = 77 
inline int ftruncate(fd_t fd, uint64_t length);
}

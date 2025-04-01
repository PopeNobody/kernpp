#include <types.hh>

extern "C" {

// __NR__ fallocate = 285 
inline int fallocate(fd_t fd, long mode, off_t offset, off_t len);
}

#include <types.hh>

extern "C" {

// __NR__ fadvise64 = 221 
inline int fadvise64(fd_t fd, off_t offset, size_t len, int advice);
}

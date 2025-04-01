#include <types.hh>

extern "C" {

// __NR__ readv = 19 
inline int readv(fd_t fd, iovec_p vec, uint64_t vlen);
}

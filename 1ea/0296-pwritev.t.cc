#include <types.hh>

extern "C" {

// __NR__ pwritev = 296 
inline int pwritev(fd_t fd, iovec_p vec, uint64_t vlen, uint64_t pos_l, uint64_t pos_h);
}

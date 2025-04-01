#include <types.hh>

extern "C" {

// __NR__ writev = 20 
inline int writev(fd_t fd, iovec_p vec, uint64_t vlen);
}

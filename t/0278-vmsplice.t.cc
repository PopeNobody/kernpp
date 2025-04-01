#include <types.hh>

extern "C" {

// __NR__ vmsplice = 278 
inline int vmsplice(fd_t fd, iovec_p iov, uint64_t nr_segs, unsigned flags);
}

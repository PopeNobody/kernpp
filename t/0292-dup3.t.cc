#include <types.hh>

extern "C" {

// __NR__ dup3 = 292 
inline int dup3(fd_t oldfd, fd_t newfd, int flags);
}

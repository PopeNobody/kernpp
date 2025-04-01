#include <types.hh>

extern "C" {

// __NR__ dup2 = 33 
inline int dup2(fd_t oldfd, fd_t newfd);
}

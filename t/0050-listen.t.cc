#include <types.hh>

extern "C" {

// __NR__ listen = 50 
inline int listen(fd_t fd, int backlog);
}

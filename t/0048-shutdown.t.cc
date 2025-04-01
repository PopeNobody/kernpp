#include <types.hh>

extern "C" {

// __NR__ shutdown = 48 
inline int shutdown(fd_t fd, int how);
}

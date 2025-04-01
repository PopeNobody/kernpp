#include <types.hh>

extern "C" {

// __NR__ close = 3 
inline int close(fd_t fd);
}

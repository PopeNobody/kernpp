#include <types.hh>

extern "C" {

// __NR__ syncfs = 306 
inline int syncfs(fd_t fd);
}

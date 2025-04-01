#include <types.hh>

extern "C" {

// __NR__ fsync = 74 
inline int fsync(fd_t fd);
}

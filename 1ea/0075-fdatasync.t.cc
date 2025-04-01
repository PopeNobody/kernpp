#include <types.hh>

extern "C" {

// __NR__ fdatasync = 75 
inline int fdatasync(fd_t fd);
}

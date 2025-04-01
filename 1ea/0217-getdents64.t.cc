#include <types.hh>

extern "C" {

// __NR__ getdents64 = 217 
inline int getdents64(fd_t fd, linux_dirent64_p dirent, unsigned count);
}

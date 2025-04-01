#include <types.hh>

extern "C" {

// __NR__ fstatfs = 138 
inline int fstatfs(fd_t fd, statfs_p buf);
}

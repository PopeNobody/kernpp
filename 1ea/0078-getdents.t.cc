#include <types.hh>

extern "C" {

// __NR__ getdents = 78 
inline ssize_t getdents(fd_t fd, linux_dirent_p dirent, size_t count);
}

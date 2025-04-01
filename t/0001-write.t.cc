#include <types.hh>

extern "C" {

// __NR__ write = 1 
inline ssize_t sys_write(fd_t fd, istr_t buf, size_t count);
}

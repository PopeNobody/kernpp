#include <types.hh>

extern "C" {

// __NR__ pwrite64 = 18 
inline int pwrite64(fd_t fd, istr_t buf, size_t count, off_t pos);
}

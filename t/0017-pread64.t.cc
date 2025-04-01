#include <types.hh>

extern "C" {

// __NR__ pread64 = 17 
inline int pread64(fd_t fd, ostr_t buf, size_t count, off_t pos);
}

#include <types.hh>

extern "C" {

// __NR__ read = 0 
inline ssize_t read(fd_t fd, ostr_t buf, size_t count);
}

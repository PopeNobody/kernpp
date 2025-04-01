#include <types.hh>

extern "C" {

// __NR__ readahead = 187 
inline int readahead(fd_t fd, off_t offset, size_t count);
}

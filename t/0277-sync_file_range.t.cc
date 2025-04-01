#include <types.hh>

extern "C" {

// __NR__ sync_file_range = 277 
inline int sync_file_range(fd_t fd, off_t offset, off_t bytes, long flags);
}

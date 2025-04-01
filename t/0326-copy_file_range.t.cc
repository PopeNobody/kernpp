#include <types.hh>

extern "C" {

// __NR__ copy_file_range = 326 
inline int copy_file_range(fd_t fd_in, off_p off_in, fd_t fd_out, off_p off_out, size_t len, unsigned flags);
}

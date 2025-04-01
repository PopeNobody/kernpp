#include <types.hh>

extern "C" {

// __NR__ sendfile = 40 
inline int sendfile(int out_fd, int in_fd, off_p offset, size_t count);
}

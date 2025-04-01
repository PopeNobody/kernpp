#include <types.hh>

extern "C" {

// __NR__ splice = 275 
inline int splice(int fd_in, off_p off_in, int fd_out, off_p off_out, size_t len, unsigned flags);
}

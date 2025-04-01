#include <types.hh>

extern "C" {

// __NR__ mmap = 9 
inline char* mmap(void* addr, size_t len, int prot, int flags, fd_t fd, off_t off);
}

#include <types.hh>

extern "C" {

// __NR__ munmap = 11 
inline int munmap(uint64_t addr, size_t len);
}

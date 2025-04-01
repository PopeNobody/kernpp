#include <types.hh>

extern "C" {

// __NR__ mremap = 25 
inline int mremap(uint64_t addr, uint64_t old_len, uint64_t new_len, uint64_t flags, uint64_t new_addr);
}

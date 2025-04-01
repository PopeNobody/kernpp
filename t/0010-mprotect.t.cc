#include <types.hh>

extern "C" {

// __NR__ mprotect = 10 
inline int mprotect(uint64_t start, size_t len, uint64_t prot);
}

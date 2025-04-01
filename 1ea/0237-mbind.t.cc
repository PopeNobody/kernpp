#include <types.hh>

extern "C" {

// __NR__ mbind = 237 
inline int mbind(uint64_t start, uint64_t len, uint64_t mode, uint64_p nmask, uint64_t maxnode, unsigned flags);
}

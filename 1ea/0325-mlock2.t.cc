#include <types.hh>

extern "C" {

// __NR__ mlock2 = 325 
inline int mlock2(uint64_t start, size_t len, int flags);
}

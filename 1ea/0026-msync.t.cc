#include <types.hh>

extern "C" {

// __NR__ msync = 26 
inline int msync(uint64_t start, size_t len, int flags);
}

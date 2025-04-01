#include <types.hh>

extern "C" {

// __NR__ madvise = 28 
inline int madvise(uint64_t start, size_t len_in, int behavior);
}

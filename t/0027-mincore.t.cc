#include <types.hh>

extern "C" {

// __NR__ mincore = 27 
inline int mincore(uint64_t start, size_t len, ostr_t vec);
}

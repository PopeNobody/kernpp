#include <types.hh>

extern "C" {

// __NR__ ioperm = 173 
inline int ioperm(uint64_t from, uint64_t num, int turn_on);
}

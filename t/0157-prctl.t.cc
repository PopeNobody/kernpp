#include <types.hh>

extern "C" {

// __NR__ prctl = 157 
inline int prctl(int option, uint64_t arg2, uint64_t arg3, uint64_t arg4, uint64_t arg5);
}

#include <types.hh>

extern "C" {

// __NR__ keyctl = 250 
inline int keyctl(int option, uint64_t arg2, uint64_t arg3, uint64_t arg4, uint64_t arg5);
}

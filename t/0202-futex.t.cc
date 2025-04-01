#include <types.hh>

extern "C" {

// __NR__ futex = 202 
inline int futex(uint32_p uaddr, int op, uint32_t val, timespec_p utime, uint32_p uaddr2, uint32_t val3);
}

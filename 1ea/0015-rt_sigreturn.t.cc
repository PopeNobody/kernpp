#include <types.hh>

extern "C" {

// __NR__ rt_sigreturn = 15 
inline int rt_sigreturn(uint64_t __unused);
}

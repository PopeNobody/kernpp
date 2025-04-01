#include <types.hh>

extern "C" {

// __NR__ rt_sigsuspend = 130 
inline int rt_sigsuspend(sigset_p unewset, size_t sigsetsize);
}

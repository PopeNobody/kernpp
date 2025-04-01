#include <types.hh>

extern "C" {

// __NR__ rt_sigpending = 127 
inline int rt_sigpending(sigset_p set, size_t sigsetsize);
}

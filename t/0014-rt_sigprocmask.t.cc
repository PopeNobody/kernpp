#include <types.hh>

extern "C" {

// __NR__ rt_sigprocmask = 14 
inline int rt_sigprocmask(int how, sigset_p nset, sigset_p oset, size_t sigsetsize);
}

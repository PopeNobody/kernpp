#include <types.hh>

extern "C" {

// __NR__ rt_sigtimedwait = 128 
inline int rt_sigtimedwait(const sigset_p uthese, siginfo_p uinfo, timespec_p uts, size_t sigsetsize);
}

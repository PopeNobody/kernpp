#include <types.hh>

extern "C" {

// __NR__ rt_sigqueueinfo = 129 
inline int rt_sigqueueinfo(pid_t pid, int sig, siginfo_p uinfo);
}

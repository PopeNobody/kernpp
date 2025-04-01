#include <types.hh>

extern "C" {

// __NR__ rt_tgsigqueueinfo = 297 
inline int rt_tgsigqueueinfo(pid_t tgid, pid_t pid, int sig, siginfo_p uinfo);
}

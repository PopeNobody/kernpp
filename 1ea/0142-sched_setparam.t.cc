#include <types.hh>

extern "C" {

// __NR__ sched_setparam = 142 
inline int sys_sched_setparam(pid_t pid, const void * param);
}

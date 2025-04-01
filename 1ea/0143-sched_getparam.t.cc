#include <types.hh>

extern "C" {

// __NR__ sched_getparam = 143 
inline int sched_getparam(pid_t pid, sched_param_p param);
}

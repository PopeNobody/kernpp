#include <types.hh>

extern "C" {

// __NR__ sched_setscheduler = 144 
inline int sys_sched_setscheduler(pid_t pid, int policy, sched_param_p param);
}

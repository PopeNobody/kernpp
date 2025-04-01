#include <types.hh>

extern "C" {

// __NR__ sched_getscheduler = 145 
inline int sched_getscheduler(pid_t pid);
}

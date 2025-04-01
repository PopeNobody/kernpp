#include <types.hh>

extern "C" {

// __NR__ sched_rr_get_interval = 148 
inline int sched_rr_get_interval(pid_t pid, timespec_p interval);
}

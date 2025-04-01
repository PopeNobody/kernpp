#include <types.hh>

extern "C" {

// __NR__ sched_getattr = 315 
inline int sched_getattr(pid_t pid, sched_attr_p attr, unsigned size, unsigned flags);
}

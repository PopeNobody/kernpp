#include <types.hh>

extern "C" {

// __NR__ sched_setattr = 314 
inline int sched_setattr(pid_t pid, sched_attr_p attr, unsigned flags);
}

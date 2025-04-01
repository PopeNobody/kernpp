#include <types.hh>

extern "C" {

// __NR__ sched_get_priority_min = 147 
inline int sched_get_priority_min(int policy);
}

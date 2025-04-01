#include <types.hh>

extern "C" {

// __NR__ sched_get_priority_max = 146 
inline int sched_get_priority_max(int policy);
}

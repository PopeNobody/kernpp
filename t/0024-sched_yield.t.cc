#include <types.hh>

extern "C" {

// __NR__ sched_yield = 24 
inline int sched_yield();
}

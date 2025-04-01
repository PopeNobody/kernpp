#include <types.hh>

extern "C" {

// __NR__ timer_gettime = 224 
inline int timer_gettime(timer_t timer_id, itimerspec_p setting);
}

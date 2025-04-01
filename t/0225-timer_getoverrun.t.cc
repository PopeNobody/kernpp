#include <types.hh>

extern "C" {

// __NR__ timer_getoverrun = 225 
inline int timer_getoverrun(timer_t timer_id);
}

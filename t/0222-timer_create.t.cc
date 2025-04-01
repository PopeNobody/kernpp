#include <types.hh>

extern "C" {

// __NR__ timer_create = 222 
inline int timer_create(const clockid_t which_clock, sigevent_p timer_event_spec, timer_p created_timer_id);
}

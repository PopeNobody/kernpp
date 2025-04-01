#include <types.hh>

extern "C" {

// __NR__ timer_settime = 223 
inline int timer_settime(timer_t timer_id, int flags, itimerspec_p new_setting, itimerspec_p old_setting);
}

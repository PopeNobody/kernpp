#include <types.hh>

extern "C" {

// __NR__ clock_settime = 227 
inline int clock_settime(const clockid_t which_clock, timespec_p tp);
}

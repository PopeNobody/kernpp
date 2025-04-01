#include <types.hh>

extern "C" {

// __NR__ clock_adjtime = 305 
inline int clock_adjtime(clockid_t which_clock, timex_p tx);
}

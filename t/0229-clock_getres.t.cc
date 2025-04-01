#include <types.hh>

extern "C" {

// __NR__ clock_getres = 229 
inline int clock_getres(const clockid_t which_clock, timespec_p tp);
}

#include <types.hh>

extern "C" {

// __NR__ clock_gettime = 228 
inline int clock_gettime(const clockid_t which_clock, timespec_p tp);
}

#include <types.hh>

extern "C" {

// __NR__ clock_nanosleep = 230 
inline int clock_nanosleep(const clockid_t which_clock, int flags, timespec_p rqtp, timespec_p rmtp);
}

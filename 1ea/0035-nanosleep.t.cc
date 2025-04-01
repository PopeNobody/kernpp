#include <types.hh>

extern "C" {

// __NR__ nanosleep = 35 
inline int nanosleep(timespec_p rqtp, timespec_p rmtp);
}

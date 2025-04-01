#include <types.hh>

extern "C" {

// __NR__ timerfd_settime = 286 
inline int timerfd_settime(int ufd, int flags, itimerspec_p utmr, itimerspec_p otmr);
}

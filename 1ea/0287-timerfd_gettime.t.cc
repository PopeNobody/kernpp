#include <types.hh>

extern "C" {

// __NR__ timerfd_gettime = 287 
inline int timerfd_gettime(int ufd, itimerspec_p otmr);
}

#include <types.hh>

extern "C" {

// __NR__ timerfd_create = 283 
inline int timerfd_create(int clockid, int flags);
}

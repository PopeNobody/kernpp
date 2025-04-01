#include <types.hh>

extern "C" {

// __NR__ epoll_pwait = 281 
inline int epoll_pwait(int epfd, epoll_event_p events, int maxevents, int timeout, const sigset_p sigmask, size_t sigsetsize);
}

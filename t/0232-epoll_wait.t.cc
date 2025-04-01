#include <types.hh>

extern "C" {

// __NR__ epoll_wait = 232 
inline int epoll_wait(int epfd, epoll_event_p events, int maxevents, int timeout);
}

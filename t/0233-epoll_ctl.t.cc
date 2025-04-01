#include <types.hh>

extern "C" {

// __NR__ epoll_ctl = 233 
inline int epoll_ctl(int epfd, int op, fd_t fd, epoll_event_p event);
}

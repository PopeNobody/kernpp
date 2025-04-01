#include <types.hh>

extern "C" {

// __NR__ epoll_create1 = 291 
inline int epoll_create1(int flags);
}

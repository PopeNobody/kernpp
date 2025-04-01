#include <types.hh>

extern "C" {

// __NR__ epoll_create = 213 
inline int epoll_create(int size);
}

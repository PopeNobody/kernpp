#include <types.hh>

extern "C" {

// __NR__ inotify_add_watch = 254 
inline int inotify_add_watch(fd_t fd, istr_t pathname, uint32_t mask);
}

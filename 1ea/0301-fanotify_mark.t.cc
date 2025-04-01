#include <types.hh>

extern "C" {

// __NR__ fanotify_mark = 301 
inline int fanotify_mark(long fanotify_fd, long flags, uint64_t mask, fd_t dfd, long pathname);
}

#include <types.hh>

extern "C" {

// __NR__ inotify_rm_watch = 255 
inline int inotify_rm_watch(fd_t fd, int32_t wd);
}

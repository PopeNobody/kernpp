#include <types.hh>

extern "C" {

// __NR__ inotify_init1 = 294 
inline int inotify_init1(int flags);
}

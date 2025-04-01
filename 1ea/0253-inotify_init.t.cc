#include <types.hh>

extern "C" {

// __NR__ inotify_init = 253 
inline int inotify_init();
}

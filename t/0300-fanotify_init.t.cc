#include <types.hh>

extern "C" {

// __NR__ fanotify_init = 300 
inline int fanotify_init(unsigned flags, unsigned event_f_flags);
}

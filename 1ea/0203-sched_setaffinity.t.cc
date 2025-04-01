#include <types.hh>

extern "C" {

// __NR__ sched_setaffinity = 203 
inline int sys_sched_setaffinity(pid_t pid, size_t len, const void * user_mask_ptr);
}

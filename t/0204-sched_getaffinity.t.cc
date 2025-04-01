#include <types.hh>

extern "C" {

// __NR__ sched_getaffinity = 204 
inline int sys_sched_getaffinity(pid_t pid, unsigned len, uint64_p user_mask_ptr);
}

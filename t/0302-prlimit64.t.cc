#include <types.hh>

extern "C" {

// __NR__ prlimit64 = 302 
inline int prlimit64(pid_t pid, unsigned resource, rlimit64_p new_rlim, rlimit64_p old_rlim);
}

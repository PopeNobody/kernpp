#include <types.hh>

extern "C" {

// __NR__ setpgid = 109 
inline int setpgid(pid_t pid, pid_t pgid);
}

#include <types.hh>

extern "C" {

// __NR__ getsid = 124 
inline int getsid(pid_t pid);
}

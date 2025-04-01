#include <types.hh>

extern "C" {

// __NR__ getpgid = 121 
inline int getpgid(pid_t pid);
}

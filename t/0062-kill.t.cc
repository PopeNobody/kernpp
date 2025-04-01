#include <types.hh>

extern "C" {

// __NR__ kill = 62 
inline int kill(pid_t pid, int sig);
}

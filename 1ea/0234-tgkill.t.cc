#include <types.hh>

extern "C" {

// __NR__ tgkill = 234 
inline int tgkill(pid_t tgid, pid_t pid, int sig);
}

#include <types.hh>

extern "C" {

// __NR__ tkill = 200 
inline int tkill(pid_t pid, int sig);
}

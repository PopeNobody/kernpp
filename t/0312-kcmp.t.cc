#include <types.hh>

extern "C" {

// __NR__ kcmp = 312 
inline int kcmp(pid_t pid1, pid_t pid2, int type, uint64_t idx1, uint64_t idx2);
}

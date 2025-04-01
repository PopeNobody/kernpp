#include <types.hh>

extern "C" {

// __NR__ wait4 = 61 
inline int wait4(pid_t upid, int32_p stat_addr, int options, rusage_p ru);
}

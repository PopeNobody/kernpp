#include <types.hh>

extern "C" {

// __NR__ waitid = 247 
inline int waitid(int which, pid_t upid, siginfo_p infop, int options, rusage_p ru);
}

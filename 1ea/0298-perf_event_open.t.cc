#include <types.hh>

extern "C" {

// __NR__ perf_event_open = 298 
inline int perf_event_open(perf_event_attr_p attr_uptr, pid_t pid, int cpu, int group_fd, uint64_t flags);
}

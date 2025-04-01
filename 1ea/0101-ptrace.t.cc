#include <types.hh>

extern "C" {

// __NR__ ptrace = 101 
inline int ptrace(long request, long pid, uint64_t addr, uint64_t data);
}

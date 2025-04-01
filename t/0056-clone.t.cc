#include <types.hh>

extern "C" {

// __NR__ clone = 56 
inline int sys_clone(uint64_t clone_flags, uint64_t newsp, void_p parent_tid, void_p child_tid);
}

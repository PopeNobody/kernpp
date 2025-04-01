#include <types.hh>

extern "C" {

// __NR__ get_mempolicy = 239 
inline int get_mempolicy(int32_p policy, uint64_p nmask, uint64_t maxnode, uint64_t addr, uint64_t flags);
}

#include <types.hh>

extern "C" {

// __NR__ set_mempolicy = 238 
inline int set_mempolicy(int mode, uint64_p nmask, uint64_t maxnode);
}

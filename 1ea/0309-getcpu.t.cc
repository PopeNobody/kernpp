#include <types.hh>

extern "C" {

// __NR__ getcpu = 309 
inline int getcpu(uint32_p cpup, uint32_p nodep);
}

#include <types.hh>

extern "C" {

// __NR__ membarrier = 324 
inline int membarrier(int cmd, int flags);
}

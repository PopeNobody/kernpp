#include <types.hh>

extern "C" {

// __NR__ eventfd2 = 290 
inline int eventfd2(unsigned count, int flags);
}

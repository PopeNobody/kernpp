#include <types.hh>

extern "C" {

// __NR__ eventfd = 284 
inline int eventfd(unsigned count);
}

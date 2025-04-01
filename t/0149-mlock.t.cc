#include <types.hh>

extern "C" {

// __NR__ mlock = 149 
inline int mlock(void_p start, size_t len);
}

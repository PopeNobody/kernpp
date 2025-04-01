#include <types.hh>

extern "C" {

// __NR__ munlock = 150 
inline int munlock(void_p start, size_t len);
}

#include <types.hh>

extern "C" {

// __NR__ munlockall = 152 
inline int munlockall();
}

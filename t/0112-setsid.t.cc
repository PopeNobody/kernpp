#include <types.hh>

extern "C" {

// __NR__ setsid = 112 
inline int setsid();
}

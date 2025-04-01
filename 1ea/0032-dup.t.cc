#include <types.hh>

extern "C" {

// __NR__ dup = 32 
inline int dup(unsigned fildes);
}

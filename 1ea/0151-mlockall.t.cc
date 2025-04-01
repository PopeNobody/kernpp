#include <types.hh>

extern "C" {

// __NR__ mlockall = 151 
inline int mlockall(int flags);
}

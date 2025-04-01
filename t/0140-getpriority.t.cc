#include <types.hh>

extern "C" {

// __NR__ getpriority = 140 
inline int getpriority(int which, int who);
}

#include <types.hh>

extern "C" {

// __NR__ ioprio_get = 252 
inline int ioprio_get(int which, int who);
}

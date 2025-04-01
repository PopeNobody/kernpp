#include <types.hh>

extern "C" {

// __NR__ ioprio_set = 251 
inline int ioprio_set(int which, int who, int ioprio);
}

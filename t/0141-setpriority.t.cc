#include <types.hh>

extern "C" {

// __NR__ setpriority = 141 
inline int setpriority(int which, int who, int niceval);
}

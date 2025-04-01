#include <types.hh>

extern "C" {

// __NR__ getrlimit = 97 
inline int getrlimit(unsigned resource, rlimit_p rlim);
}

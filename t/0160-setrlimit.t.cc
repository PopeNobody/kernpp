#include <types.hh>

extern "C" {

// __NR__ setrlimit = 160 
inline int setrlimit(unsigned resource, rlimit_p rlim);
}

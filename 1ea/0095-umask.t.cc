#include <types.hh>

extern "C" {

// __NR__ umask = 95 
inline int umask(int mask);
}

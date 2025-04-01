#include <types.hh>

extern "C" {

// __NR__ rmdir = 84 
inline int rmdir(istr_t pathname);
}

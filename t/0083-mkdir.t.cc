#include <types.hh>

extern "C" {

// __NR__ mkdir = 83 
inline int mkdir(istr_t pathname, int mode);
}

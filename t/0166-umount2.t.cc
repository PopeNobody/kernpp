#include <types.hh>

extern "C" {

// __NR__ umount2 = 166 
inline int umount2(istr_t target, int flags);
}

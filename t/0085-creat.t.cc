#include <types.hh>

extern "C" {

// __NR__ creat = 85 
inline int creat(istr_t pathname, int mode);
}

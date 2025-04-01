#include <types.hh>

extern "C" {

// __NR__ unlink = 87 
inline int unlink(istr_t pathname);
}

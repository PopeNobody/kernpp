#include <types.hh>

extern "C" {

// __NR__ unlinkat = 263 
inline int unlinkat(fd_t dfd, istr_t pathname, int flag);
}

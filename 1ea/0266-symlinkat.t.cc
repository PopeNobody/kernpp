#include <types.hh>

extern "C" {

// __NR__ symlinkat = 266 
inline int symlinkat(istr_t oldname, fd_t newfd, istr_t newname);
}

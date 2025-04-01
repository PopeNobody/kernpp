#include <types.hh>

extern "C" {

// __NR__ linkat = 265 
inline int linkat(fd_t oldfd, istr_t oldname, fd_t newfd, istr_t newname, int flags);
}

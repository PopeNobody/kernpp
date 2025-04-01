#include <types.hh>

extern "C" {

// __NR__ renameat = 264 
inline int renameat(fd_t oldfd, istr_t oldname, fd_t newfd, istr_t newname);
}

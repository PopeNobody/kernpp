#include <types.hh>

extern "C" {

// __NR__ mkdirat = 258 
inline int mkdirat(fd_t dfd, istr_t pathname, int mode);
}

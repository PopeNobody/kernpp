#include <types.hh>

extern "C" {

// __NR__ setns = 308 
inline int setns(fd_t fd, int nstype);
}

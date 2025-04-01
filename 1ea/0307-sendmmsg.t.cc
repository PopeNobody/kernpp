#include <types.hh>

extern "C" {

// __NR__ sendmmsg = 307 
inline int sendmmsg(fd_t fd, msghdr_p mmsg, unsigned vlen, unsigned flags);
}

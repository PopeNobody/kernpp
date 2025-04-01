#include <types.hh>

extern "C" {

// __NR__ sendmsg = 46 
inline int sendmsg(fd_t fd, msghdr_p msg, unsigned flags);
}

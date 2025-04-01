#include <types.hh>

extern "C" {

// __NR__ recvmsg = 47 
inline int recvmsg(fd_t fd, msghdr_p msg, unsigned flags);
}

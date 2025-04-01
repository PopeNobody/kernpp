#include <types.hh>

extern "C" {

// __NR__ recvmmsg = 299 
inline int recvmmsg(fd_t fd, msghdr_p mmsg, unsigned vlen, unsigned flags, timespec_p timeout);
}

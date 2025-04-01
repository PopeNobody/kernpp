#include <types.hh>

extern "C" {

// __NR__ connect = 42 
inline int connect(fd_t fd, sockaddr_p uservaddr, int addrlen);
}

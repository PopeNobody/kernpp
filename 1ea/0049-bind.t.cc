#include <types.hh>

extern "C" {

// __NR__ bind = 49 
inline int bind(fd_t fd, sockaddr_p umyaddr, int addrlen);
}

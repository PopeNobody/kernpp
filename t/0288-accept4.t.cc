#include <types.hh>

extern "C" {

// __NR__ accept4 = 288 
inline int accept4(fd_t fd, sockaddr_p upeer_sockaddr, int32_p upeer_addrlen, int flags);
}

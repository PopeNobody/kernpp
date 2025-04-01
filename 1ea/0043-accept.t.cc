#include <types.hh>

extern "C" {

// __NR__ accept = 43 
inline int accept(fd_t fd, sockaddr_p upeer_sockaddr, int32_p upeer_addrlen);
}

#include <types.hh>

extern "C" {

// __NR__ getsockname = 51 
inline int getsockname(fd_t fd, sockaddr_p usockaddr, int32_p usockaddr_len);
}

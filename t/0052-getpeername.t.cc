#include <types.hh>

extern "C" {

// __NR__ getpeername = 52 
inline int getpeername(fd_t fd, sockaddr_p usockaddr, int32_p usockaddr_len);
}

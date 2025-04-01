#include <types.hh>

extern "C" {

// __NR__ sendto = 44 
inline int sendto(fd_t fd, void_p buff, size_t len, unsigned flags, sockaddr_p addr, int addr_len);
}

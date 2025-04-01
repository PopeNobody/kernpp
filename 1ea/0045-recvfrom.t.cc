#include <types.hh>

extern "C" {

// __NR__ recvfrom = 45 
inline int recvfrom(fd_t fd, void_p ubuf, size_t size, unsigned flags, sockaddr_p addr, int32_p addr_len);
}

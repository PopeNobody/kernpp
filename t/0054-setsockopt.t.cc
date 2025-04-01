#include <types.hh>

extern "C" {

// __NR__ setsockopt = 54 
inline int setsockopt(fd_t fd, int level, int optname, ostr_t optval, int optlen);
}

#include <types.hh>

extern "C" {

// __NR__ getsockopt = 55 
inline int getsockopt(fd_t fd, int level, int optname, ostr_t optval, int32_p optlen);
}

#include <types.hh>

extern "C" {

// __NR__ flistxattr = 196 
inline int flistxattr(fd_t fd, ostr_t list, size_t size);
}

#include <types.hh>

extern "C" {

// __NR__ fsetxattr = 190 
inline int fsetxattr(fd_t fd, istr_t name, const void_p value, size_t size, int flags);
}

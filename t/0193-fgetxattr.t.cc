#include <types.hh>

extern "C" {

// __NR__ fgetxattr = 193 
inline int fgetxattr(fd_t fd, istr_t name, void_p value, size_t size);
}

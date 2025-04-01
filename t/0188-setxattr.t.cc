#include <types.hh>

extern "C" {

// __NR__ setxattr = 188 
inline int setxattr(istr_t pathname, istr_t name, const void_p value, size_t size, int flags);
}

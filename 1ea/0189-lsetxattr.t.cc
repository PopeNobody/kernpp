#include <types.hh>

extern "C" {

// __NR__ lsetxattr = 189 
inline int lsetxattr(istr_t pathname, istr_t name, const void_p value, size_t size, int flags);
}

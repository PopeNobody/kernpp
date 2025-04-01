#include <types.hh>

extern "C" {

// __NR__ lgetxattr = 192 
inline int lgetxattr(istr_t pathname, istr_t name, void_p value, size_t size);
}

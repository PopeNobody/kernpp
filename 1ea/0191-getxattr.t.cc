#include <types.hh>

extern "C" {

// __NR__ getxattr = 191 
inline int getxattr(istr_t pathname, istr_t name, void_p value, size_t size);
}

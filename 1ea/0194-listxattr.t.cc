#include <types.hh>

extern "C" {

// __NR__ listxattr = 194 
inline int listxattr(istr_t pathname, ostr_t list, size_t size);
}

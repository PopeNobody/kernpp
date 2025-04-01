#include <types.hh>

extern "C" {

// __NR__ llistxattr = 195 
inline int llistxattr(istr_t pathname, ostr_t list, size_t size);
}

#include <types.hh>

extern "C" {

// __NR__ removexattr = 197 
inline int removexattr(istr_t pathname, istr_t name);
}

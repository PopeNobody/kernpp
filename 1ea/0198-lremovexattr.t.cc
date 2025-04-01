#include <types.hh>

extern "C" {

// __NR__ lremovexattr = 198 
inline int lremovexattr(istr_t pathname, istr_t name);
}

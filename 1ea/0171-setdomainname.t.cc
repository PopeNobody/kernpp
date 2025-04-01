#include <types.hh>

extern "C" {

// __NR__ setdomainname = 171 
inline int setdomainname(ostr_t name, int len);
}

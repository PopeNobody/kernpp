#include <types.hh>

extern "C" {

// __NR__ memfd_create = 319 
inline int memfd_create(istr_t uname_ptr, unsigned flags);
}

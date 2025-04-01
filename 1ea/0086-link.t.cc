#include <types.hh>

extern "C" {

// __NR__ link = 86 
inline int link(istr_t oldname, istr_t newname);
}

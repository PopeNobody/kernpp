#include <types.hh>

extern "C" {

// __NR__ symlink = 88 
inline int symlink(istr_t oldname, istr_t newname);
}

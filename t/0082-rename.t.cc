#include <types.hh>

extern "C" {

// __NR__ rename = 82 
inline int rename(istr_t oldname, istr_t newname);
}

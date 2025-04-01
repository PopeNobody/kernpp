#include <types.hh>

extern "C" {

// __NR__ statfs = 137 
inline int statfs(istr_t pathname, statfs_p buf);
}

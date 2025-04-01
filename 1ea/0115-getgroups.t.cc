#include <types.hh>

extern "C" {

// __NR__ getgroups = 115 
inline int getgroups(int gidsetsize, gid_p grouplist);
}

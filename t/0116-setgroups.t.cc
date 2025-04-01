#include <types.hh>

extern "C" {

// __NR__ setgroups = 116 
inline int setgroups(int gidsetsize, gid_p grouplist);
}

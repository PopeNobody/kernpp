#include <types.hh>

extern "C" {

// __NR__ setgid = 106 
inline int setgid(gid_t gid);
}

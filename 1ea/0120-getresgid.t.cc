#include <types.hh>

extern "C" {

// __NR__ getresgid = 120 
inline int getresgid(gid_p rgid, gid_p egid, gid_p sgid);
}

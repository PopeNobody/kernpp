#include <types.hh>

extern "C" {

// __NR__ setresgid = 119 
inline int setresgid(gid_t rgid, gid_t egid, gid_t sgid);
}

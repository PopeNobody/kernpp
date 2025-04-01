#include <types.hh>

extern "C" {

// __NR__ setregid = 114 
inline int setregid(gid_t rgid, gid_t egid);
}

#include <types.hh>

extern "C" {

// __NR__ setfsgid = 123 
inline int setfsgid(gid_t gid);
}

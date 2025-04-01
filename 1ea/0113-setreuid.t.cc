#include <types.hh>

extern "C" {

// __NR__ setreuid = 113 
inline int setreuid(uid_t ruid, uid_t euid);
}

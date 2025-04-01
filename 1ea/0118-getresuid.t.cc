#include <types.hh>

extern "C" {

// __NR__ getresuid = 118 
inline int getresuid(uid_p ruid, uid_p euid, uid_p suid);
}

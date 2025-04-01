#include <types.hh>

extern "C" {

// __NR__ setresuid = 117 
inline int setresuid(uid_p ruid, uid_p euid, uid_p suid);
}

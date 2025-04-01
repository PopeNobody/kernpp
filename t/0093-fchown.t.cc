#include <types.hh>

extern "C" {

// __NR__ fchown = 93 
inline int fchown(fd_t fd, uid_t user, gid_t group);
}

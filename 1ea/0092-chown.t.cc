#include <types.hh>

extern "C" {

// __NR__ chown = 92 
inline int chown(istr_t filename, uid_t user, gid_t group);
}

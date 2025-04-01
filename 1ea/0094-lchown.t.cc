#include <types.hh>

extern "C" {

// __NR__ lchown = 94 
inline int lchown(istr_t filename, uid_t user, gid_t group);
}

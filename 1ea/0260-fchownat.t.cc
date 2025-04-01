#include <types.hh>

extern "C" {

// __NR__ fchownat = 260 
inline int fchownat(fd_t dfd, istr_t filename, uid_t user, gid_t group, int flag);
}

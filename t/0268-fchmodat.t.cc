#include <types.hh>

extern "C" {

// __NR__ fchmodat = 268 
inline int fchmodat(fd_t dfd, istr_t filename, mode_t mode);
}

#include <types.hh>

extern "C" {

// __NR__ openat = 257 
inline int openat(fd_t dfd, istr_t filename, int flags, int mode);
}

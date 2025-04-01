#include <types.hh>

extern "C" {

// __NR__ mknodat = 259 
inline int mknodat(fd_t dfd, istr_t filename, int mode, unsigned dev);
}

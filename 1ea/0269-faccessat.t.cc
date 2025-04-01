#include <types.hh>

extern "C" {

// __NR__ faccessat = 269 
inline int faccessat(fd_t dfd, istr_t filename, int mode);
}

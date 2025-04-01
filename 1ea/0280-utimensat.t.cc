#include <types.hh>

extern "C" {

// __NR__ utimensat = 280 
inline int utimensat(fd_t dfd, istr_t filename, timespec_p utimes, int flags);
}

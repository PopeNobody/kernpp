#include <types.hh>

extern "C" {

// __NR__ newfstatat = 262 
inline int newfstatat(fd_t dfd, istr_t filename, stat_p statbuf, int flag);
}

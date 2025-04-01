#include <types.hh>

extern "C" {

// __NR__ lstat = 6 
inline int lstat(istr_t filename, stat_p statbuf);
}

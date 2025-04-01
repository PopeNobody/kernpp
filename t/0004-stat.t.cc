#include <types.hh>

extern "C" {

// __NR__ stat = 4 
inline int stat(istr_t filename, stat_p statbuf);
}

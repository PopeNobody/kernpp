#include <types.hh>

extern "C" {

// __NR__ seccomp = 317 
inline int seccomp(unsigned op, unsigned flags, istr_t uargs);
}

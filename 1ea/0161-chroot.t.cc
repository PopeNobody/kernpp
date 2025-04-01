#include <types.hh>

extern "C" {

// __NR__ chroot = 161 
inline int chroot(istr_t filename);
}

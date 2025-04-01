#include <types.hh>

extern "C" {

// __NR__ access = 21 
inline int access(istr_t filename, int mode);
}

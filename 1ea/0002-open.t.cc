#include <types.hh>

extern "C" {

// __NR__ open = 2 
inline fd_t open(istr_t filename, int flags, int mode);
}

#include <types.hh>

extern "C" {

// __NR__ chmod = 90 
inline int chmod(istr_t filename, mode_t mode);
}

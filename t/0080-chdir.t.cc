#include <types.hh>

extern "C" {

// __NR__ chdir = 80 
inline int chdir(istr_t filename);
}

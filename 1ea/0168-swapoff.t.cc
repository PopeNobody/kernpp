#include <types.hh>

extern "C" {

// __NR__ swapoff = 168 
inline int swapoff(istr_t specialfile);
}

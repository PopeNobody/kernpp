#include <types.hh>

extern "C" {

// __NR__ swapon = 167 
inline int swapon(istr_t specialfile, int swap_flags);
}

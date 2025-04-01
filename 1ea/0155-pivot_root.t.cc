#include <types.hh>

extern "C" {

// __NR__ pivot_root = 155 
inline int pivot_root(istr_t new_root, istr_t put_old);
}

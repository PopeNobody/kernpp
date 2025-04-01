#include <types.hh>

extern "C" {

// __NR__ set_robust_list = 273 
inline int set_robust_list(robust_list_head_p head, size_t len);
}

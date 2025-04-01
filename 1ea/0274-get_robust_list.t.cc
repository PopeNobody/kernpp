#include <types.hh>

extern "C" {

// __NR__ get_robust_list = 274 
inline int get_robust_list(int pid, robust_list_head_p head_ptr, size_p len_ptr);
}

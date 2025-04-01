#include <types.hh>

extern "C" {

// __NR__ arch_prctl = 158 
inline int arch_prctl(task_struct_p task, int code, uint64_t addr);
}

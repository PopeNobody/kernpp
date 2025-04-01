#include <types.hh>

extern "C" {

// __NR__ sigaltstack = 131 
inline int sigaltstack(const stack_p uss, stack_p uoss);
}

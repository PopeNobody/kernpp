#include <types.hh>

extern "C" {

// __NR__ init_module = 175 
inline int init_module(void_p umod, uint64_t len, istr_t uargs);
}

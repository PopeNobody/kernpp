#include <types.hh>

extern "C" {

// __NR__ getrandom = 318 
inline int getrandom(ostr_t buf, size_t count, unsigned flags);
}

#include <types.hh>

extern "C" {

// __NR__ getcwd = 79 
inline int getcwd(ostr_t buf, uint64_t size);
}

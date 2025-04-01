#include <types.hh>

extern "C" {

// __NR__ modify_ldt = 154 
inline int modify_ldt(int func, void_p ptr, uint64_t bytecount);
}

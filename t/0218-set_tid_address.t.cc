#include <types.hh>

extern "C" {

// __NR__ set_tid_address = 218 
inline int set_tid_address(int32_p tidptr);
}

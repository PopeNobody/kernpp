#include <types.hh>

extern "C" {

// __NR__ capget = 125 
inline int capget(cap_user_header_t header, cap_user_data_t dataptr);
}

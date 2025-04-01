#include <types.hh>

extern "C" {

// __NR__ capset = 126 
inline int capset(cap_user_header_t header, const cap_user_data_t data);
}

#include <types.hh>

extern "C" {

// __NR__ request_key = 249 
inline int request_key(istr_t _type, istr_t _description, istr_t _callout_info, uint64_t destringid);
}

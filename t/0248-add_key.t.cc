#include <types.hh>

extern "C" {

// __NR__ add_key = 248 
inline int add_key(istr_t _type, istr_t _description, const void_p _payload, size_t plen);
}

#include <types.hh>

extern "C" {

// __NR__ delete_module = 176 
inline int delete_module(istr_t name_user, unsigned flags);
}

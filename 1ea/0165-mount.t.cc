#include <types.hh>

extern "C" {

// __NR__ mount = 165 
inline int mount(ostr_t dev_name, ostr_t dir_name, ostr_t type, uint64_t flags, void_p data);
}

#include <types.hh>

extern "C" {

// __NR__ sethostname = 170 
inline int sethostname(ostr_t name, int len);
}

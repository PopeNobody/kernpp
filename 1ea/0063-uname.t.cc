#include <types.hh>

extern "C" {

// __NR__ uname = 63 
inline int uname(utsname_p name);
}

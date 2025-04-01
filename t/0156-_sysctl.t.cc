#include <types.hh>

extern "C" {

// __NR__ _sysctl = 156 
inline int _sysctl(sysctl_args_p args);
}

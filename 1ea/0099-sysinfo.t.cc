#include <types.hh>

extern "C" {

// __NR__ sysinfo = 99 
inline int sysinfo(sysinfo_p info);
}

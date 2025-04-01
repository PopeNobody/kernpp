#include <types.hh>

extern "C" {

// __NR__ sysfs = 139 
inline int sysfs(int option, uint64_t arg1, uint64_t arg2);
}

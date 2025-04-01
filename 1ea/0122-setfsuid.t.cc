#include <types.hh>

extern "C" {

// __NR__ setfsuid = 122 
inline int setfsuid(uid_t uid);
}

#include <types.hh>

extern "C" {

// __NR__ setuid = 105 
inline int setuid(uid_t uid);
}

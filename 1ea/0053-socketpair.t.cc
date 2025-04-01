#include <types.hh>

extern "C" {

// __NR__ socketpair = 53 
inline int socketpair(int family, int type, int protocol, int32_p usockvec);
}

#include <types.hh>

extern "C" {

// __NR__ socket = 41 
inline int socket(int family, int type, int protocol);
}

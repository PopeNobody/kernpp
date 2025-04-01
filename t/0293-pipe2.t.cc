#include <types.hh>

extern "C" {

// __NR__ pipe2 = 293 
inline int pipe2(fd_p filedes, int flags);
}

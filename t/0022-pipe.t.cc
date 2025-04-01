#include <types.hh>

extern "C" {

// __NR__ pipe = 22 
inline int pipe(fd_p filedes);
}

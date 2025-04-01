#include <types.hh>

extern "C" {

// __NR__ execve = 59 
inline int execve(const char * filename, char *const * argv, char *const * envp);
}

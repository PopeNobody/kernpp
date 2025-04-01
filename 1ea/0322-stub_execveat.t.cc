#include <types.hh>

extern "C" {

// __NR__ stub_execveat = 322 
inline int stub_execveat(fd_t dfd, istr_t filename, istr_v argv, istr_v envp, int flags);
}

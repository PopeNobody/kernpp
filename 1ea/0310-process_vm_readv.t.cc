#include <types.hh>

extern "C" {

// __NR__ process_vm_readv = 310 
inline int process_vm_readv(pid_t pid, iovec_p lvec, uint64_t liovcnt, iovec_p rvec, uint64_t riovcnt, uint64_t flags);
}

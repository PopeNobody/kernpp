#include <types.hh>

extern "C" {

// __NR__ ppoll = 271 
inline int ppoll(pollfd_p ufds, unsigned nfds, timespec_p tsp, const sigset_p sigmask, size_t sigsetsize);
}

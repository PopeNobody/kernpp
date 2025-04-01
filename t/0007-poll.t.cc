#include <types.hh>

extern "C" {

// __NR__ poll = 7 
inline int poll(pollfd_p ufds, unsigned nfds, long timeout_msecs);
}

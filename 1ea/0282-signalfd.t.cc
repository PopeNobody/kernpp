#include <types.hh>

extern "C" {

// __NR__ signalfd = 282 
inline int signalfd(int ufd, sigset_p user_mask, size_t sizemask);
}

#include <types.hh>

extern "C" {

// __NR__ signalfd4 = 289 
inline int signalfd4(int ufd, sigset_p user_mask, size_t sizemask, int flags);
}

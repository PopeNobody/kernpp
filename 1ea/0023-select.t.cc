#include <types.hh>

extern "C" {

// __NR__ select = 23 
inline int select(int n, fd_set_p inp, fd_set_p outp, fd_set_p exp, timeval_p tvp);
}

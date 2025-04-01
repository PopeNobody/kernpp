#include <types.hh>

extern "C" {

// __NR__ pselect6 = 270 
inline int pselect6(int n, fd_set_p inp, fd_set_p outp, fd_set_p exp, timespec_p tsp, void_p sig);
}

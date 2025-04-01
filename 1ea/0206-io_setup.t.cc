#include <types.hh>

extern "C" {

// __NR__ io_setup = 206 
inline int io_setup(unsigned nr_events, aio_context_p ctxp);
}

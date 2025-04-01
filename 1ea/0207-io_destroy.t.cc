#include <types.hh>

extern "C" {

// __NR__ io_destroy = 207 
inline int io_destroy(aio_context_t ctx);
}

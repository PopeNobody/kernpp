#include <types.hh>

extern "C" {

// __NR__ io_submit = 209 
inline int io_submit(aio_context_t ctx_id, long nr, iocb_p iocbpp);
}

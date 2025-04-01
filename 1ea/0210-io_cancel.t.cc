#include <types.hh>

extern "C" {

// __NR__ io_cancel = 210 
inline int io_cancel(aio_context_t ctx_id, iocb_p iocb, io_event_p result);
}

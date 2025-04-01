#include <types.hh>

extern "C" {

// __NR__ io_getevents = 208 
inline int io_getevents(aio_context_t ctx_id, long min_nr, long nr, io_event_p events);
}

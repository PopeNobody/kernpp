#include <types.hh>

extern "C" {

// __NR__ timer_delete = 226 
inline int timer_delete(timer_t timer_id);
}

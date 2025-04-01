#include <types.hh>

extern "C" {

// __NR__ mq_timedsend = 242 
inline int mq_timedsend(mqd_t mqdes, istr_t u_msg_ptr, size_t msg_len, unsigned msg_prio, timespec_p u_abs_timeout);
}

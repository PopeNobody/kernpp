#include <types.hh>

extern "C" {

// __NR__ mq_timedreceive = 243 
inline int mq_timedreceive(mqd_t mqdes, ostr_t u_msg_ptr, size_t msg_len, uint32_p u_msg_prio, timespec_p u_abs_timeout);
}

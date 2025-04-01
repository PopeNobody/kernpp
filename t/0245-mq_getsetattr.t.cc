#include <types.hh>

extern "C" {

// __NR__ mq_getsetattr = 245 
inline int mq_getsetattr(mqd_t mqdes, mq_attr_p u_mqstat, mq_attr_p u_omqstat);
}

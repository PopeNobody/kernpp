#include <types.hh>

extern "C" {

// __NR__ mq_notify = 244 
inline int mq_notify(mqd_t mqdes, sigevent_p u_notification);
}

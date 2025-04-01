#include <types.hh>

extern "C" {

// __NR__ mq_open = 240 
inline int mq_open(istr_t u_name, int oflag, mode_t mode, mq_attr_p u_attr);
}

#include <types.hh>

extern "C" {

// __NR__ mq_unlink = 241 
inline int mq_unlink(istr_t u_name);
}

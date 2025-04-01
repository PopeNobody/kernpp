#include <types.hh>

extern "C" {

// __NR__ syslog = 103 
inline int syslog(int type, ostr_t buf, int len);
}

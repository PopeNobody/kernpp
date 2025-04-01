#include <types.hh>

extern "C" {

// __NR__ utime = 132 
inline int utime(ostr_t filename, utimbuf_p times);
}

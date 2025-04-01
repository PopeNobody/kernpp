#include <types.hh>

extern "C" {

// __NR__ utimes = 235 
inline int utimes(ostr_t filename, timeval_p utimes);
}

#include <types.hh>

extern "C" {

// __NR__ futimesat = 261 
inline int futimesat(fd_t dfd, istr_t filename, timeval_p utimes);
}

#include <types.hh>

extern "C" {

// __NR__ readlinkat = 267 
inline int readlinkat(fd_t dfd, istr_t pathname, ostr_t buf, int bufsiz);
}

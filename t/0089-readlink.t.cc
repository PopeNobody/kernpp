#include <types.hh>

extern "C" {

// __NR__ readlink = 89 
inline int readlink(istr_t path, ostr_t buf, int bufsiz);
}

#include <types.hh>

extern "C" {

// __NR__ truncate = 76 
inline int truncate(istr_t path, long length);
}

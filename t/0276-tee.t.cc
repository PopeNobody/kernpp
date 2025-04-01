#include <types.hh>

extern "C" {

// __NR__ tee = 276 
inline int tee(int fdin, int fdout, size_t len, unsigned flags);
}

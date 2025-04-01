#include <types.hh>

extern "C" {

// __NR__ mknod = 133 
inline int mknod(istr_t filename, umode_t mode, unsigned dev);
}

#include <types.hh>

extern "C" {

// __NR__ userfaultfd = 323 
inline int userfaultfd(int flags);
}

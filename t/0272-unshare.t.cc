#include <types.hh>

extern "C" {

// __NR__ unshare = 272 
inline int unshare(int unshare_flags);
}

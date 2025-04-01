#include <types.hh>

extern "C" {

// __NR__ ustat = 136 
inline int ustat(unsigned dev, ustat_p ubuf);
}

#include <types.hh>

extern "C" {

// __NR__ lookup_dcookie = 212 
inline int lookup_dcookie(uint64_t cookie64, long buf, long len);
}

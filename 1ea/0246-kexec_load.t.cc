#include <types.hh>

extern "C" {

// __NR__ kexec_load = 246 
inline int kexec_load(uint64_t entry, uint64_t nr_segments, kexec_segment_p segments, uint64_t flags);
}

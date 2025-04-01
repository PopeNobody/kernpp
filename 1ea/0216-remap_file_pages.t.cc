#include <types.hh>

extern "C" {

// __NR__ remap_file_pages = 216 
inline int remap_file_pages(uint64_t start, uint64_t size, uint64_t prot, uint64_t pgoff, uint64_t flags);
}

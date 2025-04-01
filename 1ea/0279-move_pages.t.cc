#include <types.hh>

extern "C" {

// __NR__ move_pages = 279 
inline int move_pages(pid_t pid, uint64_t nr_pages, void_p pages, int32_p nodes, int32_p status, int flags);
}

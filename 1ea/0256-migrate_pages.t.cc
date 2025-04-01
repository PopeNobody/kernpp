#include <types.hh>

extern "C" {

// __NR__ migrate_pages = 256 
inline int migrate_pages(pid_t pid, uint64_t maxnode, uint64_p old_nodes, uint64_p new_nodes);
}

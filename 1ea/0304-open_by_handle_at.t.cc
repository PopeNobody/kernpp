#include <types.hh>

extern "C" {

// __NR__ open_by_handle_at = 304 
inline int open_by_handle_at(fd_t dfd, istr_t name, file_handle_p handle, int32_p mnt_id, int flags);
}

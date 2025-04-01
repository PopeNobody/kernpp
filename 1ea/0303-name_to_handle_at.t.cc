#include <types.hh>

extern "C" {

// __NR__ name_to_handle_at = 303 
inline int name_to_handle_at(fd_t dfd, istr_t name, file_handle_p handle, int32_p mnt_id, int flag);
}

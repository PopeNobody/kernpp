#include <types.hh>

extern "C" {

// __NR__ kexec_file_load = 320 
inline int kexec_file_load(int kernel_fd, int initrd_fd, size_t cmdline_len, istr_t cmdline_ptr, uint64_t flags);
}

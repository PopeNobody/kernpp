#include <types.hh>

extern "C" {

// __NR__ exit_group = 231 
inline int exit_group(int error_code);
}

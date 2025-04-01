#include <types.hh>

extern "C" {

// __NR__ exit = 60 
inline void _exit(int error_code);
}

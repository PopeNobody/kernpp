#include <types.hh>

extern "C" {

// __NR__ shmdt = 67 
inline int shmdt(ostr_t shmaddr);
}

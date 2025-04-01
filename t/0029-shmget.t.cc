#include <types.hh>

extern "C" {

// __NR__ shmget = 29 
inline int shmget(key_t key, size_t size, int shmflg);
}

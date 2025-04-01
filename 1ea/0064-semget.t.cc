#include <types.hh>

extern "C" {

// __NR__ semget = 64 
inline int semget(key_t key, int nsems, int semflg);
}

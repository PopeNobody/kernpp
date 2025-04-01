#include <types.hh>

extern "C" {

// __NR__ semctl = 66 
inline int semctl(int semid, int semnum, int cmd, union semun arg);
}

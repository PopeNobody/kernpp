#include <types.hh>

extern "C" {

// __NR__ shmat = 30 
inline int shmat(int shmid, ostr_t shmaddr, int shmflg);
}

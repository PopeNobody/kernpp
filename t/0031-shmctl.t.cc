#include <types.hh>

extern "C" {

// __NR__ shmctl = 31 
inline int shmctl(int shmid, int cmd, shmid_ds_p buf);
}

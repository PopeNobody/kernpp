#include <types.hh>

extern "C" {

// __NR__ semop = 65 
inline int semop(int semid, sembuf_p tsops, unsigned nsops);
}

#include <types.hh>

extern "C" {

// __NR__ semtimedop = 220 
inline int semtimedop(int semid, sembuf_p tsops, unsigned nsops, timespec_p timeout);
}

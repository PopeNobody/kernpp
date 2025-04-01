#include <types.hh>

extern "C" {

// __NR__ getrusage = 98 
inline int getrusage(int who, rusage_p ru);
}

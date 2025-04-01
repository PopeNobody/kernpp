#include <types.hh>

extern "C" {

// __NR__ getitimer = 36 
inline int getitimer(int which, itimerval_p value);
}

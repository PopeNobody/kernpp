#include <types.hh>

extern "C" {

// __NR__ setitimer = 38 
inline int setitimer(int which, itimerval_p value, itimerval_p ovalue);
}

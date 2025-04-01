#include <types.hh>

extern "C" {

// __NR__ rt_sigaction = 13 
inline int rt_sigaction(int sig, sigaction_p act, sigaction_p oact);
}

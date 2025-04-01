#include <types.hh>

extern "C" {

// __NR__ adjtimex = 159 
inline int adjtimex(timex_p txc_p);
}

#include <types.hh>

extern "C" {

// __NR__ gettimeofday = 96 
inline int gettimeofday(timeval_p tv, timezone_p tz);
}

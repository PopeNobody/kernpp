#include <types.hh>

extern "C" {

// __NR__ settimeofday = 164 
inline int settimeofday(timeval_p tv, timezone_p tz);
}

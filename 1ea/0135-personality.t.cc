#include <types.hh>

extern "C" {

// __NR__ personality = 135 
inline int personality(unsigned personality);
}

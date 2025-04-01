#include <types.hh>

extern "C" {

// __NR__ msgget = 68 
inline int msgget(key_t key, int msgflg);
}

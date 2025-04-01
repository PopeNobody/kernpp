#include <types.hh>

extern "C" {

// __NR__ quotactl = 179 
inline int quotactl(unsigned cmd, istr_t special, qid_t id, void_p addr);
}

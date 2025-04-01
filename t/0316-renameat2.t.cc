#include <types.hh>

extern "C" {

// __NR__ renameat2 = 316 
inline int renameat2(int olddfd, istr_t oldname, int newdfd, istr_t newname, unsigned flags);
}

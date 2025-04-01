#include <types.hh>

extern "C" {

// __NR__ iopl = 172 
inline int iopl(unsigned level, pt_regs_p regs);
}

#include <types.hh>

extern "C" {

// __NR__ reboot = 169 
inline int reboot(int magic1, int magic2, unsigned cmd, void_p arg);
}

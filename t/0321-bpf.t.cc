#include <types.hh>

extern "C" {

// __NR__ bpf = 321 
inline int bpf(int cmd, bpf_attr_p attr, unsigned size);
}

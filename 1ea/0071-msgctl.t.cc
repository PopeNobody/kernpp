#include <types.hh>

extern "C" {

// __NR__ msgctl = 71 
inline int msgctl(int msqid, int cmd, msqid_ds_p buf);
}

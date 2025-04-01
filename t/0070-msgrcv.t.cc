#include <types.hh>

extern "C" {

// __NR__ msgrcv = 70 
inline int msgrcv(int msqid, msgbuf_p msgp, size_t msgsz, long msgtyp, int msgflg);
}

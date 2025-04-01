#include <types.hh>

extern "C" {

// __NR__ msgsnd = 69 
inline int msgsnd(int msqid, msgbuf_p msgp, size_t msgsz, int msgflg);
}

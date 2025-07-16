#include "syscall.low.hh"
namespace sys {

// Auto-generated syscall wrappers


// __NR__ read = 0
inline ssize_t read(fd_t fd, ostr_t buf, size_t count, errhand_t hand = err_log)
  __attribute__((__always_inline__));


inline ssize_t read(fd_t fd, ostr_t buf, size_t count, errhand_t hand) {
  uint64_t res = syscall3(0 , (uint64_t)fd, (uint64_t)buf, (uint64_t)count);


  return chk_return<ssize_t>(res, hand);
}


// __NR__ write = 1
inline ssize_t write(fd_t fd, istr_t buf, size_t count, errhand_t hand = err_log)
  __attribute__((__always_inline__));


inline ssize_t write(fd_t fd, istr_t buf, size_t count, errhand_t hand) {
  uint64_t res = syscall3(1 , (uint64_t)fd, (uint64_t)buf, (uint64_t)count);


  return chk_return<ssize_t>(res, hand);
}


// __NR__ open = 2
inline fd_t open(istr_t path, int flags, int mode, errhand_t hand = err_log)
  __attribute__((__always_inline__));


inline fd_t open(istr_t path, int flags, int mode, errhand_t hand) {
  uint64_t res = syscall3(2 , (uint64_t)path, (uint64_t)flags, (uint64_t)mode);


  return chk_return<fd_t>(res, hand);
}


// __NR__ close = 3
inline int close(fd_t fd, errhand_t hand = err_log)
  __attribute__((__always_inline__));


inline int close(fd_t fd, errhand_t hand) {
  uint64_t res = syscall1(3 , (uint64_t)fd);


  return chk_return<int>(res, hand);
}


// __NR__ stat = 4
inline int stat(istr_t path, stat_p statbuf, errhand_t hand = err_log)
  __attribute__((__always_inline__));


inline int stat(istr_t path, stat_p statbuf, errhand_t hand) {
  uint64_t res = syscall2(4 , (uint64_t)path, (uint64_t)statbuf);


  return chk_return<int>(res, hand);
}


// __NR__ fstat = 5
inline int fstat(fd_t fd, stat_p statbuf, errhand_t hand = err_log)
  __attribute__((__always_inline__));


inline int fstat(fd_t fd, stat_p statbuf, errhand_t hand) {
  uint64_t res = syscall2(5 , (uint64_t)fd, (uint64_t)statbuf);


  return chk_return<int>(res, hand);
}


// __NR__ lstat = 6
inline int lstat(istr_t path, stat_p statbuf, errhand_t hand = err_log)
  __attribute__((__always_inline__));


inline int lstat(istr_t path, stat_p statbuf, errhand_t hand) {
  uint64_t res = syscall2(6 , (uint64_t)path, (uint64_t)statbuf);


  return chk_return<int>(res, hand);
}


// __NR__ poll = 7
inline int poll(pollfd_p ufds, unsigned nfds, long timeout_msecs, errhand_t hand = err_log)
  __attribute__((__always_inline__));


inline int poll(pollfd_p ufds, unsigned nfds, long timeout_msecs, errhand_t hand) {
  uint64_t res = syscall3(7 , (uint64_t)ufds, (uint64_t)nfds, (uint64_t)timeout_msecs);


  return chk_return<int>(res, hand);
}


// __NR__ lseek = 8
inline int lseek(fd_t fd, off_t offset, unsigned origin, errhand_t hand = err_log)
  __attribute__((__always_inline__));


inline int lseek(fd_t fd, off_t offset, unsigned origin, errhand_t hand) {
  uint64_t res = syscall3(8 , (uint64_t)fd, (uint64_t)offset, (uint64_t)origin);


  return chk_return<int>(res, hand);
}


// __NR__ mmap = 9
inline char* mmap(void* addr, size_t len, int prot, int flags, fd_t fd, off_t off, errhand_t hand = err_log)
  __attribute__((__always_inline__));


inline char* mmap(void* addr, size_t len, int prot, int flags, fd_t fd, off_t off, errhand_t hand) {
  uint64_t res = syscall6(9 , (uint64_t)addr, (uint64_t)len, (uint64_t)prot, (uint64_t)flags, (uint64_t)fd, (uint64_t)off);


  return chk_return<char*>(res, hand);
}


// __NR__ mprotect = 10
inline int mprotect(uint64_t start, size_t len, uint64_t prot, errhand_t hand = err_log)
  __attribute__((__always_inline__));


inline int mprotect(uint64_t start, size_t len, uint64_t prot, errhand_t hand) {
  uint64_t res = syscall3(10 , (uint64_t)start, (uint64_t)len, (uint64_t)prot);


  return chk_return<int>(res, hand);
}


// __NR__ munmap = 11
inline int munmap(uint64_t addr, size_t len, errhand_t hand = err_log)
  __attribute__((__always_inline__));


inline int munmap(uint64_t addr, size_t len, errhand_t hand) {
  uint64_t res = syscall2(11 , (uint64_t)addr, (uint64_t)len);


  return chk_return<int>(res, hand);
}


// __NR__ brk = 12
inline int brk(void_p brk, errhand_t hand = err_log)
  __attribute__((__always_inline__));


inline int brk(void_p brk, errhand_t hand) {
  uint64_t res = syscall1(12 , (uint64_t)brk);


  return chk_return<int>(res, hand);
}


// __NR__ rt_sigaction = 13
inline int rt_sigaction(int sig, sigaction_p act, sigaction_p oact, size_t sigsetsize, errhand_t hand = err_log)
  __attribute__((__always_inline__));


inline int rt_sigaction(int sig, sigaction_p act, sigaction_p oact, size_t sigsetsize, errhand_t hand) {
  uint64_t res = syscall4(13 , (uint64_t)sig, (uint64_t)act, (uint64_t)oact, (uint64_t)sigsetsize);


  return chk_return<int>(res, hand);
}


// __NR__ rt_sigprocmask = 14
inline int rt_sigprocmask(int how, sigset_p nset, sigset_p oset, size_t sigsetsize, errhand_t hand = err_log)
  __attribute__((__always_inline__));


inline int rt_sigprocmask(int how, sigset_p nset, sigset_p oset, size_t sigsetsize, errhand_t hand) {
  uint64_t res = syscall4(14 , (uint64_t)how, (uint64_t)nset, (uint64_t)oset, (uint64_t)sigsetsize);


  return chk_return<int>(res, hand);
}


// __NR__ rt_sigreturn = 15
inline int rt_sigreturn(uint64_t __unused, errhand_t hand = err_log)
  __attribute__((__always_inline__));


inline int rt_sigreturn(uint64_t __unused, errhand_t hand) {
  uint64_t res = syscall1(15 , (uint64_t)__unused);


  return chk_return<int>(res, hand);
}


// __NR__ ioctl = 16
inline int ioctl(fd_t fd, unsigned cmd, uint64_t arg, errhand_t hand = err_log)
  __attribute__((__always_inline__));


inline int ioctl(fd_t fd, unsigned cmd, uint64_t arg, errhand_t hand) {
  uint64_t res = syscall3(16 , (uint64_t)fd, (uint64_t)cmd, (uint64_t)arg);


  return chk_return<int>(res, hand);
}


// __NR__ pread64 = 17
inline int pread64(fd_t fd, ostr_t buf, size_t count, off_t pos, errhand_t hand = err_log)
  __attribute__((__always_inline__));


inline int pread64(fd_t fd, ostr_t buf, size_t count, off_t pos, errhand_t hand) {
  uint64_t res = syscall4(17 , (uint64_t)fd, (uint64_t)buf, (uint64_t)count, (uint64_t)pos);


  return chk_return<int>(res, hand);
}


// __NR__ pwrite64 = 18
inline int pwrite64(fd_t fd, istr_t buf, size_t count, off_t pos, errhand_t hand = err_log)
  __attribute__((__always_inline__));


inline int pwrite64(fd_t fd, istr_t buf, size_t count, off_t pos, errhand_t hand) {
  uint64_t res = syscall4(18 , (uint64_t)fd, (uint64_t)buf, (uint64_t)count, (uint64_t)pos);


  return chk_return<int>(res, hand);
}


// __NR__ readv = 19
inline int readv(fd_t fd, iovec_p vec, uint64_t vlen, errhand_t hand = err_log)
  __attribute__((__always_inline__));


inline int readv(fd_t fd, iovec_p vec, uint64_t vlen, errhand_t hand) {
  uint64_t res = syscall3(19 , (uint64_t)fd, (uint64_t)vec, (uint64_t)vlen);


  return chk_return<int>(res, hand);
}


// __NR__ writev = 20
inline int writev(fd_t fd, iovec_p vec, uint64_t vlen, errhand_t hand = err_log)
  __attribute__((__always_inline__));


inline int writev(fd_t fd, iovec_p vec, uint64_t vlen, errhand_t hand) {
  uint64_t res = syscall3(20 , (uint64_t)fd, (uint64_t)vec, (uint64_t)vlen);


  return chk_return<int>(res, hand);
}


// __NR__ access = 21
inline int access(istr_t path, int mode, errhand_t hand = err_log)
  __attribute__((__always_inline__));


inline int access(istr_t path, int mode, errhand_t hand) {
  uint64_t res = syscall2(21 , (uint64_t)path, (uint64_t)mode);


  return chk_return<int>(res, hand);
}


// __NR__ pipe = 22
inline int pipe(fd_p filedes, errhand_t hand = err_log)
  __attribute__((__always_inline__));


inline int pipe(fd_p filedes, errhand_t hand) {
  uint64_t res = syscall1(22 , (uint64_t)filedes);


  return chk_return<int>(res, hand);
}


// __NR__ select = 23
inline int select(int n, fdset_p inp, fdset_p outp, fdset_p exp, timeval_p tvp, errhand_t hand = err_log)
  __attribute__((__always_inline__));


inline int select(int n, fdset_p inp, fdset_p outp, fdset_p exp, timeval_p tvp, errhand_t hand) {
  uint64_t res = syscall5(23 , (uint64_t)n, (uint64_t)inp, (uint64_t)outp, (uint64_t)exp, (uint64_t)tvp);


  return chk_return<int>(res, hand);
}


// __NR__ sched_yield = 24
inline int sched_yield(errhand_t hand = err_log)
  __attribute__((__always_inline__));


inline int sched_yield(errhand_t hand) {
  uint64_t res = syscall0(24 );


  return chk_return<int>(res, hand);
}


// __NR__ mremap = 25
inline int mremap(uint64_t addr, uint64_t old_len, uint64_t new_len, uint64_t flags, uint64_t new_addr, errhand_t hand = err_log)
  __attribute__((__always_inline__));


inline int mremap(uint64_t addr, uint64_t old_len, uint64_t new_len, uint64_t flags, uint64_t new_addr, errhand_t hand) {
  uint64_t res = syscall5(25 , (uint64_t)addr, (uint64_t)old_len, (uint64_t)new_len, (uint64_t)flags, (uint64_t)new_addr);


  return chk_return<int>(res, hand);
}


// __NR__ msync = 26
inline int msync(uint64_t start, size_t len, int flags, errhand_t hand = err_log)
  __attribute__((__always_inline__));


inline int msync(uint64_t start, size_t len, int flags, errhand_t hand) {
  uint64_t res = syscall3(26 , (uint64_t)start, (uint64_t)len, (uint64_t)flags);


  return chk_return<int>(res, hand);
}


// __NR__ mincore = 27
inline int mincore(uint64_t start, size_t len, ostr_t vec, errhand_t hand = err_log)
  __attribute__((__always_inline__));


inline int mincore(uint64_t start, size_t len, ostr_t vec, errhand_t hand) {
  uint64_t res = syscall3(27 , (uint64_t)start, (uint64_t)len, (uint64_t)vec);


  return chk_return<int>(res, hand);
}


// __NR__ madvise = 28
inline int madvise(uint64_t start, size_t len_in, int behavior, errhand_t hand = err_log)
  __attribute__((__always_inline__));


inline int madvise(uint64_t start, size_t len_in, int behavior, errhand_t hand) {
  uint64_t res = syscall3(28 , (uint64_t)start, (uint64_t)len_in, (uint64_t)behavior);


  return chk_return<int>(res, hand);
}


// __NR__ shmget = 29
inline int shmget(key_t key, size_t size, int shmflg, errhand_t hand = err_log)
  __attribute__((__always_inline__));


inline int shmget(key_t key, size_t size, int shmflg, errhand_t hand) {
  uint64_t res = syscall3(29 , (uint64_t)key, (uint64_t)size, (uint64_t)shmflg);


  return chk_return<int>(res, hand);
}


// __NR__ shmat = 30
inline int shmat(int shmid, ostr_t shmaddr, int shmflg, errhand_t hand = err_log)
  __attribute__((__always_inline__));


inline int shmat(int shmid, ostr_t shmaddr, int shmflg, errhand_t hand) {
  uint64_t res = syscall3(30 , (uint64_t)shmid, (uint64_t)shmaddr, (uint64_t)shmflg);


  return chk_return<int>(res, hand);
}


// __NR__ shmctl = 31
inline int shmctl(int shmid, int cmd, shmid_ds_p buf, errhand_t hand = err_log)
  __attribute__((__always_inline__));


inline int shmctl(int shmid, int cmd, shmid_ds_p buf, errhand_t hand) {
  uint64_t res = syscall3(31 , (uint64_t)shmid, (uint64_t)cmd, (uint64_t)buf);


  return chk_return<int>(res, hand);
}


// __NR__ dup = 32
inline int dup(unsigned fildes, errhand_t hand = err_log)
  __attribute__((__always_inline__));


inline int dup(unsigned fildes, errhand_t hand) {
  uint64_t res = syscall1(32 , (uint64_t)fildes);


  return chk_return<int>(res, hand);
}


// __NR__ dup2 = 33
inline int dup2(fd_t oldfd, fd_t newfd, errhand_t hand = err_log)
  __attribute__((__always_inline__));


inline int dup2(fd_t oldfd, fd_t newfd, errhand_t hand) {
  uint64_t res = syscall2(33 , (uint64_t)oldfd, (uint64_t)newfd);


  return chk_return<int>(res, hand);
}


// __NR__ pause = 34
inline int pause(errhand_t hand = err_log)
  __attribute__((__always_inline__));


inline int pause(errhand_t hand) {
  uint64_t res = syscall0(34 );


  return chk_return<int>(res, hand);
}


// __NR__ nanosleep = 35
inline int nanosleep(timespec_p rqtp, timespec_p rmtp, errhand_t hand = err_log)
  __attribute__((__always_inline__));


inline int nanosleep(timespec_p rqtp, timespec_p rmtp, errhand_t hand) {
  uint64_t res = syscall2(35 , (uint64_t)rqtp, (uint64_t)rmtp);


  return chk_return<int>(res, hand);
}


// __NR__ getitimer = 36
inline int getitimer(int which, itimerval_p value, errhand_t hand = err_log)
  __attribute__((__always_inline__));


inline int getitimer(int which, itimerval_p value, errhand_t hand) {
  uint64_t res = syscall2(36 , (uint64_t)which, (uint64_t)value);


  return chk_return<int>(res, hand);
}


// __NR__ alarm = 37
inline int alarm(unsigned seconds, errhand_t hand = err_log)
  __attribute__((__always_inline__));


inline int alarm(unsigned seconds, errhand_t hand) {
  uint64_t res = syscall1(37 , (uint64_t)seconds);


  return chk_return<int>(res, hand);
}


// __NR__ setitimer = 38
inline int setitimer(int which, itimerval_p value, itimerval_p ovalue, errhand_t hand = err_log)
  __attribute__((__always_inline__));


inline int setitimer(int which, itimerval_p value, itimerval_p ovalue, errhand_t hand) {
  uint64_t res = syscall3(38 , (uint64_t)which, (uint64_t)value, (uint64_t)ovalue);


  return chk_return<int>(res, hand);
}


// __NR__ getpid = 39
inline int getpid(errhand_t hand = err_log)
  __attribute__((__always_inline__));


inline int getpid(errhand_t hand) {
  uint64_t res = syscall0(39 );


  return chk_return<int>(res, hand);
}


// __NR__ sendfile = 40
inline int sendfile(int out_fd, int in_fd, off_p offset, size_t count, errhand_t hand = err_log)
  __attribute__((__always_inline__));


inline int sendfile(int out_fd, int in_fd, off_p offset, size_t count, errhand_t hand) {
  uint64_t res = syscall4(40 , (uint64_t)out_fd, (uint64_t)in_fd, (uint64_t)offset, (uint64_t)count);


  return chk_return<int>(res, hand);
}


// __NR__ socket = 41
inline int socket(int family, int type, int protocol, errhand_t hand = err_log)
  __attribute__((__always_inline__));


inline int socket(int family, int type, int protocol, errhand_t hand) {
  uint64_t res = syscall3(41 , (uint64_t)family, (uint64_t)type, (uint64_t)protocol);


  return chk_return<int>(res, hand);
}


// __NR__ connect = 42
inline int connect(fd_t fd, sockaddr_p uservaddr, int addrlen, errhand_t hand = err_log)
  __attribute__((__always_inline__));


inline int connect(fd_t fd, sockaddr_p uservaddr, int addrlen, errhand_t hand) {
  uint64_t res = syscall3(42 , (uint64_t)fd, (uint64_t)uservaddr, (uint64_t)addrlen);


  return chk_return<int>(res, hand);
}


// __NR__ accept = 43
inline int accept(fd_t fd, sockaddr_p upeer_sockaddr, int32_p upeer_addrlen, errhand_t hand = err_log)
  __attribute__((__always_inline__));


inline int accept(fd_t fd, sockaddr_p upeer_sockaddr, int32_p upeer_addrlen, errhand_t hand) {
  uint64_t res = syscall3(43 , (uint64_t)fd, (uint64_t)upeer_sockaddr, (uint64_t)upeer_addrlen);


  return chk_return<int>(res, hand);
}


// __NR__ sendto = 44
inline int sendto(fd_t fd, void_p buff, size_t len, unsigned flags, sockaddr_p addr, int addr_len, errhand_t hand = err_log)
  __attribute__((__always_inline__));


inline int sendto(fd_t fd, void_p buff, size_t len, unsigned flags, sockaddr_p addr, int addr_len, errhand_t hand) {
  uint64_t res = syscall6(44 , (uint64_t)fd, (uint64_t)buff, (uint64_t)len, (uint64_t)flags, (uint64_t)addr, (uint64_t)addr_len);


  return chk_return<int>(res, hand);
}


// __NR__ recvfrom = 45
inline int recvfrom(fd_t fd, void_p ubuf, size_t size, unsigned flags, sockaddr_p addr, int32_p addr_len, errhand_t hand = err_log)
  __attribute__((__always_inline__));


inline int recvfrom(fd_t fd, void_p ubuf, size_t size, unsigned flags, sockaddr_p addr, int32_p addr_len, errhand_t hand) {
  uint64_t res = syscall6(45 , (uint64_t)fd, (uint64_t)ubuf, (uint64_t)size, (uint64_t)flags, (uint64_t)addr, (uint64_t)addr_len);


  return chk_return<int>(res, hand);
}


// __NR__ sendmsg = 46
inline int sendmsg(fd_t fd, msghdr_p msg, unsigned flags, errhand_t hand = err_log)
  __attribute__((__always_inline__));


inline int sendmsg(fd_t fd, msghdr_p msg, unsigned flags, errhand_t hand) {
  uint64_t res = syscall3(46 , (uint64_t)fd, (uint64_t)msg, (uint64_t)flags);


  return chk_return<int>(res, hand);
}


// __NR__ recvmsg = 47
inline int recvmsg(fd_t fd, msghdr_p msg, unsigned flags, errhand_t hand = err_log)
  __attribute__((__always_inline__));


inline int recvmsg(fd_t fd, msghdr_p msg, unsigned flags, errhand_t hand) {
  uint64_t res = syscall3(47 , (uint64_t)fd, (uint64_t)msg, (uint64_t)flags);


  return chk_return<int>(res, hand);
}


// __NR__ shutdown = 48
inline int shutdown(fd_t fd, int how, errhand_t hand = err_log)
  __attribute__((__always_inline__));


inline int shutdown(fd_t fd, int how, errhand_t hand) {
  uint64_t res = syscall2(48 , (uint64_t)fd, (uint64_t)how);


  return chk_return<int>(res, hand);
}


// __NR__ bind = 49
inline int bind(fd_t fd, sockaddr_p umyaddr, int addrlen, errhand_t hand = err_log)
  __attribute__((__always_inline__));


inline int bind(fd_t fd, sockaddr_p umyaddr, int addrlen, errhand_t hand) {
  uint64_t res = syscall3(49 , (uint64_t)fd, (uint64_t)umyaddr, (uint64_t)addrlen);


  return chk_return<int>(res, hand);
}


// __NR__ listen = 50
inline int listen(fd_t fd, int backlog, errhand_t hand = err_log)
  __attribute__((__always_inline__));


inline int listen(fd_t fd, int backlog, errhand_t hand) {
  uint64_t res = syscall2(50 , (uint64_t)fd, (uint64_t)backlog);


  return chk_return<int>(res, hand);
}


// __NR__ getsockname = 51
inline int getsockname(fd_t fd, sockaddr_p usockaddr, int32_p usockaddr_len, errhand_t hand = err_log)
  __attribute__((__always_inline__));


inline int getsockname(fd_t fd, sockaddr_p usockaddr, int32_p usockaddr_len, errhand_t hand) {
  uint64_t res = syscall3(51 , (uint64_t)fd, (uint64_t)usockaddr, (uint64_t)usockaddr_len);


  return chk_return<int>(res, hand);
}


// __NR__ getpeername = 52
inline int getpeername(fd_t fd, sockaddr_p usockaddr, int32_p usockaddr_len, errhand_t hand = err_log)
  __attribute__((__always_inline__));


inline int getpeername(fd_t fd, sockaddr_p usockaddr, int32_p usockaddr_len, errhand_t hand) {
  uint64_t res = syscall3(52 , (uint64_t)fd, (uint64_t)usockaddr, (uint64_t)usockaddr_len);


  return chk_return<int>(res, hand);
}


// __NR__ socketpair = 53
inline int socketpair(int family, int type, int protocol, int32_p usockvec, errhand_t hand = err_log)
  __attribute__((__always_inline__));


inline int socketpair(int family, int type, int protocol, int32_p usockvec, errhand_t hand) {
  uint64_t res = syscall4(53 , (uint64_t)family, (uint64_t)type, (uint64_t)protocol, (uint64_t)usockvec);


  return chk_return<int>(res, hand);
}


// __NR__ setsockopt = 54
inline int setsockopt(fd_t fd, int level, int optname, ostr_t optval, int optlen, errhand_t hand = err_log)
  __attribute__((__always_inline__));


inline int setsockopt(fd_t fd, int level, int optname, ostr_t optval, int optlen, errhand_t hand) {
  uint64_t res = syscall5(54 , (uint64_t)fd, (uint64_t)level, (uint64_t)optname, (uint64_t)optval, (uint64_t)optlen);


  return chk_return<int>(res, hand);
}


// __NR__ getsockopt = 55
inline int getsockopt(fd_t fd, int level, int optname, ostr_t optval, int32_p optlen, errhand_t hand = err_log)
  __attribute__((__always_inline__));


inline int getsockopt(fd_t fd, int level, int optname, ostr_t optval, int32_p optlen, errhand_t hand) {
  uint64_t res = syscall5(55 , (uint64_t)fd, (uint64_t)level, (uint64_t)optname, (uint64_t)optval, (uint64_t)optlen);


  return chk_return<int>(res, hand);
}


// __NR__ clone = 56
inline int clone(uint64_t clone_flags, uint64_t newsp, void_p parent_tid, void_p child_tid, errhand_t hand = err_log)
  __attribute__((__always_inline__));


inline int clone(uint64_t clone_flags, uint64_t newsp, void_p parent_tid, void_p child_tid, errhand_t hand) {
  uint64_t res = syscall4(56 , (uint64_t)clone_flags, (uint64_t)newsp, (uint64_t)parent_tid, (uint64_t)child_tid);


  return chk_return<int>(res, hand);
}


// __NR__ fork = 57
inline pid_t fork(errhand_t hand = err_log)
  __attribute__((__always_inline__));


inline pid_t fork(errhand_t hand) {
  uint64_t res = syscall0(57 );


  return chk_return<pid_t>(res, hand);
}


// __NR__ vfork = 58
inline pid_t vfork(errhand_t hand = err_log)
  __attribute__((__always_inline__));


inline pid_t vfork(errhand_t hand) {
  uint64_t res = syscall0(58 );


  return chk_return<pid_t>(res, hand);
}


// __NR__ execve = 59
inline int execve(const char * filename, char *const * argv, char *const * envp, errhand_t hand = err_log)
  __attribute__((__always_inline__, __noreturn__));


inline int execve(const char * filename, char *const * argv, char *const * envp, errhand_t hand) {
  uint64_t res = syscall3(59 , (uint64_t)filename, (uint64_t)argv, (uint64_t)envp);


  __builtin_unreachable();
}


// __NR__ exit = 60
inline void exit(int error_code, errhand_t hand = err_log)
  __attribute__((__always_inline__, __noreturn__));


inline void exit(int error_code, errhand_t hand) {
  uint64_t res = syscall1(60 , (uint64_t)error_code);


  __builtin_unreachable();
}


// __NR__ wait4 = 61
inline int wait4(pid_t upid, int32_p stat_addr, int options, rusage_p ru, errhand_t hand = err_log)
  __attribute__((__always_inline__));


inline int wait4(pid_t upid, int32_p stat_addr, int options, rusage_p ru, errhand_t hand) {
  uint64_t res = syscall4(61 , (uint64_t)upid, (uint64_t)stat_addr, (uint64_t)options, (uint64_t)ru);


  return chk_return<int>(res, hand);
}


// __NR__ kill = 62
inline int kill(pid_t pid, int sig, errhand_t hand = err_log)
  __attribute__((__always_inline__));


inline int kill(pid_t pid, int sig, errhand_t hand) {
  uint64_t res = syscall2(62 , (uint64_t)pid, (uint64_t)sig);


  return chk_return<int>(res, hand);
}


// __NR__ uname = 63
inline int uname(utsname_p name, errhand_t hand = err_log)
  __attribute__((__always_inline__));


inline int uname(utsname_p name, errhand_t hand) {
  uint64_t res = syscall1(63 , (uint64_t)name);


  return chk_return<int>(res, hand);
}


// __NR__ shmdt = 67
inline int shmdt(ostr_t shmaddr, errhand_t hand = err_log)
  __attribute__((__always_inline__));


inline int shmdt(ostr_t shmaddr, errhand_t hand) {
  uint64_t res = syscall1(67 , (uint64_t)shmaddr);


  return chk_return<int>(res, hand);
}


// __NR__ msgget = 68
inline int msgget(key_t key, int msgflg, errhand_t hand = err_log)
  __attribute__((__always_inline__));


inline int msgget(key_t key, int msgflg, errhand_t hand) {
  uint64_t res = syscall2(68 , (uint64_t)key, (uint64_t)msgflg);


  return chk_return<int>(res, hand);
}


// __NR__ msgsnd = 69
inline int msgsnd(int msqid, msgbuf_p msgp, size_t msgsz, int msgflg, errhand_t hand = err_log)
  __attribute__((__always_inline__));


inline int msgsnd(int msqid, msgbuf_p msgp, size_t msgsz, int msgflg, errhand_t hand) {
  uint64_t res = syscall4(69 , (uint64_t)msqid, (uint64_t)msgp, (uint64_t)msgsz, (uint64_t)msgflg);


  return chk_return<int>(res, hand);
}


// __NR__ msgrcv = 70
inline int msgrcv(int msqid, msgbuf_p msgp, size_t msgsz, long msgtyp, int msgflg, errhand_t hand = err_log)
  __attribute__((__always_inline__));


inline int msgrcv(int msqid, msgbuf_p msgp, size_t msgsz, long msgtyp, int msgflg, errhand_t hand) {
  uint64_t res = syscall5(70 , (uint64_t)msqid, (uint64_t)msgp, (uint64_t)msgsz, (uint64_t)msgtyp, (uint64_t)msgflg);


  return chk_return<int>(res, hand);
}


// __NR__ msgctl = 71
inline int msgctl(int msqid, int cmd, msqid_ds_p buf, errhand_t hand = err_log)
  __attribute__((__always_inline__));


inline int msgctl(int msqid, int cmd, msqid_ds_p buf, errhand_t hand) {
  uint64_t res = syscall3(71 , (uint64_t)msqid, (uint64_t)cmd, (uint64_t)buf);


  return chk_return<int>(res, hand);
}


// __NR__ fcntl = 72
inline int fcntl(fd_t fd, unsigned cmd, uint64_t arg, errhand_t hand = err_log)
  __attribute__((__always_inline__));


inline int fcntl(fd_t fd, unsigned cmd, uint64_t arg, errhand_t hand) {
  uint64_t res = syscall3(72 , (uint64_t)fd, (uint64_t)cmd, (uint64_t)arg);


  return chk_return<int>(res, hand);
}


// __NR__ flock = 73
inline int flock(fd_t fd, unsigned cmd, errhand_t hand = err_log)
  __attribute__((__always_inline__));


inline int flock(fd_t fd, unsigned cmd, errhand_t hand) {
  uint64_t res = syscall2(73 , (uint64_t)fd, (uint64_t)cmd);


  return chk_return<int>(res, hand);
}


// __NR__ fsync = 74
inline int fsync(fd_t fd, errhand_t hand = err_log)
  __attribute__((__always_inline__));


inline int fsync(fd_t fd, errhand_t hand) {
  uint64_t res = syscall1(74 , (uint64_t)fd);


  return chk_return<int>(res, hand);
}


// __NR__ fdatasync = 75
inline int fdatasync(fd_t fd, errhand_t hand = err_log)
  __attribute__((__always_inline__));


inline int fdatasync(fd_t fd, errhand_t hand) {
  uint64_t res = syscall1(75 , (uint64_t)fd);


  return chk_return<int>(res, hand);
}


// __NR__ truncate = 76
inline int truncate(istr_t path, long length, errhand_t hand = err_log)
  __attribute__((__always_inline__));


inline int truncate(istr_t path, long length, errhand_t hand) {
  uint64_t res = syscall2(76 , (uint64_t)path, (uint64_t)length);


  return chk_return<int>(res, hand);
}


// __NR__ ftruncate = 77
inline int ftruncate(fd_t fd, uint64_t length, errhand_t hand = err_log)
  __attribute__((__always_inline__));


inline int ftruncate(fd_t fd, uint64_t length, errhand_t hand) {
  uint64_t res = syscall2(77 , (uint64_t)fd, (uint64_t)length);


  return chk_return<int>(res, hand);
}


// __NR__ getdents = 78
inline ssize_t getdents(fd_t fd, linux_dirent_p dirent, size_t count, errhand_t hand = err_log)
  __attribute__((__always_inline__));


inline ssize_t getdents(fd_t fd, linux_dirent_p dirent, size_t count, errhand_t hand) {
  uint64_t res = syscall3(78 , (uint64_t)fd, (uint64_t)dirent, (uint64_t)count);


  return chk_return<ssize_t>(res, hand);
}


// __NR__ getcwd = 79
inline int getcwd(ostr_t buf, uint64_t size, errhand_t hand = err_log)
  __attribute__((__always_inline__));


inline int getcwd(ostr_t buf, uint64_t size, errhand_t hand) {
  uint64_t res = syscall2(79 , (uint64_t)buf, (uint64_t)size);


  return chk_return<int>(res, hand);
}


// __NR__ chdir = 80
inline int chdir(istr_t path, errhand_t hand = err_log)
  __attribute__((__always_inline__));


inline int chdir(istr_t path, errhand_t hand) {
  uint64_t res = syscall1(80 , (uint64_t)path);


  return chk_return<int>(res, hand);
}


// __NR__ fchdir = 81
inline int fchdir(fd_t fd, errhand_t hand = err_log)
  __attribute__((__always_inline__));


inline int fchdir(fd_t fd, errhand_t hand) {
  uint64_t res = syscall1(81 , (uint64_t)fd);


  return chk_return<int>(res, hand);
}


// __NR__ rename = 82
inline int rename(istr_t opath, istr_t npath, errhand_t hand = err_log)
  __attribute__((__always_inline__));


inline int rename(istr_t opath, istr_t npath, errhand_t hand) {
  uint64_t res = syscall2(82 , (uint64_t)opath, (uint64_t)npath);


  return chk_return<int>(res, hand);
}


// __NR__ mkdir = 83
inline int mkdir(istr_t path, int mode, errhand_t hand = err_log)
  __attribute__((__always_inline__));


inline int mkdir(istr_t path, int mode, errhand_t hand) {
  uint64_t res = syscall2(83 , (uint64_t)path, (uint64_t)mode);


  return chk_return<int>(res, hand);
}


// __NR__ rmdir = 84
inline int rmdir(istr_t path, errhand_t hand = err_log)
  __attribute__((__always_inline__));


inline int rmdir(istr_t path, errhand_t hand) {
  uint64_t res = syscall1(84 , (uint64_t)path);


  return chk_return<int>(res, hand);
}


// __NR__ creat = 85
inline int creat(istr_t path, int mode, errhand_t hand = err_log)
  __attribute__((__always_inline__));


inline int creat(istr_t path, int mode, errhand_t hand) {
  uint64_t res = syscall2(85 , (uint64_t)path, (uint64_t)mode);


  return chk_return<int>(res, hand);
}


// __NR__ link = 86
inline int link(istr_t opath, istr_t npath, errhand_t hand = err_log)
  __attribute__((__always_inline__));


inline int link(istr_t opath, istr_t npath, errhand_t hand) {
  uint64_t res = syscall2(86 , (uint64_t)opath, (uint64_t)npath);


  return chk_return<int>(res, hand);
}


// __NR__ unlink = 87
inline int unlink(istr_t path, errhand_t hand = err_log)
  __attribute__((__always_inline__));


inline int unlink(istr_t path, errhand_t hand) {
  uint64_t res = syscall1(87 , (uint64_t)path);


  return chk_return<int>(res, hand);
}


// __NR__ symlink = 88
inline int symlink(istr_t opath, istr_t npath, errhand_t hand = err_log)
  __attribute__((__always_inline__));


inline int symlink(istr_t opath, istr_t npath, errhand_t hand) {
  uint64_t res = syscall2(88 , (uint64_t)opath, (uint64_t)npath);


  return chk_return<int>(res, hand);
}


// __NR__ readlink = 89
inline int readlink(istr_t path, ostr_t buf, int bufsiz, errhand_t hand = err_log)
  __attribute__((__always_inline__));


inline int readlink(istr_t path, ostr_t buf, int bufsiz, errhand_t hand) {
  uint64_t res = syscall3(89 , (uint64_t)path, (uint64_t)buf, (uint64_t)bufsiz);


  return chk_return<int>(res, hand);
}


// __NR__ chmod = 90
inline int chmod(istr_t path, mode_t mode, errhand_t hand = err_log)
  __attribute__((__always_inline__));


inline int chmod(istr_t path, mode_t mode, errhand_t hand) {
  uint64_t res = syscall2(90 , (uint64_t)path, (uint64_t)mode);


  return chk_return<int>(res, hand);
}


// __NR__ fchmod = 91
inline int fchmod(fd_t fd, mode_t mode, errhand_t hand = err_log)
  __attribute__((__always_inline__));


inline int fchmod(fd_t fd, mode_t mode, errhand_t hand) {
  uint64_t res = syscall2(91 , (uint64_t)fd, (uint64_t)mode);


  return chk_return<int>(res, hand);
}


// __NR__ chown = 92
inline int chown(istr_t path, uid_t user, gid_t group, errhand_t hand = err_log)
  __attribute__((__always_inline__));


inline int chown(istr_t path, uid_t user, gid_t group, errhand_t hand) {
  uint64_t res = syscall3(92 , (uint64_t)path, (uint64_t)user, (uint64_t)group);


  return chk_return<int>(res, hand);
}


// __NR__ fchown = 93
inline int fchown(fd_t fd, uid_t user, gid_t group, errhand_t hand = err_log)
  __attribute__((__always_inline__));


inline int fchown(fd_t fd, uid_t user, gid_t group, errhand_t hand) {
  uint64_t res = syscall3(93 , (uint64_t)fd, (uint64_t)user, (uint64_t)group);


  return chk_return<int>(res, hand);
}


// __NR__ lchown = 94
inline int lchown(istr_t path, uid_t user, gid_t group, errhand_t hand = err_log)
  __attribute__((__always_inline__));


inline int lchown(istr_t path, uid_t user, gid_t group, errhand_t hand) {
  uint64_t res = syscall3(94 , (uint64_t)path, (uint64_t)user, (uint64_t)group);


  return chk_return<int>(res, hand);
}


// __NR__ umask = 95
inline int umask(int mask, errhand_t hand = err_log)
  __attribute__((__always_inline__));


inline int umask(int mask, errhand_t hand) {
  uint64_t res = syscall1(95 , (uint64_t)mask);


  return chk_return<int>(res, hand);
}


// __NR__ gettimeofday = 96
inline int gettimeofday(timeval_p tv, timezone_p tz, errhand_t hand = err_log)
  __attribute__((__always_inline__));


inline int gettimeofday(timeval_p tv, timezone_p tz, errhand_t hand) {
  uint64_t res = syscall2(96 , (uint64_t)tv, (uint64_t)tz);


  return chk_return<int>(res, hand);
}


// __NR__ getrlimit = 97
inline int getrlimit(unsigned resource, rlimit_p rlim, errhand_t hand = err_log)
  __attribute__((__always_inline__));


inline int getrlimit(unsigned resource, rlimit_p rlim, errhand_t hand) {
  uint64_t res = syscall2(97 , (uint64_t)resource, (uint64_t)rlim);


  return chk_return<int>(res, hand);
}


// __NR__ getrusage = 98
inline int getrusage(int who, rusage_p ru, errhand_t hand = err_log)
  __attribute__((__always_inline__));


inline int getrusage(int who, rusage_p ru, errhand_t hand) {
  uint64_t res = syscall2(98 , (uint64_t)who, (uint64_t)ru);


  return chk_return<int>(res, hand);
}


// __NR__ sysinfo = 99
inline int sysinfo(sysinfo_p info, errhand_t hand = err_log)
  __attribute__((__always_inline__));


inline int sysinfo(sysinfo_p info, errhand_t hand) {
  uint64_t res = syscall1(99 , (uint64_t)info);


  return chk_return<int>(res, hand);
}


// __NR__ times = 100
inline int times(sysinfo_p info, errhand_t hand = err_log)
  __attribute__((__always_inline__));


inline int times(sysinfo_p info, errhand_t hand) {
  uint64_t res = syscall1(100 , (uint64_t)info);


  return chk_return<int>(res, hand);
}


// __NR__ ptrace = 101
inline int ptrace(long request, long pid, uint64_t addr, uint64_t data, errhand_t hand = err_log)
  __attribute__((__always_inline__));


inline int ptrace(long request, long pid, uint64_t addr, uint64_t data, errhand_t hand) {
  uint64_t res = syscall4(101 , (uint64_t)request, (uint64_t)pid, (uint64_t)addr, (uint64_t)data);


  return chk_return<int>(res, hand);
}


// __NR__ getuid = 102
inline int getuid(errhand_t hand = err_log)
  __attribute__((__always_inline__));


inline int getuid(errhand_t hand) {
  uint64_t res = syscall0(102 );


  return chk_return<int>(res, hand);
}


// __NR__ syslog = 103
inline int syslog(int type, ostr_t buf, int len, errhand_t hand = err_log)
  __attribute__((__always_inline__));


inline int syslog(int type, ostr_t buf, int len, errhand_t hand) {
  uint64_t res = syscall3(103 , (uint64_t)type, (uint64_t)buf, (uint64_t)len);


  return chk_return<int>(res, hand);
}


// __NR__ getgid = 104
inline int getgid(errhand_t hand = err_log)
  __attribute__((__always_inline__));


inline int getgid(errhand_t hand) {
  uint64_t res = syscall0(104 );


  return chk_return<int>(res, hand);
}


// __NR__ setuid = 105
inline int setuid(uid_t uid, errhand_t hand = err_log)
  __attribute__((__always_inline__));


inline int setuid(uid_t uid, errhand_t hand) {
  uint64_t res = syscall1(105 , (uint64_t)uid);


  return chk_return<int>(res, hand);
}


// __NR__ setgid = 106
inline int setgid(gid_t gid, errhand_t hand = err_log)
  __attribute__((__always_inline__));


inline int setgid(gid_t gid, errhand_t hand) {
  uint64_t res = syscall1(106 , (uint64_t)gid);


  return chk_return<int>(res, hand);
}


// __NR__ geteuid = 107
inline int geteuid(errhand_t hand = err_log)
  __attribute__((__always_inline__));


inline int geteuid(errhand_t hand) {
  uint64_t res = syscall0(107 );


  return chk_return<int>(res, hand);
}


// __NR__ getegid = 108
inline int getegid(errhand_t hand = err_log)
  __attribute__((__always_inline__));


inline int getegid(errhand_t hand) {
  uint64_t res = syscall0(108 );


  return chk_return<int>(res, hand);
}


// __NR__ setpgid = 109
inline int setpgid(pid_t pid, pid_t pgid, errhand_t hand = err_log)
  __attribute__((__always_inline__));


inline int setpgid(pid_t pid, pid_t pgid, errhand_t hand) {
  uint64_t res = syscall2(109 , (uint64_t)pid, (uint64_t)pgid);


  return chk_return<int>(res, hand);
}


// __NR__ getppid = 110
inline int getppid(errhand_t hand = err_log)
  __attribute__((__always_inline__));


inline int getppid(errhand_t hand) {
  uint64_t res = syscall0(110 );


  return chk_return<int>(res, hand);
}


// __NR__ getpgrp = 111
inline int getpgrp(errhand_t hand = err_log)
  __attribute__((__always_inline__));


inline int getpgrp(errhand_t hand) {
  uint64_t res = syscall0(111 );


  return chk_return<int>(res, hand);
}


// __NR__ setsid = 112
inline int setsid(errhand_t hand = err_log)
  __attribute__((__always_inline__));


inline int setsid(errhand_t hand) {
  uint64_t res = syscall0(112 );


  return chk_return<int>(res, hand);
}


// __NR__ setreuid = 113
inline int setreuid(uid_t ruid, uid_t euid, errhand_t hand = err_log)
  __attribute__((__always_inline__));


inline int setreuid(uid_t ruid, uid_t euid, errhand_t hand) {
  uint64_t res = syscall2(113 , (uint64_t)ruid, (uint64_t)euid);


  return chk_return<int>(res, hand);
}


// __NR__ setregid = 114
inline int setregid(gid_t rgid, gid_t egid, errhand_t hand = err_log)
  __attribute__((__always_inline__));


inline int setregid(gid_t rgid, gid_t egid, errhand_t hand) {
  uint64_t res = syscall2(114 , (uint64_t)rgid, (uint64_t)egid);


  return chk_return<int>(res, hand);
}


// __NR__ getgroups = 115
inline int getgroups(int gidsetsize, gid_p grouplist, errhand_t hand = err_log)
  __attribute__((__always_inline__));


inline int getgroups(int gidsetsize, gid_p grouplist, errhand_t hand) {
  uint64_t res = syscall2(115 , (uint64_t)gidsetsize, (uint64_t)grouplist);


  return chk_return<int>(res, hand);
}


// __NR__ setgroups = 116
inline int setgroups(int gidsetsize, gid_p grouplist, errhand_t hand = err_log)
  __attribute__((__always_inline__));


inline int setgroups(int gidsetsize, gid_p grouplist, errhand_t hand) {
  uint64_t res = syscall2(116 , (uint64_t)gidsetsize, (uint64_t)grouplist);


  return chk_return<int>(res, hand);
}


// __NR__ setresuid = 117
inline int setresuid(uid_p ruid, uid_p euid, uid_p suid, errhand_t hand = err_log)
  __attribute__((__always_inline__));


inline int setresuid(uid_p ruid, uid_p euid, uid_p suid, errhand_t hand) {
  uint64_t res = syscall3(117 , (uint64_t)ruid, (uint64_t)euid, (uint64_t)suid);


  return chk_return<int>(res, hand);
}


// __NR__ getresuid = 118
inline int getresuid(uid_p ruid, uid_p euid, uid_p suid, errhand_t hand = err_log)
  __attribute__((__always_inline__));


inline int getresuid(uid_p ruid, uid_p euid, uid_p suid, errhand_t hand) {
  uint64_t res = syscall3(118 , (uint64_t)ruid, (uint64_t)euid, (uint64_t)suid);


  return chk_return<int>(res, hand);
}


// __NR__ setresgid = 119
inline int setresgid(gid_t rgid, gid_t egid, gid_t sgid, errhand_t hand = err_log)
  __attribute__((__always_inline__));


inline int setresgid(gid_t rgid, gid_t egid, gid_t sgid, errhand_t hand) {
  uint64_t res = syscall3(119 , (uint64_t)rgid, (uint64_t)egid, (uint64_t)sgid);


  return chk_return<int>(res, hand);
}


// __NR__ getresgid = 120
inline int getresgid(gid_p rgid, gid_p egid, gid_p sgid, errhand_t hand = err_log)
  __attribute__((__always_inline__));


inline int getresgid(gid_p rgid, gid_p egid, gid_p sgid, errhand_t hand) {
  uint64_t res = syscall3(120 , (uint64_t)rgid, (uint64_t)egid, (uint64_t)sgid);


  return chk_return<int>(res, hand);
}


// __NR__ getpgid = 121
inline int getpgid(pid_t pid, errhand_t hand = err_log)
  __attribute__((__always_inline__));


inline int getpgid(pid_t pid, errhand_t hand) {
  uint64_t res = syscall1(121 , (uint64_t)pid);


  return chk_return<int>(res, hand);
}


// __NR__ setfsuid = 122
inline int setfsuid(uid_t uid, errhand_t hand = err_log)
  __attribute__((__always_inline__));


inline int setfsuid(uid_t uid, errhand_t hand) {
  uint64_t res = syscall1(122 , (uint64_t)uid);


  return chk_return<int>(res, hand);
}


// __NR__ setfsgid = 123
inline int setfsgid(gid_t gid, errhand_t hand = err_log)
  __attribute__((__always_inline__));


inline int setfsgid(gid_t gid, errhand_t hand) {
  uint64_t res = syscall1(123 , (uint64_t)gid);


  return chk_return<int>(res, hand);
}


// __NR__ getsid = 124
inline int getsid(pid_t pid, errhand_t hand = err_log)
  __attribute__((__always_inline__));


inline int getsid(pid_t pid, errhand_t hand) {
  uint64_t res = syscall1(124 , (uint64_t)pid);


  return chk_return<int>(res, hand);
}


// __NR__ capget = 125
inline int capget(cap_user_header_t header, cap_user_data_t dataptr, errhand_t hand = err_log)
  __attribute__((__always_inline__));


inline int capget(cap_user_header_t header, cap_user_data_t dataptr, errhand_t hand) {
  uint64_t res = syscall2(125 , (uint64_t)header, (uint64_t)dataptr);


  return chk_return<int>(res, hand);
}


// __NR__ capset = 126
inline int capset(cap_user_header_t header, const cap_user_data_t data, errhand_t hand = err_log)
  __attribute__((__always_inline__));


inline int capset(cap_user_header_t header, const cap_user_data_t data, errhand_t hand) {
  uint64_t res = syscall2(126 , (uint64_t)header, (uint64_t)data);


  return chk_return<int>(res, hand);
}


// __NR__ rt_sigpending = 127
inline int rt_sigpending(sigset_p set, size_t sigsetsize, errhand_t hand = err_log)
  __attribute__((__always_inline__));


inline int rt_sigpending(sigset_p set, size_t sigsetsize, errhand_t hand) {
  uint64_t res = syscall2(127 , (uint64_t)set, (uint64_t)sigsetsize);


  return chk_return<int>(res, hand);
}


// __NR__ rt_sigtimedwait = 128
inline int rt_sigtimedwait(const sigset_p uthese, siginfo_p uinfo, timespec_p uts, size_t sigsetsize, errhand_t hand = err_log)
  __attribute__((__always_inline__));


inline int rt_sigtimedwait(const sigset_p uthese, siginfo_p uinfo, timespec_p uts, size_t sigsetsize, errhand_t hand) {
  uint64_t res = syscall4(128 , (uint64_t)uthese, (uint64_t)uinfo, (uint64_t)uts, (uint64_t)sigsetsize);


  return chk_return<int>(res, hand);
}


// __NR__ rt_sigqueueinfo = 129
inline int rt_sigqueueinfo(pid_t pid, int sig, siginfo_p uinfo, errhand_t hand = err_log)
  __attribute__((__always_inline__));


inline int rt_sigqueueinfo(pid_t pid, int sig, siginfo_p uinfo, errhand_t hand) {
  uint64_t res = syscall3(129 , (uint64_t)pid, (uint64_t)sig, (uint64_t)uinfo);


  return chk_return<int>(res, hand);
}


// __NR__ rt_sigsuspend = 130
inline int rt_sigsuspend(sigset_p unewset, size_t sigsetsize, errhand_t hand = err_log)
  __attribute__((__always_inline__));


inline int rt_sigsuspend(sigset_p unewset, size_t sigsetsize, errhand_t hand) {
  uint64_t res = syscall2(130 , (uint64_t)unewset, (uint64_t)sigsetsize);


  return chk_return<int>(res, hand);
}


// __NR__ sigaltstack = 131
inline int sigaltstack(const stack_p uss, stack_p uoss, errhand_t hand = err_log)
  __attribute__((__always_inline__));


inline int sigaltstack(const stack_p uss, stack_p uoss, errhand_t hand) {
  uint64_t res = syscall2(131 , (uint64_t)uss, (uint64_t)uoss);


  return chk_return<int>(res, hand);
}


// __NR__ utime = 132
inline int utime(ostr_t path, utimbuf_p times, errhand_t hand = err_log)
  __attribute__((__always_inline__));


inline int utime(ostr_t path, utimbuf_p times, errhand_t hand) {
  uint64_t res = syscall2(132 , (uint64_t)path, (uint64_t)times);


  return chk_return<int>(res, hand);
}


// __NR__ mknod = 133
inline int mknod(istr_t path, umode_t mode, unsigned dev, errhand_t hand = err_log)
  __attribute__((__always_inline__));


inline int mknod(istr_t path, umode_t mode, unsigned dev, errhand_t hand) {
  uint64_t res = syscall3(133 , (uint64_t)path, (uint64_t)mode, (uint64_t)dev);


  return chk_return<int>(res, hand);
}


// __NR__ personality = 135
inline int personality(unsigned personality, errhand_t hand = err_log)
  __attribute__((__always_inline__));


inline int personality(unsigned personality, errhand_t hand) {
  uint64_t res = syscall1(135 , (uint64_t)personality);


  return chk_return<int>(res, hand);
}


// __NR__ ustat = 136
inline int ustat(unsigned dev, ustat_p ubuf, errhand_t hand = err_log)
  __attribute__((__always_inline__));


inline int ustat(unsigned dev, ustat_p ubuf, errhand_t hand) {
  uint64_t res = syscall2(136 , (uint64_t)dev, (uint64_t)ubuf);


  return chk_return<int>(res, hand);
}


// __NR__ statfs = 137
inline int statfs(istr_t path, statfs_p buf, errhand_t hand = err_log)
  __attribute__((__always_inline__));


inline int statfs(istr_t path, statfs_p buf, errhand_t hand) {
  uint64_t res = syscall2(137 , (uint64_t)path, (uint64_t)buf);


  return chk_return<int>(res, hand);
}


// __NR__ fstatfs = 138
inline int fstatfs(fd_t fd, statfs_p buf, errhand_t hand = err_log)
  __attribute__((__always_inline__));


inline int fstatfs(fd_t fd, statfs_p buf, errhand_t hand) {
  uint64_t res = syscall2(138 , (uint64_t)fd, (uint64_t)buf);


  return chk_return<int>(res, hand);
}


// __NR__ sysfs = 139
inline int sysfs(int option, uint64_t arg1, uint64_t arg2, errhand_t hand = err_log)
  __attribute__((__always_inline__));


inline int sysfs(int option, uint64_t arg1, uint64_t arg2, errhand_t hand) {
  uint64_t res = syscall3(139 , (uint64_t)option, (uint64_t)arg1, (uint64_t)arg2);


  return chk_return<int>(res, hand);
}


// __NR__ getpriority = 140
inline int getpriority(int which, int who, errhand_t hand = err_log)
  __attribute__((__always_inline__));


inline int getpriority(int which, int who, errhand_t hand) {
  uint64_t res = syscall2(140 , (uint64_t)which, (uint64_t)who);


  return chk_return<int>(res, hand);
}


// __NR__ setpriority = 141
inline int setpriority(int which, int who, int niceval, errhand_t hand = err_log)
  __attribute__((__always_inline__));


inline int setpriority(int which, int who, int niceval, errhand_t hand) {
  uint64_t res = syscall3(141 , (uint64_t)which, (uint64_t)who, (uint64_t)niceval);


  return chk_return<int>(res, hand);
}


// __NR__ sched_setparam = 142
inline int sched_setparam(pid_t pid, const void * param, errhand_t hand = err_log)
  __attribute__((__always_inline__));


inline int sched_setparam(pid_t pid, const void * param, errhand_t hand) {
  uint64_t res = syscall2(142 , (uint64_t)pid, (uint64_t)param);


  return chk_return<int>(res, hand);
}


// __NR__ sched_getparam = 143
inline int sched_getparam(pid_t pid, sched_param_p param, errhand_t hand = err_log)
  __attribute__((__always_inline__));


inline int sched_getparam(pid_t pid, sched_param_p param, errhand_t hand) {
  uint64_t res = syscall2(143 , (uint64_t)pid, (uint64_t)param);


  return chk_return<int>(res, hand);
}


// __NR__ sched_setscheduler = 144
inline int sched_setscheduler(pid_t pid, int policy, sched_param_p param, errhand_t hand = err_log)
  __attribute__((__always_inline__));


inline int sched_setscheduler(pid_t pid, int policy, sched_param_p param, errhand_t hand) {
  uint64_t res = syscall3(144 , (uint64_t)pid, (uint64_t)policy, (uint64_t)param);


  return chk_return<int>(res, hand);
}


// __NR__ sched_getscheduler = 145
inline int sched_getscheduler(pid_t pid, errhand_t hand = err_log)
  __attribute__((__always_inline__));


inline int sched_getscheduler(pid_t pid, errhand_t hand) {
  uint64_t res = syscall1(145 , (uint64_t)pid);


  return chk_return<int>(res, hand);
}


// __NR__ sched_get_priority_max = 146
inline int sched_get_priority_max(int policy, errhand_t hand = err_log)
  __attribute__((__always_inline__));


inline int sched_get_priority_max(int policy, errhand_t hand) {
  uint64_t res = syscall1(146 , (uint64_t)policy);


  return chk_return<int>(res, hand);
}


// __NR__ sched_get_priority_min = 147
inline int sched_get_priority_min(int policy, errhand_t hand = err_log)
  __attribute__((__always_inline__));


inline int sched_get_priority_min(int policy, errhand_t hand) {
  uint64_t res = syscall1(147 , (uint64_t)policy);


  return chk_return<int>(res, hand);
}


// __NR__ sched_rr_get_interval = 148
inline int sched_rr_get_interval(pid_t pid, timespec_p interval, errhand_t hand = err_log)
  __attribute__((__always_inline__));


inline int sched_rr_get_interval(pid_t pid, timespec_p interval, errhand_t hand) {
  uint64_t res = syscall2(148 , (uint64_t)pid, (uint64_t)interval);


  return chk_return<int>(res, hand);
}


// __NR__ mlock = 149
inline int mlock(void_p start, size_t len, errhand_t hand = err_log)
  __attribute__((__always_inline__));


inline int mlock(void_p start, size_t len, errhand_t hand) {
  uint64_t res = syscall2(149 , (uint64_t)start, (uint64_t)len);


  return chk_return<int>(res, hand);
}


// __NR__ munlock = 150
inline int munlock(void_p start, size_t len, errhand_t hand = err_log)
  __attribute__((__always_inline__));


inline int munlock(void_p start, size_t len, errhand_t hand) {
  uint64_t res = syscall2(150 , (uint64_t)start, (uint64_t)len);


  return chk_return<int>(res, hand);
}


// __NR__ mlockall = 151
inline int mlockall(int flags, errhand_t hand = err_log)
  __attribute__((__always_inline__));


inline int mlockall(int flags, errhand_t hand) {
  uint64_t res = syscall1(151 , (uint64_t)flags);


  return chk_return<int>(res, hand);
}


// __NR__ munlockall = 152
inline int munlockall(errhand_t hand = err_log)
  __attribute__((__always_inline__));


inline int munlockall(errhand_t hand) {
  uint64_t res = syscall0(152 );


  return chk_return<int>(res, hand);
}


// __NR__ vhangup = 153
inline int vhangup(errhand_t hand = err_log)
  __attribute__((__always_inline__));


inline int vhangup(errhand_t hand) {
  uint64_t res = syscall0(153 );


  return chk_return<int>(res, hand);
}


// __NR__ modify_ldt = 154
inline int modify_ldt(int func, void_p ptr, uint64_t bytecount, errhand_t hand = err_log)
  __attribute__((__always_inline__));


inline int modify_ldt(int func, void_p ptr, uint64_t bytecount, errhand_t hand) {
  uint64_t res = syscall3(154 , (uint64_t)func, (uint64_t)ptr, (uint64_t)bytecount);


  return chk_return<int>(res, hand);
}


// __NR__ pivot_root = 155
inline int pivot_root(istr_t new_root, istr_t put_old, errhand_t hand = err_log)
  __attribute__((__always_inline__));


inline int pivot_root(istr_t new_root, istr_t put_old, errhand_t hand) {
  uint64_t res = syscall2(155 , (uint64_t)new_root, (uint64_t)put_old);


  return chk_return<int>(res, hand);
}


// __NR__ _sysctl = 156
inline int _sysctl(sysctl_args_p args, errhand_t hand = err_log)
  __attribute__((__always_inline__));


inline int _sysctl(sysctl_args_p args, errhand_t hand) {
  uint64_t res = syscall1(156 , (uint64_t)args);


  return chk_return<int>(res, hand);
}


// __NR__ prctl = 157
inline int prctl(int option, uint64_t arg2, uint64_t arg3, uint64_t arg4, uint64_t arg5, errhand_t hand = err_log)
  __attribute__((__always_inline__));


inline int prctl(int option, uint64_t arg2, uint64_t arg3, uint64_t arg4, uint64_t arg5, errhand_t hand) {
  uint64_t res = syscall5(157 , (uint64_t)option, (uint64_t)arg2, (uint64_t)arg3, (uint64_t)arg4, (uint64_t)arg5);


  return chk_return<int>(res, hand);
}


// __NR__ arch_prctl = 158
inline int arch_prctl(task_struct_p task, int code, uint64_t addr, errhand_t hand = err_log)
  __attribute__((__always_inline__));


inline int arch_prctl(task_struct_p task, int code, uint64_t addr, errhand_t hand) {
  uint64_t res = syscall3(158 , (uint64_t)task, (uint64_t)code, (uint64_t)addr);


  return chk_return<int>(res, hand);
}


// __NR__ adjtimex = 159
inline int adjtimex(timex_p txc_p, errhand_t hand = err_log)
  __attribute__((__always_inline__));


inline int adjtimex(timex_p txc_p, errhand_t hand) {
  uint64_t res = syscall1(159 , (uint64_t)txc_p);


  return chk_return<int>(res, hand);
}


// __NR__ setrlimit = 160
inline int setrlimit(unsigned resource, rlimit_p rlim, errhand_t hand = err_log)
  __attribute__((__always_inline__));


inline int setrlimit(unsigned resource, rlimit_p rlim, errhand_t hand) {
  uint64_t res = syscall2(160 , (uint64_t)resource, (uint64_t)rlim);


  return chk_return<int>(res, hand);
}


// __NR__ chroot = 161
inline int chroot(istr_t path, errhand_t hand = err_log)
  __attribute__((__always_inline__));


inline int chroot(istr_t path, errhand_t hand) {
  uint64_t res = syscall1(161 , (uint64_t)path);


  return chk_return<int>(res, hand);
}


// __NR__ sync = 162
inline int sync(errhand_t hand = err_log)
  __attribute__((__always_inline__));


inline int sync(errhand_t hand) {
  uint64_t res = syscall0(162 );


  return chk_return<int>(res, hand);
}


// __NR__ acct = 163
inline int acct(istr_t name, errhand_t hand = err_log)
  __attribute__((__always_inline__));


inline int acct(istr_t name, errhand_t hand) {
  uint64_t res = syscall1(163 , (uint64_t)name);


  return chk_return<int>(res, hand);
}


// __NR__ settimeofday = 164
inline int settimeofday(timeval_p tv, timezone_p tz, errhand_t hand = err_log)
  __attribute__((__always_inline__));


inline int settimeofday(timeval_p tv, timezone_p tz, errhand_t hand) {
  uint64_t res = syscall2(164 , (uint64_t)tv, (uint64_t)tz);


  return chk_return<int>(res, hand);
}


// __NR__ mount = 165
inline int mount(ostr_t dev_name, ostr_t dir_name, ostr_t type, uint64_t flags, void_p data, errhand_t hand = err_log)
  __attribute__((__always_inline__));


inline int mount(ostr_t dev_name, ostr_t dir_name, ostr_t type, uint64_t flags, void_p data, errhand_t hand) {
  uint64_t res = syscall5(165 , (uint64_t)dev_name, (uint64_t)dir_name, (uint64_t)type, (uint64_t)flags, (uint64_t)data);


  return chk_return<int>(res, hand);
}


// __NR__ umount2 = 166
inline int umount2(istr_t target, int flags, errhand_t hand = err_log)
  __attribute__((__always_inline__));


inline int umount2(istr_t target, int flags, errhand_t hand) {
  uint64_t res = syscall2(166 , (uint64_t)target, (uint64_t)flags);


  return chk_return<int>(res, hand);
}


// __NR__ swapon = 167
inline int swapon(istr_t specialfile, int swap_flags, errhand_t hand = err_log)
  __attribute__((__always_inline__));


inline int swapon(istr_t specialfile, int swap_flags, errhand_t hand) {
  uint64_t res = syscall2(167 , (uint64_t)specialfile, (uint64_t)swap_flags);


  return chk_return<int>(res, hand);
}


// __NR__ swapoff = 168
inline int swapoff(istr_t specialfile, errhand_t hand = err_log)
  __attribute__((__always_inline__));


inline int swapoff(istr_t specialfile, errhand_t hand) {
  uint64_t res = syscall1(168 , (uint64_t)specialfile);


  return chk_return<int>(res, hand);
}


// __NR__ reboot = 169
inline int reboot(int magic1, int magic2, unsigned cmd, void_p arg, errhand_t hand = err_log)
  __attribute__((__always_inline__));


inline int reboot(int magic1, int magic2, unsigned cmd, void_p arg, errhand_t hand) {
  uint64_t res = syscall4(169 , (uint64_t)magic1, (uint64_t)magic2, (uint64_t)cmd, (uint64_t)arg);


  return chk_return<int>(res, hand);
}


// __NR__ sethostname = 170
inline int sethostname(ostr_t name, int len, errhand_t hand = err_log)
  __attribute__((__always_inline__));


inline int sethostname(ostr_t name, int len, errhand_t hand) {
  uint64_t res = syscall2(170 , (uint64_t)name, (uint64_t)len);


  return chk_return<int>(res, hand);
}


// __NR__ setdomainname = 171
inline int setdomainname(ostr_t name, int len, errhand_t hand = err_log)
  __attribute__((__always_inline__));


inline int setdomainname(ostr_t name, int len, errhand_t hand) {
  uint64_t res = syscall2(171 , (uint64_t)name, (uint64_t)len);


  return chk_return<int>(res, hand);
}


// __NR__ iopl = 172
inline int iopl(unsigned level, pt_regs_p regs, errhand_t hand = err_log)
  __attribute__((__always_inline__));


inline int iopl(unsigned level, pt_regs_p regs, errhand_t hand) {
  uint64_t res = syscall2(172 , (uint64_t)level, (uint64_t)regs);


  return chk_return<int>(res, hand);
}


// __NR__ ioperm = 173
inline int ioperm(uint64_t from, uint64_t num, int turn_on, errhand_t hand = err_log)
  __attribute__((__always_inline__));


inline int ioperm(uint64_t from, uint64_t num, int turn_on, errhand_t hand) {
  uint64_t res = syscall3(173 , (uint64_t)from, (uint64_t)num, (uint64_t)turn_on);


  return chk_return<int>(res, hand);
}


// __NR__ init_module = 175
inline int init_module(void_p umod, uint64_t len, istr_t uargs, errhand_t hand = err_log)
  __attribute__((__always_inline__));


inline int init_module(void_p umod, uint64_t len, istr_t uargs, errhand_t hand) {
  uint64_t res = syscall3(175 , (uint64_t)umod, (uint64_t)len, (uint64_t)uargs);


  return chk_return<int>(res, hand);
}


// __NR__ delete_module = 176
inline int delete_module(istr_t name_user, unsigned flags, errhand_t hand = err_log)
  __attribute__((__always_inline__));


inline int delete_module(istr_t name_user, unsigned flags, errhand_t hand) {
  uint64_t res = syscall2(176 , (uint64_t)name_user, (uint64_t)flags);


  return chk_return<int>(res, hand);
}


// __NR__ quotactl = 179
inline int quotactl(unsigned cmd, istr_t special, qid_t id, void_p addr, errhand_t hand = err_log)
  __attribute__((__always_inline__));


inline int quotactl(unsigned cmd, istr_t special, qid_t id, void_p addr, errhand_t hand) {
  uint64_t res = syscall4(179 , (uint64_t)cmd, (uint64_t)special, (uint64_t)id, (uint64_t)addr);


  return chk_return<int>(res, hand);
}


// __NR__ gettid = 186
inline int gettid(errhand_t hand = err_log)
  __attribute__((__always_inline__));


inline int gettid(errhand_t hand) {
  uint64_t res = syscall0(186 );


  return chk_return<int>(res, hand);
}


// __NR__ readahead = 187
inline int readahead(fd_t fd, off_t offset, size_t count, errhand_t hand = err_log)
  __attribute__((__always_inline__));


inline int readahead(fd_t fd, off_t offset, size_t count, errhand_t hand) {
  uint64_t res = syscall3(187 , (uint64_t)fd, (uint64_t)offset, (uint64_t)count);


  return chk_return<int>(res, hand);
}


// __NR__ setxattr = 188
inline int setxattr(istr_t path, istr_t name, const void_p value, size_t size, int flags, errhand_t hand = err_log)
  __attribute__((__always_inline__));


inline int setxattr(istr_t path, istr_t name, const void_p value, size_t size, int flags, errhand_t hand) {
  uint64_t res = syscall5(188 , (uint64_t)path, (uint64_t)name, (uint64_t)value, (uint64_t)size, (uint64_t)flags);


  return chk_return<int>(res, hand);
}


// __NR__ lsetxattr = 189
inline int lsetxattr(istr_t path, istr_t name, const void_p value, size_t size, int flags, errhand_t hand = err_log)
  __attribute__((__always_inline__));


inline int lsetxattr(istr_t path, istr_t name, const void_p value, size_t size, int flags, errhand_t hand) {
  uint64_t res = syscall5(189 , (uint64_t)path, (uint64_t)name, (uint64_t)value, (uint64_t)size, (uint64_t)flags);


  return chk_return<int>(res, hand);
}


// __NR__ fsetxattr = 190
inline int fsetxattr(fd_t fd, istr_t name, const void_p value, size_t size, int flags, errhand_t hand = err_log)
  __attribute__((__always_inline__));


inline int fsetxattr(fd_t fd, istr_t name, const void_p value, size_t size, int flags, errhand_t hand) {
  uint64_t res = syscall5(190 , (uint64_t)fd, (uint64_t)name, (uint64_t)value, (uint64_t)size, (uint64_t)flags);


  return chk_return<int>(res, hand);
}


// __NR__ getxattr = 191
inline int getxattr(istr_t path, istr_t name, void_p value, size_t size, errhand_t hand = err_log)
  __attribute__((__always_inline__));


inline int getxattr(istr_t path, istr_t name, void_p value, size_t size, errhand_t hand) {
  uint64_t res = syscall4(191 , (uint64_t)path, (uint64_t)name, (uint64_t)value, (uint64_t)size);


  return chk_return<int>(res, hand);
}


// __NR__ lgetxattr = 192
inline int lgetxattr(istr_t path, istr_t name, void_p value, size_t size, errhand_t hand = err_log)
  __attribute__((__always_inline__));


inline int lgetxattr(istr_t path, istr_t name, void_p value, size_t size, errhand_t hand) {
  uint64_t res = syscall4(192 , (uint64_t)path, (uint64_t)name, (uint64_t)value, (uint64_t)size);


  return chk_return<int>(res, hand);
}


// __NR__ fgetxattr = 193
inline int fgetxattr(fd_t fd, istr_t name, void_p value, size_t size, errhand_t hand = err_log)
  __attribute__((__always_inline__));


inline int fgetxattr(fd_t fd, istr_t name, void_p value, size_t size, errhand_t hand) {
  uint64_t res = syscall4(193 , (uint64_t)fd, (uint64_t)name, (uint64_t)value, (uint64_t)size);


  return chk_return<int>(res, hand);
}


// __NR__ listxattr = 194
inline int listxattr(istr_t path, ostr_t list, size_t size, errhand_t hand = err_log)
  __attribute__((__always_inline__));


inline int listxattr(istr_t path, ostr_t list, size_t size, errhand_t hand) {
  uint64_t res = syscall3(194 , (uint64_t)path, (uint64_t)list, (uint64_t)size);


  return chk_return<int>(res, hand);
}


// __NR__ llistxattr = 195
inline int llistxattr(istr_t path, ostr_t list, size_t size, errhand_t hand = err_log)
  __attribute__((__always_inline__));


inline int llistxattr(istr_t path, ostr_t list, size_t size, errhand_t hand) {
  uint64_t res = syscall3(195 , (uint64_t)path, (uint64_t)list, (uint64_t)size);


  return chk_return<int>(res, hand);
}


// __NR__ flistxattr = 196
inline int flistxattr(fd_t fd, ostr_t list, size_t size, errhand_t hand = err_log)
  __attribute__((__always_inline__));


inline int flistxattr(fd_t fd, ostr_t list, size_t size, errhand_t hand) {
  uint64_t res = syscall3(196 , (uint64_t)fd, (uint64_t)list, (uint64_t)size);


  return chk_return<int>(res, hand);
}


// __NR__ removexattr = 197
inline int removexattr(istr_t path, istr_t name, errhand_t hand = err_log)
  __attribute__((__always_inline__));


inline int removexattr(istr_t path, istr_t name, errhand_t hand) {
  uint64_t res = syscall2(197 , (uint64_t)path, (uint64_t)name);


  return chk_return<int>(res, hand);
}


// __NR__ lremovexattr = 198
inline int lremovexattr(istr_t path, istr_t name, errhand_t hand = err_log)
  __attribute__((__always_inline__));


inline int lremovexattr(istr_t path, istr_t name, errhand_t hand) {
  uint64_t res = syscall2(198 , (uint64_t)path, (uint64_t)name);


  return chk_return<int>(res, hand);
}


// __NR__ fremovexattr = 199
inline int fremovexattr(fd_t fd, istr_t name, errhand_t hand = err_log)
  __attribute__((__always_inline__));


inline int fremovexattr(fd_t fd, istr_t name, errhand_t hand) {
  uint64_t res = syscall2(199 , (uint64_t)fd, (uint64_t)name);


  return chk_return<int>(res, hand);
}


// __NR__ tkill = 200
inline int tkill(pid_t pid, int sig, errhand_t hand = err_log)
  __attribute__((__always_inline__));


inline int tkill(pid_t pid, int sig, errhand_t hand) {
  uint64_t res = syscall2(200 , (uint64_t)pid, (uint64_t)sig);


  return chk_return<int>(res, hand);
}


// __NR__ time = 201
inline time_t time(time_p tloc, errhand_t hand = err_log)
  __attribute__((__always_inline__));


inline time_t time(time_p tloc, errhand_t hand) {
  uint64_t res = syscall1(201 , (uint64_t)tloc);


  return chk_return<time_t>(res, hand);
}


// __NR__ futex = 202
inline int futex(uint32_p uaddr, int op, uint32_t val, timespec_p utime, uint32_p uaddr2, uint32_t val3, errhand_t hand = err_log)
  __attribute__((__always_inline__));


inline int futex(uint32_p uaddr, int op, uint32_t val, timespec_p utime, uint32_p uaddr2, uint32_t val3, errhand_t hand) {
  uint64_t res = syscall6(202 , (uint64_t)uaddr, (uint64_t)op, (uint64_t)val, (uint64_t)utime, (uint64_t)uaddr2, (uint64_t)val3);


  return chk_return<int>(res, hand);
}


// __NR__ sched_setaffinity = 203
inline int sched_setaffinity(pid_t pid, size_t len, const void * user_mask_ptr, errhand_t hand = err_log)
  __attribute__((__always_inline__));


inline int sched_setaffinity(pid_t pid, size_t len, const void * user_mask_ptr, errhand_t hand) {
  uint64_t res = syscall3(203 , (uint64_t)pid, (uint64_t)len, (uint64_t)user_mask_ptr);


  return chk_return<int>(res, hand);
}


// __NR__ sched_getaffinity = 204
inline int sched_getaffinity(pid_t pid, unsigned len, uint64_p user_mask_ptr, errhand_t hand = err_log)
  __attribute__((__always_inline__));


inline int sched_getaffinity(pid_t pid, unsigned len, uint64_p user_mask_ptr, errhand_t hand) {
  uint64_t res = syscall3(204 , (uint64_t)pid, (uint64_t)len, (uint64_t)user_mask_ptr);


  return chk_return<int>(res, hand);
}


// __NR__ lookup_dcookie = 212
inline int lookup_dcookie(uint64_t cookie64, long buf, long len, errhand_t hand = err_log)
  __attribute__((__always_inline__));


inline int lookup_dcookie(uint64_t cookie64, long buf, long len, errhand_t hand) {
  uint64_t res = syscall3(212 , (uint64_t)cookie64, (uint64_t)buf, (uint64_t)len);


  return chk_return<int>(res, hand);
}


// __NR__ epoll_create = 213
inline int epoll_create(int size, errhand_t hand = err_log)
  __attribute__((__always_inline__));


inline int epoll_create(int size, errhand_t hand) {
  uint64_t res = syscall1(213 , (uint64_t)size);


  return chk_return<int>(res, hand);
}


// __NR__ remap_file_pages = 216
inline int remap_file_pages(uint64_t start, uint64_t size, uint64_t prot, uint64_t pgoff, uint64_t flags, errhand_t hand = err_log)
  __attribute__((__always_inline__));


inline int remap_file_pages(uint64_t start, uint64_t size, uint64_t prot, uint64_t pgoff, uint64_t flags, errhand_t hand) {
  uint64_t res = syscall5(216 , (uint64_t)start, (uint64_t)size, (uint64_t)prot, (uint64_t)pgoff, (uint64_t)flags);


  return chk_return<int>(res, hand);
}


// __NR__ getdents64 = 217
inline int getdents64(fd_t fd, linux_dirent64_p dirent, unsigned count, errhand_t hand = err_log)
  __attribute__((__always_inline__));


inline int getdents64(fd_t fd, linux_dirent64_p dirent, unsigned count, errhand_t hand) {
  uint64_t res = syscall3(217 , (uint64_t)fd, (uint64_t)dirent, (uint64_t)count);


  return chk_return<int>(res, hand);
}


// __NR__ set_tid_address = 218
inline int set_tid_address(int32_p tidptr, errhand_t hand = err_log)
  __attribute__((__always_inline__));


inline int set_tid_address(int32_p tidptr, errhand_t hand) {
  uint64_t res = syscall1(218 , (uint64_t)tidptr);


  return chk_return<int>(res, hand);
}


// __NR__ restart_syscall = 219
inline int restart_syscall(errhand_t hand = err_log)
  __attribute__((__always_inline__));


inline int restart_syscall(errhand_t hand) {
  uint64_t res = syscall0(219 );


  return chk_return<int>(res, hand);
}


// __NR__ semtimedop = 220
inline int semtimedop(int semid, sembuf_p tsops, unsigned nsops, timespec_p timeout, errhand_t hand = err_log)
  __attribute__((__always_inline__));


inline int semtimedop(int semid, sembuf_p tsops, unsigned nsops, timespec_p timeout, errhand_t hand) {
  uint64_t res = syscall4(220 , (uint64_t)semid, (uint64_t)tsops, (uint64_t)nsops, (uint64_t)timeout);


  return chk_return<int>(res, hand);
}


// __NR__ fadvise64 = 221
inline int fadvise64(fd_t fd, off_t offset, size_t len, int advice, errhand_t hand = err_log)
  __attribute__((__always_inline__));


inline int fadvise64(fd_t fd, off_t offset, size_t len, int advice, errhand_t hand) {
  uint64_t res = syscall4(221 , (uint64_t)fd, (uint64_t)offset, (uint64_t)len, (uint64_t)advice);


  return chk_return<int>(res, hand);
}


// __NR__ timer_create = 222
inline int timer_create(const clockid_t which_clock, sigevent_p timer_event_spec, timer_p created_timer_id, errhand_t hand = err_log)
  __attribute__((__always_inline__));


inline int timer_create(const clockid_t which_clock, sigevent_p timer_event_spec, timer_p created_timer_id, errhand_t hand) {
  uint64_t res = syscall3(222 , (uint64_t)which_clock, (uint64_t)timer_event_spec, (uint64_t)created_timer_id);


  return chk_return<int>(res, hand);
}


// __NR__ timer_settime = 223
inline int timer_settime(timer_t timer_id, int flags, itimerspec_p new_setting, itimerspec_p old_setting, errhand_t hand = err_log)
  __attribute__((__always_inline__));


inline int timer_settime(timer_t timer_id, int flags, itimerspec_p new_setting, itimerspec_p old_setting, errhand_t hand) {
  uint64_t res = syscall4(223 , (uint64_t)timer_id, (uint64_t)flags, (uint64_t)new_setting, (uint64_t)old_setting);


  return chk_return<int>(res, hand);
}


// __NR__ timer_gettime = 224
inline int timer_gettime(timer_t timer_id, itimerspec_p setting, errhand_t hand = err_log)
  __attribute__((__always_inline__));


inline int timer_gettime(timer_t timer_id, itimerspec_p setting, errhand_t hand) {
  uint64_t res = syscall2(224 , (uint64_t)timer_id, (uint64_t)setting);


  return chk_return<int>(res, hand);
}


// __NR__ timer_getoverrun = 225
inline int timer_getoverrun(timer_t timer_id, errhand_t hand = err_log)
  __attribute__((__always_inline__));


inline int timer_getoverrun(timer_t timer_id, errhand_t hand) {
  uint64_t res = syscall1(225 , (uint64_t)timer_id);


  return chk_return<int>(res, hand);
}


// __NR__ timer_delete = 226
inline int timer_delete(timer_t timer_id, errhand_t hand = err_log)
  __attribute__((__always_inline__));


inline int timer_delete(timer_t timer_id, errhand_t hand) {
  uint64_t res = syscall1(226 , (uint64_t)timer_id);


  return chk_return<int>(res, hand);
}


// __NR__ clock_settime = 227
inline int clock_settime(const clockid_t which_clock, timespec_p tp, errhand_t hand = err_log)
  __attribute__((__always_inline__));


inline int clock_settime(const clockid_t which_clock, timespec_p tp, errhand_t hand) {
  uint64_t res = syscall2(227 , (uint64_t)which_clock, (uint64_t)tp);


  return chk_return<int>(res, hand);
}


// __NR__ clock_gettime = 228
inline int clock_gettime(const clockid_t which_clock, timespec_p tp, errhand_t hand = err_log)
  __attribute__((__always_inline__));


inline int clock_gettime(const clockid_t which_clock, timespec_p tp, errhand_t hand) {
  uint64_t res = syscall2(228 , (uint64_t)which_clock, (uint64_t)tp);


  return chk_return<int>(res, hand);
}


// __NR__ clock_getres = 229
inline int clock_getres(const clockid_t which_clock, timespec_p tp, errhand_t hand = err_log)
  __attribute__((__always_inline__));


inline int clock_getres(const clockid_t which_clock, timespec_p tp, errhand_t hand) {
  uint64_t res = syscall2(229 , (uint64_t)which_clock, (uint64_t)tp);


  return chk_return<int>(res, hand);
}


// __NR__ clock_nanosleep = 230
inline int clock_nanosleep(const clockid_t which_clock, int flags, timespec_p rqtp, timespec_p rmtp, errhand_t hand = err_log)
  __attribute__((__always_inline__));


inline int clock_nanosleep(const clockid_t which_clock, int flags, timespec_p rqtp, timespec_p rmtp, errhand_t hand) {
  uint64_t res = syscall4(230 , (uint64_t)which_clock, (uint64_t)flags, (uint64_t)rqtp, (uint64_t)rmtp);


  return chk_return<int>(res, hand);
}


// __NR__ exit_group = 231
inline int exit_group(int error_code, errhand_t hand = err_log)
  __attribute__((__always_inline__, __noreturn__));


inline int exit_group(int error_code, errhand_t hand) {
  uint64_t res = syscall1(231 , (uint64_t)error_code);


  __builtin_unreachable();
}


// __NR__ epoll_wait = 232
inline int epoll_wait(int epfd, epoll_event_p events, int maxevents, int timeout, errhand_t hand = err_log)
  __attribute__((__always_inline__));


inline int epoll_wait(int epfd, epoll_event_p events, int maxevents, int timeout, errhand_t hand) {
  uint64_t res = syscall4(232 , (uint64_t)epfd, (uint64_t)events, (uint64_t)maxevents, (uint64_t)timeout);


  return chk_return<int>(res, hand);
}


// __NR__ epoll_ctl = 233
inline int epoll_ctl(int epfd, int op, fd_t fd, epoll_event_p event, errhand_t hand = err_log)
  __attribute__((__always_inline__));


inline int epoll_ctl(int epfd, int op, fd_t fd, epoll_event_p event, errhand_t hand) {
  uint64_t res = syscall4(233 , (uint64_t)epfd, (uint64_t)op, (uint64_t)fd, (uint64_t)event);


  return chk_return<int>(res, hand);
}


// __NR__ tgkill = 234
inline int tgkill(pid_t tgid, pid_t pid, int sig, errhand_t hand = err_log)
  __attribute__((__always_inline__));


inline int tgkill(pid_t tgid, pid_t pid, int sig, errhand_t hand) {
  uint64_t res = syscall3(234 , (uint64_t)tgid, (uint64_t)pid, (uint64_t)sig);


  return chk_return<int>(res, hand);
}


// __NR__ utimes = 235
inline int utimes(ostr_t path, timeval_p utimes, errhand_t hand = err_log)
  __attribute__((__always_inline__));


inline int utimes(ostr_t path, timeval_p utimes, errhand_t hand) {
  uint64_t res = syscall2(235 , (uint64_t)path, (uint64_t)utimes);


  return chk_return<int>(res, hand);
}


// __NR__ mbind = 237
inline int mbind(uint64_t start, uint64_t len, uint64_t mode, uint64_p nmask, uint64_t maxnode, unsigned flags, errhand_t hand = err_log)
  __attribute__((__always_inline__));


inline int mbind(uint64_t start, uint64_t len, uint64_t mode, uint64_p nmask, uint64_t maxnode, unsigned flags, errhand_t hand) {
  uint64_t res = syscall6(237 , (uint64_t)start, (uint64_t)len, (uint64_t)mode, (uint64_t)nmask, (uint64_t)maxnode, (uint64_t)flags);


  return chk_return<int>(res, hand);
}


// __NR__ set_mempolicy = 238
inline int set_mempolicy(int mode, uint64_p nmask, uint64_t maxnode, errhand_t hand = err_log)
  __attribute__((__always_inline__));


inline int set_mempolicy(int mode, uint64_p nmask, uint64_t maxnode, errhand_t hand) {
  uint64_t res = syscall3(238 , (uint64_t)mode, (uint64_t)nmask, (uint64_t)maxnode);


  return chk_return<int>(res, hand);
}


// __NR__ get_mempolicy = 239
inline int get_mempolicy(int32_p policy, uint64_p nmask, uint64_t maxnode, uint64_t addr, uint64_t flags, errhand_t hand = err_log)
  __attribute__((__always_inline__));


inline int get_mempolicy(int32_p policy, uint64_p nmask, uint64_t maxnode, uint64_t addr, uint64_t flags, errhand_t hand) {
  uint64_t res = syscall5(239 , (uint64_t)policy, (uint64_t)nmask, (uint64_t)maxnode, (uint64_t)addr, (uint64_t)flags);


  return chk_return<int>(res, hand);
}


// __NR__ mq_open = 240
inline int mq_open(istr_t u_name, int oflag, mode_t mode, mq_attr_p u_attr, errhand_t hand = err_log)
  __attribute__((__always_inline__));


inline int mq_open(istr_t u_name, int oflag, mode_t mode, mq_attr_p u_attr, errhand_t hand) {
  uint64_t res = syscall4(240 , (uint64_t)u_name, (uint64_t)oflag, (uint64_t)mode, (uint64_t)u_attr);


  return chk_return<int>(res, hand);
}


// __NR__ mq_unlink = 241
inline int mq_unlink(istr_t u_name, errhand_t hand = err_log)
  __attribute__((__always_inline__));


inline int mq_unlink(istr_t u_name, errhand_t hand) {
  uint64_t res = syscall1(241 , (uint64_t)u_name);


  return chk_return<int>(res, hand);
}


// __NR__ mq_timedsend = 242
inline int mq_timedsend(mqd_t mqdes, istr_t u_msg_ptr, size_t msg_len, unsigned msg_prio, timespec_p u_abs_timeout, errhand_t hand = err_log)
  __attribute__((__always_inline__));


inline int mq_timedsend(mqd_t mqdes, istr_t u_msg_ptr, size_t msg_len, unsigned msg_prio, timespec_p u_abs_timeout, errhand_t hand) {
  uint64_t res = syscall5(242 , (uint64_t)mqdes, (uint64_t)u_msg_ptr, (uint64_t)msg_len, (uint64_t)msg_prio, (uint64_t)u_abs_timeout);


  return chk_return<int>(res, hand);
}


// __NR__ mq_timedreceive = 243
inline int mq_timedreceive(mqd_t mqdes, ostr_t u_msg_ptr, size_t msg_len, uint32_p u_msg_prio, timespec_p u_abs_timeout, errhand_t hand = err_log)
  __attribute__((__always_inline__));


inline int mq_timedreceive(mqd_t mqdes, ostr_t u_msg_ptr, size_t msg_len, uint32_p u_msg_prio, timespec_p u_abs_timeout, errhand_t hand) {
  uint64_t res = syscall5(243 , (uint64_t)mqdes, (uint64_t)u_msg_ptr, (uint64_t)msg_len, (uint64_t)u_msg_prio, (uint64_t)u_abs_timeout);


  return chk_return<int>(res, hand);
}


// __NR__ mq_notify = 244
inline int mq_notify(mqd_t mqdes, sigevent_p u_notification, errhand_t hand = err_log)
  __attribute__((__always_inline__));


inline int mq_notify(mqd_t mqdes, sigevent_p u_notification, errhand_t hand) {
  uint64_t res = syscall2(244 , (uint64_t)mqdes, (uint64_t)u_notification);


  return chk_return<int>(res, hand);
}


// __NR__ mq_getsetattr = 245
inline int mq_getsetattr(mqd_t mqdes, mq_attr_p u_mqstat, mq_attr_p u_omqstat, errhand_t hand = err_log)
  __attribute__((__always_inline__));


inline int mq_getsetattr(mqd_t mqdes, mq_attr_p u_mqstat, mq_attr_p u_omqstat, errhand_t hand) {
  uint64_t res = syscall3(245 , (uint64_t)mqdes, (uint64_t)u_mqstat, (uint64_t)u_omqstat);


  return chk_return<int>(res, hand);
}


// __NR__ kexec_load = 246
inline int kexec_load(uint64_t entry, uint64_t nr_segments, kexec_segment_p segments, uint64_t flags, errhand_t hand = err_log)
  __attribute__((__always_inline__));


inline int kexec_load(uint64_t entry, uint64_t nr_segments, kexec_segment_p segments, uint64_t flags, errhand_t hand) {
  uint64_t res = syscall4(246 , (uint64_t)entry, (uint64_t)nr_segments, (uint64_t)segments, (uint64_t)flags);


  return chk_return<int>(res, hand);
}


// __NR__ waitid = 247
inline int waitid(int which, pid_t upid, siginfo_p infop, int options, rusage_p ru, errhand_t hand = err_log)
  __attribute__((__always_inline__));


inline int waitid(int which, pid_t upid, siginfo_p infop, int options, rusage_p ru, errhand_t hand) {
  uint64_t res = syscall5(247 , (uint64_t)which, (uint64_t)upid, (uint64_t)infop, (uint64_t)options, (uint64_t)ru);


  return chk_return<int>(res, hand);
}


// __NR__ add_key = 248
inline int add_key(istr_t _type, istr_t _description, const void_p _payload, size_t plen, errhand_t hand = err_log)
  __attribute__((__always_inline__));


inline int add_key(istr_t _type, istr_t _description, const void_p _payload, size_t plen, errhand_t hand) {
  uint64_t res = syscall4(248 , (uint64_t)_type, (uint64_t)_description, (uint64_t)_payload, (uint64_t)plen);


  return chk_return<int>(res, hand);
}


// __NR__ request_key = 249
inline int request_key(istr_t _type, istr_t _description, istr_t _callout_info, uint64_t destringid, errhand_t hand = err_log)
  __attribute__((__always_inline__));


inline int request_key(istr_t _type, istr_t _description, istr_t _callout_info, uint64_t destringid, errhand_t hand) {
  uint64_t res = syscall4(249 , (uint64_t)_type, (uint64_t)_description, (uint64_t)_callout_info, (uint64_t)destringid);


  return chk_return<int>(res, hand);
}


// __NR__ keyctl = 250
inline int keyctl(int option, uint64_t arg2, uint64_t arg3, uint64_t arg4, uint64_t arg5, errhand_t hand = err_log)
  __attribute__((__always_inline__));


inline int keyctl(int option, uint64_t arg2, uint64_t arg3, uint64_t arg4, uint64_t arg5, errhand_t hand) {
  uint64_t res = syscall5(250 , (uint64_t)option, (uint64_t)arg2, (uint64_t)arg3, (uint64_t)arg4, (uint64_t)arg5);


  return chk_return<int>(res, hand);
}


// __NR__ ioprio_set = 251
inline int ioprio_set(int which, int who, int ioprio, errhand_t hand = err_log)
  __attribute__((__always_inline__));


inline int ioprio_set(int which, int who, int ioprio, errhand_t hand) {
  uint64_t res = syscall3(251 , (uint64_t)which, (uint64_t)who, (uint64_t)ioprio);


  return chk_return<int>(res, hand);
}


// __NR__ ioprio_get = 252
inline int ioprio_get(int which, int who, errhand_t hand = err_log)
  __attribute__((__always_inline__));


inline int ioprio_get(int which, int who, errhand_t hand) {
  uint64_t res = syscall2(252 , (uint64_t)which, (uint64_t)who);


  return chk_return<int>(res, hand);
}


// __NR__ inotify_init = 253
inline int inotify_init(errhand_t hand = err_log)
  __attribute__((__always_inline__));


inline int inotify_init(errhand_t hand) {
  uint64_t res = syscall0(253 );


  return chk_return<int>(res, hand);
}


// __NR__ inotify_add_watch = 254
inline int inotify_add_watch(fd_t fd, istr_t path, uint32_t mask, errhand_t hand = err_log)
  __attribute__((__always_inline__));


inline int inotify_add_watch(fd_t fd, istr_t path, uint32_t mask, errhand_t hand) {
  uint64_t res = syscall3(254 , (uint64_t)fd, (uint64_t)path, (uint64_t)mask);


  return chk_return<int>(res, hand);
}


// __NR__ inotify_rm_watch = 255
inline int inotify_rm_watch(fd_t fd, int32_t wd, errhand_t hand = err_log)
  __attribute__((__always_inline__));


inline int inotify_rm_watch(fd_t fd, int32_t wd, errhand_t hand) {
  uint64_t res = syscall2(255 , (uint64_t)fd, (uint64_t)wd);


  return chk_return<int>(res, hand);
}


// __NR__ migrate_pages = 256
inline int migrate_pages(pid_t pid, uint64_t maxnode, uint64_p old_nodes, uint64_p new_nodes, errhand_t hand = err_log)
  __attribute__((__always_inline__));


inline int migrate_pages(pid_t pid, uint64_t maxnode, uint64_p old_nodes, uint64_p new_nodes, errhand_t hand) {
  uint64_t res = syscall4(256 , (uint64_t)pid, (uint64_t)maxnode, (uint64_t)old_nodes, (uint64_t)new_nodes);


  return chk_return<int>(res, hand);
}


// __NR__ openat = 257
inline int openat(fd_t dfd, istr_t path, int flags, int mode, errhand_t hand = err_log)
  __attribute__((__always_inline__));


inline int openat(fd_t dfd, istr_t path, int flags, int mode, errhand_t hand) {
  uint64_t res = syscall4(257 , (uint64_t)dfd, (uint64_t)path, (uint64_t)flags, (uint64_t)mode);


  return chk_return<int>(res, hand);
}


// __NR__ mkdirat = 258
inline int mkdirat(fd_t dfd, istr_t path, int mode, errhand_t hand = err_log)
  __attribute__((__always_inline__));


inline int mkdirat(fd_t dfd, istr_t path, int mode, errhand_t hand) {
  uint64_t res = syscall3(258 , (uint64_t)dfd, (uint64_t)path, (uint64_t)mode);


  return chk_return<int>(res, hand);
}


// __NR__ mknodat = 259
inline int mknodat(fd_t dfd, istr_t path, int mode, unsigned dev, errhand_t hand = err_log)
  __attribute__((__always_inline__));


inline int mknodat(fd_t dfd, istr_t path, int mode, unsigned dev, errhand_t hand) {
  uint64_t res = syscall4(259 , (uint64_t)dfd, (uint64_t)path, (uint64_t)mode, (uint64_t)dev);


  return chk_return<int>(res, hand);
}


// __NR__ fchownat = 260
inline int fchownat(fd_t dfd, istr_t path, uid_t user, gid_t group, int flag, errhand_t hand = err_log)
  __attribute__((__always_inline__));


inline int fchownat(fd_t dfd, istr_t path, uid_t user, gid_t group, int flag, errhand_t hand) {
  uint64_t res = syscall5(260 , (uint64_t)dfd, (uint64_t)path, (uint64_t)user, (uint64_t)group, (uint64_t)flag);


  return chk_return<int>(res, hand);
}


// __NR__ futimesat = 261
inline int futimesat(fd_t dfd, istr_t path, timeval_p utimes, errhand_t hand = err_log)
  __attribute__((__always_inline__));


inline int futimesat(fd_t dfd, istr_t path, timeval_p utimes, errhand_t hand) {
  uint64_t res = syscall3(261 , (uint64_t)dfd, (uint64_t)path, (uint64_t)utimes);


  return chk_return<int>(res, hand);
}


// __NR__ newfstatat = 262
inline int newfstatat(fd_t dfd, istr_t path, stat_p statbuf, int flag, errhand_t hand = err_log)
  __attribute__((__always_inline__));


inline int newfstatat(fd_t dfd, istr_t path, stat_p statbuf, int flag, errhand_t hand) {
  uint64_t res = syscall4(262 , (uint64_t)dfd, (uint64_t)path, (uint64_t)statbuf, (uint64_t)flag);


  return chk_return<int>(res, hand);
}


// __NR__ unlinkat = 263
inline int unlinkat(fd_t dfd, istr_t path, int flag, errhand_t hand = err_log)
  __attribute__((__always_inline__));


inline int unlinkat(fd_t dfd, istr_t path, int flag, errhand_t hand) {
  uint64_t res = syscall3(263 , (uint64_t)dfd, (uint64_t)path, (uint64_t)flag);


  return chk_return<int>(res, hand);
}


// __NR__ renameat = 264
inline int renameat(fd_t oldfd, istr_t opath, fd_t newfd, istr_t npath, errhand_t hand = err_log)
  __attribute__((__always_inline__));


inline int renameat(fd_t oldfd, istr_t opath, fd_t newfd, istr_t npath, errhand_t hand) {
  uint64_t res = syscall4(264 , (uint64_t)oldfd, (uint64_t)opath, (uint64_t)newfd, (uint64_t)npath);


  return chk_return<int>(res, hand);
}


// __NR__ linkat = 265
inline int linkat(fd_t oldfd, istr_t opath, fd_t newfd, istr_t npath, int flags, errhand_t hand = err_log)
  __attribute__((__always_inline__));


inline int linkat(fd_t oldfd, istr_t opath, fd_t newfd, istr_t npath, int flags, errhand_t hand) {
  uint64_t res = syscall5(265 , (uint64_t)oldfd, (uint64_t)opath, (uint64_t)newfd, (uint64_t)npath, (uint64_t)flags);


  return chk_return<int>(res, hand);
}


// __NR__ symlinkat = 266
inline int symlinkat(istr_t opath, fd_t newfd, istr_t npath, errhand_t hand = err_log)
  __attribute__((__always_inline__));


inline int symlinkat(istr_t opath, fd_t newfd, istr_t npath, errhand_t hand) {
  uint64_t res = syscall3(266 , (uint64_t)opath, (uint64_t)newfd, (uint64_t)npath);


  return chk_return<int>(res, hand);
}


// __NR__ readlinkat = 267
inline int readlinkat(fd_t dfd, istr_t path, ostr_t buf, int bufsiz, errhand_t hand = err_log)
  __attribute__((__always_inline__));


inline int readlinkat(fd_t dfd, istr_t path, ostr_t buf, int bufsiz, errhand_t hand) {
  uint64_t res = syscall4(267 , (uint64_t)dfd, (uint64_t)path, (uint64_t)buf, (uint64_t)bufsiz);


  return chk_return<int>(res, hand);
}


// __NR__ fchmodat = 268
inline int fchmodat(fd_t dfd, istr_t path, mode_t mode, errhand_t hand = err_log)
  __attribute__((__always_inline__));


inline int fchmodat(fd_t dfd, istr_t path, mode_t mode, errhand_t hand) {
  uint64_t res = syscall3(268 , (uint64_t)dfd, (uint64_t)path, (uint64_t)mode);


  return chk_return<int>(res, hand);
}


// __NR__ faccessat = 269
inline int faccessat(fd_t dfd, istr_t path, int mode, errhand_t hand = err_log)
  __attribute__((__always_inline__));


inline int faccessat(fd_t dfd, istr_t path, int mode, errhand_t hand) {
  uint64_t res = syscall3(269 , (uint64_t)dfd, (uint64_t)path, (uint64_t)mode);


  return chk_return<int>(res, hand);
}


// __NR__ pselect6 = 270
inline int pselect6(int n, fdset_p inp, fdset_p outp, fdset_p exp, timespec_p tsp, void_p sig, errhand_t hand = err_log)
  __attribute__((__always_inline__));


inline int pselect6(int n, fdset_p inp, fdset_p outp, fdset_p exp, timespec_p tsp, void_p sig, errhand_t hand) {
  uint64_t res = syscall6(270 , (uint64_t)n, (uint64_t)inp, (uint64_t)outp, (uint64_t)exp, (uint64_t)tsp, (uint64_t)sig);


  return chk_return<int>(res, hand);
}


// __NR__ ppoll = 271
inline int ppoll(pollfd_p ufds, unsigned nfds, timespec_p tsp, const sigset_p sigmask, size_t sigsetsize, errhand_t hand = err_log)
  __attribute__((__always_inline__));


inline int ppoll(pollfd_p ufds, unsigned nfds, timespec_p tsp, const sigset_p sigmask, size_t sigsetsize, errhand_t hand) {
  uint64_t res = syscall5(271 , (uint64_t)ufds, (uint64_t)nfds, (uint64_t)tsp, (uint64_t)sigmask, (uint64_t)sigsetsize);


  return chk_return<int>(res, hand);
}


// __NR__ unshare = 272
inline int unshare(int unshare_flags, errhand_t hand = err_log)
  __attribute__((__always_inline__));


inline int unshare(int unshare_flags, errhand_t hand) {
  uint64_t res = syscall1(272 , (uint64_t)unshare_flags);


  return chk_return<int>(res, hand);
}


// __NR__ set_robust_list = 273
inline int set_robust_list(robust_list_head_p head, size_t len, errhand_t hand = err_log)
  __attribute__((__always_inline__));


inline int set_robust_list(robust_list_head_p head, size_t len, errhand_t hand) {
  uint64_t res = syscall2(273 , (uint64_t)head, (uint64_t)len);


  return chk_return<int>(res, hand);
}


// __NR__ get_robust_list = 274
inline int get_robust_list(int pid, robust_list_head_p head_ptr, size_p len_ptr, errhand_t hand = err_log)
  __attribute__((__always_inline__));


inline int get_robust_list(int pid, robust_list_head_p head_ptr, size_p len_ptr, errhand_t hand) {
  uint64_t res = syscall3(274 , (uint64_t)pid, (uint64_t)head_ptr, (uint64_t)len_ptr);


  return chk_return<int>(res, hand);
}


// __NR__ splice = 275
inline int splice(int fd_in, off_p off_in, int fd_out, off_p off_out, size_t len, unsigned flags, errhand_t hand = err_log)
  __attribute__((__always_inline__));


inline int splice(int fd_in, off_p off_in, int fd_out, off_p off_out, size_t len, unsigned flags, errhand_t hand) {
  uint64_t res = syscall6(275 , (uint64_t)fd_in, (uint64_t)off_in, (uint64_t)fd_out, (uint64_t)off_out, (uint64_t)len, (uint64_t)flags);


  return chk_return<int>(res, hand);
}


// __NR__ tee = 276
inline int tee(int fdin, int fdout, size_t len, unsigned flags, errhand_t hand = err_log)
  __attribute__((__always_inline__));


inline int tee(int fdin, int fdout, size_t len, unsigned flags, errhand_t hand) {
  uint64_t res = syscall4(276 , (uint64_t)fdin, (uint64_t)fdout, (uint64_t)len, (uint64_t)flags);


  return chk_return<int>(res, hand);
}


// __NR__ sync_file_range = 277
inline int sync_file_range(fd_t fd, off_t offset, off_t bytes, long flags, errhand_t hand = err_log)
  __attribute__((__always_inline__));


inline int sync_file_range(fd_t fd, off_t offset, off_t bytes, long flags, errhand_t hand) {
  uint64_t res = syscall4(277 , (uint64_t)fd, (uint64_t)offset, (uint64_t)bytes, (uint64_t)flags);


  return chk_return<int>(res, hand);
}


// __NR__ vmsplice = 278
inline int vmsplice(fd_t fd, iovec_p iov, uint64_t nr_segs, unsigned flags, errhand_t hand = err_log)
  __attribute__((__always_inline__));


inline int vmsplice(fd_t fd, iovec_p iov, uint64_t nr_segs, unsigned flags, errhand_t hand) {
  uint64_t res = syscall4(278 , (uint64_t)fd, (uint64_t)iov, (uint64_t)nr_segs, (uint64_t)flags);


  return chk_return<int>(res, hand);
}


// __NR__ move_pages = 279
inline int move_pages(pid_t pid, uint64_t nr_pages, void_p pages, int32_p nodes, int32_p status, int flags, errhand_t hand = err_log)
  __attribute__((__always_inline__));


inline int move_pages(pid_t pid, uint64_t nr_pages, void_p pages, int32_p nodes, int32_p status, int flags, errhand_t hand) {
  uint64_t res = syscall6(279 , (uint64_t)pid, (uint64_t)nr_pages, (uint64_t)pages, (uint64_t)nodes, (uint64_t)status, (uint64_t)flags);


  return chk_return<int>(res, hand);
}


// __NR__ utimensat = 280
inline int utimensat(fd_t dfd, istr_t path, timespec_p utimes, int flags, errhand_t hand = err_log)
  __attribute__((__always_inline__));


inline int utimensat(fd_t dfd, istr_t path, timespec_p utimes, int flags, errhand_t hand) {
  uint64_t res = syscall4(280 , (uint64_t)dfd, (uint64_t)path, (uint64_t)utimes, (uint64_t)flags);


  return chk_return<int>(res, hand);
}


// __NR__ epoll_pwait = 281
inline int epoll_pwait(int epfd, epoll_event_p events, int maxevents, int timeout, const sigset_p sigmask, size_t sigsetsize, errhand_t hand = err_log)
  __attribute__((__always_inline__));


inline int epoll_pwait(int epfd, epoll_event_p events, int maxevents, int timeout, const sigset_p sigmask, size_t sigsetsize, errhand_t hand) {
  uint64_t res = syscall6(281 , (uint64_t)epfd, (uint64_t)events, (uint64_t)maxevents, (uint64_t)timeout, (uint64_t)sigmask, (uint64_t)sigsetsize);


  return chk_return<int>(res, hand);
}


// __NR__ signalfd = 282
inline int signalfd(int ufd, sigset_p user_mask, size_t sizemask, errhand_t hand = err_log)
  __attribute__((__always_inline__));


inline int signalfd(int ufd, sigset_p user_mask, size_t sizemask, errhand_t hand) {
  uint64_t res = syscall3(282 , (uint64_t)ufd, (uint64_t)user_mask, (uint64_t)sizemask);


  return chk_return<int>(res, hand);
}


// __NR__ timerfd_create = 283
inline int timerfd_create(int clockid, int flags, errhand_t hand = err_log)
  __attribute__((__always_inline__));


inline int timerfd_create(int clockid, int flags, errhand_t hand) {
  uint64_t res = syscall2(283 , (uint64_t)clockid, (uint64_t)flags);


  return chk_return<int>(res, hand);
}


// __NR__ eventfd = 284
inline int eventfd(unsigned count, errhand_t hand = err_log)
  __attribute__((__always_inline__));


inline int eventfd(unsigned count, errhand_t hand) {
  uint64_t res = syscall1(284 , (uint64_t)count);


  return chk_return<int>(res, hand);
}


// __NR__ fallocate = 285
inline int fallocate(fd_t fd, long mode, off_t offset, off_t len, errhand_t hand = err_log)
  __attribute__((__always_inline__));


inline int fallocate(fd_t fd, long mode, off_t offset, off_t len, errhand_t hand) {
  uint64_t res = syscall4(285 , (uint64_t)fd, (uint64_t)mode, (uint64_t)offset, (uint64_t)len);


  return chk_return<int>(res, hand);
}


// __NR__ timerfd_settime = 286
inline int timerfd_settime(int ufd, int flags, itimerspec_p utmr, itimerspec_p otmr, errhand_t hand = err_log)
  __attribute__((__always_inline__));


inline int timerfd_settime(int ufd, int flags, itimerspec_p utmr, itimerspec_p otmr, errhand_t hand) {
  uint64_t res = syscall4(286 , (uint64_t)ufd, (uint64_t)flags, (uint64_t)utmr, (uint64_t)otmr);


  return chk_return<int>(res, hand);
}


// __NR__ timerfd_gettime = 287
inline int timerfd_gettime(int ufd, itimerspec_p otmr, errhand_t hand = err_log)
  __attribute__((__always_inline__));


inline int timerfd_gettime(int ufd, itimerspec_p otmr, errhand_t hand) {
  uint64_t res = syscall2(287 , (uint64_t)ufd, (uint64_t)otmr);


  return chk_return<int>(res, hand);
}


// __NR__ accept4 = 288
inline int accept4(fd_t fd, sockaddr_p upeer_sockaddr, int32_p upeer_addrlen, int flags, errhand_t hand = err_log)
  __attribute__((__always_inline__));


inline int accept4(fd_t fd, sockaddr_p upeer_sockaddr, int32_p upeer_addrlen, int flags, errhand_t hand) {
  uint64_t res = syscall4(288 , (uint64_t)fd, (uint64_t)upeer_sockaddr, (uint64_t)upeer_addrlen, (uint64_t)flags);


  return chk_return<int>(res, hand);
}


// __NR__ signalfd4 = 289
inline int signalfd4(int ufd, sigset_p user_mask, size_t sizemask, int flags, errhand_t hand = err_log)
  __attribute__((__always_inline__));


inline int signalfd4(int ufd, sigset_p user_mask, size_t sizemask, int flags, errhand_t hand) {
  uint64_t res = syscall4(289 , (uint64_t)ufd, (uint64_t)user_mask, (uint64_t)sizemask, (uint64_t)flags);


  return chk_return<int>(res, hand);
}


// __NR__ eventfd2 = 290
inline int eventfd2(unsigned count, int flags, errhand_t hand = err_log)
  __attribute__((__always_inline__));


inline int eventfd2(unsigned count, int flags, errhand_t hand) {
  uint64_t res = syscall2(290 , (uint64_t)count, (uint64_t)flags);


  return chk_return<int>(res, hand);
}


// __NR__ epoll_create1 = 291
inline int epoll_create1(int flags, errhand_t hand = err_log)
  __attribute__((__always_inline__));


inline int epoll_create1(int flags, errhand_t hand) {
  uint64_t res = syscall1(291 , (uint64_t)flags);


  return chk_return<int>(res, hand);
}


// __NR__ dup3 = 292
inline int dup3(fd_t oldfd, fd_t newfd, int flags, errhand_t hand = err_log)
  __attribute__((__always_inline__));


inline int dup3(fd_t oldfd, fd_t newfd, int flags, errhand_t hand) {
  uint64_t res = syscall3(292 , (uint64_t)oldfd, (uint64_t)newfd, (uint64_t)flags);


  return chk_return<int>(res, hand);
}


// __NR__ pipe2 = 293
inline int pipe2(fd_p filedes, int flags, errhand_t hand = err_log)
  __attribute__((__always_inline__));


inline int pipe2(fd_p filedes, int flags, errhand_t hand) {
  uint64_t res = syscall2(293 , (uint64_t)filedes, (uint64_t)flags);


  return chk_return<int>(res, hand);
}


// __NR__ inotify_init1 = 294
inline int inotify_init1(int flags, errhand_t hand = err_log)
  __attribute__((__always_inline__));


inline int inotify_init1(int flags, errhand_t hand) {
  uint64_t res = syscall1(294 , (uint64_t)flags);


  return chk_return<int>(res, hand);
}


// __NR__ preadv = 295
inline int preadv(fd_t fd, iovec_p vec, uint64_t vlen, uint64_t pos_l, uint64_t pos_h, errhand_t hand = err_log)
  __attribute__((__always_inline__));


inline int preadv(fd_t fd, iovec_p vec, uint64_t vlen, uint64_t pos_l, uint64_t pos_h, errhand_t hand) {
  uint64_t res = syscall5(295 , (uint64_t)fd, (uint64_t)vec, (uint64_t)vlen, (uint64_t)pos_l, (uint64_t)pos_h);


  return chk_return<int>(res, hand);
}


// __NR__ pwritev = 296
inline int pwritev(fd_t fd, iovec_p vec, uint64_t vlen, uint64_t pos_l, uint64_t pos_h, errhand_t hand = err_log)
  __attribute__((__always_inline__));


inline int pwritev(fd_t fd, iovec_p vec, uint64_t vlen, uint64_t pos_l, uint64_t pos_h, errhand_t hand) {
  uint64_t res = syscall5(296 , (uint64_t)fd, (uint64_t)vec, (uint64_t)vlen, (uint64_t)pos_l, (uint64_t)pos_h);


  return chk_return<int>(res, hand);
}


// __NR__ rt_tgsigqueueinfo = 297
inline int rt_tgsigqueueinfo(pid_t tgid, pid_t pid, int sig, siginfo_p uinfo, errhand_t hand = err_log)
  __attribute__((__always_inline__));


inline int rt_tgsigqueueinfo(pid_t tgid, pid_t pid, int sig, siginfo_p uinfo, errhand_t hand) {
  uint64_t res = syscall4(297 , (uint64_t)tgid, (uint64_t)pid, (uint64_t)sig, (uint64_t)uinfo);


  return chk_return<int>(res, hand);
}


// __NR__ perf_event_open = 298
inline int perf_event_open(perf_event_attr_p attr_uptr, pid_t pid, int cpu, int group_fd, uint64_t flags, errhand_t hand = err_log)
  __attribute__((__always_inline__));


inline int perf_event_open(perf_event_attr_p attr_uptr, pid_t pid, int cpu, int group_fd, uint64_t flags, errhand_t hand) {
  uint64_t res = syscall5(298 , (uint64_t)attr_uptr, (uint64_t)pid, (uint64_t)cpu, (uint64_t)group_fd, (uint64_t)flags);


  return chk_return<int>(res, hand);
}


// __NR__ recvmmsg = 299
inline int recvmmsg(fd_t fd, msghdr_p mmsg, unsigned vlen, unsigned flags, timespec_p timeout, errhand_t hand = err_log)
  __attribute__((__always_inline__));


inline int recvmmsg(fd_t fd, msghdr_p mmsg, unsigned vlen, unsigned flags, timespec_p timeout, errhand_t hand) {
  uint64_t res = syscall5(299 , (uint64_t)fd, (uint64_t)mmsg, (uint64_t)vlen, (uint64_t)flags, (uint64_t)timeout);


  return chk_return<int>(res, hand);
}


// __NR__ fanotify_init = 300
inline int fanotify_init(unsigned flags, unsigned event_f_flags, errhand_t hand = err_log)
  __attribute__((__always_inline__));


inline int fanotify_init(unsigned flags, unsigned event_f_flags, errhand_t hand) {
  uint64_t res = syscall2(300 , (uint64_t)flags, (uint64_t)event_f_flags);


  return chk_return<int>(res, hand);
}


// __NR__ fanotify_mark = 301
inline int fanotify_mark(long fanotify_fd, long flags, uint64_t mask, fd_t dfd, istr_t path, errhand_t hand = err_log)
  __attribute__((__always_inline__));


inline int fanotify_mark(long fanotify_fd, long flags, uint64_t mask, fd_t dfd, istr_t path, errhand_t hand) {
  uint64_t res = syscall5(301 , (uint64_t)fanotify_fd, (uint64_t)flags, (uint64_t)mask, (uint64_t)dfd, (uint64_t)path);


  return chk_return<int>(res, hand);
}


// __NR__ prlimit64 = 302
inline int prlimit64(pid_t pid, unsigned resource, rlimit64_p new_rlim, rlimit64_p old_rlim, errhand_t hand = err_log)
  __attribute__((__always_inline__));


inline int prlimit64(pid_t pid, unsigned resource, rlimit64_p new_rlim, rlimit64_p old_rlim, errhand_t hand) {
  uint64_t res = syscall4(302 , (uint64_t)pid, (uint64_t)resource, (uint64_t)new_rlim, (uint64_t)old_rlim);


  return chk_return<int>(res, hand);
}


// __NR__ name_to_handle_at = 303
inline int name_to_handle_at(fd_t dfd, istr_t name, file_handle_p handle, int32_p mnt_id, int flag, errhand_t hand = err_log)
  __attribute__((__always_inline__));


inline int name_to_handle_at(fd_t dfd, istr_t name, file_handle_p handle, int32_p mnt_id, int flag, errhand_t hand) {
  uint64_t res = syscall5(303 , (uint64_t)dfd, (uint64_t)name, (uint64_t)handle, (uint64_t)mnt_id, (uint64_t)flag);


  return chk_return<int>(res, hand);
}


// __NR__ open_by_handle_at = 304
inline int open_by_handle_at(fd_t dfd, istr_t name, file_handle_p handle, int32_p mnt_id, int flags, errhand_t hand = err_log)
  __attribute__((__always_inline__));


inline int open_by_handle_at(fd_t dfd, istr_t name, file_handle_p handle, int32_p mnt_id, int flags, errhand_t hand) {
  uint64_t res = syscall5(304 , (uint64_t)dfd, (uint64_t)name, (uint64_t)handle, (uint64_t)mnt_id, (uint64_t)flags);


  return chk_return<int>(res, hand);
}


// __NR__ clock_adjtime = 305
inline int clock_adjtime(clockid_t which_clock, timex_p tx, errhand_t hand = err_log)
  __attribute__((__always_inline__));


inline int clock_adjtime(clockid_t which_clock, timex_p tx, errhand_t hand) {
  uint64_t res = syscall2(305 , (uint64_t)which_clock, (uint64_t)tx);


  return chk_return<int>(res, hand);
}


// __NR__ syncfs = 306
inline int syncfs(fd_t fd, errhand_t hand = err_log)
  __attribute__((__always_inline__));


inline int syncfs(fd_t fd, errhand_t hand) {
  uint64_t res = syscall1(306 , (uint64_t)fd);


  return chk_return<int>(res, hand);
}


// __NR__ sendmmsg = 307
inline int sendmmsg(fd_t fd, msghdr_p mmsg, unsigned vlen, unsigned flags, errhand_t hand = err_log)
  __attribute__((__always_inline__));


inline int sendmmsg(fd_t fd, msghdr_p mmsg, unsigned vlen, unsigned flags, errhand_t hand) {
  uint64_t res = syscall4(307 , (uint64_t)fd, (uint64_t)mmsg, (uint64_t)vlen, (uint64_t)flags);


  return chk_return<int>(res, hand);
}


// __NR__ setns = 308
inline int setns(fd_t fd, int nstype, errhand_t hand = err_log)
  __attribute__((__always_inline__));


inline int setns(fd_t fd, int nstype, errhand_t hand) {
  uint64_t res = syscall2(308 , (uint64_t)fd, (uint64_t)nstype);


  return chk_return<int>(res, hand);
}


// __NR__ getcpu = 309
inline int getcpu(uint32_p cpup, uint32_p nodep, errhand_t hand = err_log)
  __attribute__((__always_inline__));


inline int getcpu(uint32_p cpup, uint32_p nodep, errhand_t hand) {
  uint64_t res = syscall2(309 , (uint64_t)cpup, (uint64_t)nodep);


  return chk_return<int>(res, hand);
}


// __NR__ process_vm_readv = 310
inline int process_vm_readv(pid_t pid, iovec_p lvec, uint64_t liovcnt, iovec_p rvec, uint64_t riovcnt, uint64_t flags, errhand_t hand = err_log)
  __attribute__((__always_inline__));


inline int process_vm_readv(pid_t pid, iovec_p lvec, uint64_t liovcnt, iovec_p rvec, uint64_t riovcnt, uint64_t flags, errhand_t hand) {
  uint64_t res = syscall6(310 , (uint64_t)pid, (uint64_t)lvec, (uint64_t)liovcnt, (uint64_t)rvec, (uint64_t)riovcnt, (uint64_t)flags);


  return chk_return<int>(res, hand);
}


// __NR__ process_vm_writev = 311
inline int process_vm_writev(pid_t pid, iovec_p lvec, uint64_t liovcnt, iovec_p rvec, uint64_t riovcnt, uint64_t flags, errhand_t hand = err_log)
  __attribute__((__always_inline__));


inline int process_vm_writev(pid_t pid, iovec_p lvec, uint64_t liovcnt, iovec_p rvec, uint64_t riovcnt, uint64_t flags, errhand_t hand) {
  uint64_t res = syscall6(311 , (uint64_t)pid, (uint64_t)lvec, (uint64_t)liovcnt, (uint64_t)rvec, (uint64_t)riovcnt, (uint64_t)flags);


  return chk_return<int>(res, hand);
}


// __NR__ kcmp = 312
inline int kcmp(pid_t pid1, pid_t pid2, int type, uint64_t idx1, uint64_t idx2, errhand_t hand = err_log)
  __attribute__((__always_inline__));


inline int kcmp(pid_t pid1, pid_t pid2, int type, uint64_t idx1, uint64_t idx2, errhand_t hand) {
  uint64_t res = syscall5(312 , (uint64_t)pid1, (uint64_t)pid2, (uint64_t)type, (uint64_t)idx1, (uint64_t)idx2);


  return chk_return<int>(res, hand);
}


// __NR__ finit_module = 313
inline int finit_module(fd_t fd, istr_t uargs, int flags, errhand_t hand = err_log)
  __attribute__((__always_inline__));


inline int finit_module(fd_t fd, istr_t uargs, int flags, errhand_t hand) {
  uint64_t res = syscall3(313 , (uint64_t)fd, (uint64_t)uargs, (uint64_t)flags);


  return chk_return<int>(res, hand);
}


// __NR__ sched_setattr = 314
inline int sched_setattr(pid_t pid, sched_attr_p attr, unsigned flags, errhand_t hand = err_log)
  __attribute__((__always_inline__));


inline int sched_setattr(pid_t pid, sched_attr_p attr, unsigned flags, errhand_t hand) {
  uint64_t res = syscall3(314 , (uint64_t)pid, (uint64_t)attr, (uint64_t)flags);


  return chk_return<int>(res, hand);
}


// __NR__ sched_getattr = 315
inline int sched_getattr(pid_t pid, sched_attr_p attr, unsigned size, unsigned flags, errhand_t hand = err_log)
  __attribute__((__always_inline__));


inline int sched_getattr(pid_t pid, sched_attr_p attr, unsigned size, unsigned flags, errhand_t hand) {
  uint64_t res = syscall4(315 , (uint64_t)pid, (uint64_t)attr, (uint64_t)size, (uint64_t)flags);


  return chk_return<int>(res, hand);
}


// __NR__ renameat2 = 316
inline int renameat2(int olddfd, istr_t opath, int newdfd, istr_t npath, unsigned flags, errhand_t hand = err_log)
  __attribute__((__always_inline__));


inline int renameat2(int olddfd, istr_t opath, int newdfd, istr_t npath, unsigned flags, errhand_t hand) {
  uint64_t res = syscall5(316 , (uint64_t)olddfd, (uint64_t)opath, (uint64_t)newdfd, (uint64_t)npath, (uint64_t)flags);


  return chk_return<int>(res, hand);
}


// __NR__ seccomp = 317
inline int seccomp(unsigned op, unsigned flags, istr_t uargs, errhand_t hand = err_log)
  __attribute__((__always_inline__));


inline int seccomp(unsigned op, unsigned flags, istr_t uargs, errhand_t hand) {
  uint64_t res = syscall3(317 , (uint64_t)op, (uint64_t)flags, (uint64_t)uargs);


  return chk_return<int>(res, hand);
}


// __NR__ getrandom = 318
inline int getrandom(ostr_t buf, size_t count, unsigned flags, errhand_t hand = err_log)
  __attribute__((__always_inline__));


inline int getrandom(ostr_t buf, size_t count, unsigned flags, errhand_t hand) {
  uint64_t res = syscall3(318 , (uint64_t)buf, (uint64_t)count, (uint64_t)flags);


  return chk_return<int>(res, hand);
}


// __NR__ memfd_create = 319
inline int memfd_create(istr_t uname_ptr, unsigned flags, errhand_t hand = err_log)
  __attribute__((__always_inline__));


inline int memfd_create(istr_t uname_ptr, unsigned flags, errhand_t hand) {
  uint64_t res = syscall2(319 , (uint64_t)uname_ptr, (uint64_t)flags);


  return chk_return<int>(res, hand);
}


// __NR__ kexec_file_load = 320
inline int kexec_file_load(int kernel_fd, int initrd_fd, size_t cmdline_len, istr_t cmdline_ptr, uint64_t flags, errhand_t hand = err_log)
  __attribute__((__always_inline__));


inline int kexec_file_load(int kernel_fd, int initrd_fd, size_t cmdline_len, istr_t cmdline_ptr, uint64_t flags, errhand_t hand) {
  uint64_t res = syscall5(320 , (uint64_t)kernel_fd, (uint64_t)initrd_fd, (uint64_t)cmdline_len, (uint64_t)cmdline_ptr, (uint64_t)flags);


  return chk_return<int>(res, hand);
}


// __NR__ bpf = 321
inline int bpf(int cmd, bpf_attr_p attr, unsigned size, errhand_t hand = err_log)
  __attribute__((__always_inline__));


inline int bpf(int cmd, bpf_attr_p attr, unsigned size, errhand_t hand) {
  uint64_t res = syscall3(321 , (uint64_t)cmd, (uint64_t)attr, (uint64_t)size);


  return chk_return<int>(res, hand);
}


// __NR__ execveat = 322
inline int execveat(fd_t dfd, istr_t path, istr_v argv, istr_v envp, int flags, errhand_t hand = err_log)
  __attribute__((__always_inline__));


inline int execveat(fd_t dfd, istr_t path, istr_v argv, istr_v envp, int flags, errhand_t hand) {
  uint64_t res = syscall5(322 , (uint64_t)dfd, (uint64_t)path, (uint64_t)argv, (uint64_t)envp, (uint64_t)flags);


  return chk_return<int>(res, hand);
}


// __NR__ userfaultfd = 323
inline int userfaultfd(int flags, errhand_t hand = err_log)
  __attribute__((__always_inline__));


inline int userfaultfd(int flags, errhand_t hand) {
  uint64_t res = syscall1(323 , (uint64_t)flags);


  return chk_return<int>(res, hand);
}


// __NR__ membarrier = 324
inline int membarrier(int cmd, int flags, errhand_t hand = err_log)
  __attribute__((__always_inline__));


inline int membarrier(int cmd, int flags, errhand_t hand) {
  uint64_t res = syscall2(324 , (uint64_t)cmd, (uint64_t)flags);


  return chk_return<int>(res, hand);
}


// __NR__ mlock2 = 325
inline int mlock2(uint64_t start, size_t len, int flags, errhand_t hand = err_log)
  __attribute__((__always_inline__));


inline int mlock2(uint64_t start, size_t len, int flags, errhand_t hand) {
  uint64_t res = syscall3(325 , (uint64_t)start, (uint64_t)len, (uint64_t)flags);


  return chk_return<int>(res, hand);
}


// __NR__ copy_file_range = 326
inline int copy_file_range(fd_t fd_in, off_p off_in, fd_t fd_out, off_p off_out, size_t len, unsigned flags, errhand_t hand = err_log)
  __attribute__((__always_inline__));


inline int copy_file_range(fd_t fd_in, off_p off_in, fd_t fd_out, off_p off_out, size_t len, unsigned flags, errhand_t hand) {
  uint64_t res = syscall6(326 , (uint64_t)fd_in, (uint64_t)off_in, (uint64_t)fd_out, (uint64_t)off_out, (uint64_t)len, (uint64_t)flags);


  return chk_return<int>(res, hand);
}


// __NR__ preadv2 = 327
inline int preadv2(fd_t fd, iovec_p vec, uint64_t vlen, uint64_t pos_l, uint64_t pos_h, int flags, errhand_t hand = err_log)
  __attribute__((__always_inline__));


inline int preadv2(fd_t fd, iovec_p vec, uint64_t vlen, uint64_t pos_l, uint64_t pos_h, int flags, errhand_t hand) {
  uint64_t res = syscall6(327 , (uint64_t)fd, (uint64_t)vec, (uint64_t)vlen, (uint64_t)pos_l, (uint64_t)pos_h, (uint64_t)flags);


  return chk_return<int>(res, hand);
}


// __NR__ pwritev2 = 328
inline int pwritev2(fd_t fd, iovec_p vec, uint64_t vlen, uint64_t pos_l, uint64_t pos_h, int flags, errhand_t hand = err_log)
  __attribute__((__always_inline__));


inline int pwritev2(fd_t fd, iovec_p vec, uint64_t vlen, uint64_t pos_l, uint64_t pos_h, int flags, errhand_t hand) {
  uint64_t res = syscall6(328 , (uint64_t)fd, (uint64_t)vec, (uint64_t)vlen, (uint64_t)pos_l, (uint64_t)pos_h, (uint64_t)flags);


  return chk_return<int>(res, hand);
}

} // namespace sys

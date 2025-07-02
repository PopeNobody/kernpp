#file scr/genheaders.pl
#line 16
extern "C" {



  // __NR__ read = 0
  inline ssize_t read(fd_t fd, ostr_t buf, size_t count, errhand_t hand = err_log )
      __attribute__((__always_inline__));

  inline ssize_t read(fd_t fd, ostr_t buf, size_t count, errhand_t hand) {
    uint64_t res = 0xfeebdaed;
    asm("\tsyscall;\n"
        : "=a"(res)
        : "0"(0), "D"(fd), "S"(buf), "d"(count)
        : "rcx", "r11", "memory");
    return chk_return<ssize_t>(res, hand);
  }






  // __NR__ write = 1
  inline ssize_t sys_write(fd_t fd, istr_t buf, size_t count, errhand_t hand = err_log )
      __attribute__((__always_inline__));

  inline ssize_t sys_write(fd_t fd, istr_t buf, size_t count, errhand_t hand) {
    uint64_t res = 0xfeebdaed;
    asm("\tsyscall;\n"
        : "=a"(res)
        : "0"(1), "D"(fd), "S"(buf), "d"(count)
        : "rcx", "r11", "memory");
    return chk_return<ssize_t>(res, hand);
  }






  // __NR__ open = 2
  inline fd_t open(istr_t path, int flags, int mode, errhand_t hand = err_log )
      __attribute__((__always_inline__));

  inline fd_t open(istr_t path, int flags, int mode, errhand_t hand) {
    uint64_t res = 0xfeebdaed;
    asm("\tsyscall;\n"
        : "=a"(res)
        : "0"(2), "D"(path), "S"(flags), "d"(mode)
        : "rcx", "r11", "memory");
    return chk_return<fd_t>(res, hand);
  }






  // __NR__ close = 3
  inline int close(fd_t fd, errhand_t hand = err_log )
      __attribute__((__always_inline__));

  inline int close(fd_t fd, errhand_t hand) {
    uint64_t res = 0xfeebdaed;
    asm("\tsyscall;\n"
        : "=a"(res)
        : "0"(3), "D"(fd)
        : "rcx", "r11", "memory");
    return chk_return<int>(res, hand);
  }






  // __NR__ stat = 4
  inline int stat(istr_t path, stat_p statbuf, errhand_t hand = err_log )
      __attribute__((__always_inline__));

  inline int stat(istr_t path, stat_p statbuf, errhand_t hand) {
    uint64_t res = 0xfeebdaed;
    asm("\tsyscall;\n"
        : "=a"(res)
        : "0"(4), "D"(path), "S"(statbuf)
        : "rcx", "r11", "memory");
    return chk_return<int>(res, hand);
  }






  // __NR__ fstat = 5
  inline int fstat(fd_t fd, stat_p statbuf, errhand_t hand = err_log )
      __attribute__((__always_inline__));

  inline int fstat(fd_t fd, stat_p statbuf, errhand_t hand) {
    uint64_t res = 0xfeebdaed;
    asm("\tsyscall;\n"
        : "=a"(res)
        : "0"(5), "D"(fd), "S"(statbuf)
        : "rcx", "r11", "memory");
    return chk_return<int>(res, hand);
  }






  // __NR__ lstat = 6
  inline int lstat(istr_t path, stat_p statbuf, errhand_t hand = err_log )
      __attribute__((__always_inline__));

  inline int lstat(istr_t path, stat_p statbuf, errhand_t hand) {
    uint64_t res = 0xfeebdaed;
    asm("\tsyscall;\n"
        : "=a"(res)
        : "0"(6), "D"(path), "S"(statbuf)
        : "rcx", "r11", "memory");
    return chk_return<int>(res, hand);
  }






  // __NR__ poll = 7
  inline int poll(pollfd_p ufds, unsigned nfds, long timeout_msecs, errhand_t hand = err_log )
      __attribute__((__always_inline__));

  inline int poll(pollfd_p ufds, unsigned nfds, long timeout_msecs, errhand_t hand) {
    uint64_t res = 0xfeebdaed;
    asm("\tsyscall;\n"
        : "=a"(res)
        : "0"(7), "D"(ufds), "S"(nfds), "d"(timeout_msecs)
        : "rcx", "r11", "memory");
    return chk_return<int>(res, hand);
  }






  // __NR__ lseek = 8
  inline int lseek(fd_t fd, off_t offset, unsigned origin, errhand_t hand = err_log )
      __attribute__((__always_inline__));

  inline int lseek(fd_t fd, off_t offset, unsigned origin, errhand_t hand) {
    uint64_t res = 0xfeebdaed;
    asm("\tsyscall;\n"
        : "=a"(res)
        : "0"(8), "D"(fd), "S"(offset), "d"(origin)
        : "rcx", "r11", "memory");
    return chk_return<int>(res, hand);
  }






  // __NR__ mmap = 9
  inline char* mmap(void* addr, size_t len, int prot, int flags, fd_t fd, off_t off, errhand_t hand = err_log )
      __attribute__((__always_inline__));

  inline char* mmap(void* addr, size_t len, int prot, int flags, fd_t fd, off_t off, errhand_t hand) {
    uint64_t res = 0xfeebdaed;
    asm("\tsyscall;\n"
        : "=a"(res)
        : "0"(9), "D"(addr), "S"(len), "d"(prot), "r10"(flags), "r8"(fd), "r9"(off)
        : "rcx", "r11", "memory");
    return chk_return<char*>(res, hand);
  }






  // __NR__ mprotect = 10
  inline int mprotect(uint64_t start, size_t len, uint64_t prot, errhand_t hand = err_log )
      __attribute__((__always_inline__));

  inline int mprotect(uint64_t start, size_t len, uint64_t prot, errhand_t hand) {
    uint64_t res = 0xfeebdaed;
    asm("\tsyscall;\n"
        : "=a"(res)
        : "0"(10), "D"(start), "S"(len), "d"(prot)
        : "rcx", "r11", "memory");
    return chk_return<int>(res, hand);
  }






  // __NR__ munmap = 11
  inline int munmap(uint64_t addr, size_t len, errhand_t hand = err_log )
      __attribute__((__always_inline__));

  inline int munmap(uint64_t addr, size_t len, errhand_t hand) {
    uint64_t res = 0xfeebdaed;
    asm("\tsyscall;\n"
        : "=a"(res)
        : "0"(11), "D"(addr), "S"(len)
        : "rcx", "r11", "memory");
    return chk_return<int>(res, hand);
  }






  // __NR__ brk = 12
  inline int brk(void_p brk, errhand_t hand = err_log )
      __attribute__((__always_inline__));

  inline int brk(void_p brk, errhand_t hand) {
    uint64_t res = 0xfeebdaed;
    asm("\tsyscall;\n"
        : "=a"(res)
        : "0"(12), "D"(brk)
        : "rcx", "r11", "memory");
    return chk_return<int>(res, hand);
  }






  // __NR__ rt_sigaction = 13
  inline int rt_sigaction(int sig, sigaction_p act, sigaction_p oact, errhand_t hand = err_log )
      __attribute__((__always_inline__));

  inline int rt_sigaction(int sig, sigaction_p act, sigaction_p oact, errhand_t hand) {
    uint64_t res = 0xfeebdaed;
    asm("\tsyscall;\n"
        : "=a"(res)
        : "0"(13), "D"(sig), "S"(act), "d"(oact)
        : "rcx", "r11", "memory");
    return chk_return<int>(res, hand);
  }






  // __NR__ rt_sigprocmask = 14
  inline int rt_sigprocmask(int how, sigset_p nset, sigset_p oset, size_t sigsetsize, errhand_t hand = err_log )
      __attribute__((__always_inline__));

  inline int rt_sigprocmask(int how, sigset_p nset, sigset_p oset, size_t sigsetsize, errhand_t hand) {
    uint64_t res = 0xfeebdaed;
    asm("\tsyscall;\n"
        : "=a"(res)
        : "0"(14), "D"(how), "S"(nset), "d"(oset), "r10"(sigsetsize)
        : "rcx", "r11", "memory");
    return chk_return<int>(res, hand);
  }






  // __NR__ rt_sigreturn = 15
  inline int rt_sigreturn(uint64_t __unused, errhand_t hand = err_log )
      __attribute__((__always_inline__));

  inline int rt_sigreturn(uint64_t __unused, errhand_t hand) {
    uint64_t res = 0xfeebdaed;
    asm("\tsyscall;\n"
        : "=a"(res)
        : "0"(15), "D"(__unused)
        : "rcx", "r11", "memory");
    return chk_return<int>(res, hand);
  }






  // __NR__ ioctl = 16
  inline int ioctl(fd_t fd, unsigned cmd, uint64_t arg, errhand_t hand = err_log )
      __attribute__((__always_inline__));

  inline int ioctl(fd_t fd, unsigned cmd, uint64_t arg, errhand_t hand) {
    uint64_t res = 0xfeebdaed;
    asm("\tsyscall;\n"
        : "=a"(res)
        : "0"(16), "D"(fd), "S"(cmd), "d"(arg)
        : "rcx", "r11", "memory");
    return chk_return<int>(res, hand);
  }






  // __NR__ pread64 = 17
  inline int pread64(fd_t fd, ostr_t buf, size_t count, off_t pos, errhand_t hand = err_log )
      __attribute__((__always_inline__));

  inline int pread64(fd_t fd, ostr_t buf, size_t count, off_t pos, errhand_t hand) {
    uint64_t res = 0xfeebdaed;
    asm("\tsyscall;\n"
        : "=a"(res)
        : "0"(17), "D"(fd), "S"(buf), "d"(count), "r10"(pos)
        : "rcx", "r11", "memory");
    return chk_return<int>(res, hand);
  }






  // __NR__ pwrite64 = 18
  inline int pwrite64(fd_t fd, istr_t buf, size_t count, off_t pos, errhand_t hand = err_log )
      __attribute__((__always_inline__));

  inline int pwrite64(fd_t fd, istr_t buf, size_t count, off_t pos, errhand_t hand) {
    uint64_t res = 0xfeebdaed;
    asm("\tsyscall;\n"
        : "=a"(res)
        : "0"(18), "D"(fd), "S"(buf), "d"(count), "r10"(pos)
        : "rcx", "r11", "memory");
    return chk_return<int>(res, hand);
  }






  // __NR__ readv = 19
  inline int readv(fd_t fd, iovec_p vec, uint64_t vlen, errhand_t hand = err_log )
      __attribute__((__always_inline__));

  inline int readv(fd_t fd, iovec_p vec, uint64_t vlen, errhand_t hand) {
    uint64_t res = 0xfeebdaed;
    asm("\tsyscall;\n"
        : "=a"(res)
        : "0"(19), "D"(fd), "S"(vec), "d"(vlen)
        : "rcx", "r11", "memory");
    return chk_return<int>(res, hand);
  }






  // __NR__ writev = 20
  inline int writev(fd_t fd, iovec_p vec, uint64_t vlen, errhand_t hand = err_log )
      __attribute__((__always_inline__));

  inline int writev(fd_t fd, iovec_p vec, uint64_t vlen, errhand_t hand) {
    uint64_t res = 0xfeebdaed;
    asm("\tsyscall;\n"
        : "=a"(res)
        : "0"(20), "D"(fd), "S"(vec), "d"(vlen)
        : "rcx", "r11", "memory");
    return chk_return<int>(res, hand);
  }






  // __NR__ access = 21
  inline int access(istr_t path, int mode, errhand_t hand = err_log )
      __attribute__((__always_inline__));

  inline int access(istr_t path, int mode, errhand_t hand) {
    uint64_t res = 0xfeebdaed;
    asm("\tsyscall;\n"
        : "=a"(res)
        : "0"(21), "D"(path), "S"(mode)
        : "rcx", "r11", "memory");
    return chk_return<int>(res, hand);
  }






  // __NR__ pipe = 22
  inline int pipe(fd_p filedes, errhand_t hand = err_log )
      __attribute__((__always_inline__));

  inline int pipe(fd_p filedes, errhand_t hand) {
    uint64_t res = 0xfeebdaed;
    asm("\tsyscall;\n"
        : "=a"(res)
        : "0"(22), "D"(filedes)
        : "rcx", "r11", "memory");
    return chk_return<int>(res, hand);
  }






  // __NR__ select = 23
  inline int select(int n, fd_set_p inp, fd_set_p outp, fd_set_p exp, timeval_p tvp, errhand_t hand = err_log )
      __attribute__((__always_inline__));

  inline int select(int n, fd_set_p inp, fd_set_p outp, fd_set_p exp, timeval_p tvp, errhand_t hand) {
    uint64_t res = 0xfeebdaed;
    asm("\tsyscall;\n"
        : "=a"(res)
        : "0"(23), "D"(n), "S"(inp), "d"(outp), "r10"(exp), "r8"(tvp)
        : "rcx", "r11", "memory");
    return chk_return<int>(res, hand);
  }






  // __NR__ sched_yield = 24
  inline int sched_yield(errhand_t hand = err_log )
      __attribute__((__always_inline__));

  inline int sched_yield(errhand_t hand) {
    uint64_t res = 0xfeebdaed;
    asm("\tsyscall;\n"
        : "=a"(res)
        : "0"(24)
        : "rcx", "r11", "memory");
    return chk_return<int>(res, hand);
  }






  // __NR__ mremap = 25
  inline int mremap(uint64_t addr, uint64_t old_len, uint64_t new_len, uint64_t flags, uint64_t new_addr, errhand_t hand = err_log )
      __attribute__((__always_inline__));

  inline int mremap(uint64_t addr, uint64_t old_len, uint64_t new_len, uint64_t flags, uint64_t new_addr, errhand_t hand) {
    uint64_t res = 0xfeebdaed;
    asm("\tsyscall;\n"
        : "=a"(res)
        : "0"(25), "D"(addr), "S"(old_len), "d"(new_len), "r10"(flags), "r8"(new_addr)
        : "rcx", "r11", "memory");
    return chk_return<int>(res, hand);
  }






  // __NR__ msync = 26
  inline int msync(uint64_t start, size_t len, int flags, errhand_t hand = err_log )
      __attribute__((__always_inline__));

  inline int msync(uint64_t start, size_t len, int flags, errhand_t hand) {
    uint64_t res = 0xfeebdaed;
    asm("\tsyscall;\n"
        : "=a"(res)
        : "0"(26), "D"(start), "S"(len), "d"(flags)
        : "rcx", "r11", "memory");
    return chk_return<int>(res, hand);
  }






  // __NR__ mincore = 27
  inline int mincore(uint64_t start, size_t len, ostr_t vec, errhand_t hand = err_log )
      __attribute__((__always_inline__));

  inline int mincore(uint64_t start, size_t len, ostr_t vec, errhand_t hand) {
    uint64_t res = 0xfeebdaed;
    asm("\tsyscall;\n"
        : "=a"(res)
        : "0"(27), "D"(start), "S"(len), "d"(vec)
        : "rcx", "r11", "memory");
    return chk_return<int>(res, hand);
  }






  // __NR__ madvise = 28
  inline int madvise(uint64_t start, size_t len_in, int behavior, errhand_t hand = err_log )
      __attribute__((__always_inline__));

  inline int madvise(uint64_t start, size_t len_in, int behavior, errhand_t hand) {
    uint64_t res = 0xfeebdaed;
    asm("\tsyscall;\n"
        : "=a"(res)
        : "0"(28), "D"(start), "S"(len_in), "d"(behavior)
        : "rcx", "r11", "memory");
    return chk_return<int>(res, hand);
  }






  // __NR__ shmget = 29
  inline int shmget(key_t key, size_t size, int shmflg, errhand_t hand = err_log )
      __attribute__((__always_inline__));

  inline int shmget(key_t key, size_t size, int shmflg, errhand_t hand) {
    uint64_t res = 0xfeebdaed;
    asm("\tsyscall;\n"
        : "=a"(res)
        : "0"(29), "D"(key), "S"(size), "d"(shmflg)
        : "rcx", "r11", "memory");
    return chk_return<int>(res, hand);
  }






  // __NR__ shmat = 30
  inline int shmat(int shmid, ostr_t shmaddr, int shmflg, errhand_t hand = err_log )
      __attribute__((__always_inline__));

  inline int shmat(int shmid, ostr_t shmaddr, int shmflg, errhand_t hand) {
    uint64_t res = 0xfeebdaed;
    asm("\tsyscall;\n"
        : "=a"(res)
        : "0"(30), "D"(shmid), "S"(shmaddr), "d"(shmflg)
        : "rcx", "r11", "memory");
    return chk_return<int>(res, hand);
  }






  // __NR__ shmctl = 31
  inline int shmctl(int shmid, int cmd, shmid_ds_p buf, errhand_t hand = err_log )
      __attribute__((__always_inline__));

  inline int shmctl(int shmid, int cmd, shmid_ds_p buf, errhand_t hand) {
    uint64_t res = 0xfeebdaed;
    asm("\tsyscall;\n"
        : "=a"(res)
        : "0"(31), "D"(shmid), "S"(cmd), "d"(buf)
        : "rcx", "r11", "memory");
    return chk_return<int>(res, hand);
  }






  // __NR__ dup = 32
  inline int dup(unsigned fildes, errhand_t hand = err_log )
      __attribute__((__always_inline__));

  inline int dup(unsigned fildes, errhand_t hand) {
    uint64_t res = 0xfeebdaed;
    asm("\tsyscall;\n"
        : "=a"(res)
        : "0"(32), "D"(fildes)
        : "rcx", "r11", "memory");
    return chk_return<int>(res, hand);
  }






  // __NR__ dup2 = 33
  inline int dup2(fd_t oldfd, fd_t newfd, errhand_t hand = err_log )
      __attribute__((__always_inline__));

  inline int dup2(fd_t oldfd, fd_t newfd, errhand_t hand) {
    uint64_t res = 0xfeebdaed;
    asm("\tsyscall;\n"
        : "=a"(res)
        : "0"(33), "D"(oldfd), "S"(newfd)
        : "rcx", "r11", "memory");
    return chk_return<int>(res, hand);
  }






  // __NR__ pause = 34
  inline int pause(errhand_t hand = err_log )
      __attribute__((__always_inline__));

  inline int pause(errhand_t hand) {
    uint64_t res = 0xfeebdaed;
    asm("\tsyscall;\n"
        : "=a"(res)
        : "0"(34)
        : "rcx", "r11", "memory");
    return chk_return<int>(res, hand);
  }






  // __NR__ nanosleep = 35
  inline int nanosleep(timespec_p rqtp, timespec_p rmtp, errhand_t hand = err_log )
      __attribute__((__always_inline__));

  inline int nanosleep(timespec_p rqtp, timespec_p rmtp, errhand_t hand) {
    uint64_t res = 0xfeebdaed;
    asm("\tsyscall;\n"
        : "=a"(res)
        : "0"(35), "D"(rqtp), "S"(rmtp)
        : "rcx", "r11", "memory");
    return chk_return<int>(res, hand);
  }






  // __NR__ getitimer = 36
  inline int getitimer(int which, itimerval_p value, errhand_t hand = err_log )
      __attribute__((__always_inline__));

  inline int getitimer(int which, itimerval_p value, errhand_t hand) {
    uint64_t res = 0xfeebdaed;
    asm("\tsyscall;\n"
        : "=a"(res)
        : "0"(36), "D"(which), "S"(value)
        : "rcx", "r11", "memory");
    return chk_return<int>(res, hand);
  }






  // __NR__ alarm = 37
  inline int alarm(unsigned seconds, errhand_t hand = err_log )
      __attribute__((__always_inline__));

  inline int alarm(unsigned seconds, errhand_t hand) {
    uint64_t res = 0xfeebdaed;
    asm("\tsyscall;\n"
        : "=a"(res)
        : "0"(37), "D"(seconds)
        : "rcx", "r11", "memory");
    return chk_return<int>(res, hand);
  }






  // __NR__ setitimer = 38
  inline int setitimer(int which, itimerval_p value, itimerval_p ovalue, errhand_t hand = err_log )
      __attribute__((__always_inline__));

  inline int setitimer(int which, itimerval_p value, itimerval_p ovalue, errhand_t hand) {
    uint64_t res = 0xfeebdaed;
    asm("\tsyscall;\n"
        : "=a"(res)
        : "0"(38), "D"(which), "S"(value), "d"(ovalue)
        : "rcx", "r11", "memory");
    return chk_return<int>(res, hand);
  }






  // __NR__ getpid = 39
  inline int getpid(errhand_t hand = err_log )
      __attribute__((__always_inline__));

  inline int getpid(errhand_t hand) {
    uint64_t res = 0xfeebdaed;
    asm("\tsyscall;\n"
        : "=a"(res)
        : "0"(39)
        : "rcx", "r11", "memory");
    return chk_return<int>(res, hand);
  }






  // __NR__ sendfile = 40
  inline int sendfile(int out_fd, int in_fd, off_p offset, size_t count, errhand_t hand = err_log )
      __attribute__((__always_inline__));

  inline int sendfile(int out_fd, int in_fd, off_p offset, size_t count, errhand_t hand) {
    uint64_t res = 0xfeebdaed;
    asm("\tsyscall;\n"
        : "=a"(res)
        : "0"(40), "D"(out_fd), "S"(in_fd), "d"(offset), "r10"(count)
        : "rcx", "r11", "memory");
    return chk_return<int>(res, hand);
  }






  // __NR__ socket = 41
  inline int socket(int family, int type, int protocol, errhand_t hand = err_log )
      __attribute__((__always_inline__));

  inline int socket(int family, int type, int protocol, errhand_t hand) {
    uint64_t res = 0xfeebdaed;
    asm("\tsyscall;\n"
        : "=a"(res)
        : "0"(41), "D"(family), "S"(type), "d"(protocol)
        : "rcx", "r11", "memory");
    return chk_return<int>(res, hand);
  }






  // __NR__ connect = 42
  inline int connect(fd_t fd, sockaddr_p uservaddr, int addrlen, errhand_t hand = err_log )
      __attribute__((__always_inline__));

  inline int connect(fd_t fd, sockaddr_p uservaddr, int addrlen, errhand_t hand) {
    uint64_t res = 0xfeebdaed;
    asm("\tsyscall;\n"
        : "=a"(res)
        : "0"(42), "D"(fd), "S"(uservaddr), "d"(addrlen)
        : "rcx", "r11", "memory");
    return chk_return<int>(res, hand);
  }






  // __NR__ accept = 43
  inline int accept(fd_t fd, sockaddr_p upeer_sockaddr, int32_p upeer_addrlen, errhand_t hand = err_log )
      __attribute__((__always_inline__));

  inline int accept(fd_t fd, sockaddr_p upeer_sockaddr, int32_p upeer_addrlen, errhand_t hand) {
    uint64_t res = 0xfeebdaed;
    asm("\tsyscall;\n"
        : "=a"(res)
        : "0"(43), "D"(fd), "S"(upeer_sockaddr), "d"(upeer_addrlen)
        : "rcx", "r11", "memory");
    return chk_return<int>(res, hand);
  }






  // __NR__ sendto = 44
  inline int sendto(fd_t fd, void_p buff, size_t len, unsigned flags, sockaddr_p addr, int addr_len, errhand_t hand = err_log )
      __attribute__((__always_inline__));

  inline int sendto(fd_t fd, void_p buff, size_t len, unsigned flags, sockaddr_p addr, int addr_len, errhand_t hand) {
    uint64_t res = 0xfeebdaed;
    asm("\tsyscall;\n"
        : "=a"(res)
        : "0"(44), "D"(fd), "S"(buff), "d"(len), "r10"(flags), "r8"(addr), "r9"(addr_len)
        : "rcx", "r11", "memory");
    return chk_return<int>(res, hand);
  }






  // __NR__ recvfrom = 45
  inline int recvfrom(fd_t fd, void_p ubuf, size_t size, unsigned flags, sockaddr_p addr, int32_p addr_len, errhand_t hand = err_log )
      __attribute__((__always_inline__));

  inline int recvfrom(fd_t fd, void_p ubuf, size_t size, unsigned flags, sockaddr_p addr, int32_p addr_len, errhand_t hand) {
    uint64_t res = 0xfeebdaed;
    asm("\tsyscall;\n"
        : "=a"(res)
        : "0"(45), "D"(fd), "S"(ubuf), "d"(size), "r10"(flags), "r8"(addr), "r9"(addr_len)
        : "rcx", "r11", "memory");
    return chk_return<int>(res, hand);
  }






  // __NR__ sendmsg = 46
  inline int sendmsg(fd_t fd, msghdr_p msg, unsigned flags, errhand_t hand = err_log )
      __attribute__((__always_inline__));

  inline int sendmsg(fd_t fd, msghdr_p msg, unsigned flags, errhand_t hand) {
    uint64_t res = 0xfeebdaed;
    asm("\tsyscall;\n"
        : "=a"(res)
        : "0"(46), "D"(fd), "S"(msg), "d"(flags)
        : "rcx", "r11", "memory");
    return chk_return<int>(res, hand);
  }






  // __NR__ recvmsg = 47
  inline int recvmsg(fd_t fd, msghdr_p msg, unsigned flags, errhand_t hand = err_log )
      __attribute__((__always_inline__));

  inline int recvmsg(fd_t fd, msghdr_p msg, unsigned flags, errhand_t hand) {
    uint64_t res = 0xfeebdaed;
    asm("\tsyscall;\n"
        : "=a"(res)
        : "0"(47), "D"(fd), "S"(msg), "d"(flags)
        : "rcx", "r11", "memory");
    return chk_return<int>(res, hand);
  }






  // __NR__ shutdown = 48
  inline int shutdown(fd_t fd, int how, errhand_t hand = err_log )
      __attribute__((__always_inline__));

  inline int shutdown(fd_t fd, int how, errhand_t hand) {
    uint64_t res = 0xfeebdaed;
    asm("\tsyscall;\n"
        : "=a"(res)
        : "0"(48), "D"(fd), "S"(how)
        : "rcx", "r11", "memory");
    return chk_return<int>(res, hand);
  }






  // __NR__ bind = 49
  inline int bind(fd_t fd, sockaddr_p umyaddr, int addrlen, errhand_t hand = err_log )
      __attribute__((__always_inline__));

  inline int bind(fd_t fd, sockaddr_p umyaddr, int addrlen, errhand_t hand) {
    uint64_t res = 0xfeebdaed;
    asm("\tsyscall;\n"
        : "=a"(res)
        : "0"(49), "D"(fd), "S"(umyaddr), "d"(addrlen)
        : "rcx", "r11", "memory");
    return chk_return<int>(res, hand);
  }






  // __NR__ listen = 50
  inline int listen(fd_t fd, int backlog, errhand_t hand = err_log )
      __attribute__((__always_inline__));

  inline int listen(fd_t fd, int backlog, errhand_t hand) {
    uint64_t res = 0xfeebdaed;
    asm("\tsyscall;\n"
        : "=a"(res)
        : "0"(50), "D"(fd), "S"(backlog)
        : "rcx", "r11", "memory");
    return chk_return<int>(res, hand);
  }






  // __NR__ getsockname = 51
  inline int getsockname(fd_t fd, sockaddr_p usockaddr, int32_p usockaddr_len, errhand_t hand = err_log )
      __attribute__((__always_inline__));

  inline int getsockname(fd_t fd, sockaddr_p usockaddr, int32_p usockaddr_len, errhand_t hand) {
    uint64_t res = 0xfeebdaed;
    asm("\tsyscall;\n"
        : "=a"(res)
        : "0"(51), "D"(fd), "S"(usockaddr), "d"(usockaddr_len)
        : "rcx", "r11", "memory");
    return chk_return<int>(res, hand);
  }






  // __NR__ getpeername = 52
  inline int getpeername(fd_t fd, sockaddr_p usockaddr, int32_p usockaddr_len, errhand_t hand = err_log )
      __attribute__((__always_inline__));

  inline int getpeername(fd_t fd, sockaddr_p usockaddr, int32_p usockaddr_len, errhand_t hand) {
    uint64_t res = 0xfeebdaed;
    asm("\tsyscall;\n"
        : "=a"(res)
        : "0"(52), "D"(fd), "S"(usockaddr), "d"(usockaddr_len)
        : "rcx", "r11", "memory");
    return chk_return<int>(res, hand);
  }






  // __NR__ socketpair = 53
  inline int socketpair(int family, int type, int protocol, int32_p usockvec, errhand_t hand = err_log )
      __attribute__((__always_inline__));

  inline int socketpair(int family, int type, int protocol, int32_p usockvec, errhand_t hand) {
    uint64_t res = 0xfeebdaed;
    asm("\tsyscall;\n"
        : "=a"(res)
        : "0"(53), "D"(family), "S"(type), "d"(protocol), "r10"(usockvec)
        : "rcx", "r11", "memory");
    return chk_return<int>(res, hand);
  }






  // __NR__ setsockopt = 54
  inline int setsockopt(fd_t fd, int level, int optname, ostr_t optval, int optlen, errhand_t hand = err_log )
      __attribute__((__always_inline__));

  inline int setsockopt(fd_t fd, int level, int optname, ostr_t optval, int optlen, errhand_t hand) {
    uint64_t res = 0xfeebdaed;
    asm("\tsyscall;\n"
        : "=a"(res)
        : "0"(54), "D"(fd), "S"(level), "d"(optname), "r10"(optval), "r8"(optlen)
        : "rcx", "r11", "memory");
    return chk_return<int>(res, hand);
  }






  // __NR__ getsockopt = 55
  inline int getsockopt(fd_t fd, int level, int optname, ostr_t optval, int32_p optlen, errhand_t hand = err_log )
      __attribute__((__always_inline__));

  inline int getsockopt(fd_t fd, int level, int optname, ostr_t optval, int32_p optlen, errhand_t hand) {
    uint64_t res = 0xfeebdaed;
    asm("\tsyscall;\n"
        : "=a"(res)
        : "0"(55), "D"(fd), "S"(level), "d"(optname), "r10"(optval), "r8"(optlen)
        : "rcx", "r11", "memory");
    return chk_return<int>(res, hand);
  }






  // __NR__ clone = 56
  inline int sys_clone(uint64_t clone_flags, uint64_t newsp, void_p parent_tid, void_p child_tid, errhand_t hand = err_log )
      __attribute__((__always_inline__));

  inline int sys_clone(uint64_t clone_flags, uint64_t newsp, void_p parent_tid, void_p child_tid, errhand_t hand) {
    uint64_t res = 0xfeebdaed;
    asm("\tsyscall;\n"
        : "=a"(res)
        : "0"(56), "D"(clone_flags), "S"(newsp), "d"(parent_tid), "r10"(child_tid)
        : "rcx", "r11", "memory");
    return chk_return<int>(res, hand);
  }






  // __NR__ fork = 57
  inline int fork(errhand_t hand = err_log )
      __attribute__((__always_inline__));

  inline int fork(errhand_t hand) {
    uint64_t res = 0xfeebdaed;
    asm("\tsyscall;\n"
        : "=a"(res)
        : "0"(57)
        : "rcx", "r11", "memory");
    return chk_return<int>(res, hand);
  }






  // __NR__ vfork = 58
  inline int vfork(errhand_t hand = err_log )
      __attribute__((__always_inline__));

  inline int vfork(errhand_t hand) {
    uint64_t res = 0xfeebdaed;
    asm("\tsyscall;\n"
        : "=a"(res)
        : "0"(58)
        : "rcx", "r11", "memory");
    return chk_return<int>(res, hand);
  }






  // __NR__ execve = 59
  inline int execve(const char * filename, char *const * argv, char *const * envp, errhand_t hand = err_log )
      __attribute__((__always_inline__));

  inline int execve(const char * filename, char *const * argv, char *const * envp, errhand_t hand) {
    uint64_t res = 0xfeebdaed;
    asm("\tsyscall;\n"
        : "=a"(res)
        : "0"(59), "D"(filename), "S"(argv), "d"(envp)
        : "rcx", "r11", "memory");
    return chk_return<int>(res, hand);
  }






  // __NR__ exit = 60
  inline void _exit(int error_code, errhand_t hand = err_log )
      __attribute__((__always_inline__));

  inline void _exit(int error_code, errhand_t hand) {
    uint64_t res = 0xfeebdaed;
    asm("\tsyscall;\n"
        : "=a"(res)
        : "0"(60), "D"(error_code)
        : "rcx", "r11", "memory");
    return chk_return<void>(res, hand);
  }






  // __NR__ wait4 = 61
  inline int wait4(pid_t upid, int32_p stat_addr, int options, rusage_p ru, errhand_t hand = err_log )
      __attribute__((__always_inline__));

  inline int wait4(pid_t upid, int32_p stat_addr, int options, rusage_p ru, errhand_t hand) {
    uint64_t res = 0xfeebdaed;
    asm("\tsyscall;\n"
        : "=a"(res)
        : "0"(61), "D"(upid), "S"(stat_addr), "d"(options), "r10"(ru)
        : "rcx", "r11", "memory");
    return chk_return<int>(res, hand);
  }






  // __NR__ kill = 62
  inline int kill(pid_t pid, int sig, errhand_t hand = err_log )
      __attribute__((__always_inline__));

  inline int kill(pid_t pid, int sig, errhand_t hand) {
    uint64_t res = 0xfeebdaed;
    asm("\tsyscall;\n"
        : "=a"(res)
        : "0"(62), "D"(pid), "S"(sig)
        : "rcx", "r11", "memory");
    return chk_return<int>(res, hand);
  }






  // __NR__ uname = 63
  inline int uname(utsname_p name, errhand_t hand = err_log )
      __attribute__((__always_inline__));

  inline int uname(utsname_p name, errhand_t hand) {
    uint64_t res = 0xfeebdaed;
    asm("\tsyscall;\n"
        : "=a"(res)
        : "0"(63), "D"(name)
        : "rcx", "r11", "memory");
    return chk_return<int>(res, hand);
  }






  // __NR__ semget = 64
  inline int semget(key_t key, int nsems, int semflg, errhand_t hand = err_log )
      __attribute__((__always_inline__));

  inline int semget(key_t key, int nsems, int semflg, errhand_t hand) {
    uint64_t res = 0xfeebdaed;
    asm("\tsyscall;\n"
        : "=a"(res)
        : "0"(64), "D"(key), "S"(nsems), "d"(semflg)
        : "rcx", "r11", "memory");
    return chk_return<int>(res, hand);
  }






  // __NR__ semop = 65
  inline int semop(int semid, sembuf_p tsops, unsigned nsops, errhand_t hand = err_log )
      __attribute__((__always_inline__));

  inline int semop(int semid, sembuf_p tsops, unsigned nsops, errhand_t hand) {
    uint64_t res = 0xfeebdaed;
    asm("\tsyscall;\n"
        : "=a"(res)
        : "0"(65), "D"(semid), "S"(tsops), "d"(nsops)
        : "rcx", "r11", "memory");
    return chk_return<int>(res, hand);
  }






  // __NR__ semctl = 66
  inline int semctl(int semid, int semnum, int cmd, union semun arg, errhand_t hand = err_log )
      __attribute__((__always_inline__));

  inline int semctl(int semid, int semnum, int cmd, union semun arg, errhand_t hand) {
    uint64_t res = 0xfeebdaed;
    asm("\tsyscall;\n"
        : "=a"(res)
        : "0"(66), "D"(semid), "S"(semnum), "d"(cmd), "r10"(arg)
        : "rcx", "r11", "memory");
    return chk_return<int>(res, hand);
  }






  // __NR__ shmdt = 67
  inline int shmdt(ostr_t shmaddr, errhand_t hand = err_log )
      __attribute__((__always_inline__));

  inline int shmdt(ostr_t shmaddr, errhand_t hand) {
    uint64_t res = 0xfeebdaed;
    asm("\tsyscall;\n"
        : "=a"(res)
        : "0"(67), "D"(shmaddr)
        : "rcx", "r11", "memory");
    return chk_return<int>(res, hand);
  }






  // __NR__ msgget = 68
  inline int msgget(key_t key, int msgflg, errhand_t hand = err_log )
      __attribute__((__always_inline__));

  inline int msgget(key_t key, int msgflg, errhand_t hand) {
    uint64_t res = 0xfeebdaed;
    asm("\tsyscall;\n"
        : "=a"(res)
        : "0"(68), "D"(key), "S"(msgflg)
        : "rcx", "r11", "memory");
    return chk_return<int>(res, hand);
  }






  // __NR__ msgsnd = 69
  inline int msgsnd(int msqid, msgbuf_p msgp, size_t msgsz, int msgflg, errhand_t hand = err_log )
      __attribute__((__always_inline__));

  inline int msgsnd(int msqid, msgbuf_p msgp, size_t msgsz, int msgflg, errhand_t hand) {
    uint64_t res = 0xfeebdaed;
    asm("\tsyscall;\n"
        : "=a"(res)
        : "0"(69), "D"(msqid), "S"(msgp), "d"(msgsz), "r10"(msgflg)
        : "rcx", "r11", "memory");
    return chk_return<int>(res, hand);
  }






  // __NR__ msgrcv = 70
  inline int msgrcv(int msqid, msgbuf_p msgp, size_t msgsz, long msgtyp, int msgflg, errhand_t hand = err_log )
      __attribute__((__always_inline__));

  inline int msgrcv(int msqid, msgbuf_p msgp, size_t msgsz, long msgtyp, int msgflg, errhand_t hand) {
    uint64_t res = 0xfeebdaed;
    asm("\tsyscall;\n"
        : "=a"(res)
        : "0"(70), "D"(msqid), "S"(msgp), "d"(msgsz), "r10"(msgtyp), "r8"(msgflg)
        : "rcx", "r11", "memory");
    return chk_return<int>(res, hand);
  }






  // __NR__ msgctl = 71
  inline int msgctl(int msqid, int cmd, msqid_ds_p buf, errhand_t hand = err_log )
      __attribute__((__always_inline__));

  inline int msgctl(int msqid, int cmd, msqid_ds_p buf, errhand_t hand) {
    uint64_t res = 0xfeebdaed;
    asm("\tsyscall;\n"
        : "=a"(res)
        : "0"(71), "D"(msqid), "S"(cmd), "d"(buf)
        : "rcx", "r11", "memory");
    return chk_return<int>(res, hand);
  }






  // __NR__ fcntl = 72
  inline int fcntl(fd_t fd, unsigned cmd, uint64_t arg, errhand_t hand = err_log )
      __attribute__((__always_inline__));

  inline int fcntl(fd_t fd, unsigned cmd, uint64_t arg, errhand_t hand) {
    uint64_t res = 0xfeebdaed;
    asm("\tsyscall;\n"
        : "=a"(res)
        : "0"(72), "D"(fd), "S"(cmd), "d"(arg)
        : "rcx", "r11", "memory");
    return chk_return<int>(res, hand);
  }






  // __NR__ flock = 73
  inline int flock(fd_t fd, unsigned cmd, errhand_t hand = err_log )
      __attribute__((__always_inline__));

  inline int flock(fd_t fd, unsigned cmd, errhand_t hand) {
    uint64_t res = 0xfeebdaed;
    asm("\tsyscall;\n"
        : "=a"(res)
        : "0"(73), "D"(fd), "S"(cmd)
        : "rcx", "r11", "memory");
    return chk_return<int>(res, hand);
  }






  // __NR__ fsync = 74
  inline int fsync(fd_t fd, errhand_t hand = err_log )
      __attribute__((__always_inline__));

  inline int fsync(fd_t fd, errhand_t hand) {
    uint64_t res = 0xfeebdaed;
    asm("\tsyscall;\n"
        : "=a"(res)
        : "0"(74), "D"(fd)
        : "rcx", "r11", "memory");
    return chk_return<int>(res, hand);
  }






  // __NR__ fdatasync = 75
  inline int fdatasync(fd_t fd, errhand_t hand = err_log )
      __attribute__((__always_inline__));

  inline int fdatasync(fd_t fd, errhand_t hand) {
    uint64_t res = 0xfeebdaed;
    asm("\tsyscall;\n"
        : "=a"(res)
        : "0"(75), "D"(fd)
        : "rcx", "r11", "memory");
    return chk_return<int>(res, hand);
  }






  // __NR__ truncate = 76
  inline int truncate(istr_t path, long length, errhand_t hand = err_log )
      __attribute__((__always_inline__));

  inline int truncate(istr_t path, long length, errhand_t hand) {
    uint64_t res = 0xfeebdaed;
    asm("\tsyscall;\n"
        : "=a"(res)
        : "0"(76), "D"(path), "S"(length)
        : "rcx", "r11", "memory");
    return chk_return<int>(res, hand);
  }






  // __NR__ ftruncate = 77
  inline int ftruncate(fd_t fd, uint64_t length, errhand_t hand = err_log )
      __attribute__((__always_inline__));

  inline int ftruncate(fd_t fd, uint64_t length, errhand_t hand) {
    uint64_t res = 0xfeebdaed;
    asm("\tsyscall;\n"
        : "=a"(res)
        : "0"(77), "D"(fd), "S"(length)
        : "rcx", "r11", "memory");
    return chk_return<int>(res, hand);
  }






  // __NR__ getdents = 78
  inline ssize_t getdents(fd_t fd, linux_dirent_p dirent, size_t count, errhand_t hand = err_log )
      __attribute__((__always_inline__));

  inline ssize_t getdents(fd_t fd, linux_dirent_p dirent, size_t count, errhand_t hand) {
    uint64_t res = 0xfeebdaed;
    asm("\tsyscall;\n"
        : "=a"(res)
        : "0"(78), "D"(fd), "S"(dirent), "d"(count)
        : "rcx", "r11", "memory");
    return chk_return<ssize_t>(res, hand);
  }






  // __NR__ getcwd = 79
  inline int getcwd(ostr_t buf, uint64_t size, errhand_t hand = err_log )
      __attribute__((__always_inline__));

  inline int getcwd(ostr_t buf, uint64_t size, errhand_t hand) {
    uint64_t res = 0xfeebdaed;
    asm("\tsyscall;\n"
        : "=a"(res)
        : "0"(79), "D"(buf), "S"(size)
        : "rcx", "r11", "memory");
    return chk_return<int>(res, hand);
  }






  // __NR__ chdir = 80
  inline int chdir(istr_t path, errhand_t hand = err_log )
      __attribute__((__always_inline__));

  inline int chdir(istr_t path, errhand_t hand) {
    uint64_t res = 0xfeebdaed;
    asm("\tsyscall;\n"
        : "=a"(res)
        : "0"(80), "D"(path)
        : "rcx", "r11", "memory");
    return chk_return<int>(res, hand);
  }






  // __NR__ fchdir = 81
  inline int fchdir(fd_t fd, errhand_t hand = err_log )
      __attribute__((__always_inline__));

  inline int fchdir(fd_t fd, errhand_t hand) {
    uint64_t res = 0xfeebdaed;
    asm("\tsyscall;\n"
        : "=a"(res)
        : "0"(81), "D"(fd)
        : "rcx", "r11", "memory");
    return chk_return<int>(res, hand);
  }






  // __NR__ rename = 82
  inline int rename(istr_t opath, istr_t npath, errhand_t hand = err_log )
      __attribute__((__always_inline__));

  inline int rename(istr_t opath, istr_t npath, errhand_t hand) {
    uint64_t res = 0xfeebdaed;
    asm("\tsyscall;\n"
        : "=a"(res)
        : "0"(82), "D"(opath), "S"(npath)
        : "rcx", "r11", "memory");
    return chk_return<int>(res, hand);
  }






  // __NR__ mkdir = 83
  inline int mkdir(istr_t path, int mode, errhand_t hand = err_log )
      __attribute__((__always_inline__));

  inline int mkdir(istr_t path, int mode, errhand_t hand) {
    uint64_t res = 0xfeebdaed;
    asm("\tsyscall;\n"
        : "=a"(res)
        : "0"(83), "D"(path), "S"(mode)
        : "rcx", "r11", "memory");
    return chk_return<int>(res, hand);
  }






  // __NR__ rmdir = 84
  inline int rmdir(istr_t path, errhand_t hand = err_log )
      __attribute__((__always_inline__));

  inline int rmdir(istr_t path, errhand_t hand) {
    uint64_t res = 0xfeebdaed;
    asm("\tsyscall;\n"
        : "=a"(res)
        : "0"(84), "D"(path)
        : "rcx", "r11", "memory");
    return chk_return<int>(res, hand);
  }






  // __NR__ creat = 85
  inline int creat(istr_t path, int mode, errhand_t hand = err_log )
      __attribute__((__always_inline__));

  inline int creat(istr_t path, int mode, errhand_t hand) {
    uint64_t res = 0xfeebdaed;
    asm("\tsyscall;\n"
        : "=a"(res)
        : "0"(85), "D"(path), "S"(mode)
        : "rcx", "r11", "memory");
    return chk_return<int>(res, hand);
  }






  // __NR__ link = 86
  inline int link(istr_t opath, istr_t npath, errhand_t hand = err_log )
      __attribute__((__always_inline__));

  inline int link(istr_t opath, istr_t npath, errhand_t hand) {
    uint64_t res = 0xfeebdaed;
    asm("\tsyscall;\n"
        : "=a"(res)
        : "0"(86), "D"(opath), "S"(npath)
        : "rcx", "r11", "memory");
    return chk_return<int>(res, hand);
  }






  // __NR__ unlink = 87
  inline int unlink(istr_t path, errhand_t hand = err_log )
      __attribute__((__always_inline__));

  inline int unlink(istr_t path, errhand_t hand) {
    uint64_t res = 0xfeebdaed;
    asm("\tsyscall;\n"
        : "=a"(res)
        : "0"(87), "D"(path)
        : "rcx", "r11", "memory");
    return chk_return<int>(res, hand);
  }






  // __NR__ symlink = 88
  inline int symlink(istr_t opath, istr_t npath, errhand_t hand = err_log )
      __attribute__((__always_inline__));

  inline int symlink(istr_t opath, istr_t npath, errhand_t hand) {
    uint64_t res = 0xfeebdaed;
    asm("\tsyscall;\n"
        : "=a"(res)
        : "0"(88), "D"(opath), "S"(npath)
        : "rcx", "r11", "memory");
    return chk_return<int>(res, hand);
  }






  // __NR__ readlink = 89
  inline int readlink(istr_t path, ostr_t buf, int bufsiz, errhand_t hand = err_log )
      __attribute__((__always_inline__));

  inline int readlink(istr_t path, ostr_t buf, int bufsiz, errhand_t hand) {
    uint64_t res = 0xfeebdaed;
    asm("\tsyscall;\n"
        : "=a"(res)
        : "0"(89), "D"(path), "S"(buf), "d"(bufsiz)
        : "rcx", "r11", "memory");
    return chk_return<int>(res, hand);
  }






  // __NR__ chmod = 90
  inline int chmod(istr_t path, mode_t mode, errhand_t hand = err_log )
      __attribute__((__always_inline__));

  inline int chmod(istr_t path, mode_t mode, errhand_t hand) {
    uint64_t res = 0xfeebdaed;
    asm("\tsyscall;\n"
        : "=a"(res)
        : "0"(90), "D"(path), "S"(mode)
        : "rcx", "r11", "memory");
    return chk_return<int>(res, hand);
  }






  // __NR__ fchmod = 91
  inline int fchmod(fd_t fd, mode_t mode, errhand_t hand = err_log )
      __attribute__((__always_inline__));

  inline int fchmod(fd_t fd, mode_t mode, errhand_t hand) {
    uint64_t res = 0xfeebdaed;
    asm("\tsyscall;\n"
        : "=a"(res)
        : "0"(91), "D"(fd), "S"(mode)
        : "rcx", "r11", "memory");
    return chk_return<int>(res, hand);
  }






  // __NR__ chown = 92
  inline int chown(istr_t path, uid_t user, gid_t group, errhand_t hand = err_log )
      __attribute__((__always_inline__));

  inline int chown(istr_t path, uid_t user, gid_t group, errhand_t hand) {
    uint64_t res = 0xfeebdaed;
    asm("\tsyscall;\n"
        : "=a"(res)
        : "0"(92), "D"(path), "S"(user), "d"(group)
        : "rcx", "r11", "memory");
    return chk_return<int>(res, hand);
  }






  // __NR__ fchown = 93
  inline int fchown(fd_t fd, uid_t user, gid_t group, errhand_t hand = err_log )
      __attribute__((__always_inline__));

  inline int fchown(fd_t fd, uid_t user, gid_t group, errhand_t hand) {
    uint64_t res = 0xfeebdaed;
    asm("\tsyscall;\n"
        : "=a"(res)
        : "0"(93), "D"(fd), "S"(user), "d"(group)
        : "rcx", "r11", "memory");
    return chk_return<int>(res, hand);
  }






  // __NR__ lchown = 94
  inline int lchown(istr_t path, uid_t user, gid_t group, errhand_t hand = err_log )
      __attribute__((__always_inline__));

  inline int lchown(istr_t path, uid_t user, gid_t group, errhand_t hand) {
    uint64_t res = 0xfeebdaed;
    asm("\tsyscall;\n"
        : "=a"(res)
        : "0"(94), "D"(path), "S"(user), "d"(group)
        : "rcx", "r11", "memory");
    return chk_return<int>(res, hand);
  }






  // __NR__ umask = 95
  inline int umask(int mask, errhand_t hand = err_log )
      __attribute__((__always_inline__));

  inline int umask(int mask, errhand_t hand) {
    uint64_t res = 0xfeebdaed;
    asm("\tsyscall;\n"
        : "=a"(res)
        : "0"(95), "D"(mask)
        : "rcx", "r11", "memory");
    return chk_return<int>(res, hand);
  }






  // __NR__ gettimeofday = 96
  inline int gettimeofday(timeval_p tv, timezone_p tz, errhand_t hand = err_log )
      __attribute__((__always_inline__));

  inline int gettimeofday(timeval_p tv, timezone_p tz, errhand_t hand) {
    uint64_t res = 0xfeebdaed;
    asm("\tsyscall;\n"
        : "=a"(res)
        : "0"(96), "D"(tv), "S"(tz)
        : "rcx", "r11", "memory");
    return chk_return<int>(res, hand);
  }






  // __NR__ getrlimit = 97
  inline int getrlimit(unsigned resource, rlimit_p rlim, errhand_t hand = err_log )
      __attribute__((__always_inline__));

  inline int getrlimit(unsigned resource, rlimit_p rlim, errhand_t hand) {
    uint64_t res = 0xfeebdaed;
    asm("\tsyscall;\n"
        : "=a"(res)
        : "0"(97), "D"(resource), "S"(rlim)
        : "rcx", "r11", "memory");
    return chk_return<int>(res, hand);
  }






  // __NR__ getrusage = 98
  inline int getrusage(int who, rusage_p ru, errhand_t hand = err_log )
      __attribute__((__always_inline__));

  inline int getrusage(int who, rusage_p ru, errhand_t hand) {
    uint64_t res = 0xfeebdaed;
    asm("\tsyscall;\n"
        : "=a"(res)
        : "0"(98), "D"(who), "S"(ru)
        : "rcx", "r11", "memory");
    return chk_return<int>(res, hand);
  }






  // __NR__ sysinfo = 99
  inline int sysinfo(sysinfo_p info, errhand_t hand = err_log )
      __attribute__((__always_inline__));

  inline int sysinfo(sysinfo_p info, errhand_t hand) {
    uint64_t res = 0xfeebdaed;
    asm("\tsyscall;\n"
        : "=a"(res)
        : "0"(99), "D"(info)
        : "rcx", "r11", "memory");
    return chk_return<int>(res, hand);
  }






  // __NR__ times = 100
  inline int times(sysinfo_p info, errhand_t hand = err_log )
      __attribute__((__always_inline__));

  inline int times(sysinfo_p info, errhand_t hand) {
    uint64_t res = 0xfeebdaed;
    asm("\tsyscall;\n"
        : "=a"(res)
        : "0"(100), "D"(info)
        : "rcx", "r11", "memory");
    return chk_return<int>(res, hand);
  }






  // __NR__ ptrace = 101
  inline int ptrace(long request, long pid, uint64_t addr, uint64_t data, errhand_t hand = err_log )
      __attribute__((__always_inline__));

  inline int ptrace(long request, long pid, uint64_t addr, uint64_t data, errhand_t hand) {
    uint64_t res = 0xfeebdaed;
    asm("\tsyscall;\n"
        : "=a"(res)
        : "0"(101), "D"(request), "S"(pid), "d"(addr), "r10"(data)
        : "rcx", "r11", "memory");
    return chk_return<int>(res, hand);
  }






  // __NR__ getuid = 102
  inline int getuid(errhand_t hand = err_log )
      __attribute__((__always_inline__));

  inline int getuid(errhand_t hand) {
    uint64_t res = 0xfeebdaed;
    asm("\tsyscall;\n"
        : "=a"(res)
        : "0"(102)
        : "rcx", "r11", "memory");
    return chk_return<int>(res, hand);
  }






  // __NR__ syslog = 103
  inline int syslog(int type, ostr_t buf, int len, errhand_t hand = err_log )
      __attribute__((__always_inline__));

  inline int syslog(int type, ostr_t buf, int len, errhand_t hand) {
    uint64_t res = 0xfeebdaed;
    asm("\tsyscall;\n"
        : "=a"(res)
        : "0"(103), "D"(type), "S"(buf), "d"(len)
        : "rcx", "r11", "memory");
    return chk_return<int>(res, hand);
  }






  // __NR__ getgid = 104
  inline int getgid(errhand_t hand = err_log )
      __attribute__((__always_inline__));

  inline int getgid(errhand_t hand) {
    uint64_t res = 0xfeebdaed;
    asm("\tsyscall;\n"
        : "=a"(res)
        : "0"(104)
        : "rcx", "r11", "memory");
    return chk_return<int>(res, hand);
  }






  // __NR__ setuid = 105
  inline int setuid(uid_t uid, errhand_t hand = err_log )
      __attribute__((__always_inline__));

  inline int setuid(uid_t uid, errhand_t hand) {
    uint64_t res = 0xfeebdaed;
    asm("\tsyscall;\n"
        : "=a"(res)
        : "0"(105), "D"(uid)
        : "rcx", "r11", "memory");
    return chk_return<int>(res, hand);
  }






  // __NR__ setgid = 106
  inline int setgid(gid_t gid, errhand_t hand = err_log )
      __attribute__((__always_inline__));

  inline int setgid(gid_t gid, errhand_t hand) {
    uint64_t res = 0xfeebdaed;
    asm("\tsyscall;\n"
        : "=a"(res)
        : "0"(106), "D"(gid)
        : "rcx", "r11", "memory");
    return chk_return<int>(res, hand);
  }






  // __NR__ geteuid = 107
  inline int geteuid(errhand_t hand = err_log )
      __attribute__((__always_inline__));

  inline int geteuid(errhand_t hand) {
    uint64_t res = 0xfeebdaed;
    asm("\tsyscall;\n"
        : "=a"(res)
        : "0"(107)
        : "rcx", "r11", "memory");
    return chk_return<int>(res, hand);
  }






  // __NR__ getegid = 108
  inline int getegid(errhand_t hand = err_log )
      __attribute__((__always_inline__));

  inline int getegid(errhand_t hand) {
    uint64_t res = 0xfeebdaed;
    asm("\tsyscall;\n"
        : "=a"(res)
        : "0"(108)
        : "rcx", "r11", "memory");
    return chk_return<int>(res, hand);
  }






  // __NR__ setpgid = 109
  inline int setpgid(pid_t pid, pid_t pgid, errhand_t hand = err_log )
      __attribute__((__always_inline__));

  inline int setpgid(pid_t pid, pid_t pgid, errhand_t hand) {
    uint64_t res = 0xfeebdaed;
    asm("\tsyscall;\n"
        : "=a"(res)
        : "0"(109), "D"(pid), "S"(pgid)
        : "rcx", "r11", "memory");
    return chk_return<int>(res, hand);
  }






  // __NR__ getppid = 110
  inline int getppid(errhand_t hand = err_log )
      __attribute__((__always_inline__));

  inline int getppid(errhand_t hand) {
    uint64_t res = 0xfeebdaed;
    asm("\tsyscall;\n"
        : "=a"(res)
        : "0"(110)
        : "rcx", "r11", "memory");
    return chk_return<int>(res, hand);
  }






  // __NR__ getpgrp = 111
  inline int getpgrp(errhand_t hand = err_log )
      __attribute__((__always_inline__));

  inline int getpgrp(errhand_t hand) {
    uint64_t res = 0xfeebdaed;
    asm("\tsyscall;\n"
        : "=a"(res)
        : "0"(111)
        : "rcx", "r11", "memory");
    return chk_return<int>(res, hand);
  }






  // __NR__ setsid = 112
  inline int setsid(errhand_t hand = err_log )
      __attribute__((__always_inline__));

  inline int setsid(errhand_t hand) {
    uint64_t res = 0xfeebdaed;
    asm("\tsyscall;\n"
        : "=a"(res)
        : "0"(112)
        : "rcx", "r11", "memory");
    return chk_return<int>(res, hand);
  }






  // __NR__ setreuid = 113
  inline int setreuid(uid_t ruid, uid_t euid, errhand_t hand = err_log )
      __attribute__((__always_inline__));

  inline int setreuid(uid_t ruid, uid_t euid, errhand_t hand) {
    uint64_t res = 0xfeebdaed;
    asm("\tsyscall;\n"
        : "=a"(res)
        : "0"(113), "D"(ruid), "S"(euid)
        : "rcx", "r11", "memory");
    return chk_return<int>(res, hand);
  }






  // __NR__ setregid = 114
  inline int setregid(gid_t rgid, gid_t egid, errhand_t hand = err_log )
      __attribute__((__always_inline__));

  inline int setregid(gid_t rgid, gid_t egid, errhand_t hand) {
    uint64_t res = 0xfeebdaed;
    asm("\tsyscall;\n"
        : "=a"(res)
        : "0"(114), "D"(rgid), "S"(egid)
        : "rcx", "r11", "memory");
    return chk_return<int>(res, hand);
  }






  // __NR__ getgroups = 115
  inline int getgroups(int gidsetsize, gid_p grouplist, errhand_t hand = err_log )
      __attribute__((__always_inline__));

  inline int getgroups(int gidsetsize, gid_p grouplist, errhand_t hand) {
    uint64_t res = 0xfeebdaed;
    asm("\tsyscall;\n"
        : "=a"(res)
        : "0"(115), "D"(gidsetsize), "S"(grouplist)
        : "rcx", "r11", "memory");
    return chk_return<int>(res, hand);
  }






  // __NR__ setgroups = 116
  inline int setgroups(int gidsetsize, gid_p grouplist, errhand_t hand = err_log )
      __attribute__((__always_inline__));

  inline int setgroups(int gidsetsize, gid_p grouplist, errhand_t hand) {
    uint64_t res = 0xfeebdaed;
    asm("\tsyscall;\n"
        : "=a"(res)
        : "0"(116), "D"(gidsetsize), "S"(grouplist)
        : "rcx", "r11", "memory");
    return chk_return<int>(res, hand);
  }






  // __NR__ setresuid = 117
  inline int setresuid(uid_p ruid, uid_p euid, uid_p suid, errhand_t hand = err_log )
      __attribute__((__always_inline__));

  inline int setresuid(uid_p ruid, uid_p euid, uid_p suid, errhand_t hand) {
    uint64_t res = 0xfeebdaed;
    asm("\tsyscall;\n"
        : "=a"(res)
        : "0"(117), "D"(ruid), "S"(euid), "d"(suid)
        : "rcx", "r11", "memory");
    return chk_return<int>(res, hand);
  }






  // __NR__ getresuid = 118
  inline int getresuid(uid_p ruid, uid_p euid, uid_p suid, errhand_t hand = err_log )
      __attribute__((__always_inline__));

  inline int getresuid(uid_p ruid, uid_p euid, uid_p suid, errhand_t hand) {
    uint64_t res = 0xfeebdaed;
    asm("\tsyscall;\n"
        : "=a"(res)
        : "0"(118), "D"(ruid), "S"(euid), "d"(suid)
        : "rcx", "r11", "memory");
    return chk_return<int>(res, hand);
  }






  // __NR__ setresgid = 119
  inline int setresgid(gid_t rgid, gid_t egid, gid_t sgid, errhand_t hand = err_log )
      __attribute__((__always_inline__));

  inline int setresgid(gid_t rgid, gid_t egid, gid_t sgid, errhand_t hand) {
    uint64_t res = 0xfeebdaed;
    asm("\tsyscall;\n"
        : "=a"(res)
        : "0"(119), "D"(rgid), "S"(egid), "d"(sgid)
        : "rcx", "r11", "memory");
    return chk_return<int>(res, hand);
  }






  // __NR__ getresgid = 120
  inline int getresgid(gid_p rgid, gid_p egid, gid_p sgid, errhand_t hand = err_log )
      __attribute__((__always_inline__));

  inline int getresgid(gid_p rgid, gid_p egid, gid_p sgid, errhand_t hand) {
    uint64_t res = 0xfeebdaed;
    asm("\tsyscall;\n"
        : "=a"(res)
        : "0"(120), "D"(rgid), "S"(egid), "d"(sgid)
        : "rcx", "r11", "memory");
    return chk_return<int>(res, hand);
  }






  // __NR__ getpgid = 121
  inline int getpgid(pid_t pid, errhand_t hand = err_log )
      __attribute__((__always_inline__));

  inline int getpgid(pid_t pid, errhand_t hand) {
    uint64_t res = 0xfeebdaed;
    asm("\tsyscall;\n"
        : "=a"(res)
        : "0"(121), "D"(pid)
        : "rcx", "r11", "memory");
    return chk_return<int>(res, hand);
  }






  // __NR__ setfsuid = 122
  inline int setfsuid(uid_t uid, errhand_t hand = err_log )
      __attribute__((__always_inline__));

  inline int setfsuid(uid_t uid, errhand_t hand) {
    uint64_t res = 0xfeebdaed;
    asm("\tsyscall;\n"
        : "=a"(res)
        : "0"(122), "D"(uid)
        : "rcx", "r11", "memory");
    return chk_return<int>(res, hand);
  }






  // __NR__ setfsgid = 123
  inline int setfsgid(gid_t gid, errhand_t hand = err_log )
      __attribute__((__always_inline__));

  inline int setfsgid(gid_t gid, errhand_t hand) {
    uint64_t res = 0xfeebdaed;
    asm("\tsyscall;\n"
        : "=a"(res)
        : "0"(123), "D"(gid)
        : "rcx", "r11", "memory");
    return chk_return<int>(res, hand);
  }






  // __NR__ getsid = 124
  inline int getsid(pid_t pid, errhand_t hand = err_log )
      __attribute__((__always_inline__));

  inline int getsid(pid_t pid, errhand_t hand) {
    uint64_t res = 0xfeebdaed;
    asm("\tsyscall;\n"
        : "=a"(res)
        : "0"(124), "D"(pid)
        : "rcx", "r11", "memory");
    return chk_return<int>(res, hand);
  }






  // __NR__ capget = 125
  inline int capget(cap_user_header_t header, cap_user_data_t dataptr, errhand_t hand = err_log )
      __attribute__((__always_inline__));

  inline int capget(cap_user_header_t header, cap_user_data_t dataptr, errhand_t hand) {
    uint64_t res = 0xfeebdaed;
    asm("\tsyscall;\n"
        : "=a"(res)
        : "0"(125), "D"(header), "S"(dataptr)
        : "rcx", "r11", "memory");
    return chk_return<int>(res, hand);
  }






  // __NR__ capset = 126
  inline int capset(cap_user_header_t header, const cap_user_data_t data, errhand_t hand = err_log )
      __attribute__((__always_inline__));

  inline int capset(cap_user_header_t header, const cap_user_data_t data, errhand_t hand) {
    uint64_t res = 0xfeebdaed;
    asm("\tsyscall;\n"
        : "=a"(res)
        : "0"(126), "D"(header), "S"(data)
        : "rcx", "r11", "memory");
    return chk_return<int>(res, hand);
  }






  // __NR__ rt_sigpending = 127
  inline int rt_sigpending(sigset_p set, size_t sigsetsize, errhand_t hand = err_log )
      __attribute__((__always_inline__));

  inline int rt_sigpending(sigset_p set, size_t sigsetsize, errhand_t hand) {
    uint64_t res = 0xfeebdaed;
    asm("\tsyscall;\n"
        : "=a"(res)
        : "0"(127), "D"(set), "S"(sigsetsize)
        : "rcx", "r11", "memory");
    return chk_return<int>(res, hand);
  }






  // __NR__ rt_sigtimedwait = 128
  inline int rt_sigtimedwait(const sigset_p uthese, siginfo_p uinfo, timespec_p uts, size_t sigsetsize, errhand_t hand = err_log )
      __attribute__((__always_inline__));

  inline int rt_sigtimedwait(const sigset_p uthese, siginfo_p uinfo, timespec_p uts, size_t sigsetsize, errhand_t hand) {
    uint64_t res = 0xfeebdaed;
    asm("\tsyscall;\n"
        : "=a"(res)
        : "0"(128), "D"(uthese), "S"(uinfo), "d"(uts), "r10"(sigsetsize)
        : "rcx", "r11", "memory");
    return chk_return<int>(res, hand);
  }






  // __NR__ rt_sigqueueinfo = 129
  inline int rt_sigqueueinfo(pid_t pid, int sig, siginfo_p uinfo, errhand_t hand = err_log )
      __attribute__((__always_inline__));

  inline int rt_sigqueueinfo(pid_t pid, int sig, siginfo_p uinfo, errhand_t hand) {
    uint64_t res = 0xfeebdaed;
    asm("\tsyscall;\n"
        : "=a"(res)
        : "0"(129), "D"(pid), "S"(sig), "d"(uinfo)
        : "rcx", "r11", "memory");
    return chk_return<int>(res, hand);
  }






  // __NR__ rt_sigsuspend = 130
  inline int rt_sigsuspend(sigset_p unewset, size_t sigsetsize, errhand_t hand = err_log )
      __attribute__((__always_inline__));

  inline int rt_sigsuspend(sigset_p unewset, size_t sigsetsize, errhand_t hand) {
    uint64_t res = 0xfeebdaed;
    asm("\tsyscall;\n"
        : "=a"(res)
        : "0"(130), "D"(unewset), "S"(sigsetsize)
        : "rcx", "r11", "memory");
    return chk_return<int>(res, hand);
  }






  // __NR__ sigaltstack = 131
  inline int sigaltstack(const stack_p uss, stack_p uoss, errhand_t hand = err_log )
      __attribute__((__always_inline__));

  inline int sigaltstack(const stack_p uss, stack_p uoss, errhand_t hand) {
    uint64_t res = 0xfeebdaed;
    asm("\tsyscall;\n"
        : "=a"(res)
        : "0"(131), "D"(uss), "S"(uoss)
        : "rcx", "r11", "memory");
    return chk_return<int>(res, hand);
  }






  // __NR__ utime = 132
  inline int utime(ostr_t path, utimbuf_p times, errhand_t hand = err_log )
      __attribute__((__always_inline__));

  inline int utime(ostr_t path, utimbuf_p times, errhand_t hand) {
    uint64_t res = 0xfeebdaed;
    asm("\tsyscall;\n"
        : "=a"(res)
        : "0"(132), "D"(path), "S"(times)
        : "rcx", "r11", "memory");
    return chk_return<int>(res, hand);
  }






  // __NR__ mknod = 133
  inline int mknod(istr_t path, umode_t mode, unsigned dev, errhand_t hand = err_log )
      __attribute__((__always_inline__));

  inline int mknod(istr_t path, umode_t mode, unsigned dev, errhand_t hand) {
    uint64_t res = 0xfeebdaed;
    asm("\tsyscall;\n"
        : "=a"(res)
        : "0"(133), "D"(path), "S"(mode), "d"(dev)
        : "rcx", "r11", "memory");
    return chk_return<int>(res, hand);
  }






  // __NR__ personality = 135
  inline int personality(unsigned personality, errhand_t hand = err_log )
      __attribute__((__always_inline__));

  inline int personality(unsigned personality, errhand_t hand) {
    uint64_t res = 0xfeebdaed;
    asm("\tsyscall;\n"
        : "=a"(res)
        : "0"(135), "D"(personality)
        : "rcx", "r11", "memory");
    return chk_return<int>(res, hand);
  }






  // __NR__ ustat = 136
  inline int ustat(unsigned dev, ustat_p ubuf, errhand_t hand = err_log )
      __attribute__((__always_inline__));

  inline int ustat(unsigned dev, ustat_p ubuf, errhand_t hand) {
    uint64_t res = 0xfeebdaed;
    asm("\tsyscall;\n"
        : "=a"(res)
        : "0"(136), "D"(dev), "S"(ubuf)
        : "rcx", "r11", "memory");
    return chk_return<int>(res, hand);
  }






  // __NR__ statfs = 137
  inline int statfs(istr_t path, statfs_p buf, errhand_t hand = err_log )
      __attribute__((__always_inline__));

  inline int statfs(istr_t path, statfs_p buf, errhand_t hand) {
    uint64_t res = 0xfeebdaed;
    asm("\tsyscall;\n"
        : "=a"(res)
        : "0"(137), "D"(path), "S"(buf)
        : "rcx", "r11", "memory");
    return chk_return<int>(res, hand);
  }






  // __NR__ fstatfs = 138
  inline int fstatfs(fd_t fd, statfs_p buf, errhand_t hand = err_log )
      __attribute__((__always_inline__));

  inline int fstatfs(fd_t fd, statfs_p buf, errhand_t hand) {
    uint64_t res = 0xfeebdaed;
    asm("\tsyscall;\n"
        : "=a"(res)
        : "0"(138), "D"(fd), "S"(buf)
        : "rcx", "r11", "memory");
    return chk_return<int>(res, hand);
  }






  // __NR__ sysfs = 139
  inline int sysfs(int option, uint64_t arg1, uint64_t arg2, errhand_t hand = err_log )
      __attribute__((__always_inline__));

  inline int sysfs(int option, uint64_t arg1, uint64_t arg2, errhand_t hand) {
    uint64_t res = 0xfeebdaed;
    asm("\tsyscall;\n"
        : "=a"(res)
        : "0"(139), "D"(option), "S"(arg1), "d"(arg2)
        : "rcx", "r11", "memory");
    return chk_return<int>(res, hand);
  }






  // __NR__ getpriority = 140
  inline int getpriority(int which, int who, errhand_t hand = err_log )
      __attribute__((__always_inline__));

  inline int getpriority(int which, int who, errhand_t hand) {
    uint64_t res = 0xfeebdaed;
    asm("\tsyscall;\n"
        : "=a"(res)
        : "0"(140), "D"(which), "S"(who)
        : "rcx", "r11", "memory");
    return chk_return<int>(res, hand);
  }






  // __NR__ setpriority = 141
  inline int setpriority(int which, int who, int niceval, errhand_t hand = err_log )
      __attribute__((__always_inline__));

  inline int setpriority(int which, int who, int niceval, errhand_t hand) {
    uint64_t res = 0xfeebdaed;
    asm("\tsyscall;\n"
        : "=a"(res)
        : "0"(141), "D"(which), "S"(who), "d"(niceval)
        : "rcx", "r11", "memory");
    return chk_return<int>(res, hand);
  }






  // __NR__ sched_setparam = 142
  inline int sys_sched_setparam(pid_t pid, const void * param, errhand_t hand = err_log )
      __attribute__((__always_inline__));

  inline int sys_sched_setparam(pid_t pid, const void * param, errhand_t hand) {
    uint64_t res = 0xfeebdaed;
    asm("\tsyscall;\n"
        : "=a"(res)
        : "0"(142), "D"(pid), "S"(param)
        : "rcx", "r11", "memory");
    return chk_return<int>(res, hand);
  }






  // __NR__ sched_getparam = 143
  inline int sched_getparam(pid_t pid, sched_param_p param, errhand_t hand = err_log )
      __attribute__((__always_inline__));

  inline int sched_getparam(pid_t pid, sched_param_p param, errhand_t hand) {
    uint64_t res = 0xfeebdaed;
    asm("\tsyscall;\n"
        : "=a"(res)
        : "0"(143), "D"(pid), "S"(param)
        : "rcx", "r11", "memory");
    return chk_return<int>(res, hand);
  }






  // __NR__ sched_setscheduler = 144
  inline int sys_sched_setscheduler(pid_t pid, int policy, sched_param_p param, errhand_t hand = err_log )
      __attribute__((__always_inline__));

  inline int sys_sched_setscheduler(pid_t pid, int policy, sched_param_p param, errhand_t hand) {
    uint64_t res = 0xfeebdaed;
    asm("\tsyscall;\n"
        : "=a"(res)
        : "0"(144), "D"(pid), "S"(policy), "d"(param)
        : "rcx", "r11", "memory");
    return chk_return<int>(res, hand);
  }






  // __NR__ sched_getscheduler = 145
  inline int sched_getscheduler(pid_t pid, errhand_t hand = err_log )
      __attribute__((__always_inline__));

  inline int sched_getscheduler(pid_t pid, errhand_t hand) {
    uint64_t res = 0xfeebdaed;
    asm("\tsyscall;\n"
        : "=a"(res)
        : "0"(145), "D"(pid)
        : "rcx", "r11", "memory");
    return chk_return<int>(res, hand);
  }






  // __NR__ sched_get_priority_max = 146
  inline int sched_get_priority_max(int policy, errhand_t hand = err_log )
      __attribute__((__always_inline__));

  inline int sched_get_priority_max(int policy, errhand_t hand) {
    uint64_t res = 0xfeebdaed;
    asm("\tsyscall;\n"
        : "=a"(res)
        : "0"(146), "D"(policy)
        : "rcx", "r11", "memory");
    return chk_return<int>(res, hand);
  }






  // __NR__ sched_get_priority_min = 147
  inline int sched_get_priority_min(int policy, errhand_t hand = err_log )
      __attribute__((__always_inline__));

  inline int sched_get_priority_min(int policy, errhand_t hand) {
    uint64_t res = 0xfeebdaed;
    asm("\tsyscall;\n"
        : "=a"(res)
        : "0"(147), "D"(policy)
        : "rcx", "r11", "memory");
    return chk_return<int>(res, hand);
  }






  // __NR__ sched_rr_get_interval = 148
  inline int sched_rr_get_interval(pid_t pid, timespec_p interval, errhand_t hand = err_log )
      __attribute__((__always_inline__));

  inline int sched_rr_get_interval(pid_t pid, timespec_p interval, errhand_t hand) {
    uint64_t res = 0xfeebdaed;
    asm("\tsyscall;\n"
        : "=a"(res)
        : "0"(148), "D"(pid), "S"(interval)
        : "rcx", "r11", "memory");
    return chk_return<int>(res, hand);
  }






  // __NR__ mlock = 149
  inline int mlock(void_p start, size_t len, errhand_t hand = err_log )
      __attribute__((__always_inline__));

  inline int mlock(void_p start, size_t len, errhand_t hand) {
    uint64_t res = 0xfeebdaed;
    asm("\tsyscall;\n"
        : "=a"(res)
        : "0"(149), "D"(start), "S"(len)
        : "rcx", "r11", "memory");
    return chk_return<int>(res, hand);
  }






  // __NR__ munlock = 150
  inline int munlock(void_p start, size_t len, errhand_t hand = err_log )
      __attribute__((__always_inline__));

  inline int munlock(void_p start, size_t len, errhand_t hand) {
    uint64_t res = 0xfeebdaed;
    asm("\tsyscall;\n"
        : "=a"(res)
        : "0"(150), "D"(start), "S"(len)
        : "rcx", "r11", "memory");
    return chk_return<int>(res, hand);
  }






  // __NR__ mlockall = 151
  inline int mlockall(int flags, errhand_t hand = err_log )
      __attribute__((__always_inline__));

  inline int mlockall(int flags, errhand_t hand) {
    uint64_t res = 0xfeebdaed;
    asm("\tsyscall;\n"
        : "=a"(res)
        : "0"(151), "D"(flags)
        : "rcx", "r11", "memory");
    return chk_return<int>(res, hand);
  }






  // __NR__ munlockall = 152
  inline int munlockall(errhand_t hand = err_log )
      __attribute__((__always_inline__));

  inline int munlockall(errhand_t hand) {
    uint64_t res = 0xfeebdaed;
    asm("\tsyscall;\n"
        : "=a"(res)
        : "0"(152)
        : "rcx", "r11", "memory");
    return chk_return<int>(res, hand);
  }






  // __NR__ vhangup = 153
  inline int vhangup(errhand_t hand = err_log )
      __attribute__((__always_inline__));

  inline int vhangup(errhand_t hand) {
    uint64_t res = 0xfeebdaed;
    asm("\tsyscall;\n"
        : "=a"(res)
        : "0"(153)
        : "rcx", "r11", "memory");
    return chk_return<int>(res, hand);
  }






  // __NR__ modify_ldt = 154
  inline int modify_ldt(int func, void_p ptr, uint64_t bytecount, errhand_t hand = err_log )
      __attribute__((__always_inline__));

  inline int modify_ldt(int func, void_p ptr, uint64_t bytecount, errhand_t hand) {
    uint64_t res = 0xfeebdaed;
    asm("\tsyscall;\n"
        : "=a"(res)
        : "0"(154), "D"(func), "S"(ptr), "d"(bytecount)
        : "rcx", "r11", "memory");
    return chk_return<int>(res, hand);
  }






  // __NR__ pivot_root = 155
  inline int pivot_root(istr_t new_root, istr_t put_old, errhand_t hand = err_log )
      __attribute__((__always_inline__));

  inline int pivot_root(istr_t new_root, istr_t put_old, errhand_t hand) {
    uint64_t res = 0xfeebdaed;
    asm("\tsyscall;\n"
        : "=a"(res)
        : "0"(155), "D"(new_root), "S"(put_old)
        : "rcx", "r11", "memory");
    return chk_return<int>(res, hand);
  }






  // __NR__ _sysctl = 156
  inline int _sysctl(sysctl_args_p args, errhand_t hand = err_log )
      __attribute__((__always_inline__));

  inline int _sysctl(sysctl_args_p args, errhand_t hand) {
    uint64_t res = 0xfeebdaed;
    asm("\tsyscall;\n"
        : "=a"(res)
        : "0"(156), "D"(args)
        : "rcx", "r11", "memory");
    return chk_return<int>(res, hand);
  }






  // __NR__ prctl = 157
  inline int prctl(int option, uint64_t arg2, uint64_t arg3, uint64_t arg4, uint64_t arg5, errhand_t hand = err_log )
      __attribute__((__always_inline__));

  inline int prctl(int option, uint64_t arg2, uint64_t arg3, uint64_t arg4, uint64_t arg5, errhand_t hand) {
    uint64_t res = 0xfeebdaed;
    asm("\tsyscall;\n"
        : "=a"(res)
        : "0"(157), "D"(option), "S"(arg2), "d"(arg3), "r10"(arg4), "r8"(arg5)
        : "rcx", "r11", "memory");
    return chk_return<int>(res, hand);
  }






  // __NR__ arch_prctl = 158
  inline int arch_prctl(task_struct_p task, int code, uint64_t addr, errhand_t hand = err_log )
      __attribute__((__always_inline__));

  inline int arch_prctl(task_struct_p task, int code, uint64_t addr, errhand_t hand) {
    uint64_t res = 0xfeebdaed;
    asm("\tsyscall;\n"
        : "=a"(res)
        : "0"(158), "D"(task), "S"(code), "d"(addr)
        : "rcx", "r11", "memory");
    return chk_return<int>(res, hand);
  }






  // __NR__ adjtimex = 159
  inline int adjtimex(timex_p txc_p, errhand_t hand = err_log )
      __attribute__((__always_inline__));

  inline int adjtimex(timex_p txc_p, errhand_t hand) {
    uint64_t res = 0xfeebdaed;
    asm("\tsyscall;\n"
        : "=a"(res)
        : "0"(159), "D"(txc_p)
        : "rcx", "r11", "memory");
    return chk_return<int>(res, hand);
  }






  // __NR__ setrlimit = 160
  inline int setrlimit(unsigned resource, rlimit_p rlim, errhand_t hand = err_log )
      __attribute__((__always_inline__));

  inline int setrlimit(unsigned resource, rlimit_p rlim, errhand_t hand) {
    uint64_t res = 0xfeebdaed;
    asm("\tsyscall;\n"
        : "=a"(res)
        : "0"(160), "D"(resource), "S"(rlim)
        : "rcx", "r11", "memory");
    return chk_return<int>(res, hand);
  }






  // __NR__ chroot = 161
  inline int chroot(istr_t path, errhand_t hand = err_log )
      __attribute__((__always_inline__));

  inline int chroot(istr_t path, errhand_t hand) {
    uint64_t res = 0xfeebdaed;
    asm("\tsyscall;\n"
        : "=a"(res)
        : "0"(161), "D"(path)
        : "rcx", "r11", "memory");
    return chk_return<int>(res, hand);
  }






  // __NR__ sync = 162
  inline int sync(errhand_t hand = err_log )
      __attribute__((__always_inline__));

  inline int sync(errhand_t hand) {
    uint64_t res = 0xfeebdaed;
    asm("\tsyscall;\n"
        : "=a"(res)
        : "0"(162)
        : "rcx", "r11", "memory");
    return chk_return<int>(res, hand);
  }






  // __NR__ acct = 163
  inline int acct(istr_t name, errhand_t hand = err_log )
      __attribute__((__always_inline__));

  inline int acct(istr_t name, errhand_t hand) {
    uint64_t res = 0xfeebdaed;
    asm("\tsyscall;\n"
        : "=a"(res)
        : "0"(163), "D"(name)
        : "rcx", "r11", "memory");
    return chk_return<int>(res, hand);
  }






  // __NR__ settimeofday = 164
  inline int settimeofday(timeval_p tv, timezone_p tz, errhand_t hand = err_log )
      __attribute__((__always_inline__));

  inline int settimeofday(timeval_p tv, timezone_p tz, errhand_t hand) {
    uint64_t res = 0xfeebdaed;
    asm("\tsyscall;\n"
        : "=a"(res)
        : "0"(164), "D"(tv), "S"(tz)
        : "rcx", "r11", "memory");
    return chk_return<int>(res, hand);
  }






  // __NR__ mount = 165
  inline int mount(ostr_t dev_name, ostr_t dir_name, ostr_t type, uint64_t flags, void_p data, errhand_t hand = err_log )
      __attribute__((__always_inline__));

  inline int mount(ostr_t dev_name, ostr_t dir_name, ostr_t type, uint64_t flags, void_p data, errhand_t hand) {
    uint64_t res = 0xfeebdaed;
    asm("\tsyscall;\n"
        : "=a"(res)
        : "0"(165), "D"(dev_name), "S"(dir_name), "d"(type), "r10"(flags), "r8"(data)
        : "rcx", "r11", "memory");
    return chk_return<int>(res, hand);
  }






  // __NR__ umount2 = 166
  inline int umount2(istr_t target, int flags, errhand_t hand = err_log )
      __attribute__((__always_inline__));

  inline int umount2(istr_t target, int flags, errhand_t hand) {
    uint64_t res = 0xfeebdaed;
    asm("\tsyscall;\n"
        : "=a"(res)
        : "0"(166), "D"(target), "S"(flags)
        : "rcx", "r11", "memory");
    return chk_return<int>(res, hand);
  }






  // __NR__ swapon = 167
  inline int swapon(istr_t specialfile, int swap_flags, errhand_t hand = err_log )
      __attribute__((__always_inline__));

  inline int swapon(istr_t specialfile, int swap_flags, errhand_t hand) {
    uint64_t res = 0xfeebdaed;
    asm("\tsyscall;\n"
        : "=a"(res)
        : "0"(167), "D"(specialfile), "S"(swap_flags)
        : "rcx", "r11", "memory");
    return chk_return<int>(res, hand);
  }






  // __NR__ swapoff = 168
  inline int swapoff(istr_t specialfile, errhand_t hand = err_log )
      __attribute__((__always_inline__));

  inline int swapoff(istr_t specialfile, errhand_t hand) {
    uint64_t res = 0xfeebdaed;
    asm("\tsyscall;\n"
        : "=a"(res)
        : "0"(168), "D"(specialfile)
        : "rcx", "r11", "memory");
    return chk_return<int>(res, hand);
  }






  // __NR__ reboot = 169
  inline int reboot(int magic1, int magic2, unsigned cmd, void_p arg, errhand_t hand = err_log )
      __attribute__((__always_inline__));

  inline int reboot(int magic1, int magic2, unsigned cmd, void_p arg, errhand_t hand) {
    uint64_t res = 0xfeebdaed;
    asm("\tsyscall;\n"
        : "=a"(res)
        : "0"(169), "D"(magic1), "S"(magic2), "d"(cmd), "r10"(arg)
        : "rcx", "r11", "memory");
    return chk_return<int>(res, hand);
  }






  // __NR__ sethostname = 170
  inline int sethostname(ostr_t name, int len, errhand_t hand = err_log )
      __attribute__((__always_inline__));

  inline int sethostname(ostr_t name, int len, errhand_t hand) {
    uint64_t res = 0xfeebdaed;
    asm("\tsyscall;\n"
        : "=a"(res)
        : "0"(170), "D"(name), "S"(len)
        : "rcx", "r11", "memory");
    return chk_return<int>(res, hand);
  }






  // __NR__ setdomainname = 171
  inline int setdomainname(ostr_t name, int len, errhand_t hand = err_log )
      __attribute__((__always_inline__));

  inline int setdomainname(ostr_t name, int len, errhand_t hand) {
    uint64_t res = 0xfeebdaed;
    asm("\tsyscall;\n"
        : "=a"(res)
        : "0"(171), "D"(name), "S"(len)
        : "rcx", "r11", "memory");
    return chk_return<int>(res, hand);
  }






  // __NR__ iopl = 172
  inline int iopl(unsigned level, pt_regs_p regs, errhand_t hand = err_log )
      __attribute__((__always_inline__));

  inline int iopl(unsigned level, pt_regs_p regs, errhand_t hand) {
    uint64_t res = 0xfeebdaed;
    asm("\tsyscall;\n"
        : "=a"(res)
        : "0"(172), "D"(level), "S"(regs)
        : "rcx", "r11", "memory");
    return chk_return<int>(res, hand);
  }






  // __NR__ ioperm = 173
  inline int ioperm(uint64_t from, uint64_t num, int turn_on, errhand_t hand = err_log )
      __attribute__((__always_inline__));

  inline int ioperm(uint64_t from, uint64_t num, int turn_on, errhand_t hand) {
    uint64_t res = 0xfeebdaed;
    asm("\tsyscall;\n"
        : "=a"(res)
        : "0"(173), "D"(from), "S"(num), "d"(turn_on)
        : "rcx", "r11", "memory");
    return chk_return<int>(res, hand);
  }






  // __NR__ init_module = 175
  inline int init_module(void_p umod, uint64_t len, istr_t uargs, errhand_t hand = err_log )
      __attribute__((__always_inline__));

  inline int init_module(void_p umod, uint64_t len, istr_t uargs, errhand_t hand) {
    uint64_t res = 0xfeebdaed;
    asm("\tsyscall;\n"
        : "=a"(res)
        : "0"(175), "D"(umod), "S"(len), "d"(uargs)
        : "rcx", "r11", "memory");
    return chk_return<int>(res, hand);
  }






  // __NR__ delete_module = 176
  inline int delete_module(istr_t name_user, unsigned flags, errhand_t hand = err_log )
      __attribute__((__always_inline__));

  inline int delete_module(istr_t name_user, unsigned flags, errhand_t hand) {
    uint64_t res = 0xfeebdaed;
    asm("\tsyscall;\n"
        : "=a"(res)
        : "0"(176), "D"(name_user), "S"(flags)
        : "rcx", "r11", "memory");
    return chk_return<int>(res, hand);
  }






  // __NR__ quotactl = 179
  inline int quotactl(unsigned cmd, istr_t special, qid_t id, void_p addr, errhand_t hand = err_log )
      __attribute__((__always_inline__));

  inline int quotactl(unsigned cmd, istr_t special, qid_t id, void_p addr, errhand_t hand) {
    uint64_t res = 0xfeebdaed;
    asm("\tsyscall;\n"
        : "=a"(res)
        : "0"(179), "D"(cmd), "S"(special), "d"(id), "r10"(addr)
        : "rcx", "r11", "memory");
    return chk_return<int>(res, hand);
  }






  // __NR__ gettid = 186
  inline int gettid(errhand_t hand = err_log )
      __attribute__((__always_inline__));

  inline int gettid(errhand_t hand) {
    uint64_t res = 0xfeebdaed;
    asm("\tsyscall;\n"
        : "=a"(res)
        : "0"(186)
        : "rcx", "r11", "memory");
    return chk_return<int>(res, hand);
  }






  // __NR__ readahead = 187
  inline int readahead(fd_t fd, off_t offset, size_t count, errhand_t hand = err_log )
      __attribute__((__always_inline__));

  inline int readahead(fd_t fd, off_t offset, size_t count, errhand_t hand) {
    uint64_t res = 0xfeebdaed;
    asm("\tsyscall;\n"
        : "=a"(res)
        : "0"(187), "D"(fd), "S"(offset), "d"(count)
        : "rcx", "r11", "memory");
    return chk_return<int>(res, hand);
  }






  // __NR__ setxattr = 188
  inline int setxattr(istr_t path, istr_t name, const void_p value, size_t size, int flags, errhand_t hand = err_log )
      __attribute__((__always_inline__));

  inline int setxattr(istr_t path, istr_t name, const void_p value, size_t size, int flags, errhand_t hand) {
    uint64_t res = 0xfeebdaed;
    asm("\tsyscall;\n"
        : "=a"(res)
        : "0"(188), "D"(path), "S"(name), "d"(value), "r10"(size), "r8"(flags)
        : "rcx", "r11", "memory");
    return chk_return<int>(res, hand);
  }






  // __NR__ lsetxattr = 189
  inline int lsetxattr(istr_t path, istr_t name, const void_p value, size_t size, int flags, errhand_t hand = err_log )
      __attribute__((__always_inline__));

  inline int lsetxattr(istr_t path, istr_t name, const void_p value, size_t size, int flags, errhand_t hand) {
    uint64_t res = 0xfeebdaed;
    asm("\tsyscall;\n"
        : "=a"(res)
        : "0"(189), "D"(path), "S"(name), "d"(value), "r10"(size), "r8"(flags)
        : "rcx", "r11", "memory");
    return chk_return<int>(res, hand);
  }






  // __NR__ fsetxattr = 190
  inline int fsetxattr(fd_t fd, istr_t name, const void_p value, size_t size, int flags, errhand_t hand = err_log )
      __attribute__((__always_inline__));

  inline int fsetxattr(fd_t fd, istr_t name, const void_p value, size_t size, int flags, errhand_t hand) {
    uint64_t res = 0xfeebdaed;
    asm("\tsyscall;\n"
        : "=a"(res)
        : "0"(190), "D"(fd), "S"(name), "d"(value), "r10"(size), "r8"(flags)
        : "rcx", "r11", "memory");
    return chk_return<int>(res, hand);
  }






  // __NR__ getxattr = 191
  inline int getxattr(istr_t path, istr_t name, void_p value, size_t size, errhand_t hand = err_log )
      __attribute__((__always_inline__));

  inline int getxattr(istr_t path, istr_t name, void_p value, size_t size, errhand_t hand) {
    uint64_t res = 0xfeebdaed;
    asm("\tsyscall;\n"
        : "=a"(res)
        : "0"(191), "D"(path), "S"(name), "d"(value), "r10"(size)
        : "rcx", "r11", "memory");
    return chk_return<int>(res, hand);
  }






  // __NR__ lgetxattr = 192
  inline int lgetxattr(istr_t path, istr_t name, void_p value, size_t size, errhand_t hand = err_log )
      __attribute__((__always_inline__));

  inline int lgetxattr(istr_t path, istr_t name, void_p value, size_t size, errhand_t hand) {
    uint64_t res = 0xfeebdaed;
    asm("\tsyscall;\n"
        : "=a"(res)
        : "0"(192), "D"(path), "S"(name), "d"(value), "r10"(size)
        : "rcx", "r11", "memory");
    return chk_return<int>(res, hand);
  }






  // __NR__ fgetxattr = 193
  inline int fgetxattr(fd_t fd, istr_t name, void_p value, size_t size, errhand_t hand = err_log )
      __attribute__((__always_inline__));

  inline int fgetxattr(fd_t fd, istr_t name, void_p value, size_t size, errhand_t hand) {
    uint64_t res = 0xfeebdaed;
    asm("\tsyscall;\n"
        : "=a"(res)
        : "0"(193), "D"(fd), "S"(name), "d"(value), "r10"(size)
        : "rcx", "r11", "memory");
    return chk_return<int>(res, hand);
  }






  // __NR__ listxattr = 194
  inline int listxattr(istr_t path, ostr_t list, size_t size, errhand_t hand = err_log )
      __attribute__((__always_inline__));

  inline int listxattr(istr_t path, ostr_t list, size_t size, errhand_t hand) {
    uint64_t res = 0xfeebdaed;
    asm("\tsyscall;\n"
        : "=a"(res)
        : "0"(194), "D"(path), "S"(list), "d"(size)
        : "rcx", "r11", "memory");
    return chk_return<int>(res, hand);
  }






  // __NR__ llistxattr = 195
  inline int llistxattr(istr_t path, ostr_t list, size_t size, errhand_t hand = err_log )
      __attribute__((__always_inline__));

  inline int llistxattr(istr_t path, ostr_t list, size_t size, errhand_t hand) {
    uint64_t res = 0xfeebdaed;
    asm("\tsyscall;\n"
        : "=a"(res)
        : "0"(195), "D"(path), "S"(list), "d"(size)
        : "rcx", "r11", "memory");
    return chk_return<int>(res, hand);
  }






  // __NR__ flistxattr = 196
  inline int flistxattr(fd_t fd, ostr_t list, size_t size, errhand_t hand = err_log )
      __attribute__((__always_inline__));

  inline int flistxattr(fd_t fd, ostr_t list, size_t size, errhand_t hand) {
    uint64_t res = 0xfeebdaed;
    asm("\tsyscall;\n"
        : "=a"(res)
        : "0"(196), "D"(fd), "S"(list), "d"(size)
        : "rcx", "r11", "memory");
    return chk_return<int>(res, hand);
  }






  // __NR__ removexattr = 197
  inline int removexattr(istr_t path, istr_t name, errhand_t hand = err_log )
      __attribute__((__always_inline__));

  inline int removexattr(istr_t path, istr_t name, errhand_t hand) {
    uint64_t res = 0xfeebdaed;
    asm("\tsyscall;\n"
        : "=a"(res)
        : "0"(197), "D"(path), "S"(name)
        : "rcx", "r11", "memory");
    return chk_return<int>(res, hand);
  }






  // __NR__ lremovexattr = 198
  inline int lremovexattr(istr_t path, istr_t name, errhand_t hand = err_log )
      __attribute__((__always_inline__));

  inline int lremovexattr(istr_t path, istr_t name, errhand_t hand) {
    uint64_t res = 0xfeebdaed;
    asm("\tsyscall;\n"
        : "=a"(res)
        : "0"(198), "D"(path), "S"(name)
        : "rcx", "r11", "memory");
    return chk_return<int>(res, hand);
  }






  // __NR__ fremovexattr = 199
  inline int fremovexattr(fd_t fd, istr_t name, errhand_t hand = err_log )
      __attribute__((__always_inline__));

  inline int fremovexattr(fd_t fd, istr_t name, errhand_t hand) {
    uint64_t res = 0xfeebdaed;
    asm("\tsyscall;\n"
        : "=a"(res)
        : "0"(199), "D"(fd), "S"(name)
        : "rcx", "r11", "memory");
    return chk_return<int>(res, hand);
  }






  // __NR__ tkill = 200
  inline int tkill(pid_t pid, int sig, errhand_t hand = err_log )
      __attribute__((__always_inline__));

  inline int tkill(pid_t pid, int sig, errhand_t hand) {
    uint64_t res = 0xfeebdaed;
    asm("\tsyscall;\n"
        : "=a"(res)
        : "0"(200), "D"(pid), "S"(sig)
        : "rcx", "r11", "memory");
    return chk_return<int>(res, hand);
  }






  // __NR__ time = 201
  inline time_t time(time_p tloc, errhand_t hand = err_log )
      __attribute__((__always_inline__));

  inline time_t time(time_p tloc, errhand_t hand) {
    uint64_t res = 0xfeebdaed;
    asm("\tsyscall;\n"
        : "=a"(res)
        : "0"(201), "D"(tloc)
        : "rcx", "r11", "memory");
    return chk_return<time_t>(res, hand);
  }






  // __NR__ futex = 202
  inline int futex(uint32_p uaddr, int op, uint32_t val, timespec_p utime, uint32_p uaddr2, uint32_t val3, errhand_t hand = err_log )
      __attribute__((__always_inline__));

  inline int futex(uint32_p uaddr, int op, uint32_t val, timespec_p utime, uint32_p uaddr2, uint32_t val3, errhand_t hand) {
    uint64_t res = 0xfeebdaed;
    asm("\tsyscall;\n"
        : "=a"(res)
        : "0"(202), "D"(uaddr), "S"(op), "d"(val), "r10"(utime), "r8"(uaddr2), "r9"(val3)
        : "rcx", "r11", "memory");
    return chk_return<int>(res, hand);
  }






  // __NR__ sched_setaffinity = 203
  inline int sys_sched_setaffinity(pid_t pid, size_t len, const void * user_mask_ptr, errhand_t hand = err_log )
      __attribute__((__always_inline__));

  inline int sys_sched_setaffinity(pid_t pid, size_t len, const void * user_mask_ptr, errhand_t hand) {
    uint64_t res = 0xfeebdaed;
    asm("\tsyscall;\n"
        : "=a"(res)
        : "0"(203), "D"(pid), "S"(len), "d"(user_mask_ptr)
        : "rcx", "r11", "memory");
    return chk_return<int>(res, hand);
  }






  // __NR__ sched_getaffinity = 204
  inline int sys_sched_getaffinity(pid_t pid, unsigned len, uint64_p user_mask_ptr, errhand_t hand = err_log )
      __attribute__((__always_inline__));

  inline int sys_sched_getaffinity(pid_t pid, unsigned len, uint64_p user_mask_ptr, errhand_t hand) {
    uint64_t res = 0xfeebdaed;
    asm("\tsyscall;\n"
        : "=a"(res)
        : "0"(204), "D"(pid), "S"(len), "d"(user_mask_ptr)
        : "rcx", "r11", "memory");
    return chk_return<int>(res, hand);
  }






  // __NR__ io_setup = 206
  inline int io_setup(unsigned nr_events, aio_context_p ctxp, errhand_t hand = err_log )
      __attribute__((__always_inline__));

  inline int io_setup(unsigned nr_events, aio_context_p ctxp, errhand_t hand) {
    uint64_t res = 0xfeebdaed;
    asm("\tsyscall;\n"
        : "=a"(res)
        : "0"(206), "D"(nr_events), "S"(ctxp)
        : "rcx", "r11", "memory");
    return chk_return<int>(res, hand);
  }






  // __NR__ io_destroy = 207
  inline int io_destroy(aio_context_t ctx, errhand_t hand = err_log )
      __attribute__((__always_inline__));

  inline int io_destroy(aio_context_t ctx, errhand_t hand) {
    uint64_t res = 0xfeebdaed;
    asm("\tsyscall;\n"
        : "=a"(res)
        : "0"(207), "D"(ctx)
        : "rcx", "r11", "memory");
    return chk_return<int>(res, hand);
  }






  // __NR__ io_getevents = 208
  inline int io_getevents(aio_context_t ctx_id, long min_nr, long nr, io_event_p events, errhand_t hand = err_log )
      __attribute__((__always_inline__));

  inline int io_getevents(aio_context_t ctx_id, long min_nr, long nr, io_event_p events, errhand_t hand) {
    uint64_t res = 0xfeebdaed;
    asm("\tsyscall;\n"
        : "=a"(res)
        : "0"(208), "D"(ctx_id), "S"(min_nr), "d"(nr), "r10"(events)
        : "rcx", "r11", "memory");
    return chk_return<int>(res, hand);
  }






  // __NR__ io_submit = 209
  inline int io_submit(aio_context_t ctx_id, long nr, iocb_p iocbpp, errhand_t hand = err_log )
      __attribute__((__always_inline__));

  inline int io_submit(aio_context_t ctx_id, long nr, iocb_p iocbpp, errhand_t hand) {
    uint64_t res = 0xfeebdaed;
    asm("\tsyscall;\n"
        : "=a"(res)
        : "0"(209), "D"(ctx_id), "S"(nr), "d"(iocbpp)
        : "rcx", "r11", "memory");
    return chk_return<int>(res, hand);
  }






  // __NR__ io_cancel = 210
  inline int io_cancel(aio_context_t ctx_id, iocb_p iocb, io_event_p result, errhand_t hand = err_log )
      __attribute__((__always_inline__));

  inline int io_cancel(aio_context_t ctx_id, iocb_p iocb, io_event_p result, errhand_t hand) {
    uint64_t res = 0xfeebdaed;
    asm("\tsyscall;\n"
        : "=a"(res)
        : "0"(210), "D"(ctx_id), "S"(iocb), "d"(result)
        : "rcx", "r11", "memory");
    return chk_return<int>(res, hand);
  }






  // __NR__ lookup_dcookie = 212
  inline int lookup_dcookie(uint64_t cookie64, long buf, long len, errhand_t hand = err_log )
      __attribute__((__always_inline__));

  inline int lookup_dcookie(uint64_t cookie64, long buf, long len, errhand_t hand) {
    uint64_t res = 0xfeebdaed;
    asm("\tsyscall;\n"
        : "=a"(res)
        : "0"(212), "D"(cookie64), "S"(buf), "d"(len)
        : "rcx", "r11", "memory");
    return chk_return<int>(res, hand);
  }






  // __NR__ epoll_create = 213
  inline int epoll_create(int size, errhand_t hand = err_log )
      __attribute__((__always_inline__));

  inline int epoll_create(int size, errhand_t hand) {
    uint64_t res = 0xfeebdaed;
    asm("\tsyscall;\n"
        : "=a"(res)
        : "0"(213), "D"(size)
        : "rcx", "r11", "memory");
    return chk_return<int>(res, hand);
  }






  // __NR__ remap_file_pages = 216
  inline int remap_file_pages(uint64_t start, uint64_t size, uint64_t prot, uint64_t pgoff, uint64_t flags, errhand_t hand = err_log )
      __attribute__((__always_inline__));

  inline int remap_file_pages(uint64_t start, uint64_t size, uint64_t prot, uint64_t pgoff, uint64_t flags, errhand_t hand) {
    uint64_t res = 0xfeebdaed;
    asm("\tsyscall;\n"
        : "=a"(res)
        : "0"(216), "D"(start), "S"(size), "d"(prot), "r10"(pgoff), "r8"(flags)
        : "rcx", "r11", "memory");
    return chk_return<int>(res, hand);
  }






  // __NR__ getdents64 = 217
  inline int getdents64(fd_t fd, linux_dirent64_p dirent, unsigned count, errhand_t hand = err_log )
      __attribute__((__always_inline__));

  inline int getdents64(fd_t fd, linux_dirent64_p dirent, unsigned count, errhand_t hand) {
    uint64_t res = 0xfeebdaed;
    asm("\tsyscall;\n"
        : "=a"(res)
        : "0"(217), "D"(fd), "S"(dirent), "d"(count)
        : "rcx", "r11", "memory");
    return chk_return<int>(res, hand);
  }






  // __NR__ set_tid_address = 218
  inline int set_tid_address(int32_p tidptr, errhand_t hand = err_log )
      __attribute__((__always_inline__));

  inline int set_tid_address(int32_p tidptr, errhand_t hand) {
    uint64_t res = 0xfeebdaed;
    asm("\tsyscall;\n"
        : "=a"(res)
        : "0"(218), "D"(tidptr)
        : "rcx", "r11", "memory");
    return chk_return<int>(res, hand);
  }






  // __NR__ restart_syscall = 219
  inline int restart_syscall(errhand_t hand = err_log )
      __attribute__((__always_inline__));

  inline int restart_syscall(errhand_t hand) {
    uint64_t res = 0xfeebdaed;
    asm("\tsyscall;\n"
        : "=a"(res)
        : "0"(219)
        : "rcx", "r11", "memory");
    return chk_return<int>(res, hand);
  }






  // __NR__ semtimedop = 220
  inline int semtimedop(int semid, sembuf_p tsops, unsigned nsops, timespec_p timeout, errhand_t hand = err_log )
      __attribute__((__always_inline__));

  inline int semtimedop(int semid, sembuf_p tsops, unsigned nsops, timespec_p timeout, errhand_t hand) {
    uint64_t res = 0xfeebdaed;
    asm("\tsyscall;\n"
        : "=a"(res)
        : "0"(220), "D"(semid), "S"(tsops), "d"(nsops), "r10"(timeout)
        : "rcx", "r11", "memory");
    return chk_return<int>(res, hand);
  }






  // __NR__ fadvise64 = 221
  inline int fadvise64(fd_t fd, off_t offset, size_t len, int advice, errhand_t hand = err_log )
      __attribute__((__always_inline__));

  inline int fadvise64(fd_t fd, off_t offset, size_t len, int advice, errhand_t hand) {
    uint64_t res = 0xfeebdaed;
    asm("\tsyscall;\n"
        : "=a"(res)
        : "0"(221), "D"(fd), "S"(offset), "d"(len), "r10"(advice)
        : "rcx", "r11", "memory");
    return chk_return<int>(res, hand);
  }






  // __NR__ timer_create = 222
  inline int timer_create(const clockid_t which_clock, sigevent_p timer_event_spec, timer_p created_timer_id, errhand_t hand = err_log )
      __attribute__((__always_inline__));

  inline int timer_create(const clockid_t which_clock, sigevent_p timer_event_spec, timer_p created_timer_id, errhand_t hand) {
    uint64_t res = 0xfeebdaed;
    asm("\tsyscall;\n"
        : "=a"(res)
        : "0"(222), "D"(which_clock), "S"(timer_event_spec), "d"(created_timer_id)
        : "rcx", "r11", "memory");
    return chk_return<int>(res, hand);
  }






  // __NR__ timer_settime = 223
  inline int timer_settime(timer_t timer_id, int flags, itimerspec_p new_setting, itimerspec_p old_setting, errhand_t hand = err_log )
      __attribute__((__always_inline__));

  inline int timer_settime(timer_t timer_id, int flags, itimerspec_p new_setting, itimerspec_p old_setting, errhand_t hand) {
    uint64_t res = 0xfeebdaed;
    asm("\tsyscall;\n"
        : "=a"(res)
        : "0"(223), "D"(timer_id), "S"(flags), "d"(new_setting), "r10"(old_setting)
        : "rcx", "r11", "memory");
    return chk_return<int>(res, hand);
  }






  // __NR__ timer_gettime = 224
  inline int timer_gettime(timer_t timer_id, itimerspec_p setting, errhand_t hand = err_log )
      __attribute__((__always_inline__));

  inline int timer_gettime(timer_t timer_id, itimerspec_p setting, errhand_t hand) {
    uint64_t res = 0xfeebdaed;
    asm("\tsyscall;\n"
        : "=a"(res)
        : "0"(224), "D"(timer_id), "S"(setting)
        : "rcx", "r11", "memory");
    return chk_return<int>(res, hand);
  }






  // __NR__ timer_getoverrun = 225
  inline int timer_getoverrun(timer_t timer_id, errhand_t hand = err_log )
      __attribute__((__always_inline__));

  inline int timer_getoverrun(timer_t timer_id, errhand_t hand) {
    uint64_t res = 0xfeebdaed;
    asm("\tsyscall;\n"
        : "=a"(res)
        : "0"(225), "D"(timer_id)
        : "rcx", "r11", "memory");
    return chk_return<int>(res, hand);
  }






  // __NR__ timer_delete = 226
  inline int timer_delete(timer_t timer_id, errhand_t hand = err_log )
      __attribute__((__always_inline__));

  inline int timer_delete(timer_t timer_id, errhand_t hand) {
    uint64_t res = 0xfeebdaed;
    asm("\tsyscall;\n"
        : "=a"(res)
        : "0"(226), "D"(timer_id)
        : "rcx", "r11", "memory");
    return chk_return<int>(res, hand);
  }






  // __NR__ clock_settime = 227
  inline int clock_settime(const clockid_t which_clock, timespec_p tp, errhand_t hand = err_log )
      __attribute__((__always_inline__));

  inline int clock_settime(const clockid_t which_clock, timespec_p tp, errhand_t hand) {
    uint64_t res = 0xfeebdaed;
    asm("\tsyscall;\n"
        : "=a"(res)
        : "0"(227), "D"(which_clock), "S"(tp)
        : "rcx", "r11", "memory");
    return chk_return<int>(res, hand);
  }






  // __NR__ clock_gettime = 228
  inline int clock_gettime(const clockid_t which_clock, timespec_p tp, errhand_t hand = err_log )
      __attribute__((__always_inline__));

  inline int clock_gettime(const clockid_t which_clock, timespec_p tp, errhand_t hand) {
    uint64_t res = 0xfeebdaed;
    asm("\tsyscall;\n"
        : "=a"(res)
        : "0"(228), "D"(which_clock), "S"(tp)
        : "rcx", "r11", "memory");
    return chk_return<int>(res, hand);
  }






  // __NR__ clock_getres = 229
  inline int clock_getres(const clockid_t which_clock, timespec_p tp, errhand_t hand = err_log )
      __attribute__((__always_inline__));

  inline int clock_getres(const clockid_t which_clock, timespec_p tp, errhand_t hand) {
    uint64_t res = 0xfeebdaed;
    asm("\tsyscall;\n"
        : "=a"(res)
        : "0"(229), "D"(which_clock), "S"(tp)
        : "rcx", "r11", "memory");
    return chk_return<int>(res, hand);
  }






  // __NR__ clock_nanosleep = 230
  inline int clock_nanosleep(const clockid_t which_clock, int flags, timespec_p rqtp, timespec_p rmtp, errhand_t hand = err_log )
      __attribute__((__always_inline__));

  inline int clock_nanosleep(const clockid_t which_clock, int flags, timespec_p rqtp, timespec_p rmtp, errhand_t hand) {
    uint64_t res = 0xfeebdaed;
    asm("\tsyscall;\n"
        : "=a"(res)
        : "0"(230), "D"(which_clock), "S"(flags), "d"(rqtp), "r10"(rmtp)
        : "rcx", "r11", "memory");
    return chk_return<int>(res, hand);
  }






  // __NR__ exit_group = 231
  inline int exit_group(int error_code, errhand_t hand = err_log )
      __attribute__((__always_inline__));

  inline int exit_group(int error_code, errhand_t hand) {
    uint64_t res = 0xfeebdaed;
    asm("\tsyscall;\n"
        : "=a"(res)
        : "0"(231), "D"(error_code)
        : "rcx", "r11", "memory");
    return chk_return<int>(res, hand);
  }






  // __NR__ epoll_wait = 232
  inline int epoll_wait(int epfd, epoll_event_p events, int maxevents, int timeout, errhand_t hand = err_log )
      __attribute__((__always_inline__));

  inline int epoll_wait(int epfd, epoll_event_p events, int maxevents, int timeout, errhand_t hand) {
    uint64_t res = 0xfeebdaed;
    asm("\tsyscall;\n"
        : "=a"(res)
        : "0"(232), "D"(epfd), "S"(events), "d"(maxevents), "r10"(timeout)
        : "rcx", "r11", "memory");
    return chk_return<int>(res, hand);
  }






  // __NR__ epoll_ctl = 233
  inline int epoll_ctl(int epfd, int op, fd_t fd, epoll_event_p event, errhand_t hand = err_log )
      __attribute__((__always_inline__));

  inline int epoll_ctl(int epfd, int op, fd_t fd, epoll_event_p event, errhand_t hand) {
    uint64_t res = 0xfeebdaed;
    asm("\tsyscall;\n"
        : "=a"(res)
        : "0"(233), "D"(epfd), "S"(op), "d"(fd), "r10"(event)
        : "rcx", "r11", "memory");
    return chk_return<int>(res, hand);
  }






  // __NR__ tgkill = 234
  inline int tgkill(pid_t tgid, pid_t pid, int sig, errhand_t hand = err_log )
      __attribute__((__always_inline__));

  inline int tgkill(pid_t tgid, pid_t pid, int sig, errhand_t hand) {
    uint64_t res = 0xfeebdaed;
    asm("\tsyscall;\n"
        : "=a"(res)
        : "0"(234), "D"(tgid), "S"(pid), "d"(sig)
        : "rcx", "r11", "memory");
    return chk_return<int>(res, hand);
  }






  // __NR__ utimes = 235
  inline int utimes(ostr_t path, timeval_p utimes, errhand_t hand = err_log )
      __attribute__((__always_inline__));

  inline int utimes(ostr_t path, timeval_p utimes, errhand_t hand) {
    uint64_t res = 0xfeebdaed;
    asm("\tsyscall;\n"
        : "=a"(res)
        : "0"(235), "D"(path), "S"(utimes)
        : "rcx", "r11", "memory");
    return chk_return<int>(res, hand);
  }






  // __NR__ mbind = 237
  inline int mbind(uint64_t start, uint64_t len, uint64_t mode, uint64_p nmask, uint64_t maxnode, unsigned flags, errhand_t hand = err_log )
      __attribute__((__always_inline__));

  inline int mbind(uint64_t start, uint64_t len, uint64_t mode, uint64_p nmask, uint64_t maxnode, unsigned flags, errhand_t hand) {
    uint64_t res = 0xfeebdaed;
    asm("\tsyscall;\n"
        : "=a"(res)
        : "0"(237), "D"(start), "S"(len), "d"(mode), "r10"(nmask), "r8"(maxnode), "r9"(flags)
        : "rcx", "r11", "memory");
    return chk_return<int>(res, hand);
  }






  // __NR__ set_mempolicy = 238
  inline int set_mempolicy(int mode, uint64_p nmask, uint64_t maxnode, errhand_t hand = err_log )
      __attribute__((__always_inline__));

  inline int set_mempolicy(int mode, uint64_p nmask, uint64_t maxnode, errhand_t hand) {
    uint64_t res = 0xfeebdaed;
    asm("\tsyscall;\n"
        : "=a"(res)
        : "0"(238), "D"(mode), "S"(nmask), "d"(maxnode)
        : "rcx", "r11", "memory");
    return chk_return<int>(res, hand);
  }






  // __NR__ get_mempolicy = 239
  inline int get_mempolicy(int32_p policy, uint64_p nmask, uint64_t maxnode, uint64_t addr, uint64_t flags, errhand_t hand = err_log )
      __attribute__((__always_inline__));

  inline int get_mempolicy(int32_p policy, uint64_p nmask, uint64_t maxnode, uint64_t addr, uint64_t flags, errhand_t hand) {
    uint64_t res = 0xfeebdaed;
    asm("\tsyscall;\n"
        : "=a"(res)
        : "0"(239), "D"(policy), "S"(nmask), "d"(maxnode), "r10"(addr), "r8"(flags)
        : "rcx", "r11", "memory");
    return chk_return<int>(res, hand);
  }






  // __NR__ mq_open = 240
  inline int mq_open(istr_t u_name, int oflag, mode_t mode, mq_attr_p u_attr, errhand_t hand = err_log )
      __attribute__((__always_inline__));

  inline int mq_open(istr_t u_name, int oflag, mode_t mode, mq_attr_p u_attr, errhand_t hand) {
    uint64_t res = 0xfeebdaed;
    asm("\tsyscall;\n"
        : "=a"(res)
        : "0"(240), "D"(u_name), "S"(oflag), "d"(mode), "r10"(u_attr)
        : "rcx", "r11", "memory");
    return chk_return<int>(res, hand);
  }






  // __NR__ mq_unlink = 241
  inline int mq_unlink(istr_t u_name, errhand_t hand = err_log )
      __attribute__((__always_inline__));

  inline int mq_unlink(istr_t u_name, errhand_t hand) {
    uint64_t res = 0xfeebdaed;
    asm("\tsyscall;\n"
        : "=a"(res)
        : "0"(241), "D"(u_name)
        : "rcx", "r11", "memory");
    return chk_return<int>(res, hand);
  }






  // __NR__ mq_timedsend = 242
  inline int mq_timedsend(mqd_t mqdes, istr_t u_msg_ptr, size_t msg_len, unsigned msg_prio, timespec_p u_abs_timeout, errhand_t hand = err_log )
      __attribute__((__always_inline__));

  inline int mq_timedsend(mqd_t mqdes, istr_t u_msg_ptr, size_t msg_len, unsigned msg_prio, timespec_p u_abs_timeout, errhand_t hand) {
    uint64_t res = 0xfeebdaed;
    asm("\tsyscall;\n"
        : "=a"(res)
        : "0"(242), "D"(mqdes), "S"(u_msg_ptr), "d"(msg_len), "r10"(msg_prio), "r8"(u_abs_timeout)
        : "rcx", "r11", "memory");
    return chk_return<int>(res, hand);
  }






  // __NR__ mq_timedreceive = 243
  inline int mq_timedreceive(mqd_t mqdes, ostr_t u_msg_ptr, size_t msg_len, uint32_p u_msg_prio, timespec_p u_abs_timeout, errhand_t hand = err_log )
      __attribute__((__always_inline__));

  inline int mq_timedreceive(mqd_t mqdes, ostr_t u_msg_ptr, size_t msg_len, uint32_p u_msg_prio, timespec_p u_abs_timeout, errhand_t hand) {
    uint64_t res = 0xfeebdaed;
    asm("\tsyscall;\n"
        : "=a"(res)
        : "0"(243), "D"(mqdes), "S"(u_msg_ptr), "d"(msg_len), "r10"(u_msg_prio), "r8"(u_abs_timeout)
        : "rcx", "r11", "memory");
    return chk_return<int>(res, hand);
  }






  // __NR__ mq_notify = 244
  inline int mq_notify(mqd_t mqdes, sigevent_p u_notification, errhand_t hand = err_log )
      __attribute__((__always_inline__));

  inline int mq_notify(mqd_t mqdes, sigevent_p u_notification, errhand_t hand) {
    uint64_t res = 0xfeebdaed;
    asm("\tsyscall;\n"
        : "=a"(res)
        : "0"(244), "D"(mqdes), "S"(u_notification)
        : "rcx", "r11", "memory");
    return chk_return<int>(res, hand);
  }






  // __NR__ mq_getsetattr = 245
  inline int mq_getsetattr(mqd_t mqdes, mq_attr_p u_mqstat, mq_attr_p u_omqstat, errhand_t hand = err_log )
      __attribute__((__always_inline__));

  inline int mq_getsetattr(mqd_t mqdes, mq_attr_p u_mqstat, mq_attr_p u_omqstat, errhand_t hand) {
    uint64_t res = 0xfeebdaed;
    asm("\tsyscall;\n"
        : "=a"(res)
        : "0"(245), "D"(mqdes), "S"(u_mqstat), "d"(u_omqstat)
        : "rcx", "r11", "memory");
    return chk_return<int>(res, hand);
  }






  // __NR__ kexec_load = 246
  inline int kexec_load(uint64_t entry, uint64_t nr_segments, kexec_segment_p segments, uint64_t flags, errhand_t hand = err_log )
      __attribute__((__always_inline__));

  inline int kexec_load(uint64_t entry, uint64_t nr_segments, kexec_segment_p segments, uint64_t flags, errhand_t hand) {
    uint64_t res = 0xfeebdaed;
    asm("\tsyscall;\n"
        : "=a"(res)
        : "0"(246), "D"(entry), "S"(nr_segments), "d"(segments), "r10"(flags)
        : "rcx", "r11", "memory");
    return chk_return<int>(res, hand);
  }






  // __NR__ waitid = 247
  inline int waitid(int which, pid_t upid, siginfo_p infop, int options, rusage_p ru, errhand_t hand = err_log )
      __attribute__((__always_inline__));

  inline int waitid(int which, pid_t upid, siginfo_p infop, int options, rusage_p ru, errhand_t hand) {
    uint64_t res = 0xfeebdaed;
    asm("\tsyscall;\n"
        : "=a"(res)
        : "0"(247), "D"(which), "S"(upid), "d"(infop), "r10"(options), "r8"(ru)
        : "rcx", "r11", "memory");
    return chk_return<int>(res, hand);
  }






  // __NR__ add_key = 248
  inline int add_key(istr_t _type, istr_t _description, const void_p _payload, size_t plen, errhand_t hand = err_log )
      __attribute__((__always_inline__));

  inline int add_key(istr_t _type, istr_t _description, const void_p _payload, size_t plen, errhand_t hand) {
    uint64_t res = 0xfeebdaed;
    asm("\tsyscall;\n"
        : "=a"(res)
        : "0"(248), "D"(_type), "S"(_description), "d"(_payload), "r10"(plen)
        : "rcx", "r11", "memory");
    return chk_return<int>(res, hand);
  }






  // __NR__ request_key = 249
  inline int request_key(istr_t _type, istr_t _description, istr_t _callout_info, uint64_t destringid, errhand_t hand = err_log )
      __attribute__((__always_inline__));

  inline int request_key(istr_t _type, istr_t _description, istr_t _callout_info, uint64_t destringid, errhand_t hand) {
    uint64_t res = 0xfeebdaed;
    asm("\tsyscall;\n"
        : "=a"(res)
        : "0"(249), "D"(_type), "S"(_description), "d"(_callout_info), "r10"(destringid)
        : "rcx", "r11", "memory");
    return chk_return<int>(res, hand);
  }






  // __NR__ keyctl = 250
  inline int keyctl(int option, uint64_t arg2, uint64_t arg3, uint64_t arg4, uint64_t arg5, errhand_t hand = err_log )
      __attribute__((__always_inline__));

  inline int keyctl(int option, uint64_t arg2, uint64_t arg3, uint64_t arg4, uint64_t arg5, errhand_t hand) {
    uint64_t res = 0xfeebdaed;
    asm("\tsyscall;\n"
        : "=a"(res)
        : "0"(250), "D"(option), "S"(arg2), "d"(arg3), "r10"(arg4), "r8"(arg5)
        : "rcx", "r11", "memory");
    return chk_return<int>(res, hand);
  }






  // __NR__ ioprio_set = 251
  inline int ioprio_set(int which, int who, int ioprio, errhand_t hand = err_log )
      __attribute__((__always_inline__));

  inline int ioprio_set(int which, int who, int ioprio, errhand_t hand) {
    uint64_t res = 0xfeebdaed;
    asm("\tsyscall;\n"
        : "=a"(res)
        : "0"(251), "D"(which), "S"(who), "d"(ioprio)
        : "rcx", "r11", "memory");
    return chk_return<int>(res, hand);
  }






  // __NR__ ioprio_get = 252
  inline int ioprio_get(int which, int who, errhand_t hand = err_log )
      __attribute__((__always_inline__));

  inline int ioprio_get(int which, int who, errhand_t hand) {
    uint64_t res = 0xfeebdaed;
    asm("\tsyscall;\n"
        : "=a"(res)
        : "0"(252), "D"(which), "S"(who)
        : "rcx", "r11", "memory");
    return chk_return<int>(res, hand);
  }






  // __NR__ inotify_init = 253
  inline int inotify_init(errhand_t hand = err_log )
      __attribute__((__always_inline__));

  inline int inotify_init(errhand_t hand) {
    uint64_t res = 0xfeebdaed;
    asm("\tsyscall;\n"
        : "=a"(res)
        : "0"(253)
        : "rcx", "r11", "memory");
    return chk_return<int>(res, hand);
  }






  // __NR__ inotify_add_watch = 254
  inline int inotify_add_watch(fd_t fd, istr_t path, uint32_t mask, errhand_t hand = err_log )
      __attribute__((__always_inline__));

  inline int inotify_add_watch(fd_t fd, istr_t path, uint32_t mask, errhand_t hand) {
    uint64_t res = 0xfeebdaed;
    asm("\tsyscall;\n"
        : "=a"(res)
        : "0"(254), "D"(fd), "S"(path), "d"(mask)
        : "rcx", "r11", "memory");
    return chk_return<int>(res, hand);
  }






  // __NR__ inotify_rm_watch = 255
  inline int inotify_rm_watch(fd_t fd, int32_t wd, errhand_t hand = err_log )
      __attribute__((__always_inline__));

  inline int inotify_rm_watch(fd_t fd, int32_t wd, errhand_t hand) {
    uint64_t res = 0xfeebdaed;
    asm("\tsyscall;\n"
        : "=a"(res)
        : "0"(255), "D"(fd), "S"(wd)
        : "rcx", "r11", "memory");
    return chk_return<int>(res, hand);
  }






  // __NR__ migrate_pages = 256
  inline int migrate_pages(pid_t pid, uint64_t maxnode, uint64_p old_nodes, uint64_p new_nodes, errhand_t hand = err_log )
      __attribute__((__always_inline__));

  inline int migrate_pages(pid_t pid, uint64_t maxnode, uint64_p old_nodes, uint64_p new_nodes, errhand_t hand) {
    uint64_t res = 0xfeebdaed;
    asm("\tsyscall;\n"
        : "=a"(res)
        : "0"(256), "D"(pid), "S"(maxnode), "d"(old_nodes), "r10"(new_nodes)
        : "rcx", "r11", "memory");
    return chk_return<int>(res, hand);
  }






  // __NR__ openat = 257
  inline int openat(fd_t dfd, istr_t path, int flags, int mode, errhand_t hand = err_log )
      __attribute__((__always_inline__));

  inline int openat(fd_t dfd, istr_t path, int flags, int mode, errhand_t hand) {
    uint64_t res = 0xfeebdaed;
    asm("\tsyscall;\n"
        : "=a"(res)
        : "0"(257), "D"(dfd), "S"(path), "d"(flags), "r10"(mode)
        : "rcx", "r11", "memory");
    return chk_return<int>(res, hand);
  }






  // __NR__ mkdirat = 258
  inline int mkdirat(fd_t dfd, istr_t path, int mode, errhand_t hand = err_log )
      __attribute__((__always_inline__));

  inline int mkdirat(fd_t dfd, istr_t path, int mode, errhand_t hand) {
    uint64_t res = 0xfeebdaed;
    asm("\tsyscall;\n"
        : "=a"(res)
        : "0"(258), "D"(dfd), "S"(path), "d"(mode)
        : "rcx", "r11", "memory");
    return chk_return<int>(res, hand);
  }






  // __NR__ mknodat = 259
  inline int mknodat(fd_t dfd, istr_t path, int mode, unsigned dev, errhand_t hand = err_log )
      __attribute__((__always_inline__));

  inline int mknodat(fd_t dfd, istr_t path, int mode, unsigned dev, errhand_t hand) {
    uint64_t res = 0xfeebdaed;
    asm("\tsyscall;\n"
        : "=a"(res)
        : "0"(259), "D"(dfd), "S"(path), "d"(mode), "r10"(dev)
        : "rcx", "r11", "memory");
    return chk_return<int>(res, hand);
  }






  // __NR__ fchownat = 260
  inline int fchownat(fd_t dfd, istr_t path, uid_t user, gid_t group, int flag, errhand_t hand = err_log )
      __attribute__((__always_inline__));

  inline int fchownat(fd_t dfd, istr_t path, uid_t user, gid_t group, int flag, errhand_t hand) {
    uint64_t res = 0xfeebdaed;
    asm("\tsyscall;\n"
        : "=a"(res)
        : "0"(260), "D"(dfd), "S"(path), "d"(user), "r10"(group), "r8"(flag)
        : "rcx", "r11", "memory");
    return chk_return<int>(res, hand);
  }






  // __NR__ futimesat = 261
  inline int futimesat(fd_t dfd, istr_t path, timeval_p utimes, errhand_t hand = err_log )
      __attribute__((__always_inline__));

  inline int futimesat(fd_t dfd, istr_t path, timeval_p utimes, errhand_t hand) {
    uint64_t res = 0xfeebdaed;
    asm("\tsyscall;\n"
        : "=a"(res)
        : "0"(261), "D"(dfd), "S"(path), "d"(utimes)
        : "rcx", "r11", "memory");
    return chk_return<int>(res, hand);
  }






  // __NR__ newfstatat = 262
  inline int newfstatat(fd_t dfd, istr_t path, stat_p statbuf, int flag, errhand_t hand = err_log )
      __attribute__((__always_inline__));

  inline int newfstatat(fd_t dfd, istr_t path, stat_p statbuf, int flag, errhand_t hand) {
    uint64_t res = 0xfeebdaed;
    asm("\tsyscall;\n"
        : "=a"(res)
        : "0"(262), "D"(dfd), "S"(path), "d"(statbuf), "r10"(flag)
        : "rcx", "r11", "memory");
    return chk_return<int>(res, hand);
  }






  // __NR__ unlinkat = 263
  inline int unlinkat(fd_t dfd, istr_t path, int flag, errhand_t hand = err_log )
      __attribute__((__always_inline__));

  inline int unlinkat(fd_t dfd, istr_t path, int flag, errhand_t hand) {
    uint64_t res = 0xfeebdaed;
    asm("\tsyscall;\n"
        : "=a"(res)
        : "0"(263), "D"(dfd), "S"(path), "d"(flag)
        : "rcx", "r11", "memory");
    return chk_return<int>(res, hand);
  }






  // __NR__ renameat = 264
  inline int renameat(fd_t oldfd, istr_t opath, fd_t newfd, istr_t npath, errhand_t hand = err_log )
      __attribute__((__always_inline__));

  inline int renameat(fd_t oldfd, istr_t opath, fd_t newfd, istr_t npath, errhand_t hand) {
    uint64_t res = 0xfeebdaed;
    asm("\tsyscall;\n"
        : "=a"(res)
        : "0"(264), "D"(oldfd), "S"(opath), "d"(newfd), "r10"(npath)
        : "rcx", "r11", "memory");
    return chk_return<int>(res, hand);
  }






  // __NR__ linkat = 265
  inline int linkat(fd_t oldfd, istr_t opath, fd_t newfd, istr_t npath, int flags, errhand_t hand = err_log )
      __attribute__((__always_inline__));

  inline int linkat(fd_t oldfd, istr_t opath, fd_t newfd, istr_t npath, int flags, errhand_t hand) {
    uint64_t res = 0xfeebdaed;
    asm("\tsyscall;\n"
        : "=a"(res)
        : "0"(265), "D"(oldfd), "S"(opath), "d"(newfd), "r10"(npath), "r8"(flags)
        : "rcx", "r11", "memory");
    return chk_return<int>(res, hand);
  }






  // __NR__ symlinkat = 266
  inline int symlinkat(istr_t opath, fd_t newfd, istr_t npath, errhand_t hand = err_log )
      __attribute__((__always_inline__));

  inline int symlinkat(istr_t opath, fd_t newfd, istr_t npath, errhand_t hand) {
    uint64_t res = 0xfeebdaed;
    asm("\tsyscall;\n"
        : "=a"(res)
        : "0"(266), "D"(opath), "S"(newfd), "d"(npath)
        : "rcx", "r11", "memory");
    return chk_return<int>(res, hand);
  }






  // __NR__ readlinkat = 267
  inline int readlinkat(fd_t dfd, istr_t path, ostr_t buf, int bufsiz, errhand_t hand = err_log )
      __attribute__((__always_inline__));

  inline int readlinkat(fd_t dfd, istr_t path, ostr_t buf, int bufsiz, errhand_t hand) {
    uint64_t res = 0xfeebdaed;
    asm("\tsyscall;\n"
        : "=a"(res)
        : "0"(267), "D"(dfd), "S"(path), "d"(buf), "r10"(bufsiz)
        : "rcx", "r11", "memory");
    return chk_return<int>(res, hand);
  }






  // __NR__ fchmodat = 268
  inline int fchmodat(fd_t dfd, istr_t path, mode_t mode, errhand_t hand = err_log )
      __attribute__((__always_inline__));

  inline int fchmodat(fd_t dfd, istr_t path, mode_t mode, errhand_t hand) {
    uint64_t res = 0xfeebdaed;
    asm("\tsyscall;\n"
        : "=a"(res)
        : "0"(268), "D"(dfd), "S"(path), "d"(mode)
        : "rcx", "r11", "memory");
    return chk_return<int>(res, hand);
  }






  // __NR__ faccessat = 269
  inline int faccessat(fd_t dfd, istr_t path, int mode, errhand_t hand = err_log )
      __attribute__((__always_inline__));

  inline int faccessat(fd_t dfd, istr_t path, int mode, errhand_t hand) {
    uint64_t res = 0xfeebdaed;
    asm("\tsyscall;\n"
        : "=a"(res)
        : "0"(269), "D"(dfd), "S"(path), "d"(mode)
        : "rcx", "r11", "memory");
    return chk_return<int>(res, hand);
  }






  // __NR__ pselect6 = 270
  inline int pselect6(int n, fd_set_p inp, fd_set_p outp, fd_set_p exp, timespec_p tsp, void_p sig, errhand_t hand = err_log )
      __attribute__((__always_inline__));

  inline int pselect6(int n, fd_set_p inp, fd_set_p outp, fd_set_p exp, timespec_p tsp, void_p sig, errhand_t hand) {
    uint64_t res = 0xfeebdaed;
    asm("\tsyscall;\n"
        : "=a"(res)
        : "0"(270), "D"(n), "S"(inp), "d"(outp), "r10"(exp), "r8"(tsp), "r9"(sig)
        : "rcx", "r11", "memory");
    return chk_return<int>(res, hand);
  }






  // __NR__ ppoll = 271
  inline int ppoll(pollfd_p ufds, unsigned nfds, timespec_p tsp, const sigset_p sigmask, size_t sigsetsize, errhand_t hand = err_log )
      __attribute__((__always_inline__));

  inline int ppoll(pollfd_p ufds, unsigned nfds, timespec_p tsp, const sigset_p sigmask, size_t sigsetsize, errhand_t hand) {
    uint64_t res = 0xfeebdaed;
    asm("\tsyscall;\n"
        : "=a"(res)
        : "0"(271), "D"(ufds), "S"(nfds), "d"(tsp), "r10"(sigmask), "r8"(sigsetsize)
        : "rcx", "r11", "memory");
    return chk_return<int>(res, hand);
  }






  // __NR__ unshare = 272
  inline int unshare(int unshare_flags, errhand_t hand = err_log )
      __attribute__((__always_inline__));

  inline int unshare(int unshare_flags, errhand_t hand) {
    uint64_t res = 0xfeebdaed;
    asm("\tsyscall;\n"
        : "=a"(res)
        : "0"(272), "D"(unshare_flags)
        : "rcx", "r11", "memory");
    return chk_return<int>(res, hand);
  }






  // __NR__ set_robust_list = 273
  inline int set_robust_list(robust_list_head_p head, size_t len, errhand_t hand = err_log )
      __attribute__((__always_inline__));

  inline int set_robust_list(robust_list_head_p head, size_t len, errhand_t hand) {
    uint64_t res = 0xfeebdaed;
    asm("\tsyscall;\n"
        : "=a"(res)
        : "0"(273), "D"(head), "S"(len)
        : "rcx", "r11", "memory");
    return chk_return<int>(res, hand);
  }






  // __NR__ get_robust_list = 274
  inline int get_robust_list(int pid, robust_list_head_p head_ptr, size_p len_ptr, errhand_t hand = err_log )
      __attribute__((__always_inline__));

  inline int get_robust_list(int pid, robust_list_head_p head_ptr, size_p len_ptr, errhand_t hand) {
    uint64_t res = 0xfeebdaed;
    asm("\tsyscall;\n"
        : "=a"(res)
        : "0"(274), "D"(pid), "S"(head_ptr), "d"(len_ptr)
        : "rcx", "r11", "memory");
    return chk_return<int>(res, hand);
  }






  // __NR__ splice = 275
  inline int splice(int fd_in, off_p off_in, int fd_out, off_p off_out, size_t len, unsigned flags, errhand_t hand = err_log )
      __attribute__((__always_inline__));

  inline int splice(int fd_in, off_p off_in, int fd_out, off_p off_out, size_t len, unsigned flags, errhand_t hand) {
    uint64_t res = 0xfeebdaed;
    asm("\tsyscall;\n"
        : "=a"(res)
        : "0"(275), "D"(fd_in), "S"(off_in), "d"(fd_out), "r10"(off_out), "r8"(len), "r9"(flags)
        : "rcx", "r11", "memory");
    return chk_return<int>(res, hand);
  }






  // __NR__ tee = 276
  inline int tee(int fdin, int fdout, size_t len, unsigned flags, errhand_t hand = err_log )
      __attribute__((__always_inline__));

  inline int tee(int fdin, int fdout, size_t len, unsigned flags, errhand_t hand) {
    uint64_t res = 0xfeebdaed;
    asm("\tsyscall;\n"
        : "=a"(res)
        : "0"(276), "D"(fdin), "S"(fdout), "d"(len), "r10"(flags)
        : "rcx", "r11", "memory");
    return chk_return<int>(res, hand);
  }






  // __NR__ sync_file_range = 277
  inline int sync_file_range(fd_t fd, off_t offset, off_t bytes, long flags, errhand_t hand = err_log )
      __attribute__((__always_inline__));

  inline int sync_file_range(fd_t fd, off_t offset, off_t bytes, long flags, errhand_t hand) {
    uint64_t res = 0xfeebdaed;
    asm("\tsyscall;\n"
        : "=a"(res)
        : "0"(277), "D"(fd), "S"(offset), "d"(bytes), "r10"(flags)
        : "rcx", "r11", "memory");
    return chk_return<int>(res, hand);
  }






  // __NR__ vmsplice = 278
  inline int vmsplice(fd_t fd, iovec_p iov, uint64_t nr_segs, unsigned flags, errhand_t hand = err_log )
      __attribute__((__always_inline__));

  inline int vmsplice(fd_t fd, iovec_p iov, uint64_t nr_segs, unsigned flags, errhand_t hand) {
    uint64_t res = 0xfeebdaed;
    asm("\tsyscall;\n"
        : "=a"(res)
        : "0"(278), "D"(fd), "S"(iov), "d"(nr_segs), "r10"(flags)
        : "rcx", "r11", "memory");
    return chk_return<int>(res, hand);
  }






  // __NR__ move_pages = 279
  inline int move_pages(pid_t pid, uint64_t nr_pages, void_p pages, int32_p nodes, int32_p status, int flags, errhand_t hand = err_log )
      __attribute__((__always_inline__));

  inline int move_pages(pid_t pid, uint64_t nr_pages, void_p pages, int32_p nodes, int32_p status, int flags, errhand_t hand) {
    uint64_t res = 0xfeebdaed;
    asm("\tsyscall;\n"
        : "=a"(res)
        : "0"(279), "D"(pid), "S"(nr_pages), "d"(pages), "r10"(nodes), "r8"(status), "r9"(flags)
        : "rcx", "r11", "memory");
    return chk_return<int>(res, hand);
  }






  // __NR__ utimensat = 280
  inline int utimensat(fd_t dfd, istr_t path, timespec_p utimes, int flags, errhand_t hand = err_log )
      __attribute__((__always_inline__));

  inline int utimensat(fd_t dfd, istr_t path, timespec_p utimes, int flags, errhand_t hand) {
    uint64_t res = 0xfeebdaed;
    asm("\tsyscall;\n"
        : "=a"(res)
        : "0"(280), "D"(dfd), "S"(path), "d"(utimes), "r10"(flags)
        : "rcx", "r11", "memory");
    return chk_return<int>(res, hand);
  }






  // __NR__ epoll_pwait = 281
  inline int epoll_pwait(int epfd, epoll_event_p events, int maxevents, int timeout, const sigset_p sigmask, size_t sigsetsize, errhand_t hand = err_log )
      __attribute__((__always_inline__));

  inline int epoll_pwait(int epfd, epoll_event_p events, int maxevents, int timeout, const sigset_p sigmask, size_t sigsetsize, errhand_t hand) {
    uint64_t res = 0xfeebdaed;
    asm("\tsyscall;\n"
        : "=a"(res)
        : "0"(281), "D"(epfd), "S"(events), "d"(maxevents), "r10"(timeout), "r8"(sigmask), "r9"(sigsetsize)
        : "rcx", "r11", "memory");
    return chk_return<int>(res, hand);
  }






  // __NR__ signalfd = 282
  inline int signalfd(int ufd, sigset_p user_mask, size_t sizemask, errhand_t hand = err_log )
      __attribute__((__always_inline__));

  inline int signalfd(int ufd, sigset_p user_mask, size_t sizemask, errhand_t hand) {
    uint64_t res = 0xfeebdaed;
    asm("\tsyscall;\n"
        : "=a"(res)
        : "0"(282), "D"(ufd), "S"(user_mask), "d"(sizemask)
        : "rcx", "r11", "memory");
    return chk_return<int>(res, hand);
  }






  // __NR__ timerfd_create = 283
  inline int timerfd_create(int clockid, int flags, errhand_t hand = err_log )
      __attribute__((__always_inline__));

  inline int timerfd_create(int clockid, int flags, errhand_t hand) {
    uint64_t res = 0xfeebdaed;
    asm("\tsyscall;\n"
        : "=a"(res)
        : "0"(283), "D"(clockid), "S"(flags)
        : "rcx", "r11", "memory");
    return chk_return<int>(res, hand);
  }






  // __NR__ eventfd = 284
  inline int eventfd(unsigned count, errhand_t hand = err_log )
      __attribute__((__always_inline__));

  inline int eventfd(unsigned count, errhand_t hand) {
    uint64_t res = 0xfeebdaed;
    asm("\tsyscall;\n"
        : "=a"(res)
        : "0"(284), "D"(count)
        : "rcx", "r11", "memory");
    return chk_return<int>(res, hand);
  }






  // __NR__ fallocate = 285
  inline int fallocate(fd_t fd, long mode, off_t offset, off_t len, errhand_t hand = err_log )
      __attribute__((__always_inline__));

  inline int fallocate(fd_t fd, long mode, off_t offset, off_t len, errhand_t hand) {
    uint64_t res = 0xfeebdaed;
    asm("\tsyscall;\n"
        : "=a"(res)
        : "0"(285), "D"(fd), "S"(mode), "d"(offset), "r10"(len)
        : "rcx", "r11", "memory");
    return chk_return<int>(res, hand);
  }






  // __NR__ timerfd_settime = 286
  inline int timerfd_settime(int ufd, int flags, itimerspec_p utmr, itimerspec_p otmr, errhand_t hand = err_log )
      __attribute__((__always_inline__));

  inline int timerfd_settime(int ufd, int flags, itimerspec_p utmr, itimerspec_p otmr, errhand_t hand) {
    uint64_t res = 0xfeebdaed;
    asm("\tsyscall;\n"
        : "=a"(res)
        : "0"(286), "D"(ufd), "S"(flags), "d"(utmr), "r10"(otmr)
        : "rcx", "r11", "memory");
    return chk_return<int>(res, hand);
  }






  // __NR__ timerfd_gettime = 287
  inline int timerfd_gettime(int ufd, itimerspec_p otmr, errhand_t hand = err_log )
      __attribute__((__always_inline__));

  inline int timerfd_gettime(int ufd, itimerspec_p otmr, errhand_t hand) {
    uint64_t res = 0xfeebdaed;
    asm("\tsyscall;\n"
        : "=a"(res)
        : "0"(287), "D"(ufd), "S"(otmr)
        : "rcx", "r11", "memory");
    return chk_return<int>(res, hand);
  }






  // __NR__ accept4 = 288
  inline int accept4(fd_t fd, sockaddr_p upeer_sockaddr, int32_p upeer_addrlen, int flags, errhand_t hand = err_log )
      __attribute__((__always_inline__));

  inline int accept4(fd_t fd, sockaddr_p upeer_sockaddr, int32_p upeer_addrlen, int flags, errhand_t hand) {
    uint64_t res = 0xfeebdaed;
    asm("\tsyscall;\n"
        : "=a"(res)
        : "0"(288), "D"(fd), "S"(upeer_sockaddr), "d"(upeer_addrlen), "r10"(flags)
        : "rcx", "r11", "memory");
    return chk_return<int>(res, hand);
  }






  // __NR__ signalfd4 = 289
  inline int signalfd4(int ufd, sigset_p user_mask, size_t sizemask, int flags, errhand_t hand = err_log )
      __attribute__((__always_inline__));

  inline int signalfd4(int ufd, sigset_p user_mask, size_t sizemask, int flags, errhand_t hand) {
    uint64_t res = 0xfeebdaed;
    asm("\tsyscall;\n"
        : "=a"(res)
        : "0"(289), "D"(ufd), "S"(user_mask), "d"(sizemask), "r10"(flags)
        : "rcx", "r11", "memory");
    return chk_return<int>(res, hand);
  }






  // __NR__ eventfd2 = 290
  inline int eventfd2(unsigned count, int flags, errhand_t hand = err_log )
      __attribute__((__always_inline__));

  inline int eventfd2(unsigned count, int flags, errhand_t hand) {
    uint64_t res = 0xfeebdaed;
    asm("\tsyscall;\n"
        : "=a"(res)
        : "0"(290), "D"(count), "S"(flags)
        : "rcx", "r11", "memory");
    return chk_return<int>(res, hand);
  }






  // __NR__ epoll_create1 = 291
  inline int epoll_create1(int flags, errhand_t hand = err_log )
      __attribute__((__always_inline__));

  inline int epoll_create1(int flags, errhand_t hand) {
    uint64_t res = 0xfeebdaed;
    asm("\tsyscall;\n"
        : "=a"(res)
        : "0"(291), "D"(flags)
        : "rcx", "r11", "memory");
    return chk_return<int>(res, hand);
  }






  // __NR__ dup3 = 292
  inline int dup3(fd_t oldfd, fd_t newfd, int flags, errhand_t hand = err_log )
      __attribute__((__always_inline__));

  inline int dup3(fd_t oldfd, fd_t newfd, int flags, errhand_t hand) {
    uint64_t res = 0xfeebdaed;
    asm("\tsyscall;\n"
        : "=a"(res)
        : "0"(292), "D"(oldfd), "S"(newfd), "d"(flags)
        : "rcx", "r11", "memory");
    return chk_return<int>(res, hand);
  }






  // __NR__ pipe2 = 293
  inline int pipe2(fd_p filedes, int flags, errhand_t hand = err_log )
      __attribute__((__always_inline__));

  inline int pipe2(fd_p filedes, int flags, errhand_t hand) {
    uint64_t res = 0xfeebdaed;
    asm("\tsyscall;\n"
        : "=a"(res)
        : "0"(293), "D"(filedes), "S"(flags)
        : "rcx", "r11", "memory");
    return chk_return<int>(res, hand);
  }






  // __NR__ inotify_init1 = 294
  inline int inotify_init1(int flags, errhand_t hand = err_log )
      __attribute__((__always_inline__));

  inline int inotify_init1(int flags, errhand_t hand) {
    uint64_t res = 0xfeebdaed;
    asm("\tsyscall;\n"
        : "=a"(res)
        : "0"(294), "D"(flags)
        : "rcx", "r11", "memory");
    return chk_return<int>(res, hand);
  }






  // __NR__ preadv = 295
  inline int preadv(fd_t fd, iovec_p vec, uint64_t vlen, uint64_t pos_l, uint64_t pos_h, errhand_t hand = err_log )
      __attribute__((__always_inline__));

  inline int preadv(fd_t fd, iovec_p vec, uint64_t vlen, uint64_t pos_l, uint64_t pos_h, errhand_t hand) {
    uint64_t res = 0xfeebdaed;
    asm("\tsyscall;\n"
        : "=a"(res)
        : "0"(295), "D"(fd), "S"(vec), "d"(vlen), "r10"(pos_l), "r8"(pos_h)
        : "rcx", "r11", "memory");
    return chk_return<int>(res, hand);
  }






  // __NR__ pwritev = 296
  inline int pwritev(fd_t fd, iovec_p vec, uint64_t vlen, uint64_t pos_l, uint64_t pos_h, errhand_t hand = err_log )
      __attribute__((__always_inline__));

  inline int pwritev(fd_t fd, iovec_p vec, uint64_t vlen, uint64_t pos_l, uint64_t pos_h, errhand_t hand) {
    uint64_t res = 0xfeebdaed;
    asm("\tsyscall;\n"
        : "=a"(res)
        : "0"(296), "D"(fd), "S"(vec), "d"(vlen), "r10"(pos_l), "r8"(pos_h)
        : "rcx", "r11", "memory");
    return chk_return<int>(res, hand);
  }






  // __NR__ rt_tgsigqueueinfo = 297
  inline int rt_tgsigqueueinfo(pid_t tgid, pid_t pid, int sig, siginfo_p uinfo, errhand_t hand = err_log )
      __attribute__((__always_inline__));

  inline int rt_tgsigqueueinfo(pid_t tgid, pid_t pid, int sig, siginfo_p uinfo, errhand_t hand) {
    uint64_t res = 0xfeebdaed;
    asm("\tsyscall;\n"
        : "=a"(res)
        : "0"(297), "D"(tgid), "S"(pid), "d"(sig), "r10"(uinfo)
        : "rcx", "r11", "memory");
    return chk_return<int>(res, hand);
  }






  // __NR__ perf_event_open = 298
  inline int perf_event_open(perf_event_attr_p attr_uptr, pid_t pid, int cpu, int group_fd, uint64_t flags, errhand_t hand = err_log )
      __attribute__((__always_inline__));

  inline int perf_event_open(perf_event_attr_p attr_uptr, pid_t pid, int cpu, int group_fd, uint64_t flags, errhand_t hand) {
    uint64_t res = 0xfeebdaed;
    asm("\tsyscall;\n"
        : "=a"(res)
        : "0"(298), "D"(attr_uptr), "S"(pid), "d"(cpu), "r10"(group_fd), "r8"(flags)
        : "rcx", "r11", "memory");
    return chk_return<int>(res, hand);
  }






  // __NR__ recvmmsg = 299
  inline int recvmmsg(fd_t fd, msghdr_p mmsg, unsigned vlen, unsigned flags, timespec_p timeout, errhand_t hand = err_log )
      __attribute__((__always_inline__));

  inline int recvmmsg(fd_t fd, msghdr_p mmsg, unsigned vlen, unsigned flags, timespec_p timeout, errhand_t hand) {
    uint64_t res = 0xfeebdaed;
    asm("\tsyscall;\n"
        : "=a"(res)
        : "0"(299), "D"(fd), "S"(mmsg), "d"(vlen), "r10"(flags), "r8"(timeout)
        : "rcx", "r11", "memory");
    return chk_return<int>(res, hand);
  }






  // __NR__ fanotify_init = 300
  inline int fanotify_init(unsigned flags, unsigned event_f_flags, errhand_t hand = err_log )
      __attribute__((__always_inline__));

  inline int fanotify_init(unsigned flags, unsigned event_f_flags, errhand_t hand) {
    uint64_t res = 0xfeebdaed;
    asm("\tsyscall;\n"
        : "=a"(res)
        : "0"(300), "D"(flags), "S"(event_f_flags)
        : "rcx", "r11", "memory");
    return chk_return<int>(res, hand);
  }






  // __NR__ fanotify_mark = 301
  inline int fanotify_mark(long fanotify_fd, long flags, uint64_t mask, fd_t dfd, istr_t path, errhand_t hand = err_log )
      __attribute__((__always_inline__));

  inline int fanotify_mark(long fanotify_fd, long flags, uint64_t mask, fd_t dfd, istr_t path, errhand_t hand) {
    uint64_t res = 0xfeebdaed;
    asm("\tsyscall;\n"
        : "=a"(res)
        : "0"(301), "D"(fanotify_fd), "S"(flags), "d"(mask), "r10"(dfd), "r8"(path)
        : "rcx", "r11", "memory");
    return chk_return<int>(res, hand);
  }






  // __NR__ prlimit64 = 302
  inline int prlimit64(pid_t pid, unsigned resource, rlimit64_p new_rlim, rlimit64_p old_rlim, errhand_t hand = err_log )
      __attribute__((__always_inline__));

  inline int prlimit64(pid_t pid, unsigned resource, rlimit64_p new_rlim, rlimit64_p old_rlim, errhand_t hand) {
    uint64_t res = 0xfeebdaed;
    asm("\tsyscall;\n"
        : "=a"(res)
        : "0"(302), "D"(pid), "S"(resource), "d"(new_rlim), "r10"(old_rlim)
        : "rcx", "r11", "memory");
    return chk_return<int>(res, hand);
  }






  // __NR__ name_to_handle_at = 303
  inline int name_to_handle_at(fd_t dfd, istr_t name, file_handle_p handle, int32_p mnt_id, int flag, errhand_t hand = err_log )
      __attribute__((__always_inline__));

  inline int name_to_handle_at(fd_t dfd, istr_t name, file_handle_p handle, int32_p mnt_id, int flag, errhand_t hand) {
    uint64_t res = 0xfeebdaed;
    asm("\tsyscall;\n"
        : "=a"(res)
        : "0"(303), "D"(dfd), "S"(name), "d"(handle), "r10"(mnt_id), "r8"(flag)
        : "rcx", "r11", "memory");
    return chk_return<int>(res, hand);
  }






  // __NR__ open_by_handle_at = 304
  inline int open_by_handle_at(fd_t dfd, istr_t name, file_handle_p handle, int32_p mnt_id, int flags, errhand_t hand = err_log )
      __attribute__((__always_inline__));

  inline int open_by_handle_at(fd_t dfd, istr_t name, file_handle_p handle, int32_p mnt_id, int flags, errhand_t hand) {
    uint64_t res = 0xfeebdaed;
    asm("\tsyscall;\n"
        : "=a"(res)
        : "0"(304), "D"(dfd), "S"(name), "d"(handle), "r10"(mnt_id), "r8"(flags)
        : "rcx", "r11", "memory");
    return chk_return<int>(res, hand);
  }






  // __NR__ clock_adjtime = 305
  inline int clock_adjtime(clockid_t which_clock, timex_p tx, errhand_t hand = err_log )
      __attribute__((__always_inline__));

  inline int clock_adjtime(clockid_t which_clock, timex_p tx, errhand_t hand) {
    uint64_t res = 0xfeebdaed;
    asm("\tsyscall;\n"
        : "=a"(res)
        : "0"(305), "D"(which_clock), "S"(tx)
        : "rcx", "r11", "memory");
    return chk_return<int>(res, hand);
  }






  // __NR__ syncfs = 306
  inline int syncfs(fd_t fd, errhand_t hand = err_log )
      __attribute__((__always_inline__));

  inline int syncfs(fd_t fd, errhand_t hand) {
    uint64_t res = 0xfeebdaed;
    asm("\tsyscall;\n"
        : "=a"(res)
        : "0"(306), "D"(fd)
        : "rcx", "r11", "memory");
    return chk_return<int>(res, hand);
  }






  // __NR__ sendmmsg = 307
  inline int sendmmsg(fd_t fd, msghdr_p mmsg, unsigned vlen, unsigned flags, errhand_t hand = err_log )
      __attribute__((__always_inline__));

  inline int sendmmsg(fd_t fd, msghdr_p mmsg, unsigned vlen, unsigned flags, errhand_t hand) {
    uint64_t res = 0xfeebdaed;
    asm("\tsyscall;\n"
        : "=a"(res)
        : "0"(307), "D"(fd), "S"(mmsg), "d"(vlen), "r10"(flags)
        : "rcx", "r11", "memory");
    return chk_return<int>(res, hand);
  }






  // __NR__ setns = 308
  inline int setns(fd_t fd, int nstype, errhand_t hand = err_log )
      __attribute__((__always_inline__));

  inline int setns(fd_t fd, int nstype, errhand_t hand) {
    uint64_t res = 0xfeebdaed;
    asm("\tsyscall;\n"
        : "=a"(res)
        : "0"(308), "D"(fd), "S"(nstype)
        : "rcx", "r11", "memory");
    return chk_return<int>(res, hand);
  }






  // __NR__ getcpu = 309
  inline int getcpu(uint32_p cpup, uint32_p nodep, errhand_t hand = err_log )
      __attribute__((__always_inline__));

  inline int getcpu(uint32_p cpup, uint32_p nodep, errhand_t hand) {
    uint64_t res = 0xfeebdaed;
    asm("\tsyscall;\n"
        : "=a"(res)
        : "0"(309), "D"(cpup), "S"(nodep)
        : "rcx", "r11", "memory");
    return chk_return<int>(res, hand);
  }






  // __NR__ process_vm_readv = 310
  inline int process_vm_readv(pid_t pid, iovec_p lvec, uint64_t liovcnt, iovec_p rvec, uint64_t riovcnt, uint64_t flags, errhand_t hand = err_log )
      __attribute__((__always_inline__));

  inline int process_vm_readv(pid_t pid, iovec_p lvec, uint64_t liovcnt, iovec_p rvec, uint64_t riovcnt, uint64_t flags, errhand_t hand) {
    uint64_t res = 0xfeebdaed;
    asm("\tsyscall;\n"
        : "=a"(res)
        : "0"(310), "D"(pid), "S"(lvec), "d"(liovcnt), "r10"(rvec), "r8"(riovcnt), "r9"(flags)
        : "rcx", "r11", "memory");
    return chk_return<int>(res, hand);
  }






  // __NR__ process_vm_writev = 311
  inline int process_vm_writev(pid_t pid, iovec_p lvec, uint64_t liovcnt, iovec_p rvec, uint64_t riovcnt, uint64_t flags, errhand_t hand = err_log )
      __attribute__((__always_inline__));

  inline int process_vm_writev(pid_t pid, iovec_p lvec, uint64_t liovcnt, iovec_p rvec, uint64_t riovcnt, uint64_t flags, errhand_t hand) {
    uint64_t res = 0xfeebdaed;
    asm("\tsyscall;\n"
        : "=a"(res)
        : "0"(311), "D"(pid), "S"(lvec), "d"(liovcnt), "r10"(rvec), "r8"(riovcnt), "r9"(flags)
        : "rcx", "r11", "memory");
    return chk_return<int>(res, hand);
  }






  // __NR__ kcmp = 312
  inline int kcmp(pid_t pid1, pid_t pid2, int type, uint64_t idx1, uint64_t idx2, errhand_t hand = err_log )
      __attribute__((__always_inline__));

  inline int kcmp(pid_t pid1, pid_t pid2, int type, uint64_t idx1, uint64_t idx2, errhand_t hand) {
    uint64_t res = 0xfeebdaed;
    asm("\tsyscall;\n"
        : "=a"(res)
        : "0"(312), "D"(pid1), "S"(pid2), "d"(type), "r10"(idx1), "r8"(idx2)
        : "rcx", "r11", "memory");
    return chk_return<int>(res, hand);
  }






  // __NR__ finit_module = 313
  inline int finit_module(fd_t fd, istr_t uargs, int flags, errhand_t hand = err_log )
      __attribute__((__always_inline__));

  inline int finit_module(fd_t fd, istr_t uargs, int flags, errhand_t hand) {
    uint64_t res = 0xfeebdaed;
    asm("\tsyscall;\n"
        : "=a"(res)
        : "0"(313), "D"(fd), "S"(uargs), "d"(flags)
        : "rcx", "r11", "memory");
    return chk_return<int>(res, hand);
  }






  // __NR__ sched_setattr = 314
  inline int sched_setattr(pid_t pid, sched_attr_p attr, unsigned flags, errhand_t hand = err_log )
      __attribute__((__always_inline__));

  inline int sched_setattr(pid_t pid, sched_attr_p attr, unsigned flags, errhand_t hand) {
    uint64_t res = 0xfeebdaed;
    asm("\tsyscall;\n"
        : "=a"(res)
        : "0"(314), "D"(pid), "S"(attr), "d"(flags)
        : "rcx", "r11", "memory");
    return chk_return<int>(res, hand);
  }






  // __NR__ sched_getattr = 315
  inline int sched_getattr(pid_t pid, sched_attr_p attr, unsigned size, unsigned flags, errhand_t hand = err_log )
      __attribute__((__always_inline__));

  inline int sched_getattr(pid_t pid, sched_attr_p attr, unsigned size, unsigned flags, errhand_t hand) {
    uint64_t res = 0xfeebdaed;
    asm("\tsyscall;\n"
        : "=a"(res)
        : "0"(315), "D"(pid), "S"(attr), "d"(size), "r10"(flags)
        : "rcx", "r11", "memory");
    return chk_return<int>(res, hand);
  }






  // __NR__ renameat2 = 316
  inline int renameat2(int olddfd, istr_t opath, int newdfd, istr_t npath, unsigned flags, errhand_t hand = err_log )
      __attribute__((__always_inline__));

  inline int renameat2(int olddfd, istr_t opath, int newdfd, istr_t npath, unsigned flags, errhand_t hand) {
    uint64_t res = 0xfeebdaed;
    asm("\tsyscall;\n"
        : "=a"(res)
        : "0"(316), "D"(olddfd), "S"(opath), "d"(newdfd), "r10"(npath), "r8"(flags)
        : "rcx", "r11", "memory");
    return chk_return<int>(res, hand);
  }






  // __NR__ seccomp = 317
  inline int seccomp(unsigned op, unsigned flags, istr_t uargs, errhand_t hand = err_log )
      __attribute__((__always_inline__));

  inline int seccomp(unsigned op, unsigned flags, istr_t uargs, errhand_t hand) {
    uint64_t res = 0xfeebdaed;
    asm("\tsyscall;\n"
        : "=a"(res)
        : "0"(317), "D"(op), "S"(flags), "d"(uargs)
        : "rcx", "r11", "memory");
    return chk_return<int>(res, hand);
  }






  // __NR__ getrandom = 318
  inline int getrandom(ostr_t buf, size_t count, unsigned flags, errhand_t hand = err_log )
      __attribute__((__always_inline__));

  inline int getrandom(ostr_t buf, size_t count, unsigned flags, errhand_t hand) {
    uint64_t res = 0xfeebdaed;
    asm("\tsyscall;\n"
        : "=a"(res)
        : "0"(318), "D"(buf), "S"(count), "d"(flags)
        : "rcx", "r11", "memory");
    return chk_return<int>(res, hand);
  }






  // __NR__ memfd_create = 319
  inline int memfd_create(istr_t uname_ptr, unsigned flags, errhand_t hand = err_log )
      __attribute__((__always_inline__));

  inline int memfd_create(istr_t uname_ptr, unsigned flags, errhand_t hand) {
    uint64_t res = 0xfeebdaed;
    asm("\tsyscall;\n"
        : "=a"(res)
        : "0"(319), "D"(uname_ptr), "S"(flags)
        : "rcx", "r11", "memory");
    return chk_return<int>(res, hand);
  }






  // __NR__ kexec_file_load = 320
  inline int kexec_file_load(int kernel_fd, int initrd_fd, size_t cmdline_len, istr_t cmdline_ptr, uint64_t flags, errhand_t hand = err_log )
      __attribute__((__always_inline__));

  inline int kexec_file_load(int kernel_fd, int initrd_fd, size_t cmdline_len, istr_t cmdline_ptr, uint64_t flags, errhand_t hand) {
    uint64_t res = 0xfeebdaed;
    asm("\tsyscall;\n"
        : "=a"(res)
        : "0"(320), "D"(kernel_fd), "S"(initrd_fd), "d"(cmdline_len), "r10"(cmdline_ptr), "r8"(flags)
        : "rcx", "r11", "memory");
    return chk_return<int>(res, hand);
  }






  // __NR__ bpf = 321
  inline int bpf(int cmd, bpf_attr_p attr, unsigned size, errhand_t hand = err_log )
      __attribute__((__always_inline__));

  inline int bpf(int cmd, bpf_attr_p attr, unsigned size, errhand_t hand) {
    uint64_t res = 0xfeebdaed;
    asm("\tsyscall;\n"
        : "=a"(res)
        : "0"(321), "D"(cmd), "S"(attr), "d"(size)
        : "rcx", "r11", "memory");
    return chk_return<int>(res, hand);
  }






  // __NR__ stub_execveat = 322
  inline int stub_execveat(fd_t dfd, istr_t path, istr_v argv, istr_v envp, int flags, errhand_t hand = err_log )
      __attribute__((__always_inline__));

  inline int stub_execveat(fd_t dfd, istr_t path, istr_v argv, istr_v envp, int flags, errhand_t hand) {
    uint64_t res = 0xfeebdaed;
    asm("\tsyscall;\n"
        : "=a"(res)
        : "0"(322), "D"(dfd), "S"(path), "d"(argv), "r10"(envp), "r8"(flags)
        : "rcx", "r11", "memory");
    return chk_return<int>(res, hand);
  }






  // __NR__ userfaultfd = 323
  inline int userfaultfd(int flags, errhand_t hand = err_log )
      __attribute__((__always_inline__));

  inline int userfaultfd(int flags, errhand_t hand) {
    uint64_t res = 0xfeebdaed;
    asm("\tsyscall;\n"
        : "=a"(res)
        : "0"(323), "D"(flags)
        : "rcx", "r11", "memory");
    return chk_return<int>(res, hand);
  }






  // __NR__ membarrier = 324
  inline int membarrier(int cmd, int flags, errhand_t hand = err_log )
      __attribute__((__always_inline__));

  inline int membarrier(int cmd, int flags, errhand_t hand) {
    uint64_t res = 0xfeebdaed;
    asm("\tsyscall;\n"
        : "=a"(res)
        : "0"(324), "D"(cmd), "S"(flags)
        : "rcx", "r11", "memory");
    return chk_return<int>(res, hand);
  }






  // __NR__ mlock2 = 325
  inline int mlock2(uint64_t start, size_t len, int flags, errhand_t hand = err_log )
      __attribute__((__always_inline__));

  inline int mlock2(uint64_t start, size_t len, int flags, errhand_t hand) {
    uint64_t res = 0xfeebdaed;
    asm("\tsyscall;\n"
        : "=a"(res)
        : "0"(325), "D"(start), "S"(len), "d"(flags)
        : "rcx", "r11", "memory");
    return chk_return<int>(res, hand);
  }






  // __NR__ copy_file_range = 326
  inline int copy_file_range(fd_t fd_in, off_p off_in, fd_t fd_out, off_p off_out, size_t len, unsigned flags, errhand_t hand = err_log )
      __attribute__((__always_inline__));

  inline int copy_file_range(fd_t fd_in, off_p off_in, fd_t fd_out, off_p off_out, size_t len, unsigned flags, errhand_t hand) {
    uint64_t res = 0xfeebdaed;
    asm("\tsyscall;\n"
        : "=a"(res)
        : "0"(326), "D"(fd_in), "S"(off_in), "d"(fd_out), "r10"(off_out), "r8"(len), "r9"(flags)
        : "rcx", "r11", "memory");
    return chk_return<int>(res, hand);
  }






  // __NR__ preadv2 = 327
  inline int preadv2(fd_t fd, iovec_p vec, uint64_t vlen, uint64_t pos_l, uint64_t pos_h, int flags, errhand_t hand = err_log )
      __attribute__((__always_inline__));

  inline int preadv2(fd_t fd, iovec_p vec, uint64_t vlen, uint64_t pos_l, uint64_t pos_h, int flags, errhand_t hand) {
    uint64_t res = 0xfeebdaed;
    asm("\tsyscall;\n"
        : "=a"(res)
        : "0"(327), "D"(fd), "S"(vec), "d"(vlen), "r10"(pos_l), "r8"(pos_h), "r9"(flags)
        : "rcx", "r11", "memory");
    return chk_return<int>(res, hand);
  }






  // __NR__ pwritev2 = 328
  inline int pwritev2(fd_t fd, iovec_p vec, uint64_t vlen, uint64_t pos_l, uint64_t pos_h, int flags, errhand_t hand = err_log )
      __attribute__((__always_inline__));

  inline int pwritev2(fd_t fd, iovec_p vec, uint64_t vlen, uint64_t pos_l, uint64_t pos_h, int flags, errhand_t hand) {
    uint64_t res = 0xfeebdaed;
    asm("\tsyscall;\n"
        : "=a"(res)
        : "0"(328), "D"(fd), "S"(vec), "d"(vlen), "r10"(pos_l), "r8"(pos_h), "r9"(flags)
        : "rcx", "r11", "memory");
    return chk_return<int>(res, hand);
  }



}

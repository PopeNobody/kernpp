// Auto-generated syscall wrappers
#pragma once

namespace sys {


// __NR__ read = 0
ssize_t read(fd_t fd, ostr_t buf, size_t count, errhand_t hand = err_log)
  __attribute__((__always_inline__));




// __NR__ write = 1
ssize_t write(fd_t fd, istr_t buf, size_t count, errhand_t hand = err_log)
  __attribute__((__always_inline__));




// __NR__ open = 2
fd_t open(istr_t path, int flags, int mode, errhand_t hand = err_log)
  __attribute__((__always_inline__));




// __NR__ close = 3
int close(fd_t fd, errhand_t hand = err_log)
  __attribute__((__always_inline__));




// __NR__ stat = 4
int stat(istr_t path, stat_p statbuf, errhand_t hand = err_log)
  __attribute__((__always_inline__));




// __NR__ fstat = 5
int fstat(fd_t fd, stat_p statbuf, errhand_t hand = err_log)
  __attribute__((__always_inline__));




// __NR__ lstat = 6
int lstat(istr_t path, stat_p statbuf, errhand_t hand = err_log)
  __attribute__((__always_inline__));




// __NR__ poll = 7
int poll(pollfd_p ufds, unsigned nfds, long timeout_msecs, errhand_t hand = err_log)
  __attribute__((__always_inline__));




// __NR__ lseek = 8
int lseek(fd_t fd, off_t offset, unsigned origin, errhand_t hand = err_log)
  __attribute__((__always_inline__));




// __NR__ mmap = 9
char* mmap(void* addr, size_t len, int prot, int flags, fd_t fd, off_t off, errhand_t hand = err_log)
  __attribute__((__always_inline__));




// __NR__ mprotect = 10
int mprotect(uint64_t start, size_t len, uint64_t prot, errhand_t hand = err_log)
  __attribute__((__always_inline__));




// __NR__ munmap = 11
int munmap(uint64_t addr, size_t len, errhand_t hand = err_log)
  __attribute__((__always_inline__));




// __NR__ brk = 12
int brk(void_p brk, errhand_t hand = err_log)
  __attribute__((__always_inline__));




// __NR__ rt_sigaction = 13
int rt_sigaction(int sig, sigaction_p act, sigaction_p oact, size_t sigsetsize, errhand_t hand = err_log)
  __attribute__((__always_inline__));




// __NR__ rt_sigprocmask = 14
int rt_sigprocmask(int how, sigset_p nset, sigset_p oset, size_t sigsetsize, errhand_t hand = err_log)
  __attribute__((__always_inline__));




// __NR__ rt_sigreturn = 15
int rt_sigreturn(uint64_t __unused, errhand_t hand = err_log)
  __attribute__((__always_inline__));




// __NR__ ioctl = 16
int ioctl(fd_t fd, unsigned cmd, uint64_t arg, errhand_t hand = err_log)
  __attribute__((__always_inline__));




// __NR__ pread64 = 17
int pread64(fd_t fd, ostr_t buf, size_t count, off_t pos, errhand_t hand = err_log)
  __attribute__((__always_inline__));




// __NR__ pwrite64 = 18
int pwrite64(fd_t fd, istr_t buf, size_t count, off_t pos, errhand_t hand = err_log)
  __attribute__((__always_inline__));




// __NR__ readv = 19
int readv(fd_t fd, iovec_p vec, uint64_t vlen, errhand_t hand = err_log)
  __attribute__((__always_inline__));




// __NR__ writev = 20
int writev(fd_t fd, iovec_p vec, uint64_t vlen, errhand_t hand = err_log)
  __attribute__((__always_inline__));




// __NR__ access = 21
int access(istr_t path, int mode, errhand_t hand = err_log)
  __attribute__((__always_inline__));




// __NR__ pipe = 22
int pipe(fd_p filedes, errhand_t hand = err_log)
  __attribute__((__always_inline__));




// __NR__ select = 23
int select(int n, fdset_p inp, fdset_p outp, fdset_p exp, timeval_p tvp, errhand_t hand = err_log)
  __attribute__((__always_inline__));




// __NR__ sched_yield = 24
int sched_yield(errhand_t hand = err_log)
  __attribute__((__always_inline__));




// __NR__ mremap = 25
int mremap(uint64_t addr, uint64_t old_len, uint64_t new_len, uint64_t flags, uint64_t new_addr, errhand_t hand = err_log)
  __attribute__((__always_inline__));




// __NR__ msync = 26
int msync(uint64_t start, size_t len, int flags, errhand_t hand = err_log)
  __attribute__((__always_inline__));




// __NR__ mincore = 27
int mincore(uint64_t start, size_t len, ostr_t vec, errhand_t hand = err_log)
  __attribute__((__always_inline__));




// __NR__ madvise = 28
int madvise(uint64_t start, size_t len_in, int behavior, errhand_t hand = err_log)
  __attribute__((__always_inline__));




// __NR__ shmget = 29
int shmget(key_t key, size_t size, int shmflg, errhand_t hand = err_log)
  __attribute__((__always_inline__));




// __NR__ shmat = 30
int shmat(int shmid, ostr_t shmaddr, int shmflg, errhand_t hand = err_log)
  __attribute__((__always_inline__));




// __NR__ shmctl = 31
int shmctl(int shmid, int cmd, shmid_ds_p buf, errhand_t hand = err_log)
  __attribute__((__always_inline__));




// __NR__ dup = 32
int dup(unsigned fildes, errhand_t hand = err_log)
  __attribute__((__always_inline__));




// __NR__ dup2 = 33
int dup2(fd_t oldfd, fd_t newfd, errhand_t hand = err_log)
  __attribute__((__always_inline__));




// __NR__ pause = 34
int pause(errhand_t hand = err_log)
  __attribute__((__always_inline__));




// __NR__ nanosleep = 35
int nanosleep(timespec_p rqtp, timespec_p rmtp, errhand_t hand = err_log)
  __attribute__((__always_inline__));




// __NR__ getitimer = 36
int getitimer(int which, itimerval_p value, errhand_t hand = err_log)
  __attribute__((__always_inline__));




// __NR__ alarm = 37
int alarm(unsigned seconds, errhand_t hand = err_log)
  __attribute__((__always_inline__));




// __NR__ setitimer = 38
int setitimer(int which, itimerval_p value, itimerval_p ovalue, errhand_t hand = err_log)
  __attribute__((__always_inline__));




// __NR__ getpid = 39
int getpid(errhand_t hand = err_log)
  __attribute__((__always_inline__));




// __NR__ sendfile = 40
int sendfile(int out_fd, int in_fd, off_p offset, size_t count, errhand_t hand = err_log)
  __attribute__((__always_inline__));




// __NR__ socket = 41
int socket(int family, int type, int protocol, errhand_t hand = err_log)
  __attribute__((__always_inline__));




// __NR__ connect = 42
int connect(fd_t fd, sockaddr_p uservaddr, int addrlen, errhand_t hand = err_log)
  __attribute__((__always_inline__));




// __NR__ accept = 43
int accept(fd_t fd, sockaddr_p upeer_sockaddr, int32_p upeer_addrlen, errhand_t hand = err_log)
  __attribute__((__always_inline__));




// __NR__ sendto = 44
int sendto(fd_t fd, void_p buff, size_t len, unsigned flags, sockaddr_p addr, int addr_len, errhand_t hand = err_log)
  __attribute__((__always_inline__));




// __NR__ recvfrom = 45
int recvfrom(fd_t fd, void_p ubuf, size_t size, unsigned flags, sockaddr_p addr, int32_p addr_len, errhand_t hand = err_log)
  __attribute__((__always_inline__));




// __NR__ sendmsg = 46
int sendmsg(fd_t fd, msghdr_p msg, unsigned flags, errhand_t hand = err_log)
  __attribute__((__always_inline__));




// __NR__ recvmsg = 47
int recvmsg(fd_t fd, msghdr_p msg, unsigned flags, errhand_t hand = err_log)
  __attribute__((__always_inline__));




// __NR__ shutdown = 48
int shutdown(fd_t fd, int how, errhand_t hand = err_log)
  __attribute__((__always_inline__));




// __NR__ bind = 49
int bind(fd_t fd, sockaddr_p umyaddr, int addrlen, errhand_t hand = err_log)
  __attribute__((__always_inline__));




// __NR__ listen = 50
int listen(fd_t fd, int backlog, errhand_t hand = err_log)
  __attribute__((__always_inline__));




// __NR__ getsockname = 51
int getsockname(fd_t fd, sockaddr_p usockaddr, int32_p usockaddr_len, errhand_t hand = err_log)
  __attribute__((__always_inline__));




// __NR__ getpeername = 52
int getpeername(fd_t fd, sockaddr_p usockaddr, int32_p usockaddr_len, errhand_t hand = err_log)
  __attribute__((__always_inline__));




// __NR__ socketpair = 53
int socketpair(int family, int type, int protocol, int32_p usockvec, errhand_t hand = err_log)
  __attribute__((__always_inline__));




// __NR__ setsockopt = 54
int setsockopt(fd_t fd, int level, int optname, ostr_t optval, int optlen, errhand_t hand = err_log)
  __attribute__((__always_inline__));




// __NR__ getsockopt = 55
int getsockopt(fd_t fd, int level, int optname, ostr_t optval, int32_p optlen, errhand_t hand = err_log)
  __attribute__((__always_inline__));




// __NR__ clone = 56
int clone(uint64_t clone_flags, uint64_t newsp, void_p parent_tid, void_p child_tid, errhand_t hand = err_log)
  __attribute__((__always_inline__));




// __NR__ fork = 57
pid_t fork(errhand_t hand = err_log)
  __attribute__((__always_inline__));




// __NR__ vfork = 58
pid_t vfork(errhand_t hand = err_log)
  __attribute__((__always_inline__));




// __NR__ execve = 59
int execve(const char * filename, char *const * argv, char *const * envp, errhand_t hand = err_log)
  __attribute__((__always_inline__, __noreturn__));




// __NR__ exit = 60
void exit(int error_code, errhand_t hand = err_log)
  __attribute__((__always_inline__, __noreturn__));




// __NR__ wait4 = 61
int wait4(pid_t upid, int32_p stat_addr, int options, rusage_p ru, errhand_t hand = err_log)
  __attribute__((__always_inline__));




// __NR__ kill = 62
int kill(pid_t pid, int sig, errhand_t hand = err_log)
  __attribute__((__always_inline__));




// __NR__ uname = 63
int uname(utsname_p name, errhand_t hand = err_log)
  __attribute__((__always_inline__));




// __NR__ shmdt = 67
int shmdt(ostr_t shmaddr, errhand_t hand = err_log)
  __attribute__((__always_inline__));




// __NR__ msgget = 68
int msgget(key_t key, int msgflg, errhand_t hand = err_log)
  __attribute__((__always_inline__));




// __NR__ msgsnd = 69
int msgsnd(int msqid, msgbuf_p msgp, size_t msgsz, int msgflg, errhand_t hand = err_log)
  __attribute__((__always_inline__));




// __NR__ msgrcv = 70
int msgrcv(int msqid, msgbuf_p msgp, size_t msgsz, long msgtyp, int msgflg, errhand_t hand = err_log)
  __attribute__((__always_inline__));




// __NR__ msgctl = 71
int msgctl(int msqid, int cmd, msqid_ds_p buf, errhand_t hand = err_log)
  __attribute__((__always_inline__));




// __NR__ fcntl = 72
int fcntl(fd_t fd, unsigned cmd, uint64_t arg, errhand_t hand = err_log)
  __attribute__((__always_inline__));




// __NR__ flock = 73
int flock(fd_t fd, unsigned cmd, errhand_t hand = err_log)
  __attribute__((__always_inline__));




// __NR__ fsync = 74
int fsync(fd_t fd, errhand_t hand = err_log)
  __attribute__((__always_inline__));




// __NR__ fdatasync = 75
int fdatasync(fd_t fd, errhand_t hand = err_log)
  __attribute__((__always_inline__));




// __NR__ truncate = 76
int truncate(istr_t path, long length, errhand_t hand = err_log)
  __attribute__((__always_inline__));




// __NR__ ftruncate = 77
int ftruncate(fd_t fd, uint64_t length, errhand_t hand = err_log)
  __attribute__((__always_inline__));




// __NR__ getdents = 78
ssize_t getdents(fd_t fd, linux_dirent_p dirent, size_t count, errhand_t hand = err_log)
  __attribute__((__always_inline__));




// __NR__ getcwd = 79
int getcwd(ostr_t buf, uint64_t size, errhand_t hand = err_log)
  __attribute__((__always_inline__));




// __NR__ chdir = 80
int chdir(istr_t path, errhand_t hand = err_log)
  __attribute__((__always_inline__));




// __NR__ fchdir = 81
int fchdir(fd_t fd, errhand_t hand = err_log)
  __attribute__((__always_inline__));




// __NR__ rename = 82
int rename(istr_t opath, istr_t npath, errhand_t hand = err_log)
  __attribute__((__always_inline__));




// __NR__ mkdir = 83
int mkdir(istr_t path, int mode, errhand_t hand = err_log)
  __attribute__((__always_inline__));




// __NR__ rmdir = 84
int rmdir(istr_t path, errhand_t hand = err_log)
  __attribute__((__always_inline__));




// __NR__ creat = 85
int creat(istr_t path, int mode, errhand_t hand = err_log)
  __attribute__((__always_inline__));




// __NR__ link = 86
int link(istr_t opath, istr_t npath, errhand_t hand = err_log)
  __attribute__((__always_inline__));




// __NR__ unlink = 87
int unlink(istr_t path, errhand_t hand = err_log)
  __attribute__((__always_inline__));




// __NR__ symlink = 88
int symlink(istr_t opath, istr_t npath, errhand_t hand = err_log)
  __attribute__((__always_inline__));




// __NR__ readlink = 89
int readlink(istr_t path, ostr_t buf, int bufsiz, errhand_t hand = err_log)
  __attribute__((__always_inline__));




// __NR__ chmod = 90
int chmod(istr_t path, mode_t mode, errhand_t hand = err_log)
  __attribute__((__always_inline__));




// __NR__ fchmod = 91
int fchmod(fd_t fd, mode_t mode, errhand_t hand = err_log)
  __attribute__((__always_inline__));




// __NR__ chown = 92
int chown(istr_t path, uid_t user, gid_t group, errhand_t hand = err_log)
  __attribute__((__always_inline__));




// __NR__ fchown = 93
int fchown(fd_t fd, uid_t user, gid_t group, errhand_t hand = err_log)
  __attribute__((__always_inline__));




// __NR__ lchown = 94
int lchown(istr_t path, uid_t user, gid_t group, errhand_t hand = err_log)
  __attribute__((__always_inline__));




// __NR__ umask = 95
int umask(int mask, errhand_t hand = err_log)
  __attribute__((__always_inline__));




// __NR__ gettimeofday = 96
int gettimeofday(timeval_p tv, timezone_p tz, errhand_t hand = err_log)
  __attribute__((__always_inline__));




// __NR__ getrlimit = 97
int getrlimit(unsigned resource, rlimit_p rlim, errhand_t hand = err_log)
  __attribute__((__always_inline__));




// __NR__ getrusage = 98
int getrusage(int who, rusage_p ru, errhand_t hand = err_log)
  __attribute__((__always_inline__));




// __NR__ sysinfo = 99
int sysinfo(sysinfo_p info, errhand_t hand = err_log)
  __attribute__((__always_inline__));




// __NR__ times = 100
int times(sysinfo_p info, errhand_t hand = err_log)
  __attribute__((__always_inline__));




// __NR__ ptrace = 101
int ptrace(long request, long pid, uint64_t addr, uint64_t data, errhand_t hand = err_log)
  __attribute__((__always_inline__));




// __NR__ getuid = 102
int getuid(errhand_t hand = err_log)
  __attribute__((__always_inline__));




// __NR__ syslog = 103
int syslog(int type, ostr_t buf, int len, errhand_t hand = err_log)
  __attribute__((__always_inline__));




// __NR__ getgid = 104
int getgid(errhand_t hand = err_log)
  __attribute__((__always_inline__));




// __NR__ setuid = 105
int setuid(uid_t uid, errhand_t hand = err_log)
  __attribute__((__always_inline__));




// __NR__ setgid = 106
int setgid(gid_t gid, errhand_t hand = err_log)
  __attribute__((__always_inline__));




// __NR__ geteuid = 107
int geteuid(errhand_t hand = err_log)
  __attribute__((__always_inline__));




// __NR__ getegid = 108
int getegid(errhand_t hand = err_log)
  __attribute__((__always_inline__));




// __NR__ setpgid = 109
int setpgid(pid_t pid, pid_t pgid, errhand_t hand = err_log)
  __attribute__((__always_inline__));




// __NR__ getppid = 110
int getppid(errhand_t hand = err_log)
  __attribute__((__always_inline__));




// __NR__ getpgrp = 111
int getpgrp(errhand_t hand = err_log)
  __attribute__((__always_inline__));




// __NR__ setsid = 112
int setsid(errhand_t hand = err_log)
  __attribute__((__always_inline__));




// __NR__ setreuid = 113
int setreuid(uid_t ruid, uid_t euid, errhand_t hand = err_log)
  __attribute__((__always_inline__));




// __NR__ setregid = 114
int setregid(gid_t rgid, gid_t egid, errhand_t hand = err_log)
  __attribute__((__always_inline__));




// __NR__ getgroups = 115
int getgroups(int gidsetsize, gid_p grouplist, errhand_t hand = err_log)
  __attribute__((__always_inline__));




// __NR__ setgroups = 116
int setgroups(int gidsetsize, gid_p grouplist, errhand_t hand = err_log)
  __attribute__((__always_inline__));




// __NR__ setresuid = 117
int setresuid(uid_p ruid, uid_p euid, uid_p suid, errhand_t hand = err_log)
  __attribute__((__always_inline__));




// __NR__ getresuid = 118
int getresuid(uid_p ruid, uid_p euid, uid_p suid, errhand_t hand = err_log)
  __attribute__((__always_inline__));




// __NR__ setresgid = 119
int setresgid(gid_t rgid, gid_t egid, gid_t sgid, errhand_t hand = err_log)
  __attribute__((__always_inline__));




// __NR__ getresgid = 120
int getresgid(gid_p rgid, gid_p egid, gid_p sgid, errhand_t hand = err_log)
  __attribute__((__always_inline__));




// __NR__ getpgid = 121
int getpgid(pid_t pid, errhand_t hand = err_log)
  __attribute__((__always_inline__));




// __NR__ setfsuid = 122
int setfsuid(uid_t uid, errhand_t hand = err_log)
  __attribute__((__always_inline__));




// __NR__ setfsgid = 123
int setfsgid(gid_t gid, errhand_t hand = err_log)
  __attribute__((__always_inline__));




// __NR__ getsid = 124
int getsid(pid_t pid, errhand_t hand = err_log)
  __attribute__((__always_inline__));




// __NR__ capget = 125
int capget(cap_user_header_t header, cap_user_data_t dataptr, errhand_t hand = err_log)
  __attribute__((__always_inline__));




// __NR__ capset = 126
int capset(cap_user_header_t header, const cap_user_data_t data, errhand_t hand = err_log)
  __attribute__((__always_inline__));




// __NR__ rt_sigpending = 127
int rt_sigpending(sigset_p set, size_t sigsetsize, errhand_t hand = err_log)
  __attribute__((__always_inline__));




// __NR__ rt_sigtimedwait = 128
int rt_sigtimedwait(const sigset_p uthese, siginfo_p uinfo, timespec_p uts, size_t sigsetsize, errhand_t hand = err_log)
  __attribute__((__always_inline__));




// __NR__ rt_sigqueueinfo = 129
int rt_sigqueueinfo(pid_t pid, int sig, siginfo_p uinfo, errhand_t hand = err_log)
  __attribute__((__always_inline__));




// __NR__ rt_sigsuspend = 130
int rt_sigsuspend(sigset_p unewset, size_t sigsetsize, errhand_t hand = err_log)
  __attribute__((__always_inline__));




// __NR__ sigaltstack = 131
int sigaltstack(const stack_p uss, stack_p uoss, errhand_t hand = err_log)
  __attribute__((__always_inline__));




// __NR__ utime = 132
int utime(ostr_t path, utimbuf_p times, errhand_t hand = err_log)
  __attribute__((__always_inline__));




// __NR__ mknod = 133
int mknod(istr_t path, umode_t mode, unsigned dev, errhand_t hand = err_log)
  __attribute__((__always_inline__));




// __NR__ personality = 135
int personality(unsigned personality, errhand_t hand = err_log)
  __attribute__((__always_inline__));




// __NR__ ustat = 136
int ustat(unsigned dev, ustat_p ubuf, errhand_t hand = err_log)
  __attribute__((__always_inline__));




// __NR__ statfs = 137
int statfs(istr_t path, statfs_p buf, errhand_t hand = err_log)
  __attribute__((__always_inline__));




// __NR__ fstatfs = 138
int fstatfs(fd_t fd, statfs_p buf, errhand_t hand = err_log)
  __attribute__((__always_inline__));




// __NR__ sysfs = 139
int sysfs(int option, uint64_t arg1, uint64_t arg2, errhand_t hand = err_log)
  __attribute__((__always_inline__));




// __NR__ getpriority = 140
int getpriority(int which, int who, errhand_t hand = err_log)
  __attribute__((__always_inline__));




// __NR__ setpriority = 141
int setpriority(int which, int who, int niceval, errhand_t hand = err_log)
  __attribute__((__always_inline__));




// __NR__ sched_setparam = 142
int sched_setparam(pid_t pid, const void * param, errhand_t hand = err_log)
  __attribute__((__always_inline__));




// __NR__ sched_getparam = 143
int sched_getparam(pid_t pid, sched_param_p param, errhand_t hand = err_log)
  __attribute__((__always_inline__));




// __NR__ sched_setscheduler = 144
int sched_setscheduler(pid_t pid, int policy, sched_param_p param, errhand_t hand = err_log)
  __attribute__((__always_inline__));




// __NR__ sched_getscheduler = 145
int sched_getscheduler(pid_t pid, errhand_t hand = err_log)
  __attribute__((__always_inline__));




// __NR__ sched_get_priority_max = 146
int sched_get_priority_max(int policy, errhand_t hand = err_log)
  __attribute__((__always_inline__));




// __NR__ sched_get_priority_min = 147
int sched_get_priority_min(int policy, errhand_t hand = err_log)
  __attribute__((__always_inline__));




// __NR__ sched_rr_get_interval = 148
int sched_rr_get_interval(pid_t pid, timespec_p interval, errhand_t hand = err_log)
  __attribute__((__always_inline__));




// __NR__ mlock = 149
int mlock(void_p start, size_t len, errhand_t hand = err_log)
  __attribute__((__always_inline__));




// __NR__ munlock = 150
int munlock(void_p start, size_t len, errhand_t hand = err_log)
  __attribute__((__always_inline__));




// __NR__ mlockall = 151
int mlockall(int flags, errhand_t hand = err_log)
  __attribute__((__always_inline__));




// __NR__ munlockall = 152
int munlockall(errhand_t hand = err_log)
  __attribute__((__always_inline__));




// __NR__ vhangup = 153
int vhangup(errhand_t hand = err_log)
  __attribute__((__always_inline__));




// __NR__ modify_ldt = 154
int modify_ldt(int func, void_p ptr, uint64_t bytecount, errhand_t hand = err_log)
  __attribute__((__always_inline__));




// __NR__ pivot_root = 155
int pivot_root(istr_t new_root, istr_t put_old, errhand_t hand = err_log)
  __attribute__((__always_inline__));




// __NR__ _sysctl = 156
int _sysctl(sysctl_args_p args, errhand_t hand = err_log)
  __attribute__((__always_inline__));




// __NR__ prctl = 157
int prctl(int option, uint64_t arg2, uint64_t arg3, uint64_t arg4, uint64_t arg5, errhand_t hand = err_log)
  __attribute__((__always_inline__));




// __NR__ arch_prctl = 158
int arch_prctl(task_struct_p task, int code, uint64_t addr, errhand_t hand = err_log)
  __attribute__((__always_inline__));




// __NR__ adjtimex = 159
int adjtimex(timex_p txc_p, errhand_t hand = err_log)
  __attribute__((__always_inline__));




// __NR__ setrlimit = 160
int setrlimit(unsigned resource, rlimit_p rlim, errhand_t hand = err_log)
  __attribute__((__always_inline__));




// __NR__ chroot = 161
int chroot(istr_t path, errhand_t hand = err_log)
  __attribute__((__always_inline__));




// __NR__ sync = 162
int sync(errhand_t hand = err_log)
  __attribute__((__always_inline__));




// __NR__ acct = 163
int acct(istr_t name, errhand_t hand = err_log)
  __attribute__((__always_inline__));




// __NR__ settimeofday = 164
int settimeofday(timeval_p tv, timezone_p tz, errhand_t hand = err_log)
  __attribute__((__always_inline__));




// __NR__ mount = 165
int mount(ostr_t dev_name, ostr_t dir_name, ostr_t type, uint64_t flags, void_p data, errhand_t hand = err_log)
  __attribute__((__always_inline__));




// __NR__ umount2 = 166
int umount2(istr_t target, int flags, errhand_t hand = err_log)
  __attribute__((__always_inline__));




// __NR__ swapon = 167
int swapon(istr_t specialfile, int swap_flags, errhand_t hand = err_log)
  __attribute__((__always_inline__));




// __NR__ swapoff = 168
int swapoff(istr_t specialfile, errhand_t hand = err_log)
  __attribute__((__always_inline__));




// __NR__ reboot = 169
int reboot(int magic1, int magic2, unsigned cmd, void_p arg, errhand_t hand = err_log)
  __attribute__((__always_inline__));




// __NR__ sethostname = 170
int sethostname(ostr_t name, int len, errhand_t hand = err_log)
  __attribute__((__always_inline__));




// __NR__ setdomainname = 171
int setdomainname(ostr_t name, int len, errhand_t hand = err_log)
  __attribute__((__always_inline__));




// __NR__ iopl = 172
int iopl(unsigned level, pt_regs_p regs, errhand_t hand = err_log)
  __attribute__((__always_inline__));




// __NR__ ioperm = 173
int ioperm(uint64_t from, uint64_t num, int turn_on, errhand_t hand = err_log)
  __attribute__((__always_inline__));




// __NR__ init_module = 175
int init_module(void_p umod, uint64_t len, istr_t uargs, errhand_t hand = err_log)
  __attribute__((__always_inline__));




// __NR__ delete_module = 176
int delete_module(istr_t name_user, unsigned flags, errhand_t hand = err_log)
  __attribute__((__always_inline__));




// __NR__ quotactl = 179
int quotactl(unsigned cmd, istr_t special, qid_t id, void_p addr, errhand_t hand = err_log)
  __attribute__((__always_inline__));




// __NR__ gettid = 186
int gettid(errhand_t hand = err_log)
  __attribute__((__always_inline__));




// __NR__ readahead = 187
int readahead(fd_t fd, off_t offset, size_t count, errhand_t hand = err_log)
  __attribute__((__always_inline__));




// __NR__ setxattr = 188
int setxattr(istr_t path, istr_t name, const void_p value, size_t size, int flags, errhand_t hand = err_log)
  __attribute__((__always_inline__));




// __NR__ lsetxattr = 189
int lsetxattr(istr_t path, istr_t name, const void_p value, size_t size, int flags, errhand_t hand = err_log)
  __attribute__((__always_inline__));




// __NR__ fsetxattr = 190
int fsetxattr(fd_t fd, istr_t name, const void_p value, size_t size, int flags, errhand_t hand = err_log)
  __attribute__((__always_inline__));




// __NR__ getxattr = 191
int getxattr(istr_t path, istr_t name, void_p value, size_t size, errhand_t hand = err_log)
  __attribute__((__always_inline__));




// __NR__ lgetxattr = 192
int lgetxattr(istr_t path, istr_t name, void_p value, size_t size, errhand_t hand = err_log)
  __attribute__((__always_inline__));




// __NR__ fgetxattr = 193
int fgetxattr(fd_t fd, istr_t name, void_p value, size_t size, errhand_t hand = err_log)
  __attribute__((__always_inline__));




// __NR__ listxattr = 194
int listxattr(istr_t path, ostr_t list, size_t size, errhand_t hand = err_log)
  __attribute__((__always_inline__));




// __NR__ llistxattr = 195
int llistxattr(istr_t path, ostr_t list, size_t size, errhand_t hand = err_log)
  __attribute__((__always_inline__));




// __NR__ flistxattr = 196
int flistxattr(fd_t fd, ostr_t list, size_t size, errhand_t hand = err_log)
  __attribute__((__always_inline__));




// __NR__ removexattr = 197
int removexattr(istr_t path, istr_t name, errhand_t hand = err_log)
  __attribute__((__always_inline__));




// __NR__ lremovexattr = 198
int lremovexattr(istr_t path, istr_t name, errhand_t hand = err_log)
  __attribute__((__always_inline__));




// __NR__ fremovexattr = 199
int fremovexattr(fd_t fd, istr_t name, errhand_t hand = err_log)
  __attribute__((__always_inline__));




// __NR__ tkill = 200
int tkill(pid_t pid, int sig, errhand_t hand = err_log)
  __attribute__((__always_inline__));




// __NR__ time = 201
time_t time(time_p tloc, errhand_t hand = err_log)
  __attribute__((__always_inline__));




// __NR__ futex = 202
int futex(uint32_p uaddr, int op, uint32_t val, timespec_p utime, uint32_p uaddr2, uint32_t val3, errhand_t hand = err_log)
  __attribute__((__always_inline__));




// __NR__ sched_setaffinity = 203
int sched_setaffinity(pid_t pid, size_t len, const void * user_mask_ptr, errhand_t hand = err_log)
  __attribute__((__always_inline__));




// __NR__ sched_getaffinity = 204
int sched_getaffinity(pid_t pid, unsigned len, uint64_p user_mask_ptr, errhand_t hand = err_log)
  __attribute__((__always_inline__));




// __NR__ lookup_dcookie = 212
int lookup_dcookie(uint64_t cookie64, long buf, long len, errhand_t hand = err_log)
  __attribute__((__always_inline__));




// __NR__ epoll_create = 213
int epoll_create(int size, errhand_t hand = err_log)
  __attribute__((__always_inline__));




// __NR__ remap_file_pages = 216
int remap_file_pages(uint64_t start, uint64_t size, uint64_t prot, uint64_t pgoff, uint64_t flags, errhand_t hand = err_log)
  __attribute__((__always_inline__));




// __NR__ getdents64 = 217
int getdents64(fd_t fd, linux_dirent64_p dirent, unsigned count, errhand_t hand = err_log)
  __attribute__((__always_inline__));




// __NR__ set_tid_address = 218
int set_tid_address(int32_p tidptr, errhand_t hand = err_log)
  __attribute__((__always_inline__));




// __NR__ restart_syscall = 219
int restart_syscall(errhand_t hand = err_log)
  __attribute__((__always_inline__));




// __NR__ semtimedop = 220
int semtimedop(int semid, sembuf_p tsops, unsigned nsops, timespec_p timeout, errhand_t hand = err_log)
  __attribute__((__always_inline__));




// __NR__ fadvise64 = 221
int fadvise64(fd_t fd, off_t offset, size_t len, int advice, errhand_t hand = err_log)
  __attribute__((__always_inline__));




// __NR__ timer_create = 222
int timer_create(const clockid_t which_clock, sigevent_p timer_event_spec, timer_p created_timer_id, errhand_t hand = err_log)
  __attribute__((__always_inline__));




// __NR__ timer_settime = 223
int timer_settime(timer_t timer_id, int flags, itimerspec_p new_setting, itimerspec_p old_setting, errhand_t hand = err_log)
  __attribute__((__always_inline__));




// __NR__ timer_gettime = 224
int timer_gettime(timer_t timer_id, itimerspec_p setting, errhand_t hand = err_log)
  __attribute__((__always_inline__));




// __NR__ timer_getoverrun = 225
int timer_getoverrun(timer_t timer_id, errhand_t hand = err_log)
  __attribute__((__always_inline__));




// __NR__ timer_delete = 226
int timer_delete(timer_t timer_id, errhand_t hand = err_log)
  __attribute__((__always_inline__));




// __NR__ clock_settime = 227
int clock_settime(const clockid_t which_clock, timespec_p tp, errhand_t hand = err_log)
  __attribute__((__always_inline__));




// __NR__ clock_gettime = 228
int clock_gettime(const clockid_t which_clock, timespec_p tp, errhand_t hand = err_log)
  __attribute__((__always_inline__));




// __NR__ clock_getres = 229
int clock_getres(const clockid_t which_clock, timespec_p tp, errhand_t hand = err_log)
  __attribute__((__always_inline__));




// __NR__ clock_nanosleep = 230
int clock_nanosleep(const clockid_t which_clock, int flags, timespec_p rqtp, timespec_p rmtp, errhand_t hand = err_log)
  __attribute__((__always_inline__));




// __NR__ exit_group = 231
int exit_group(int error_code, errhand_t hand = err_log)
  __attribute__((__always_inline__, __noreturn__));




// __NR__ epoll_wait = 232
int epoll_wait(int epfd, epoll_event_p events, int maxevents, int timeout, errhand_t hand = err_log)
  __attribute__((__always_inline__));




// __NR__ epoll_ctl = 233
int epoll_ctl(int epfd, int op, fd_t fd, epoll_event_p event, errhand_t hand = err_log)
  __attribute__((__always_inline__));




// __NR__ tgkill = 234
int tgkill(pid_t tgid, pid_t pid, int sig, errhand_t hand = err_log)
  __attribute__((__always_inline__));




// __NR__ utimes = 235
int utimes(ostr_t path, timeval_p utimes, errhand_t hand = err_log)
  __attribute__((__always_inline__));




// __NR__ mbind = 237
int mbind(uint64_t start, uint64_t len, uint64_t mode, uint64_p nmask, uint64_t maxnode, unsigned flags, errhand_t hand = err_log)
  __attribute__((__always_inline__));




// __NR__ set_mempolicy = 238
int set_mempolicy(int mode, uint64_p nmask, uint64_t maxnode, errhand_t hand = err_log)
  __attribute__((__always_inline__));




// __NR__ get_mempolicy = 239
int get_mempolicy(int32_p policy, uint64_p nmask, uint64_t maxnode, uint64_t addr, uint64_t flags, errhand_t hand = err_log)
  __attribute__((__always_inline__));




// __NR__ mq_open = 240
int mq_open(istr_t u_name, int oflag, mode_t mode, mq_attr_p u_attr, errhand_t hand = err_log)
  __attribute__((__always_inline__));




// __NR__ mq_unlink = 241
int mq_unlink(istr_t u_name, errhand_t hand = err_log)
  __attribute__((__always_inline__));




// __NR__ mq_timedsend = 242
int mq_timedsend(mqd_t mqdes, istr_t u_msg_ptr, size_t msg_len, unsigned msg_prio, timespec_p u_abs_timeout, errhand_t hand = err_log)
  __attribute__((__always_inline__));




// __NR__ mq_timedreceive = 243
int mq_timedreceive(mqd_t mqdes, ostr_t u_msg_ptr, size_t msg_len, uint32_p u_msg_prio, timespec_p u_abs_timeout, errhand_t hand = err_log)
  __attribute__((__always_inline__));




// __NR__ mq_notify = 244
int mq_notify(mqd_t mqdes, sigevent_p u_notification, errhand_t hand = err_log)
  __attribute__((__always_inline__));




// __NR__ mq_getsetattr = 245
int mq_getsetattr(mqd_t mqdes, mq_attr_p u_mqstat, mq_attr_p u_omqstat, errhand_t hand = err_log)
  __attribute__((__always_inline__));




// __NR__ kexec_load = 246
int kexec_load(uint64_t entry, uint64_t nr_segments, kexec_segment_p segments, uint64_t flags, errhand_t hand = err_log)
  __attribute__((__always_inline__));




// __NR__ waitid = 247
int waitid(int which, pid_t upid, siginfo_p infop, int options, rusage_p ru, errhand_t hand = err_log)
  __attribute__((__always_inline__));




// __NR__ add_key = 248
int add_key(istr_t _type, istr_t _description, const void_p _payload, size_t plen, errhand_t hand = err_log)
  __attribute__((__always_inline__));




// __NR__ request_key = 249
int request_key(istr_t _type, istr_t _description, istr_t _callout_info, uint64_t destringid, errhand_t hand = err_log)
  __attribute__((__always_inline__));




// __NR__ keyctl = 250
int keyctl(int option, uint64_t arg2, uint64_t arg3, uint64_t arg4, uint64_t arg5, errhand_t hand = err_log)
  __attribute__((__always_inline__));




// __NR__ ioprio_set = 251
int ioprio_set(int which, int who, int ioprio, errhand_t hand = err_log)
  __attribute__((__always_inline__));




// __NR__ ioprio_get = 252
int ioprio_get(int which, int who, errhand_t hand = err_log)
  __attribute__((__always_inline__));




// __NR__ inotify_init = 253
int inotify_init(errhand_t hand = err_log)
  __attribute__((__always_inline__));




// __NR__ inotify_add_watch = 254
int inotify_add_watch(fd_t fd, istr_t path, uint32_t mask, errhand_t hand = err_log)
  __attribute__((__always_inline__));




// __NR__ inotify_rm_watch = 255
int inotify_rm_watch(fd_t fd, int32_t wd, errhand_t hand = err_log)
  __attribute__((__always_inline__));




// __NR__ migrate_pages = 256
int migrate_pages(pid_t pid, uint64_t maxnode, uint64_p old_nodes, uint64_p new_nodes, errhand_t hand = err_log)
  __attribute__((__always_inline__));




// __NR__ openat = 257
int openat(fd_t dfd, istr_t path, int flags, int mode, errhand_t hand = err_log)
  __attribute__((__always_inline__));




// __NR__ mkdirat = 258
int mkdirat(fd_t dfd, istr_t path, int mode, errhand_t hand = err_log)
  __attribute__((__always_inline__));




// __NR__ mknodat = 259
int mknodat(fd_t dfd, istr_t path, int mode, unsigned dev, errhand_t hand = err_log)
  __attribute__((__always_inline__));




// __NR__ fchownat = 260
int fchownat(fd_t dfd, istr_t path, uid_t user, gid_t group, int flag, errhand_t hand = err_log)
  __attribute__((__always_inline__));




// __NR__ futimesat = 261
int futimesat(fd_t dfd, istr_t path, timeval_p utimes, errhand_t hand = err_log)
  __attribute__((__always_inline__));




// __NR__ newfstatat = 262
int newfstatat(fd_t dfd, istr_t path, stat_p statbuf, int flag, errhand_t hand = err_log)
  __attribute__((__always_inline__));




// __NR__ unlinkat = 263
int unlinkat(fd_t dfd, istr_t path, int flag, errhand_t hand = err_log)
  __attribute__((__always_inline__));




// __NR__ renameat = 264
int renameat(fd_t oldfd, istr_t opath, fd_t newfd, istr_t npath, errhand_t hand = err_log)
  __attribute__((__always_inline__));




// __NR__ linkat = 265
int linkat(fd_t oldfd, istr_t opath, fd_t newfd, istr_t npath, int flags, errhand_t hand = err_log)
  __attribute__((__always_inline__));




// __NR__ symlinkat = 266
int symlinkat(istr_t opath, fd_t newfd, istr_t npath, errhand_t hand = err_log)
  __attribute__((__always_inline__));




// __NR__ readlinkat = 267
int readlinkat(fd_t dfd, istr_t path, ostr_t buf, int bufsiz, errhand_t hand = err_log)
  __attribute__((__always_inline__));




// __NR__ fchmodat = 268
int fchmodat(fd_t dfd, istr_t path, mode_t mode, errhand_t hand = err_log)
  __attribute__((__always_inline__));




// __NR__ faccessat = 269
int faccessat(fd_t dfd, istr_t path, int mode, errhand_t hand = err_log)
  __attribute__((__always_inline__));




// __NR__ pselect6 = 270
int pselect6(int n, fdset_p inp, fdset_p outp, fdset_p exp, timespec_p tsp, void_p sig, errhand_t hand = err_log)
  __attribute__((__always_inline__));




// __NR__ ppoll = 271
int ppoll(pollfd_p ufds, unsigned nfds, timespec_p tsp, const sigset_p sigmask, size_t sigsetsize, errhand_t hand = err_log)
  __attribute__((__always_inline__));




// __NR__ unshare = 272
int unshare(int unshare_flags, errhand_t hand = err_log)
  __attribute__((__always_inline__));




// __NR__ set_robust_list = 273
int set_robust_list(robust_list_head_p head, size_t len, errhand_t hand = err_log)
  __attribute__((__always_inline__));




// __NR__ get_robust_list = 274
int get_robust_list(int pid, robust_list_head_p head_ptr, size_p len_ptr, errhand_t hand = err_log)
  __attribute__((__always_inline__));




// __NR__ splice = 275
int splice(int fd_in, off_p off_in, int fd_out, off_p off_out, size_t len, unsigned flags, errhand_t hand = err_log)
  __attribute__((__always_inline__));




// __NR__ tee = 276
int tee(int fdin, int fdout, size_t len, unsigned flags, errhand_t hand = err_log)
  __attribute__((__always_inline__));




// __NR__ sync_file_range = 277
int sync_file_range(fd_t fd, off_t offset, off_t bytes, long flags, errhand_t hand = err_log)
  __attribute__((__always_inline__));




// __NR__ vmsplice = 278
int vmsplice(fd_t fd, iovec_p iov, uint64_t nr_segs, unsigned flags, errhand_t hand = err_log)
  __attribute__((__always_inline__));




// __NR__ move_pages = 279
int move_pages(pid_t pid, uint64_t nr_pages, void_p pages, int32_p nodes, int32_p status, int flags, errhand_t hand = err_log)
  __attribute__((__always_inline__));




// __NR__ utimensat = 280
int utimensat(fd_t dfd, istr_t path, timespec_p utimes, int flags, errhand_t hand = err_log)
  __attribute__((__always_inline__));




// __NR__ epoll_pwait = 281
int epoll_pwait(int epfd, epoll_event_p events, int maxevents, int timeout, const sigset_p sigmask, size_t sigsetsize, errhand_t hand = err_log)
  __attribute__((__always_inline__));




// __NR__ signalfd = 282
int signalfd(int ufd, sigset_p user_mask, size_t sizemask, errhand_t hand = err_log)
  __attribute__((__always_inline__));




// __NR__ timerfd_create = 283
int timerfd_create(int clockid, int flags, errhand_t hand = err_log)
  __attribute__((__always_inline__));




// __NR__ eventfd = 284
int eventfd(unsigned count, errhand_t hand = err_log)
  __attribute__((__always_inline__));




// __NR__ fallocate = 285
int fallocate(fd_t fd, long mode, off_t offset, off_t len, errhand_t hand = err_log)
  __attribute__((__always_inline__));




// __NR__ timerfd_settime = 286
int timerfd_settime(int ufd, int flags, itimerspec_p utmr, itimerspec_p otmr, errhand_t hand = err_log)
  __attribute__((__always_inline__));




// __NR__ timerfd_gettime = 287
int timerfd_gettime(int ufd, itimerspec_p otmr, errhand_t hand = err_log)
  __attribute__((__always_inline__));




// __NR__ accept4 = 288
int accept4(fd_t fd, sockaddr_p upeer_sockaddr, int32_p upeer_addrlen, int flags, errhand_t hand = err_log)
  __attribute__((__always_inline__));




// __NR__ signalfd4 = 289
int signalfd4(int ufd, sigset_p user_mask, size_t sizemask, int flags, errhand_t hand = err_log)
  __attribute__((__always_inline__));




// __NR__ eventfd2 = 290
int eventfd2(unsigned count, int flags, errhand_t hand = err_log)
  __attribute__((__always_inline__));




// __NR__ epoll_create1 = 291
int epoll_create1(int flags, errhand_t hand = err_log)
  __attribute__((__always_inline__));




// __NR__ dup3 = 292
int dup3(fd_t oldfd, fd_t newfd, int flags, errhand_t hand = err_log)
  __attribute__((__always_inline__));




// __NR__ pipe2 = 293
int pipe2(fd_p filedes, int flags, errhand_t hand = err_log)
  __attribute__((__always_inline__));




// __NR__ inotify_init1 = 294
int inotify_init1(int flags, errhand_t hand = err_log)
  __attribute__((__always_inline__));




// __NR__ preadv = 295
int preadv(fd_t fd, iovec_p vec, uint64_t vlen, uint64_t pos_l, uint64_t pos_h, errhand_t hand = err_log)
  __attribute__((__always_inline__));




// __NR__ pwritev = 296
int pwritev(fd_t fd, iovec_p vec, uint64_t vlen, uint64_t pos_l, uint64_t pos_h, errhand_t hand = err_log)
  __attribute__((__always_inline__));




// __NR__ rt_tgsigqueueinfo = 297
int rt_tgsigqueueinfo(pid_t tgid, pid_t pid, int sig, siginfo_p uinfo, errhand_t hand = err_log)
  __attribute__((__always_inline__));




// __NR__ perf_event_open = 298
int perf_event_open(perf_event_attr_p attr_uptr, pid_t pid, int cpu, int group_fd, uint64_t flags, errhand_t hand = err_log)
  __attribute__((__always_inline__));




// __NR__ recvmmsg = 299
int recvmmsg(fd_t fd, msghdr_p mmsg, unsigned vlen, unsigned flags, timespec_p timeout, errhand_t hand = err_log)
  __attribute__((__always_inline__));




// __NR__ fanotify_init = 300
int fanotify_init(unsigned flags, unsigned event_f_flags, errhand_t hand = err_log)
  __attribute__((__always_inline__));




// __NR__ fanotify_mark = 301
int fanotify_mark(long fanotify_fd, long flags, uint64_t mask, fd_t dfd, istr_t path, errhand_t hand = err_log)
  __attribute__((__always_inline__));




// __NR__ prlimit64 = 302
int prlimit64(pid_t pid, unsigned resource, rlimit64_p new_rlim, rlimit64_p old_rlim, errhand_t hand = err_log)
  __attribute__((__always_inline__));




// __NR__ name_to_handle_at = 303
int name_to_handle_at(fd_t dfd, istr_t name, file_handle_p handle, int32_p mnt_id, int flag, errhand_t hand = err_log)
  __attribute__((__always_inline__));




// __NR__ open_by_handle_at = 304
int open_by_handle_at(fd_t dfd, istr_t name, file_handle_p handle, int32_p mnt_id, int flags, errhand_t hand = err_log)
  __attribute__((__always_inline__));




// __NR__ clock_adjtime = 305
int clock_adjtime(clockid_t which_clock, timex_p tx, errhand_t hand = err_log)
  __attribute__((__always_inline__));




// __NR__ syncfs = 306
int syncfs(fd_t fd, errhand_t hand = err_log)
  __attribute__((__always_inline__));




// __NR__ sendmmsg = 307
int sendmmsg(fd_t fd, msghdr_p mmsg, unsigned vlen, unsigned flags, errhand_t hand = err_log)
  __attribute__((__always_inline__));




// __NR__ setns = 308
int setns(fd_t fd, int nstype, errhand_t hand = err_log)
  __attribute__((__always_inline__));




// __NR__ getcpu = 309
int getcpu(uint32_p cpup, uint32_p nodep, errhand_t hand = err_log)
  __attribute__((__always_inline__));




// __NR__ process_vm_readv = 310
int process_vm_readv(pid_t pid, iovec_p lvec, uint64_t liovcnt, iovec_p rvec, uint64_t riovcnt, uint64_t flags, errhand_t hand = err_log)
  __attribute__((__always_inline__));




// __NR__ process_vm_writev = 311
int process_vm_writev(pid_t pid, iovec_p lvec, uint64_t liovcnt, iovec_p rvec, uint64_t riovcnt, uint64_t flags, errhand_t hand = err_log)
  __attribute__((__always_inline__));




// __NR__ kcmp = 312
int kcmp(pid_t pid1, pid_t pid2, int type, uint64_t idx1, uint64_t idx2, errhand_t hand = err_log)
  __attribute__((__always_inline__));




// __NR__ finit_module = 313
int finit_module(fd_t fd, istr_t uargs, int flags, errhand_t hand = err_log)
  __attribute__((__always_inline__));




// __NR__ sched_setattr = 314
int sched_setattr(pid_t pid, sched_attr_p attr, unsigned flags, errhand_t hand = err_log)
  __attribute__((__always_inline__));




// __NR__ sched_getattr = 315
int sched_getattr(pid_t pid, sched_attr_p attr, unsigned size, unsigned flags, errhand_t hand = err_log)
  __attribute__((__always_inline__));




// __NR__ renameat2 = 316
int renameat2(int olddfd, istr_t opath, int newdfd, istr_t npath, unsigned flags, errhand_t hand = err_log)
  __attribute__((__always_inline__));




// __NR__ seccomp = 317
int seccomp(unsigned op, unsigned flags, istr_t uargs, errhand_t hand = err_log)
  __attribute__((__always_inline__));




// __NR__ getrandom = 318
int getrandom(ostr_t buf, size_t count, unsigned flags, errhand_t hand = err_log)
  __attribute__((__always_inline__));




// __NR__ memfd_create = 319
int memfd_create(istr_t uname_ptr, unsigned flags, errhand_t hand = err_log)
  __attribute__((__always_inline__));




// __NR__ kexec_file_load = 320
int kexec_file_load(int kernel_fd, int initrd_fd, size_t cmdline_len, istr_t cmdline_ptr, uint64_t flags, errhand_t hand = err_log)
  __attribute__((__always_inline__));




// __NR__ bpf = 321
int bpf(int cmd, bpf_attr_p attr, unsigned size, errhand_t hand = err_log)
  __attribute__((__always_inline__));




// __NR__ execveat = 322
int execveat(fd_t dfd, istr_t path, istr_v argv, istr_v envp, int flags, errhand_t hand = err_log)
  __attribute__((__always_inline__));




// __NR__ userfaultfd = 323
int userfaultfd(int flags, errhand_t hand = err_log)
  __attribute__((__always_inline__));




// __NR__ membarrier = 324
int membarrier(int cmd, int flags, errhand_t hand = err_log)
  __attribute__((__always_inline__));




// __NR__ mlock2 = 325
int mlock2(uint64_t start, size_t len, int flags, errhand_t hand = err_log)
  __attribute__((__always_inline__));




// __NR__ copy_file_range = 326
int copy_file_range(fd_t fd_in, off_p off_in, fd_t fd_out, off_p off_out, size_t len, unsigned flags, errhand_t hand = err_log)
  __attribute__((__always_inline__));




// __NR__ preadv2 = 327
int preadv2(fd_t fd, iovec_p vec, uint64_t vlen, uint64_t pos_l, uint64_t pos_h, int flags, errhand_t hand = err_log)
  __attribute__((__always_inline__));




// __NR__ pwritev2 = 328
int pwritev2(fd_t fd, iovec_p vec, uint64_t vlen, uint64_t pos_l, uint64_t pos_h, int flags, errhand_t hand = err_log)
  __attribute__((__always_inline__));



} // namespace sys

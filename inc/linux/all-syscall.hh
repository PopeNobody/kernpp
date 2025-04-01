#include <types.hh>
extern "C" {
// __NR__ read = 0 

inline ssize_t read(fd_t fd, ostr_t buf, size_t count)
  __attribute__((__always_inline__));
// __NR__ write = 1 

inline ssize_t sys_write(fd_t fd, istr_t buf, size_t count)
  __attribute__((__always_inline__));
// __NR__ open = 2 

inline fd_t open(istr_t filename, int flags, int mode)
  __attribute__((__always_inline__));
// __NR__ close = 3 

inline int close(fd_t fd)
  __attribute__((__always_inline__));
// __NR__ stat = 4 

inline int stat(istr_t filename, stat_p statbuf)
  __attribute__((__always_inline__));
// __NR__ fstat = 5 

inline int fstat(fd_t fd, stat_p statbuf)
  __attribute__((__always_inline__));
// __NR__ lstat = 6 

inline int lstat(istr_t filename, stat_p statbuf)
  __attribute__((__always_inline__));
// __NR__ poll = 7 

inline int poll(pollfd_p ufds, unsigned nfds, long timeout_msecs)
  __attribute__((__always_inline__));
// __NR__ lseek = 8 

inline int lseek(fd_t fd, off_t offset, unsigned origin)
  __attribute__((__always_inline__));
// __NR__ mmap = 9 

inline char* mmap(void* addr, size_t len, int prot, int flags, fd_t fd, off_t off)
  __attribute__((__always_inline__));
// __NR__ mprotect = 10 

inline int mprotect(uint64_t start, size_t len, uint64_t prot)
  __attribute__((__always_inline__));
// __NR__ munmap = 11 

inline int munmap(uint64_t addr, size_t len)
  __attribute__((__always_inline__));
// __NR__ brk = 12 

inline int brk(void_p brk)
  __attribute__((__always_inline__));
// __NR__ rt_sigaction = 13 

inline int rt_sigaction(int sig, sigaction_p act, sigaction_p oact)
  __attribute__((__always_inline__));
// __NR__ rt_sigprocmask = 14 

inline int rt_sigprocmask(int how, sigset_p nset, sigset_p oset, size_t sigsetsize)
  __attribute__((__always_inline__));
// __NR__ rt_sigreturn = 15 

inline int rt_sigreturn(uint64_t __unused)
  __attribute__((__always_inline__));
// __NR__ ioctl = 16 

inline int ioctl(fd_t fd, unsigned cmd, uint64_t arg)
  __attribute__((__always_inline__));
// __NR__ pread64 = 17 

inline int pread64(fd_t fd, ostr_t buf, size_t count, off_t pos)
  __attribute__((__always_inline__));
// __NR__ pwrite64 = 18 

inline int pwrite64(fd_t fd, istr_t buf, size_t count, off_t pos)
  __attribute__((__always_inline__));
// __NR__ readv = 19 

inline int readv(fd_t fd, iovec_p vec, uint64_t vlen)
  __attribute__((__always_inline__));
// __NR__ writev = 20 

inline int writev(fd_t fd, iovec_p vec, uint64_t vlen)
  __attribute__((__always_inline__));
// __NR__ access = 21 

inline int access(istr_t filename, int mode)
  __attribute__((__always_inline__));
// __NR__ pipe = 22 

inline int pipe(fd_p filedes)
  __attribute__((__always_inline__));
// __NR__ select = 23 

inline int select(int n, fd_set_p inp, fd_set_p outp, fd_set_p exp, timeval_p tvp)
  __attribute__((__always_inline__));
// __NR__ sched_yield = 24 

inline int sched_yield()
  __attribute__((__always_inline__));
// __NR__ mremap = 25 

inline int mremap(uint64_t addr, uint64_t old_len, uint64_t new_len, uint64_t flags, uint64_t new_addr)
  __attribute__((__always_inline__));
// __NR__ msync = 26 

inline int msync(uint64_t start, size_t len, int flags)
  __attribute__((__always_inline__));
// __NR__ mincore = 27 

inline int mincore(uint64_t start, size_t len, ostr_t vec)
  __attribute__((__always_inline__));
// __NR__ madvise = 28 

inline int madvise(uint64_t start, size_t len_in, int behavior)
  __attribute__((__always_inline__));
// __NR__ shmget = 29 

inline int shmget(key_t key, size_t size, int shmflg)
  __attribute__((__always_inline__));
// __NR__ shmat = 30 

inline int shmat(int shmid, ostr_t shmaddr, int shmflg)
  __attribute__((__always_inline__));
// __NR__ shmctl = 31 

inline int shmctl(int shmid, int cmd, shmid_ds_p buf)
  __attribute__((__always_inline__));
// __NR__ dup = 32 

inline int dup(unsigned fildes)
  __attribute__((__always_inline__));
// __NR__ dup2 = 33 

inline int dup2(fd_t oldfd, fd_t newfd)
  __attribute__((__always_inline__));
// __NR__ pause = 34 

inline int pause()
  __attribute__((__always_inline__));
// __NR__ nanosleep = 35 

inline int nanosleep(timespec_p rqtp, timespec_p rmtp)
  __attribute__((__always_inline__));
// __NR__ getitimer = 36 

inline int getitimer(int which, itimerval_p value)
  __attribute__((__always_inline__));
// __NR__ alarm = 37 

inline int alarm(unsigned seconds)
  __attribute__((__always_inline__));
// __NR__ setitimer = 38 

inline int setitimer(int which, itimerval_p value, itimerval_p ovalue)
  __attribute__((__always_inline__));
// __NR__ getpid = 39 

inline int getpid()
  __attribute__((__always_inline__));
// __NR__ sendfile = 40 

inline int sendfile(int out_fd, int in_fd, off_p offset, size_t count)
  __attribute__((__always_inline__));
// __NR__ socket = 41 

inline int socket(int family, int type, int protocol)
  __attribute__((__always_inline__));
// __NR__ connect = 42 

inline int connect(fd_t fd, sockaddr_p uservaddr, int addrlen)
  __attribute__((__always_inline__));
// __NR__ accept = 43 

inline int accept(fd_t fd, sockaddr_p upeer_sockaddr, int32_p upeer_addrlen)
  __attribute__((__always_inline__));
// __NR__ sendto = 44 

inline int sendto(fd_t fd, void_p buff, size_t len, unsigned flags, sockaddr_p addr, int addr_len)
  __attribute__((__always_inline__));
// __NR__ recvfrom = 45 

inline int recvfrom(fd_t fd, void_p ubuf, size_t size, unsigned flags, sockaddr_p addr, int32_p addr_len)
  __attribute__((__always_inline__));
// __NR__ sendmsg = 46 

inline int sendmsg(fd_t fd, msghdr_p msg, unsigned flags)
  __attribute__((__always_inline__));
// __NR__ recvmsg = 47 

inline int recvmsg(fd_t fd, msghdr_p msg, unsigned flags)
  __attribute__((__always_inline__));
// __NR__ shutdown = 48 

inline int shutdown(fd_t fd, int how)
  __attribute__((__always_inline__));
// __NR__ bind = 49 

inline int bind(fd_t fd, sockaddr_p umyaddr, int addrlen)
  __attribute__((__always_inline__));
// __NR__ listen = 50 

inline int listen(fd_t fd, int backlog)
  __attribute__((__always_inline__));
// __NR__ getsockname = 51 

inline int getsockname(fd_t fd, sockaddr_p usockaddr, int32_p usockaddr_len)
  __attribute__((__always_inline__));
// __NR__ getpeername = 52 

inline int getpeername(fd_t fd, sockaddr_p usockaddr, int32_p usockaddr_len)
  __attribute__((__always_inline__));
// __NR__ socketpair = 53 

inline int socketpair(int family, int type, int protocol, int32_p usockvec)
  __attribute__((__always_inline__));
// __NR__ setsockopt = 54 

inline int setsockopt(fd_t fd, int level, int optname, ostr_t optval, int optlen)
  __attribute__((__always_inline__));
// __NR__ getsockopt = 55 

inline int getsockopt(fd_t fd, int level, int optname, ostr_t optval, int32_p optlen)
  __attribute__((__always_inline__));
// __NR__ clone = 56 

inline int sys_clone(uint64_t clone_flags, uint64_t newsp, void_p parent_tid, void_p child_tid)
  __attribute__((__always_inline__));
// __NR__ fork = 57 

inline int fork()
  __attribute__((__always_inline__));
// __NR__ vfork = 58 

inline int vfork()
  __attribute__((__always_inline__));
// __NR__ execve = 59 

inline int execve(const char * filename, char *const * argv, char *const * envp)
  __attribute__((__always_inline__));
// __NR__ exit = 60 

inline void _exit(int error_code)
  __attribute__((__always_inline__));
// __NR__ wait4 = 61 

inline int wait4(pid_t upid, int32_p stat_addr, int options, rusage_p ru)
  __attribute__((__always_inline__));
// __NR__ kill = 62 

inline int kill(pid_t pid, int sig)
  __attribute__((__always_inline__));
// __NR__ uname = 63 

inline int uname(utsname_p name)
  __attribute__((__always_inline__));
// __NR__ semget = 64 

inline int semget(key_t key, int nsems, int semflg)
  __attribute__((__always_inline__));
// __NR__ semop = 65 

inline int semop(int semid, sembuf_p tsops, unsigned nsops)
  __attribute__((__always_inline__));
// __NR__ semctl = 66 

inline int semctl(int semid, int semnum, int cmd, union semun arg)
  __attribute__((__always_inline__));
// __NR__ shmdt = 67 

inline int shmdt(ostr_t shmaddr)
  __attribute__((__always_inline__));
// __NR__ msgget = 68 

inline int msgget(key_t key, int msgflg)
  __attribute__((__always_inline__));
// __NR__ msgsnd = 69 

inline int msgsnd(int msqid, msgbuf_p msgp, size_t msgsz, int msgflg)
  __attribute__((__always_inline__));
// __NR__ msgrcv = 70 

inline int msgrcv(int msqid, msgbuf_p msgp, size_t msgsz, long msgtyp, int msgflg)
  __attribute__((__always_inline__));
// __NR__ msgctl = 71 

inline int msgctl(int msqid, int cmd, msqid_ds_p buf)
  __attribute__((__always_inline__));
// __NR__ fcntl = 72 

inline int fcntl(fd_t fd, unsigned cmd, uint64_t arg)
  __attribute__((__always_inline__));
// __NR__ flock = 73 

inline int flock(fd_t fd, unsigned cmd)
  __attribute__((__always_inline__));
// __NR__ fsync = 74 

inline int fsync(fd_t fd)
  __attribute__((__always_inline__));
// __NR__ fdatasync = 75 

inline int fdatasync(fd_t fd)
  __attribute__((__always_inline__));
// __NR__ truncate = 76 

inline int truncate(istr_t path, long length)
  __attribute__((__always_inline__));
// __NR__ ftruncate = 77 

inline int ftruncate(fd_t fd, uint64_t length)
  __attribute__((__always_inline__));
// __NR__ getdents = 78 

inline ssize_t getdents(fd_t fd, linux_dirent_p dirent, size_t count)
  __attribute__((__always_inline__));
// __NR__ getcwd = 79 

inline int getcwd(ostr_t buf, uint64_t size)
  __attribute__((__always_inline__));
// __NR__ chdir = 80 

inline int chdir(istr_t filename)
  __attribute__((__always_inline__));
// __NR__ fchdir = 81 

inline int fchdir(fd_t fd)
  __attribute__((__always_inline__));
// __NR__ rename = 82 

inline int rename(istr_t oldname, istr_t newname)
  __attribute__((__always_inline__));
// __NR__ mkdir = 83 

inline int mkdir(istr_t pathname, int mode)
  __attribute__((__always_inline__));
// __NR__ rmdir = 84 

inline int rmdir(istr_t pathname)
  __attribute__((__always_inline__));
// __NR__ creat = 85 

inline int creat(istr_t pathname, int mode)
  __attribute__((__always_inline__));
// __NR__ link = 86 

inline int link(istr_t oldname, istr_t newname)
  __attribute__((__always_inline__));
// __NR__ unlink = 87 

inline int unlink(istr_t pathname)
  __attribute__((__always_inline__));
// __NR__ symlink = 88 

inline int symlink(istr_t oldname, istr_t newname)
  __attribute__((__always_inline__));
// __NR__ readlink = 89 

inline int readlink(istr_t path, ostr_t buf, int bufsiz)
  __attribute__((__always_inline__));
// __NR__ chmod = 90 

inline int chmod(istr_t filename, mode_t mode)
  __attribute__((__always_inline__));
// __NR__ fchmod = 91 

inline int fchmod(fd_t fd, mode_t mode)
  __attribute__((__always_inline__));
// __NR__ chown = 92 

inline int chown(istr_t filename, uid_t user, gid_t group)
  __attribute__((__always_inline__));
// __NR__ fchown = 93 

inline int fchown(fd_t fd, uid_t user, gid_t group)
  __attribute__((__always_inline__));
// __NR__ lchown = 94 

inline int lchown(istr_t filename, uid_t user, gid_t group)
  __attribute__((__always_inline__));
// __NR__ umask = 95 

inline int umask(int mask)
  __attribute__((__always_inline__));
// __NR__ gettimeofday = 96 

inline int gettimeofday(timeval_p tv, timezone_p tz)
  __attribute__((__always_inline__));
// __NR__ getrlimit = 97 

inline int getrlimit(unsigned resource, rlimit_p rlim)
  __attribute__((__always_inline__));
// __NR__ getrusage = 98 

inline int getrusage(int who, rusage_p ru)
  __attribute__((__always_inline__));
// __NR__ sysinfo = 99 

inline int sysinfo(sysinfo_p info)
  __attribute__((__always_inline__));
// __NR__ times = 100 

inline int times(sysinfo_p info)
  __attribute__((__always_inline__));
// __NR__ ptrace = 101 

inline int ptrace(long request, long pid, uint64_t addr, uint64_t data)
  __attribute__((__always_inline__));
// __NR__ getuid = 102 

inline int getuid()
  __attribute__((__always_inline__));
// __NR__ syslog = 103 

inline int syslog(int type, ostr_t buf, int len)
  __attribute__((__always_inline__));
// __NR__ getgid = 104 

inline int getgid()
  __attribute__((__always_inline__));
// __NR__ setuid = 105 

inline int setuid(uid_t uid)
  __attribute__((__always_inline__));
// __NR__ setgid = 106 

inline int setgid(gid_t gid)
  __attribute__((__always_inline__));
// __NR__ geteuid = 107 

inline int geteuid()
  __attribute__((__always_inline__));
// __NR__ getegid = 108 

inline int getegid()
  __attribute__((__always_inline__));
// __NR__ setpgid = 109 

inline int setpgid(pid_t pid, pid_t pgid)
  __attribute__((__always_inline__));
// __NR__ getppid = 110 

inline int getppid()
  __attribute__((__always_inline__));
// __NR__ getpgrp = 111 

inline int getpgrp()
  __attribute__((__always_inline__));
// __NR__ setsid = 112 

inline int setsid()
  __attribute__((__always_inline__));
// __NR__ setreuid = 113 

inline int setreuid(uid_t ruid, uid_t euid)
  __attribute__((__always_inline__));
// __NR__ setregid = 114 

inline int setregid(gid_t rgid, gid_t egid)
  __attribute__((__always_inline__));
// __NR__ getgroups = 115 

inline int getgroups(int gidsetsize, gid_p grouplist)
  __attribute__((__always_inline__));
// __NR__ setgroups = 116 

inline int setgroups(int gidsetsize, gid_p grouplist)
  __attribute__((__always_inline__));
// __NR__ setresuid = 117 

inline int setresuid(uid_p ruid, uid_p euid, uid_p suid)
  __attribute__((__always_inline__));
// __NR__ getresuid = 118 

inline int getresuid(uid_p ruid, uid_p euid, uid_p suid)
  __attribute__((__always_inline__));
// __NR__ setresgid = 119 

inline int setresgid(gid_t rgid, gid_t egid, gid_t sgid)
  __attribute__((__always_inline__));
// __NR__ getresgid = 120 

inline int getresgid(gid_p rgid, gid_p egid, gid_p sgid)
  __attribute__((__always_inline__));
// __NR__ getpgid = 121 

inline int getpgid(pid_t pid)
  __attribute__((__always_inline__));
// __NR__ setfsuid = 122 

inline int setfsuid(uid_t uid)
  __attribute__((__always_inline__));
// __NR__ setfsgid = 123 

inline int setfsgid(gid_t gid)
  __attribute__((__always_inline__));
// __NR__ getsid = 124 

inline int getsid(pid_t pid)
  __attribute__((__always_inline__));
// __NR__ capget = 125 

inline int capget(cap_user_header_t header, cap_user_data_t dataptr)
  __attribute__((__always_inline__));
// __NR__ capset = 126 

inline int capset(cap_user_header_t header, const cap_user_data_t data)
  __attribute__((__always_inline__));
// __NR__ rt_sigpending = 127 

inline int rt_sigpending(sigset_p set, size_t sigsetsize)
  __attribute__((__always_inline__));
// __NR__ rt_sigtimedwait = 128 

inline int rt_sigtimedwait(const sigset_p uthese, siginfo_p uinfo, timespec_p uts, size_t sigsetsize)
  __attribute__((__always_inline__));
// __NR__ rt_sigqueueinfo = 129 

inline int rt_sigqueueinfo(pid_t pid, int sig, siginfo_p uinfo)
  __attribute__((__always_inline__));
// __NR__ rt_sigsuspend = 130 

inline int rt_sigsuspend(sigset_p unewset, size_t sigsetsize)
  __attribute__((__always_inline__));
// __NR__ sigaltstack = 131 

inline int sigaltstack(const stack_p uss, stack_p uoss)
  __attribute__((__always_inline__));
// __NR__ utime = 132 

inline int utime(ostr_t filename, utimbuf_p times)
  __attribute__((__always_inline__));
// __NR__ mknod = 133 

inline int mknod(istr_t filename, umode_t mode, unsigned dev)
  __attribute__((__always_inline__));
// __NR__ personality = 135 

inline int personality(unsigned personality)
  __attribute__((__always_inline__));
// __NR__ ustat = 136 

inline int ustat(unsigned dev, ustat_p ubuf)
  __attribute__((__always_inline__));
// __NR__ statfs = 137 

inline int statfs(istr_t pathname, statfs_p buf)
  __attribute__((__always_inline__));
// __NR__ fstatfs = 138 

inline int fstatfs(fd_t fd, statfs_p buf)
  __attribute__((__always_inline__));
// __NR__ sysfs = 139 

inline int sysfs(int option, uint64_t arg1, uint64_t arg2)
  __attribute__((__always_inline__));
// __NR__ getpriority = 140 

inline int getpriority(int which, int who)
  __attribute__((__always_inline__));
// __NR__ setpriority = 141 

inline int setpriority(int which, int who, int niceval)
  __attribute__((__always_inline__));
// __NR__ sched_setparam = 142 

inline int sys_sched_setparam(pid_t pid, const void * param)
  __attribute__((__always_inline__));
// __NR__ sched_getparam = 143 

inline int sched_getparam(pid_t pid, sched_param_p param)
  __attribute__((__always_inline__));
// __NR__ sched_setscheduler = 144 

inline int sys_sched_setscheduler(pid_t pid, int policy, sched_param_p param)
  __attribute__((__always_inline__));
// __NR__ sched_getscheduler = 145 

inline int sched_getscheduler(pid_t pid)
  __attribute__((__always_inline__));
// __NR__ sched_get_priority_max = 146 

inline int sched_get_priority_max(int policy)
  __attribute__((__always_inline__));
// __NR__ sched_get_priority_min = 147 

inline int sched_get_priority_min(int policy)
  __attribute__((__always_inline__));
// __NR__ sched_rr_get_interval = 148 

inline int sched_rr_get_interval(pid_t pid, timespec_p interval)
  __attribute__((__always_inline__));
// __NR__ mlock = 149 

inline int mlock(void_p start, size_t len)
  __attribute__((__always_inline__));
// __NR__ munlock = 150 

inline int munlock(void_p start, size_t len)
  __attribute__((__always_inline__));
// __NR__ mlockall = 151 

inline int mlockall(int flags)
  __attribute__((__always_inline__));
// __NR__ munlockall = 152 

inline int munlockall()
  __attribute__((__always_inline__));
// __NR__ vhangup = 153 

inline int vhangup()
  __attribute__((__always_inline__));
// __NR__ modify_ldt = 154 

inline int modify_ldt(int func, void_p ptr, uint64_t bytecount)
  __attribute__((__always_inline__));
// __NR__ pivot_root = 155 

inline int pivot_root(istr_t new_root, istr_t put_old)
  __attribute__((__always_inline__));
// __NR__ _sysctl = 156 

inline int _sysctl(sysctl_args_p args)
  __attribute__((__always_inline__));
// __NR__ prctl = 157 

inline int prctl(int option, uint64_t arg2, uint64_t arg3, uint64_t arg4, uint64_t arg5)
  __attribute__((__always_inline__));
// __NR__ arch_prctl = 158 

inline int arch_prctl(task_struct_p task, int code, uint64_t addr)
  __attribute__((__always_inline__));
// __NR__ adjtimex = 159 

inline int adjtimex(timex_p txc_p)
  __attribute__((__always_inline__));
// __NR__ setrlimit = 160 

inline int setrlimit(unsigned resource, rlimit_p rlim)
  __attribute__((__always_inline__));
// __NR__ chroot = 161 

inline int chroot(istr_t filename)
  __attribute__((__always_inline__));
// __NR__ sync = 162 

inline int sync()
  __attribute__((__always_inline__));
// __NR__ acct = 163 

inline int acct(istr_t name)
  __attribute__((__always_inline__));
// __NR__ settimeofday = 164 

inline int settimeofday(timeval_p tv, timezone_p tz)
  __attribute__((__always_inline__));
// __NR__ mount = 165 

inline int mount(ostr_t dev_name, ostr_t dir_name, ostr_t type, uint64_t flags, void_p data)
  __attribute__((__always_inline__));
// __NR__ umount2 = 166 

inline int umount2(istr_t target, int flags)
  __attribute__((__always_inline__));
// __NR__ swapon = 167 

inline int swapon(istr_t specialfile, int swap_flags)
  __attribute__((__always_inline__));
// __NR__ swapoff = 168 

inline int swapoff(istr_t specialfile)
  __attribute__((__always_inline__));
// __NR__ reboot = 169 

inline int reboot(int magic1, int magic2, unsigned cmd, void_p arg)
  __attribute__((__always_inline__));
// __NR__ sethostname = 170 

inline int sethostname(ostr_t name, int len)
  __attribute__((__always_inline__));
// __NR__ setdomainname = 171 

inline int setdomainname(ostr_t name, int len)
  __attribute__((__always_inline__));
// __NR__ iopl = 172 

inline int iopl(unsigned level, pt_regs_p regs)
  __attribute__((__always_inline__));
// __NR__ ioperm = 173 

inline int ioperm(uint64_t from, uint64_t num, int turn_on)
  __attribute__((__always_inline__));
// __NR__ init_module = 175 

inline int init_module(void_p umod, uint64_t len, istr_t uargs)
  __attribute__((__always_inline__));
// __NR__ delete_module = 176 

inline int delete_module(istr_t name_user, unsigned flags)
  __attribute__((__always_inline__));
// __NR__ quotactl = 179 

inline int quotactl(unsigned cmd, istr_t special, qid_t id, void_p addr)
  __attribute__((__always_inline__));
// __NR__ gettid = 186 

inline int gettid()
  __attribute__((__always_inline__));
// __NR__ readahead = 187 

inline int readahead(fd_t fd, off_t offset, size_t count)
  __attribute__((__always_inline__));
// __NR__ setxattr = 188 

inline int setxattr(istr_t pathname, istr_t name, const void_p value, size_t size, int flags)
  __attribute__((__always_inline__));
// __NR__ lsetxattr = 189 

inline int lsetxattr(istr_t pathname, istr_t name, const void_p value, size_t size, int flags)
  __attribute__((__always_inline__));
// __NR__ fsetxattr = 190 

inline int fsetxattr(fd_t fd, istr_t name, const void_p value, size_t size, int flags)
  __attribute__((__always_inline__));
// __NR__ getxattr = 191 

inline int getxattr(istr_t pathname, istr_t name, void_p value, size_t size)
  __attribute__((__always_inline__));
// __NR__ lgetxattr = 192 

inline int lgetxattr(istr_t pathname, istr_t name, void_p value, size_t size)
  __attribute__((__always_inline__));
// __NR__ fgetxattr = 193 

inline int fgetxattr(fd_t fd, istr_t name, void_p value, size_t size)
  __attribute__((__always_inline__));
// __NR__ listxattr = 194 

inline int listxattr(istr_t pathname, ostr_t list, size_t size)
  __attribute__((__always_inline__));
// __NR__ llistxattr = 195 

inline int llistxattr(istr_t pathname, ostr_t list, size_t size)
  __attribute__((__always_inline__));
// __NR__ flistxattr = 196 

inline int flistxattr(fd_t fd, ostr_t list, size_t size)
  __attribute__((__always_inline__));
// __NR__ removexattr = 197 

inline int removexattr(istr_t pathname, istr_t name)
  __attribute__((__always_inline__));
// __NR__ lremovexattr = 198 

inline int lremovexattr(istr_t pathname, istr_t name)
  __attribute__((__always_inline__));
// __NR__ fremovexattr = 199 

inline int fremovexattr(fd_t fd, istr_t name)
  __attribute__((__always_inline__));
// __NR__ tkill = 200 

inline int tkill(pid_t pid, int sig)
  __attribute__((__always_inline__));
// __NR__ time = 201 

inline time_t time(time_p tloc)
  __attribute__((__always_inline__));
// __NR__ futex = 202 

inline int futex(uint32_p uaddr, int op, uint32_t val, timespec_p utime, uint32_p uaddr2, uint32_t val3)
  __attribute__((__always_inline__));
// __NR__ sched_setaffinity = 203 

inline int sys_sched_setaffinity(pid_t pid, size_t len, const void * user_mask_ptr)
  __attribute__((__always_inline__));
// __NR__ sched_getaffinity = 204 

inline int sys_sched_getaffinity(pid_t pid, unsigned len, uint64_p user_mask_ptr)
  __attribute__((__always_inline__));
// __NR__ io_setup = 206 

inline int io_setup(unsigned nr_events, aio_context_p ctxp)
  __attribute__((__always_inline__));
// __NR__ io_destroy = 207 

inline int io_destroy(aio_context_t ctx)
  __attribute__((__always_inline__));
// __NR__ io_getevents = 208 

inline int io_getevents(aio_context_t ctx_id, long min_nr, long nr, io_event_p events)
  __attribute__((__always_inline__));
// __NR__ io_submit = 209 

inline int io_submit(aio_context_t ctx_id, long nr, iocb_p iocbpp)
  __attribute__((__always_inline__));
// __NR__ io_cancel = 210 

inline int io_cancel(aio_context_t ctx_id, iocb_p iocb, io_event_p result)
  __attribute__((__always_inline__));
// __NR__ lookup_dcookie = 212 

inline int lookup_dcookie(uint64_t cookie64, long buf, long len)
  __attribute__((__always_inline__));
// __NR__ epoll_create = 213 

inline int epoll_create(int size)
  __attribute__((__always_inline__));
// __NR__ remap_file_pages = 216 

inline int remap_file_pages(uint64_t start, uint64_t size, uint64_t prot, uint64_t pgoff, uint64_t flags)
  __attribute__((__always_inline__));
// __NR__ getdents64 = 217 

inline int getdents64(fd_t fd, linux_dirent64_p dirent, unsigned count)
  __attribute__((__always_inline__));
// __NR__ set_tid_address = 218 

inline int set_tid_address(int32_p tidptr)
  __attribute__((__always_inline__));
// __NR__ restart_syscall = 219 

inline int restart_syscall()
  __attribute__((__always_inline__));
// __NR__ semtimedop = 220 

inline int semtimedop(int semid, sembuf_p tsops, unsigned nsops, timespec_p timeout)
  __attribute__((__always_inline__));
// __NR__ fadvise64 = 221 

inline int fadvise64(fd_t fd, off_t offset, size_t len, int advice)
  __attribute__((__always_inline__));
// __NR__ timer_create = 222 

inline int timer_create(const clockid_t which_clock, sigevent_p timer_event_spec, timer_p created_timer_id)
  __attribute__((__always_inline__));
// __NR__ timer_settime = 223 

inline int timer_settime(timer_t timer_id, int flags, itimerspec_p new_setting, itimerspec_p old_setting)
  __attribute__((__always_inline__));
// __NR__ timer_gettime = 224 

inline int timer_gettime(timer_t timer_id, itimerspec_p setting)
  __attribute__((__always_inline__));
// __NR__ timer_getoverrun = 225 

inline int timer_getoverrun(timer_t timer_id)
  __attribute__((__always_inline__));
// __NR__ timer_delete = 226 

inline int timer_delete(timer_t timer_id)
  __attribute__((__always_inline__));
// __NR__ clock_settime = 227 

inline int clock_settime(const clockid_t which_clock, timespec_p tp)
  __attribute__((__always_inline__));
// __NR__ clock_gettime = 228 

inline int clock_gettime(const clockid_t which_clock, timespec_p tp)
  __attribute__((__always_inline__));
// __NR__ clock_getres = 229 

inline int clock_getres(const clockid_t which_clock, timespec_p tp)
  __attribute__((__always_inline__));
// __NR__ clock_nanosleep = 230 

inline int clock_nanosleep(const clockid_t which_clock, int flags, timespec_p rqtp, timespec_p rmtp)
  __attribute__((__always_inline__));
// __NR__ exit_group = 231 

inline int exit_group(int error_code)
  __attribute__((__always_inline__));
// __NR__ epoll_wait = 232 

inline int epoll_wait(int epfd, epoll_event_p events, int maxevents, int timeout)
  __attribute__((__always_inline__));
// __NR__ epoll_ctl = 233 

inline int epoll_ctl(int epfd, int op, fd_t fd, epoll_event_p event)
  __attribute__((__always_inline__));
// __NR__ tgkill = 234 

inline int tgkill(pid_t tgid, pid_t pid, int sig)
  __attribute__((__always_inline__));
// __NR__ utimes = 235 

inline int utimes(ostr_t filename, timeval_p utimes)
  __attribute__((__always_inline__));
// __NR__ mbind = 237 

inline int mbind(uint64_t start, uint64_t len, uint64_t mode, uint64_p nmask, uint64_t maxnode, unsigned flags)
  __attribute__((__always_inline__));
// __NR__ set_mempolicy = 238 

inline int set_mempolicy(int mode, uint64_p nmask, uint64_t maxnode)
  __attribute__((__always_inline__));
// __NR__ get_mempolicy = 239 

inline int get_mempolicy(int32_p policy, uint64_p nmask, uint64_t maxnode, uint64_t addr, uint64_t flags)
  __attribute__((__always_inline__));
// __NR__ mq_open = 240 

inline int mq_open(istr_t u_name, int oflag, mode_t mode, mq_attr_p u_attr)
  __attribute__((__always_inline__));
// __NR__ mq_unlink = 241 

inline int mq_unlink(istr_t u_name)
  __attribute__((__always_inline__));
// __NR__ mq_timedsend = 242 

inline int mq_timedsend(mqd_t mqdes, istr_t u_msg_ptr, size_t msg_len, unsigned msg_prio, timespec_p u_abs_timeout)
  __attribute__((__always_inline__));
// __NR__ mq_timedreceive = 243 

inline int mq_timedreceive(mqd_t mqdes, ostr_t u_msg_ptr, size_t msg_len, uint32_p u_msg_prio, timespec_p u_abs_timeout)
  __attribute__((__always_inline__));
// __NR__ mq_notify = 244 

inline int mq_notify(mqd_t mqdes, sigevent_p u_notification)
  __attribute__((__always_inline__));
// __NR__ mq_getsetattr = 245 

inline int mq_getsetattr(mqd_t mqdes, mq_attr_p u_mqstat, mq_attr_p u_omqstat)
  __attribute__((__always_inline__));
// __NR__ kexec_load = 246 

inline int kexec_load(uint64_t entry, uint64_t nr_segments, kexec_segment_p segments, uint64_t flags)
  __attribute__((__always_inline__));
// __NR__ waitid = 247 

inline int waitid(int which, pid_t upid, siginfo_p infop, int options, rusage_p ru)
  __attribute__((__always_inline__));
// __NR__ add_key = 248 

inline int add_key(istr_t _type, istr_t _description, const void_p _payload, size_t plen)
  __attribute__((__always_inline__));
// __NR__ request_key = 249 

inline int request_key(istr_t _type, istr_t _description, istr_t _callout_info, uint64_t destringid)
  __attribute__((__always_inline__));
// __NR__ keyctl = 250 

inline int keyctl(int option, uint64_t arg2, uint64_t arg3, uint64_t arg4, uint64_t arg5)
  __attribute__((__always_inline__));
// __NR__ ioprio_set = 251 

inline int ioprio_set(int which, int who, int ioprio)
  __attribute__((__always_inline__));
// __NR__ ioprio_get = 252 

inline int ioprio_get(int which, int who)
  __attribute__((__always_inline__));
// __NR__ inotify_init = 253 

inline int inotify_init()
  __attribute__((__always_inline__));
// __NR__ inotify_add_watch = 254 

inline int inotify_add_watch(fd_t fd, istr_t pathname, uint32_t mask)
  __attribute__((__always_inline__));
// __NR__ inotify_rm_watch = 255 

inline int inotify_rm_watch(fd_t fd, int32_t wd)
  __attribute__((__always_inline__));
// __NR__ migrate_pages = 256 

inline int migrate_pages(pid_t pid, uint64_t maxnode, uint64_p old_nodes, uint64_p new_nodes)
  __attribute__((__always_inline__));
// __NR__ openat = 257 

inline int openat(fd_t dfd, istr_t filename, int flags, int mode)
  __attribute__((__always_inline__));
// __NR__ mkdirat = 258 

inline int mkdirat(fd_t dfd, istr_t pathname, int mode)
  __attribute__((__always_inline__));
// __NR__ mknodat = 259 

inline int mknodat(fd_t dfd, istr_t filename, int mode, unsigned dev)
  __attribute__((__always_inline__));
// __NR__ fchownat = 260 

inline int fchownat(fd_t dfd, istr_t filename, uid_t user, gid_t group, int flag)
  __attribute__((__always_inline__));
// __NR__ futimesat = 261 

inline int futimesat(fd_t dfd, istr_t filename, timeval_p utimes)
  __attribute__((__always_inline__));
// __NR__ newfstatat = 262 

inline int newfstatat(fd_t dfd, istr_t filename, stat_p statbuf, int flag)
  __attribute__((__always_inline__));
// __NR__ unlinkat = 263 

inline int unlinkat(fd_t dfd, istr_t pathname, int flag)
  __attribute__((__always_inline__));
// __NR__ renameat = 264 

inline int renameat(fd_t oldfd, istr_t oldname, fd_t newfd, istr_t newname)
  __attribute__((__always_inline__));
// __NR__ linkat = 265 

inline int linkat(fd_t oldfd, istr_t oldname, fd_t newfd, istr_t newname, int flags)
  __attribute__((__always_inline__));
// __NR__ symlinkat = 266 

inline int symlinkat(istr_t oldname, fd_t newfd, istr_t newname)
  __attribute__((__always_inline__));
// __NR__ readlinkat = 267 

inline int readlinkat(fd_t dfd, istr_t pathname, ostr_t buf, int bufsiz)
  __attribute__((__always_inline__));
// __NR__ fchmodat = 268 

inline int fchmodat(fd_t dfd, istr_t filename, mode_t mode)
  __attribute__((__always_inline__));
// __NR__ faccessat = 269 

inline int faccessat(fd_t dfd, istr_t filename, int mode)
  __attribute__((__always_inline__));
// __NR__ pselect6 = 270 

inline int pselect6(int n, fd_set_p inp, fd_set_p outp, fd_set_p exp, timespec_p tsp, void_p sig)
  __attribute__((__always_inline__));
// __NR__ ppoll = 271 

inline int ppoll(pollfd_p ufds, unsigned nfds, timespec_p tsp, const sigset_p sigmask, size_t sigsetsize)
  __attribute__((__always_inline__));
// __NR__ unshare = 272 

inline int unshare(int unshare_flags)
  __attribute__((__always_inline__));
// __NR__ set_robust_list = 273 

inline int set_robust_list(robust_list_head_p head, size_t len)
  __attribute__((__always_inline__));
// __NR__ get_robust_list = 274 

inline int get_robust_list(int pid, robust_list_head_p head_ptr, size_p len_ptr)
  __attribute__((__always_inline__));
// __NR__ splice = 275 

inline int splice(int fd_in, off_p off_in, int fd_out, off_p off_out, size_t len, unsigned flags)
  __attribute__((__always_inline__));
// __NR__ tee = 276 

inline int tee(int fdin, int fdout, size_t len, unsigned flags)
  __attribute__((__always_inline__));
// __NR__ sync_file_range = 277 

inline int sync_file_range(fd_t fd, off_t offset, off_t bytes, long flags)
  __attribute__((__always_inline__));
// __NR__ vmsplice = 278 

inline int vmsplice(fd_t fd, iovec_p iov, uint64_t nr_segs, unsigned flags)
  __attribute__((__always_inline__));
// __NR__ move_pages = 279 

inline int move_pages(pid_t pid, uint64_t nr_pages, void_p pages, int32_p nodes, int32_p status, int flags)
  __attribute__((__always_inline__));
// __NR__ utimensat = 280 

inline int utimensat(fd_t dfd, istr_t filename, timespec_p utimes, int flags)
  __attribute__((__always_inline__));
// __NR__ epoll_pwait = 281 

inline int epoll_pwait(int epfd, epoll_event_p events, int maxevents, int timeout, const sigset_p sigmask, size_t sigsetsize)
  __attribute__((__always_inline__));
// __NR__ signalfd = 282 

inline int signalfd(int ufd, sigset_p user_mask, size_t sizemask)
  __attribute__((__always_inline__));
// __NR__ timerfd_create = 283 

inline int timerfd_create(int clockid, int flags)
  __attribute__((__always_inline__));
// __NR__ eventfd = 284 

inline int eventfd(unsigned count)
  __attribute__((__always_inline__));
// __NR__ fallocate = 285 

inline int fallocate(fd_t fd, long mode, off_t offset, off_t len)
  __attribute__((__always_inline__));
// __NR__ timerfd_settime = 286 

inline int timerfd_settime(int ufd, int flags, itimerspec_p utmr, itimerspec_p otmr)
  __attribute__((__always_inline__));
// __NR__ timerfd_gettime = 287 

inline int timerfd_gettime(int ufd, itimerspec_p otmr)
  __attribute__((__always_inline__));
// __NR__ accept4 = 288 

inline int accept4(fd_t fd, sockaddr_p upeer_sockaddr, int32_p upeer_addrlen, int flags)
  __attribute__((__always_inline__));
// __NR__ signalfd4 = 289 

inline int signalfd4(int ufd, sigset_p user_mask, size_t sizemask, int flags)
  __attribute__((__always_inline__));
// __NR__ eventfd2 = 290 

inline int eventfd2(unsigned count, int flags)
  __attribute__((__always_inline__));
// __NR__ epoll_create1 = 291 

inline int epoll_create1(int flags)
  __attribute__((__always_inline__));
// __NR__ dup3 = 292 

inline int dup3(fd_t oldfd, fd_t newfd, int flags)
  __attribute__((__always_inline__));
// __NR__ pipe2 = 293 

inline int pipe2(fd_p filedes, int flags)
  __attribute__((__always_inline__));
// __NR__ inotify_init1 = 294 

inline int inotify_init1(int flags)
  __attribute__((__always_inline__));
// __NR__ preadv = 295 

inline int preadv(fd_t fd, iovec_p vec, uint64_t vlen, uint64_t pos_l, uint64_t pos_h)
  __attribute__((__always_inline__));
// __NR__ pwritev = 296 

inline int pwritev(fd_t fd, iovec_p vec, uint64_t vlen, uint64_t pos_l, uint64_t pos_h)
  __attribute__((__always_inline__));
// __NR__ rt_tgsigqueueinfo = 297 

inline int rt_tgsigqueueinfo(pid_t tgid, pid_t pid, int sig, siginfo_p uinfo)
  __attribute__((__always_inline__));
// __NR__ perf_event_open = 298 

inline int perf_event_open(perf_event_attr_p attr_uptr, pid_t pid, int cpu, int group_fd, uint64_t flags)
  __attribute__((__always_inline__));
// __NR__ recvmmsg = 299 

inline int recvmmsg(fd_t fd, msghdr_p mmsg, unsigned vlen, unsigned flags, timespec_p timeout)
  __attribute__((__always_inline__));
// __NR__ fanotify_init = 300 

inline int fanotify_init(unsigned flags, unsigned event_f_flags)
  __attribute__((__always_inline__));
// __NR__ fanotify_mark = 301 

inline int fanotify_mark(long fanotify_fd, long flags, uint64_t mask, fd_t dfd, long pathname)
  __attribute__((__always_inline__));
// __NR__ prlimit64 = 302 

inline int prlimit64(pid_t pid, unsigned resource, rlimit64_p new_rlim, rlimit64_p old_rlim)
  __attribute__((__always_inline__));
// __NR__ name_to_handle_at = 303 

inline int name_to_handle_at(fd_t dfd, istr_t name, file_handle_p handle, int32_p mnt_id, int flag)
  __attribute__((__always_inline__));
// __NR__ open_by_handle_at = 304 

inline int open_by_handle_at(fd_t dfd, istr_t name, file_handle_p handle, int32_p mnt_id, int flags)
  __attribute__((__always_inline__));
// __NR__ clock_adjtime = 305 

inline int clock_adjtime(clockid_t which_clock, timex_p tx)
  __attribute__((__always_inline__));
// __NR__ syncfs = 306 

inline int syncfs(fd_t fd)
  __attribute__((__always_inline__));
// __NR__ sendmmsg = 307 

inline int sendmmsg(fd_t fd, msghdr_p mmsg, unsigned vlen, unsigned flags)
  __attribute__((__always_inline__));
// __NR__ setns = 308 

inline int setns(fd_t fd, int nstype)
  __attribute__((__always_inline__));
// __NR__ getcpu = 309 

inline int getcpu(uint32_p cpup, uint32_p nodep)
  __attribute__((__always_inline__));
// __NR__ process_vm_readv = 310 

inline int process_vm_readv(pid_t pid, iovec_p lvec, uint64_t liovcnt, iovec_p rvec, uint64_t riovcnt, uint64_t flags)
  __attribute__((__always_inline__));
// __NR__ process_vm_writev = 311 

inline int process_vm_writev(pid_t pid, iovec_p lvec, uint64_t liovcnt, iovec_p rvec, uint64_t riovcnt, uint64_t flags)
  __attribute__((__always_inline__));
// __NR__ kcmp = 312 

inline int kcmp(pid_t pid1, pid_t pid2, int type, uint64_t idx1, uint64_t idx2)
  __attribute__((__always_inline__));
// __NR__ finit_module = 313 

inline int finit_module(fd_t fd, istr_t uargs, int flags)
  __attribute__((__always_inline__));
// __NR__ sched_setattr = 314 

inline int sched_setattr(pid_t pid, sched_attr_p attr, unsigned flags)
  __attribute__((__always_inline__));
// __NR__ sched_getattr = 315 

inline int sched_getattr(pid_t pid, sched_attr_p attr, unsigned size, unsigned flags)
  __attribute__((__always_inline__));
// __NR__ renameat2 = 316 

inline int renameat2(int olddfd, istr_t oldname, int newdfd, istr_t newname, unsigned flags)
  __attribute__((__always_inline__));
// __NR__ seccomp = 317 

inline int seccomp(unsigned op, unsigned flags, istr_t uargs)
  __attribute__((__always_inline__));
// __NR__ getrandom = 318 

inline int getrandom(ostr_t buf, size_t count, unsigned flags)
  __attribute__((__always_inline__));
// __NR__ memfd_create = 319 

inline int memfd_create(istr_t uname_ptr, unsigned flags)
  __attribute__((__always_inline__));
// __NR__ kexec_file_load = 320 

inline int kexec_file_load(int kernel_fd, int initrd_fd, size_t cmdline_len, istr_t cmdline_ptr, uint64_t flags)
  __attribute__((__always_inline__));
// __NR__ bpf = 321 

inline int bpf(int cmd, bpf_attr_p attr, unsigned size)
  __attribute__((__always_inline__));
// __NR__ stub_execveat = 322 

inline int stub_execveat(fd_t dfd, istr_t filename, istr_v argv, istr_v envp, int flags)
  __attribute__((__always_inline__));
// __NR__ userfaultfd = 323 

inline int userfaultfd(int flags)
  __attribute__((__always_inline__));
// __NR__ membarrier = 324 

inline int membarrier(int cmd, int flags)
  __attribute__((__always_inline__));
// __NR__ mlock2 = 325 

inline int mlock2(uint64_t start, size_t len, int flags)
  __attribute__((__always_inline__));
// __NR__ copy_file_range = 326 

inline int copy_file_range(fd_t fd_in, off_p off_in, fd_t fd_out, off_p off_out, size_t len, unsigned flags)
  __attribute__((__always_inline__));
// __NR__ preadv2 = 327 

inline int preadv2(fd_t fd, iovec_p vec, uint64_t vlen, uint64_t pos_l, uint64_t pos_h, int flags)
  __attribute__((__always_inline__));
// __NR__ pwritev2 = 328 

inline int pwritev2(fd_t fd, iovec_p vec, uint64_t vlen, uint64_t pos_l, uint64_t pos_h, int flags)
  __attribute__((__always_inline__));
}

extern "C" {
inline ssize_t read(fd_t fd, ostr_t buf, size_t count)
  __attribute__((__always_inline__));
inline ssize_t sys_write(fd_t fd, istr_t buf, size_t count)
  __attribute__((__always_inline__));
inline fd_t open(istr_t filename, int flags, int mode)
  __attribute__((__always_inline__));
inline int close(fd_t fd)
  __attribute__((__always_inline__));
inline int stat(istr_t filename, stat_p statbuf)
  __attribute__((__always_inline__));
inline int fstat(fd_t fd, stat_p statbuf)
  __attribute__((__always_inline__));
inline int lstat(istr_t filename, stat_p statbuf)
  __attribute__((__always_inline__));
inline int poll(pollfd_p ufds, unsigned nfds, long timeout_msecs)
  __attribute__((__always_inline__));
inline int lseek(fd_t fd, off_t offset, unsigned origin)
  __attribute__((__always_inline__));
inline char* mmap(void* addr, size_t len, int prot, int flags, fd_t fd, off_t off)
  __attribute__((__always_inline__));
inline int mprotect(uint64_t start, size_t len, uint64_t prot)
  __attribute__((__always_inline__));
inline int munmap(uint64_t addr, size_t len)
  __attribute__((__always_inline__));
inline int brk(void_p brk)
  __attribute__((__always_inline__));
inline int rt_sigaction(int sig, sigaction_p act, sigaction_p oact, size_t sigsetsize)
  __attribute__((__always_inline__));
inline int rt_sigprocmask(int how, sigset_p nset, sigset_p oset, size_t sigsetsize)
  __attribute__((__always_inline__));
inline int rt_sigreturn(uint64_t __unused)
  __attribute__((__always_inline__));
inline int ioctl(fd_t fd, unsigned cmd, uint64_t arg)
  __attribute__((__always_inline__));
inline int pread64(fd_t fd, ostr_t buf, size_t count, off_t pos)
  __attribute__((__always_inline__));
inline int pwrite64(fd_t fd, istr_t buf, size_t count, off_t pos)
  __attribute__((__always_inline__));
inline int readv(fd_t fd, iovec_p vec, uint64_t vlen)
  __attribute__((__always_inline__));
inline int writev(fd_t fd, iovec_p vec, uint64_t vlen)
  __attribute__((__always_inline__));
inline int access(istr_t filename, int mode)
  __attribute__((__always_inline__));
inline int pipe(fd_p filedes)
  __attribute__((__always_inline__));
inline int select(int n, fd_set_p inp, fd_set_p outp, fd_set_p exp, timeval_p tvp)
  __attribute__((__always_inline__));
inline int sched_yield()
  __attribute__((__always_inline__));
inline int mremap(uint64_t addr, uint64_t old_len, uint64_t new_len, uint64_t flags, uint64_t new_addr)
  __attribute__((__always_inline__));
inline int msync(uint64_t start, size_t len, int flags)
  __attribute__((__always_inline__));
inline int mincore(uint64_t start, size_t len, ostr_t vec)
  __attribute__((__always_inline__));
inline int madvise(uint64_t start, size_t len_in, int behavior)
  __attribute__((__always_inline__));
inline int shmget(key_t key, size_t size, int shmflg)
  __attribute__((__always_inline__));
inline int shmat(int shmid, ostr_t shmaddr, int shmflg)
  __attribute__((__always_inline__));
inline int shmctl(int shmid, int cmd, shmid_ds_p buf)
  __attribute__((__always_inline__));
inline int dup(unsigned fildes)
  __attribute__((__always_inline__));
inline int dup2(fd_t oldfd, fd_t newfd)
  __attribute__((__always_inline__));
inline int pause()
  __attribute__((__always_inline__));
inline int nanosleep(timespec_p rqtp, timespec_p rmtp)
  __attribute__((__always_inline__));
inline int getitimer(int which, itimerval_p value)
  __attribute__((__always_inline__));
inline int alarm(unsigned seconds)
  __attribute__((__always_inline__));
inline int setitimer(int which, itimerval_p value, itimerval_p ovalue)
  __attribute__((__always_inline__));
inline int getpid()
  __attribute__((__always_inline__));
inline int sendfile(int out_fd, int in_fd, off_p offset, size_t count)
  __attribute__((__always_inline__));
inline int socket(int family, int type, int protocol)
  __attribute__((__always_inline__));
inline int connect(fd_t fd, sockaddr_p uservaddr, int addrlen)
  __attribute__((__always_inline__));
inline int accept(fd_t fd, sockaddr_p upeer_sockaddr, int32_p upeer_addrlen)
  __attribute__((__always_inline__));
inline int sendto(fd_t fd, void_p buff, size_t len, unsigned flags, sockaddr_p addr, int addr_len)
  __attribute__((__always_inline__));
inline int recvfrom(fd_t fd, void_p ubuf, size_t size, unsigned flags, sockaddr_p addr, int32_p addr_len)
  __attribute__((__always_inline__));
inline int sendmsg(fd_t fd, msghdr_p msg, unsigned flags)
  __attribute__((__always_inline__));
inline int recvmsg(fd_t fd, msghdr_p msg, unsigned flags)
  __attribute__((__always_inline__));
inline int shutdown(fd_t fd, int how)
  __attribute__((__always_inline__));
inline int bind(fd_t fd, sockaddr_p umyaddr, int addrlen)
  __attribute__((__always_inline__));
inline int listen(fd_t fd, int backlog)
  __attribute__((__always_inline__));
inline int getsockname(fd_t fd, sockaddr_p usockaddr, int32_p usockaddr_len)
  __attribute__((__always_inline__));
inline int getpeername(fd_t fd, sockaddr_p usockaddr, int32_p usockaddr_len)
  __attribute__((__always_inline__));
inline int socketpair(int family, int type, int protocol, int32_p usockvec)
  __attribute__((__always_inline__));
inline int setsockopt(fd_t fd, int level, int optname, ostr_t optval, int optlen)
  __attribute__((__always_inline__));
inline int getsockopt(fd_t fd, int level, int optname, ostr_t optval, int32_p optlen)
  __attribute__((__always_inline__));
inline int clone(uint64_t clone_flags, uint64_t newsp, void_p parent_tid, void_p child_tid)
  __attribute__((__always_inline__));
inline int fork()
  __attribute__((__always_inline__));
inline int vfork()
  __attribute__((__always_inline__));
inline int execve(const char * filename, char *const * argv, char *const * envp)
  __attribute__((__always_inline__));
inline void _exit(int error_code)
  __attribute__((__always_inline__));
inline int wait4(pid_t upid, int32_p stat_addr, int options, rusage_p ru)
  __attribute__((__always_inline__));
inline int kill(pid_t pid, int sig)
  __attribute__((__always_inline__));
inline int uname(utsname_p name)
  __attribute__((__always_inline__));
inline int semget(key_t key, int nsems, int semflg)
  __attribute__((__always_inline__));
inline int semop(int semid, sembuf_p tsops, unsigned nsops)
  __attribute__((__always_inline__));
inline int semctl(int semid, int semnum, int cmd, union semun arg)
  __attribute__((__always_inline__));
inline int shmdt(ostr_t shmaddr)
  __attribute__((__always_inline__));
inline int msgget(key_t key, int msgflg)
  __attribute__((__always_inline__));
inline int msgsnd(int msqid, msgbuf_p msgp, size_t msgsz, int msgflg)
  __attribute__((__always_inline__));
inline int msgrcv(int msqid, msgbuf_p msgp, size_t msgsz, long msgtyp, int msgflg)
  __attribute__((__always_inline__));
inline int msgctl(int msqid, int cmd, msqid_ds_p buf)
  __attribute__((__always_inline__));
inline int fcntl(fd_t fd, unsigned cmd, uint64_t arg)
  __attribute__((__always_inline__));
inline int flock(fd_t fd, unsigned cmd)
  __attribute__((__always_inline__));
inline int fsync(fd_t fd)
  __attribute__((__always_inline__));
inline int fdatasync(fd_t fd)
  __attribute__((__always_inline__));
inline int truncate(istr_t path, long length)
  __attribute__((__always_inline__));
inline int ftruncate(fd_t fd, uint64_t length)
  __attribute__((__always_inline__));
inline ssize_t getdents(fd_t fd, linux_dirent_p dirent, size_t count)
  __attribute__((__always_inline__));
inline int getcwd(ostr_t buf, uint64_t size)
  __attribute__((__always_inline__));
inline int chdir(istr_t filename)
  __attribute__((__always_inline__));
inline int fchdir(fd_t fd)
  __attribute__((__always_inline__));
inline int rename(istr_t oldname, istr_t newname)
  __attribute__((__always_inline__));
inline int mkdir(istr_t pathname, int mode)
  __attribute__((__always_inline__));
inline int rmdir(istr_t pathname)
  __attribute__((__always_inline__));
inline int creat(istr_t pathname, int mode)
  __attribute__((__always_inline__));
inline int link(istr_t oldname, istr_t newname)
  __attribute__((__always_inline__));
inline int unlink(istr_t pathname)
  __attribute__((__always_inline__));
inline int symlink(istr_t oldname, istr_t newname)
  __attribute__((__always_inline__));
inline int readlink(istr_t path, ostr_t buf, int bufsiz)
  __attribute__((__always_inline__));
inline int chmod(istr_t filename, mode_t mode)
  __attribute__((__always_inline__));
inline int fchmod(fd_t fd, mode_t mode)
  __attribute__((__always_inline__));
inline int chown(istr_t filename, uid_t user, gid_t group)
  __attribute__((__always_inline__));
inline int fchown(fd_t fd, uid_t user, gid_t group)
  __attribute__((__always_inline__));
inline int lchown(istr_t filename, uid_t user, gid_t group)
  __attribute__((__always_inline__));
inline int umask(int mask)
  __attribute__((__always_inline__));
inline int gettimeofday(timeval_p tv, timezone_p tz)
  __attribute__((__always_inline__));
inline int getrlimit(unsigned resource, rlimit_p rlim)
  __attribute__((__always_inline__));
inline int getrusage(int who, rusage_p ru)
  __attribute__((__always_inline__));
inline int sysinfo(sysinfo_p info)
  __attribute__((__always_inline__));
inline int times(sysinfo_p info)
  __attribute__((__always_inline__));
inline int ptrace(long request, long pid, uint64_t addr, uint64_t data)
  __attribute__((__always_inline__));
inline int getuid()
  __attribute__((__always_inline__));
inline int syslog(int type, ostr_t buf, int len)
  __attribute__((__always_inline__));
inline int getgid()
  __attribute__((__always_inline__));
inline int setuid(uid_t uid)
  __attribute__((__always_inline__));
inline int setgid(gid_t gid)
  __attribute__((__always_inline__));
inline int geteuid()
  __attribute__((__always_inline__));
inline int getegid()
  __attribute__((__always_inline__));
inline int setpgid(pid_t pid, pid_t pgid)
  __attribute__((__always_inline__));
inline int getppid()
  __attribute__((__always_inline__));
inline int getpgrp()
  __attribute__((__always_inline__));
inline int setsid()
  __attribute__((__always_inline__));
inline int setreuid(uid_t ruid, uid_t euid)
  __attribute__((__always_inline__));
inline int setregid(gid_t rgid, gid_t egid)
  __attribute__((__always_inline__));
inline int getgroups(int gidsetsize, gid_p grouplist)
  __attribute__((__always_inline__));
inline int setgroups(int gidsetsize, gid_p grouplist)
  __attribute__((__always_inline__));
inline int setresuid(uid_p ruid, uid_p euid, uid_p suid)
  __attribute__((__always_inline__));
inline int getresuid(uid_p ruid, uid_p euid, uid_p suid)
  __attribute__((__always_inline__));
inline int setresgid(gid_t rgid, gid_t egid, gid_t sgid)
  __attribute__((__always_inline__));
inline int getresgid(gid_p rgid, gid_p egid, gid_p sgid)
  __attribute__((__always_inline__));
inline int getpgid(pid_t pid)
  __attribute__((__always_inline__));
inline int setfsuid(uid_t uid)
  __attribute__((__always_inline__));
inline int setfsgid(gid_t gid)
  __attribute__((__always_inline__));
inline int getsid(pid_t pid)
  __attribute__((__always_inline__));
inline int capget(cap_user_header_t header, cap_user_data_t dataptr)
  __attribute__((__always_inline__));
inline int capset(cap_user_header_t header, const cap_user_data_t data)
  __attribute__((__always_inline__));
inline int rt_sigpending(sigset_p set, size_t sigsetsize)
  __attribute__((__always_inline__));
inline int rt_sigtimedwait(const sigset_p uthese, siginfo_p uinfo, timespec_p uts, size_t sigsetsize)
  __attribute__((__always_inline__));
inline int rt_sigqueueinfo(pid_t pid, int sig, siginfo_p uinfo)
  __attribute__((__always_inline__));
inline int rt_sigsuspend(sigset_p unewset, size_t sigsetsize)
  __attribute__((__always_inline__));
inline int sigaltstack(const stack_p uss, stack_p uoss)
  __attribute__((__always_inline__));
inline int utime(ostr_t filename, utimbuf_p times)
  __attribute__((__always_inline__));
inline int mknod(istr_t filename, umode_t mode, unsigned dev)
  __attribute__((__always_inline__));
inline int personality(unsigned personality)
  __attribute__((__always_inline__));
inline int ustat(unsigned dev, ustat_p ubuf)
  __attribute__((__always_inline__));
inline int statfs(istr_t pathname, statfs_p buf)
  __attribute__((__always_inline__));
inline int fstatfs(fd_t fd, statfs_p buf)
  __attribute__((__always_inline__));
inline int sysfs(int option, uint64_t arg1, uint64_t arg2)
  __attribute__((__always_inline__));
inline int getpriority(int which, int who)
  __attribute__((__always_inline__));
inline int setpriority(int which, int who, int niceval)
  __attribute__((__always_inline__));
inline int sched_setparam(pid_t pid, sched_param_p param)
  __attribute__((__always_inline__));
inline int sched_getparam(pid_t pid, sched_param_p param)
  __attribute__((__always_inline__));
inline int sched_setscheduler(pid_t pid, int policy, sched_param_p param)
  __attribute__((__always_inline__));
inline int sched_getscheduler(pid_t pid)
  __attribute__((__always_inline__));
inline int sched_get_priority_max(int policy)
  __attribute__((__always_inline__));
inline int sched_get_priority_min(int policy)
  __attribute__((__always_inline__));
inline int sched_rr_get_interval(pid_t pid, timespec_p interval)
  __attribute__((__always_inline__));
inline int mlock(void_p start, size_t len)
  __attribute__((__always_inline__));
inline int munlock(void_p start, size_t len)
  __attribute__((__always_inline__));
inline int mlockall(int flags)
  __attribute__((__always_inline__));
inline int munlockall()
  __attribute__((__always_inline__));
inline int vhangup()
  __attribute__((__always_inline__));
inline int modify_ldt(int func, void_p ptr, uint64_t bytecount)
  __attribute__((__always_inline__));
inline int pivot_root(istr_t new_root, istr_t put_old)
  __attribute__((__always_inline__));
inline int _sysctl(sysctl_args_p args)
  __attribute__((__always_inline__));
inline int prctl(int option, uint64_t arg2, uint64_t arg3, uint64_t arg4, uint64_t arg5)
  __attribute__((__always_inline__));
inline int arch_prctl(task_struct_p task, int code, uint64_t addr)
  __attribute__((__always_inline__));
inline int adjtimex(timex_p txc_p)
  __attribute__((__always_inline__));
inline int setrlimit(unsigned resource, rlimit_p rlim)
  __attribute__((__always_inline__));
inline int chroot(istr_t filename)
  __attribute__((__always_inline__));
inline int sync()
  __attribute__((__always_inline__));
inline int acct(istr_t name)
  __attribute__((__always_inline__));
inline int settimeofday(timeval_p tv, timezone_p tz)
  __attribute__((__always_inline__));
inline int mount(ostr_t dev_name, ostr_t dir_name, ostr_t type, uint64_t flags, void_p data)
  __attribute__((__always_inline__));
inline int umount2(istr_t target, int flags)
  __attribute__((__always_inline__));
inline int swapon(istr_t specialfile, int swap_flags)
  __attribute__((__always_inline__));
inline int swapoff(istr_t specialfile)
  __attribute__((__always_inline__));
inline int reboot(int magic1, int magic2, unsigned cmd, void_p arg)
  __attribute__((__always_inline__));
inline int sethostname(ostr_t name, int len)
  __attribute__((__always_inline__));
inline int setdomainname(ostr_t name, int len)
  __attribute__((__always_inline__));
inline int iopl(unsigned level, pt_regs_p regs)
  __attribute__((__always_inline__));
inline int ioperm(uint64_t from, uint64_t num, int turn_on)
  __attribute__((__always_inline__));
inline int init_module(void_p umod, uint64_t len, istr_t uargs)
  __attribute__((__always_inline__));
inline int delete_module(istr_t name_user, unsigned flags)
  __attribute__((__always_inline__));
inline int quotactl(unsigned cmd, istr_t special, qid_t id, void_p addr)
  __attribute__((__always_inline__));
inline int gettid()
  __attribute__((__always_inline__));
inline int readahead(fd_t fd, off_t offset, size_t count)
  __attribute__((__always_inline__));
inline int setxattr(istr_t pathname, istr_t name, const void_p value, size_t size, int flags)
  __attribute__((__always_inline__));
inline int lsetxattr(istr_t pathname, istr_t name, const void_p value, size_t size, int flags)
  __attribute__((__always_inline__));
inline int fsetxattr(fd_t fd, istr_t name, const void_p value, size_t size, int flags)
  __attribute__((__always_inline__));
inline int getxattr(istr_t pathname, istr_t name, void_p value, size_t size)
  __attribute__((__always_inline__));
inline int lgetxattr(istr_t pathname, istr_t name, void_p value, size_t size)
  __attribute__((__always_inline__));
inline int fgetxattr(fd_t fd, istr_t name, void_p value, size_t size)
  __attribute__((__always_inline__));
inline int listxattr(istr_t pathname, ostr_t list, size_t size)
  __attribute__((__always_inline__));
inline int llistxattr(istr_t pathname, ostr_t list, size_t size)
  __attribute__((__always_inline__));
inline int flistxattr(fd_t fd, ostr_t list, size_t size)
  __attribute__((__always_inline__));
inline int removexattr(istr_t pathname, istr_t name)
  __attribute__((__always_inline__));
inline int lremovexattr(istr_t pathname, istr_t name)
  __attribute__((__always_inline__));
inline int fremovexattr(fd_t fd, istr_t name)
  __attribute__((__always_inline__));
inline int tkill(pid_t pid, int sig)
  __attribute__((__always_inline__));
inline time_t time(time_p tloc)
  __attribute__((__always_inline__));
inline int futex(uint32_p uaddr, int op, uint32_t val, timespec_p utime, uint32_p uaddr2, uint32_t val3)
  __attribute__((__always_inline__));
inline int sched_setaffinity(pid_t pid, unsigned len, uint64_p user_mask_ptr)
  __attribute__((__always_inline__));
inline int sched_getaffinity(pid_t pid, unsigned len, uint64_p user_mask_ptr)
  __attribute__((__always_inline__));
inline int io_setup(unsigned nr_events, aio_context_p ctxp)
  __attribute__((__always_inline__));
inline int io_destroy(aio_context_t ctx)
  __attribute__((__always_inline__));
inline int io_getevents(aio_context_t ctx_id, long min_nr, long nr, io_event_p events)
  __attribute__((__always_inline__));
inline int io_submit(aio_context_t ctx_id, long nr, iocb_p iocbpp)
  __attribute__((__always_inline__));
inline int io_cancel(aio_context_t ctx_id, iocb_p iocb, io_event_p result)
  __attribute__((__always_inline__));
inline int lookup_dcookie(uint64_t cookie64, long buf, long len)
  __attribute__((__always_inline__));
inline int epoll_create(int size)
  __attribute__((__always_inline__));
inline int remap_file_pages(uint64_t start, uint64_t size, uint64_t prot, uint64_t pgoff, uint64_t flags)
  __attribute__((__always_inline__));
inline int getdents64(fd_t fd, linux_dirent64_p dirent, unsigned count)
  __attribute__((__always_inline__));
inline int set_tid_address(int32_p tidptr)
  __attribute__((__always_inline__));
inline int restart_syscall()
  __attribute__((__always_inline__));
inline int semtimedop(int semid, sembuf_p tsops, unsigned nsops, timespec_p timeout)
  __attribute__((__always_inline__));
inline int fadvise64(fd_t fd, off_t offset, size_t len, int advice)
  __attribute__((__always_inline__));
inline int timer_create(const clockid_t which_clock, sigevent_p timer_event_spec, timer_p created_timer_id)
  __attribute__((__always_inline__));
inline int timer_settime(timer_t timer_id, int flags, itimerspec_p new_setting, itimerspec_p old_setting)
  __attribute__((__always_inline__));
inline int timer_gettime(timer_t timer_id, itimerspec_p setting)
  __attribute__((__always_inline__));
inline int timer_getoverrun(timer_t timer_id)
  __attribute__((__always_inline__));
inline int timer_delete(timer_t timer_id)
  __attribute__((__always_inline__));
inline int clock_settime(const clockid_t which_clock, timespec_p tp)
  __attribute__((__always_inline__));
inline int clock_gettime(const clockid_t which_clock, timespec_p tp)
  __attribute__((__always_inline__));
inline int clock_getres(const clockid_t which_clock, timespec_p tp)
  __attribute__((__always_inline__));
inline int clock_nanosleep(const clockid_t which_clock, int flags, timespec_p rqtp, timespec_p rmtp)
  __attribute__((__always_inline__));
inline int exit_group(int error_code)
  __attribute__((__always_inline__));
inline int epoll_wait(int epfd, epoll_event_p events, int maxevents, int timeout)
  __attribute__((__always_inline__));
inline int epoll_ctl(int epfd, int op, fd_t fd, epoll_event_p event)
  __attribute__((__always_inline__));
inline int tgkill(pid_t tgid, pid_t pid, int sig)
  __attribute__((__always_inline__));
inline int utimes(ostr_t filename, timeval_p utimes)
  __attribute__((__always_inline__));
inline int mbind(uint64_t start, uint64_t len, uint64_t mode, uint64_p nmask, uint64_t maxnode, unsigned flags)
  __attribute__((__always_inline__));
inline int set_mempolicy(int mode, uint64_p nmask, uint64_t maxnode)
  __attribute__((__always_inline__));
inline int get_mempolicy(int32_p policy, uint64_p nmask, uint64_t maxnode, uint64_t addr, uint64_t flags)
  __attribute__((__always_inline__));
inline int mq_open(istr_t u_name, int oflag, mode_t mode, mq_attr_p u_attr)
  __attribute__((__always_inline__));
inline int mq_unlink(istr_t u_name)
  __attribute__((__always_inline__));
inline int mq_timedsend(mqd_t mqdes, istr_t u_msg_ptr, size_t msg_len, unsigned msg_prio, timespec_p u_abs_timeout)
  __attribute__((__always_inline__));
inline int mq_timedreceive(mqd_t mqdes, ostr_t u_msg_ptr, size_t msg_len, uint32_p u_msg_prio, timespec_p u_abs_timeout)
  __attribute__((__always_inline__));
inline int mq_notify(mqd_t mqdes, sigevent_p u_notification)
  __attribute__((__always_inline__));
inline int mq_getsetattr(mqd_t mqdes, mq_attr_p u_mqstat, mq_attr_p u_omqstat)
  __attribute__((__always_inline__));
inline int kexec_load(uint64_t entry, uint64_t nr_segments, kexec_segment_p segments, uint64_t flags)
  __attribute__((__always_inline__));
inline int waitid(int which, pid_t upid, siginfo_p infop, int options, rusage_p ru)
  __attribute__((__always_inline__));
inline int add_key(istr_t _type, istr_t _description, const void_p _payload, size_t plen)
  __attribute__((__always_inline__));
inline int request_key(istr_t _type, istr_t _description, istr_t _callout_info, uint64_t destringid)
  __attribute__((__always_inline__));
inline int keyctl(int option, uint64_t arg2, uint64_t arg3, uint64_t arg4, uint64_t arg5)
  __attribute__((__always_inline__));
inline int ioprio_set(int which, int who, int ioprio)
  __attribute__((__always_inline__));
inline int ioprio_get(int which, int who)
  __attribute__((__always_inline__));
inline int inotify_init()
  __attribute__((__always_inline__));
inline int inotify_add_watch(fd_t fd, istr_t pathname, uint32_t mask)
  __attribute__((__always_inline__));
inline int inotify_rm_watch(fd_t fd, int32_t wd)
  __attribute__((__always_inline__));
inline int migrate_pages(pid_t pid, uint64_t maxnode, uint64_p old_nodes, uint64_p new_nodes)
  __attribute__((__always_inline__));
inline int openat(fd_t dfd, istr_t filename, int flags, int mode)
  __attribute__((__always_inline__));
inline int mkdirat(fd_t dfd, istr_t pathname, int mode)
  __attribute__((__always_inline__));
inline int mknodat(fd_t dfd, istr_t filename, int mode, unsigned dev)
  __attribute__((__always_inline__));
inline int fchownat(fd_t dfd, istr_t filename, uid_t user, gid_t group, int flag)
  __attribute__((__always_inline__));
inline int futimesat(fd_t dfd, istr_t filename, timeval_p utimes)
  __attribute__((__always_inline__));
inline int newfstatat(fd_t dfd, istr_t filename, stat_p statbuf, int flag)
  __attribute__((__always_inline__));
inline int unlinkat(fd_t dfd, istr_t pathname, int flag)
  __attribute__((__always_inline__));
inline int renameat(fd_t oldfd, istr_t oldname, fd_t newfd, istr_t newname)
  __attribute__((__always_inline__));
inline int linkat(fd_t oldfd, istr_t oldname, fd_t newfd, istr_t newname, int flags)
  __attribute__((__always_inline__));
inline int symlinkat(istr_t oldname, fd_t newfd, istr_t newname)
  __attribute__((__always_inline__));
inline int readlinkat(fd_t dfd, istr_t pathname, ostr_t buf, int bufsiz)
  __attribute__((__always_inline__));
inline int fchmodat(fd_t dfd, istr_t filename, mode_t mode)
  __attribute__((__always_inline__));
inline int faccessat(fd_t dfd, istr_t filename, int mode)
  __attribute__((__always_inline__));
inline int pselect6(int n, fd_set_p inp, fd_set_p outp, fd_set_p exp, timespec_p tsp, void_p sig)
  __attribute__((__always_inline__));
inline int ppoll(pollfd_p ufds, unsigned nfds, timespec_p tsp, const sigset_p sigmask, size_t sigsetsize)
  __attribute__((__always_inline__));
inline int unshare(uint64_t unshare_flags)
  __attribute__((__always_inline__));
inline int set_robust_list(robust_list_head_p head, size_t len)
  __attribute__((__always_inline__));
inline int get_robust_list(int pid, robust_list_head_p head_ptr, size_p len_ptr)
  __attribute__((__always_inline__));
inline int splice(int fd_in, off_p off_in, int fd_out, off_p off_out, size_t len, unsigned flags)
  __attribute__((__always_inline__));
inline int tee(int fdin, int fdout, size_t len, unsigned flags)
  __attribute__((__always_inline__));
inline int sync_file_range(fd_t fd, off_t offset, off_t bytes, long flags)
  __attribute__((__always_inline__));
inline int vmsplice(fd_t fd, iovec_p iov, uint64_t nr_segs, unsigned flags)
  __attribute__((__always_inline__));
inline int move_pages(pid_t pid, uint64_t nr_pages, void_p pages, int32_p nodes, int32_p status, int flags)
  __attribute__((__always_inline__));
inline int utimensat(fd_t dfd, istr_t filename, timespec_p utimes, int flags)
  __attribute__((__always_inline__));
inline int epoll_pwait(int epfd, epoll_event_p events, int maxevents, int timeout, const sigset_p sigmask, size_t sigsetsize)
  __attribute__((__always_inline__));
inline int signalfd(int ufd, sigset_p user_mask, size_t sizemask)
  __attribute__((__always_inline__));
inline int timerfd_create(int clockid, int flags)
  __attribute__((__always_inline__));
inline int eventfd(unsigned count)
  __attribute__((__always_inline__));
inline int fallocate(fd_t fd, long mode, off_t offset, off_t len)
  __attribute__((__always_inline__));
inline int timerfd_settime(int ufd, int flags, itimerspec_p utmr, itimerspec_p otmr)
  __attribute__((__always_inline__));
inline int timerfd_gettime(int ufd, itimerspec_p otmr)
  __attribute__((__always_inline__));
inline int accept4(fd_t fd, sockaddr_p upeer_sockaddr, int32_p upeer_addrlen, int flags)
  __attribute__((__always_inline__));
inline int signalfd4(int ufd, sigset_p user_mask, size_t sizemask, int flags)
  __attribute__((__always_inline__));
inline int eventfd2(unsigned count, int flags)
  __attribute__((__always_inline__));
inline int epoll_create1(int flags)
  __attribute__((__always_inline__));
inline int dup3(fd_t oldfd, fd_t newfd, int flags)
  __attribute__((__always_inline__));
inline int pipe2(fd_p filedes, int flags)
  __attribute__((__always_inline__));
inline int inotify_init1(int flags)
  __attribute__((__always_inline__));
inline int preadv(fd_t fd, iovec_p vec, uint64_t vlen, uint64_t pos_l, uint64_t pos_h)
  __attribute__((__always_inline__));
inline int pwritev(fd_t fd, iovec_p vec, uint64_t vlen, uint64_t pos_l, uint64_t pos_h)
  __attribute__((__always_inline__));
inline int rt_tgsigqueueinfo(pid_t tgid, pid_t pid, int sig, siginfo_p uinfo)
  __attribute__((__always_inline__));
inline int perf_event_open(perf_event_attr_p attr_uptr, pid_t pid, int cpu, int group_fd, uint64_t flags)
  __attribute__((__always_inline__));
inline int recvmmsg(fd_t fd, msghdr_p mmsg, unsigned vlen, unsigned flags, timespec_p timeout)
  __attribute__((__always_inline__));
inline int fanotify_init(unsigned flags, unsigned event_f_flags)
  __attribute__((__always_inline__));
inline int fanotify_mark(long fanotify_fd, long flags, uint64_t mask, fd_t dfd, long pathname)
  __attribute__((__always_inline__));
inline int prlimit64(pid_t pid, unsigned resource, rlimit64_p new_rlim, rlimit64_p old_rlim)
  __attribute__((__always_inline__));
inline int name_to_handle_at(fd_t dfd, istr_t name, file_handle_p handle, int32_p mnt_id, int flag)
  __attribute__((__always_inline__));
inline int open_by_handle_at(fd_t dfd, istr_t name, file_handle_p handle, int32_p mnt_id, int flags)
  __attribute__((__always_inline__));
inline int clock_adjtime(clockid_t which_clock, timex_p tx)
  __attribute__((__always_inline__));
inline int syncfs(fd_t fd)
  __attribute__((__always_inline__));
inline int sendmmsg(fd_t fd, msghdr_p mmsg, unsigned vlen, unsigned flags)
  __attribute__((__always_inline__));
inline int setns(fd_t fd, int nstype)
  __attribute__((__always_inline__));
inline int getcpu(uint32_p cpup, uint32_p nodep, uint64_t unused)
  __attribute__((__always_inline__));
inline int process_vm_readv(pid_t pid, iovec_p lvec, uint64_t liovcnt, iovec_p rvec, uint64_t riovcnt, uint64_t flags)
  __attribute__((__always_inline__));
inline int process_vm_writev(pid_t pid, iovec_p lvec, uint64_t liovcnt, iovec_p rvec, uint64_t riovcnt, uint64_t flags)
  __attribute__((__always_inline__));
inline int kcmp(pid_t pid1, pid_t pid2, int type, uint64_t idx1, uint64_t idx2)
  __attribute__((__always_inline__));
inline int finit_module(fd_t fd, istr_t uargs, int flags)
  __attribute__((__always_inline__));
inline int sched_setattr(pid_t pid, sched_attr_p attr, unsigned flags)
  __attribute__((__always_inline__));
inline int sched_getattr(pid_t pid, sched_attr_p attr, unsigned size, unsigned flags)
  __attribute__((__always_inline__));
inline int renameat2(int olddfd, istr_t oldname, int newdfd, istr_t newname, unsigned flags)
  __attribute__((__always_inline__));
inline int seccomp(unsigned op, unsigned flags, istr_t uargs)
  __attribute__((__always_inline__));
inline int getrandom(ostr_t buf, size_t count, unsigned flags)
  __attribute__((__always_inline__));
inline int memfd_create(istr_t uname_ptr, unsigned flags)
  __attribute__((__always_inline__));
inline int kexec_file_load(int kernel_fd, int initrd_fd, size_t cmdline_len, istr_t cmdline_ptr, uint64_t flags)
  __attribute__((__always_inline__));
inline int bpf(int cmd, bpf_attr_p attr, unsigned size)
  __attribute__((__always_inline__));
inline int stub_execveat(fd_t dfd, istr_t filename, istr_v argv, istr_v envp, int flags)
  __attribute__((__always_inline__));
inline int userfaultfd(int flags)
  __attribute__((__always_inline__));
inline int membarrier(int cmd, int flags)
  __attribute__((__always_inline__));
inline int mlock2(uint64_t start, size_t len, int flags)
  __attribute__((__always_inline__));
inline int copy_file_range(fd_t fd_in, off_p off_in, fd_t fd_out, off_p off_out, size_t len, unsigned flags)
  __attribute__((__always_inline__));
inline int preadv2(fd_t fd, iovec_p vec, uint64_t vlen, uint64_t pos_l, uint64_t pos_h, int flags)
  __attribute__((__always_inline__));
inline int pwritev2(fd_t fd, iovec_p vec, uint64_t vlen, uint64_t pos_l, uint64_t pos_h, int flags)
  __attribute__((__always_inline__));
}

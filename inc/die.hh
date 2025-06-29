#include "syscall.hh"
namespace die
{
  using sys::open_flags;
  using sys::open_mode;
  void throw_errno(unsigned long res) __attribute__((__noreturn__));
  template<class res_t>
    res_t chk_return(unsigned long res){
      if(res>uint64_t(-4096))
        throw_errno(res);
      return (res_t)res;
    };
  // __NR_read=0
  inline ssize_t read(fd_t fd, char* buf, size_t len)
  {
    long res;
    asm("syscall"
        : "=a"(res)
        : "a"(0), "D"(fd), "S"(buf), "d"(len)
        : "rcx", "r11", "memory");
    return chk_return<ssize_t>(res);
  }
  // __NR_write=1
  inline ssize_t write(fd_t fd, const char* buf, size_t len)
  {
    long res;
    asm("syscall\n"
        : "=a"(res)
        : "a"(1), "D"(fd), "S"(buf), "d"(len)
        : "rcx", "r11", "memory");
    return chk_return<ssize_t>(res);
  }
  // __NR_open=2
  inline fd_t open(const char* pathname,
                   open_flags  flags,
                   open_mode   mode=sys::o_default)
  {
    int fd= -1;
    asm("syscall\n"
        : "=a"(fd)
        : "0"(2), "D"(pathname), "S"(flags), "d"(mode)
        : "rcx", "r11", "memory");
    return chk_return<fd_t>(fd_t(fd));
  }
  // __NR_close=3
  inline int close(fd_t fd)
  {
    asm("syscall\n"
        : "=a"(fd) 
        : "0"(3), "D"(fd) 
        : "rcx", "r11", "memory");
    return chk_return<int>(fd);
  }
  // __NR_stat=4
  inline int stat(const char* pathname, struct stat_t* statbuf)
  {
    int res= -1;
    asm("syscall\n"
        : "=a"(res)
        : "a"(4), "D"(pathname), "S"(statbuf)
        : "rcx", "r11", "memory");
    return chk_return<int>(res);
  }
  // __NR__ lseek = 8
  // inline int lseek(fd_t fd, off_t offset, unsigned origin)
  enum origin_t
  {
    set= 0,
    cur= 1,
    end= 2
  };
  inline off_t lseek(fd_t fd, off_t off, origin_t origin)
  {
    off_t res;
    asm("syscall\n"
        : "=a"(res)
        : "0"(8), "D"(fd), "S"(off), "d"(origin)
        : "rcx", "r11", "memory");
    return chk_return<int>(res);
  }


  enum mmap_prot_t
  {
    // For MMAP.
    prot_none = 0x0,
    prot_read = 0x1,
    prot_write= 0x2,
    prot_exec = 0x4,
  };


  enum mmap_flag_t
  {
    map_private  = 0x02,
    map_shared   = 0x01,
    map_fixed    = 0x10,
    map_anon     = 0x20,
    map_anonymous= map_anon,
    map_growsdown= 0x00100,
    map_noreserve= 0x04000,
    map_nonblock = 0x10000,
    map_populate = 0x08000,
    map_stack    = 0x20000,
  };
  // __NR_mmap=9
  inline char* mmap(void*  addr,
                    size_t length,
                    int    prot,
                    int    flags,
                    fd_t   fd,
                    off_t  off)
  {

    uint64_t res;

    __asm__ volatile(
             "\tmovq %5,%%r10 ;\n"
             "\tmovq %6,%%r8 ;\n"
             "\tmovq %7, %%r9; \n"
             "\tsyscall;\n"
             : "=a"(res)
             : "0"(9),
               "D"(addr),
               "S"(length),
               "d"(prot),
               "g"(flags),
               "g"(long(fd)),
               "g"(long(off))
             : "r11", "rcx", "memory", "r10", "r8", "r9");

    return chk_return<char*>(res);
  }
  // __NR_sigaction = 13
  inline int rt_sigaction(int sig, sigaction_p act, sigaction_p oact)
  {

    uint64_t res;

    asm("\tmovq %5,%%r10 ;\n"
        "\tsyscall;\n"
        : "=a"(res)
        : "0"(13), "D"(sig), "S"(act), "d"(oact), "g"(sizeof(sigset_t))
        : "r11", "rcx", "memory");

    return chk_return<int>(res);
  }
  // __NR_sigprocmask=14
  inline int rt_sigprocmask(int how, sigset_p nset, sigset_p oset)
  {
    int res= -1;
    asm("\tmovq %5,%%r10 ;\n"
        "\tsyscall;\n"
        : "=a"(res)
        : "0"(14), "D"(how), "S"(nset), "d"(oset), "g"(sizeof(sigset_t))
        : "r11", "rcx", "memory");

    return chk_return<int>(res);
  }
  // __NR_sigreturn=15
  inline long rt_sigreturn()
  {
    sys::errno=ENOSPC;
    return -1;
//       int res= -1;
//       asm("syscall\n" : "=a"(res) : "0"(15) : "rcx", "r11", "memory");
//       if(res < 0)
//         errno=res;
  }
  inline long ioctl( uint32_t fd, uint32_t cmd, uint64_t arg ) {
    long res;
    asm("syscall\n"
        : "=a"(res)
        : "a"(16), "D"(fd), "S"(cmd), "d"(arg)
        : "rcx", "r11", "memory");
    return chk_return<int>(res);
  }
  // __NR__ pipe = 22 

  inline int pipe(fd_t (&fds)[2])
  {
    time_t res= -1;
    asm("syscall\n"
        : "=a"(res)
        : "a"(22), "D"(fds)
        : "rcx", "r11", "memory");
    return chk_return<int>(res);
  }
  // __NR__ select = 23
  inline int select(int       n,
                    fdset_p  inp,
                    fdset_p  outp,
                    fdset_p  exp,
                    timeval_p tvp= 0)
  {

    uint64_t res;

    __asm__ volatile(
             "\tsyscall;\n"
             : "=a"(res)
             : "0"(23), "D"(n), "S"(inp), "d"(outp), "g"(exp), "g"(tvp)
             : "rcx", "memory", "r8", "r9");

    return chk_return<int>(res);
  }

  // __NR_dup = 32
  inline int dup(fd_t fd)
  {
    int res= -1;
    asm("syscall\n"
        : "=a"(res)
        : "0"(32), "D"(fd)
        : "rcx", "r11", "memory");
    return chk_return<int>(res);
  }

  // __NR_dup = 33
  inline int dup2(fd_t ofd, fd_t nfd)
  {
    int res= -1;
    asm("syscall\n"
        : "=a"(res)
        : "a"(33), "D"(ofd), "S"(nfd)
        : "rcx", "r11", "memory");
    return chk_return<int>(res);
  }
  // __NR_nanosleep = 35
  inline int nanosleep(timespec_p rqtp, timespec_p rmtp)
  {
    uint64_t res= 0xfeebdaed;
    asm("\tsyscall;\n"
        : "=a"(res)
        : "0"(35), "D"(rqtp), "S"(rmtp)
        : "rcx", "r11", "memory");
    return chk_return<int>(res);
  }

  inline int sleep(time_t secs)
  {
    uint64_t res= 0xfeebdaed;
    timespec_t rqtp, rmtp;

    rqtp.tv_sec=secs;
    rqtp.tv_nsec=0;
    rmtp.tv_sec=0;
    rmtp.tv_nsec=0;
    asm("\tsyscall;\n"
        : "=a"(res)
        : "0"(35), "D"(&rqtp), "S"(&rmtp)
        : "rcx", "r11", "memory");
    return chk_return<int>(res);
  }
  // __NR_alarm = 37
  inline int alarm(unsigned long delay)
  {
    int res= -1;
    asm("syscall\n"
        : "=a"(res)
        : "0"(37), "D"(delay)
        : "rcx", "r11", "memory");
    return chk_return<int>(res);
  }
  // __NR_getpid = 39
  inline int getpid()
  {
    int res= -1;
    asm("syscall\n" : "=a"(res) : "0"(39) : "rcx", "r11", "memory");
    return chk_return<int>(res);
  }
  // __NR__ fork = 57 
  inline int fork()
  {
    int res= -1;
    asm("syscall\n" : "=a"(res) : "0"(57) : "rcx", "r11", "memory");
    return chk_return<int>(res);
  }
  // __NO__ execve = 59
  inline int execve(const char * fn, char *const * argv, char *const * envp)
  {
    long res;
    asm("syscall"
        : "=a"(res)
        : "a"(59), "D"(fn), "S"(argv), "d"(envp)
        : "rcx", "r11", "memory");
    return chk_return<int>(res);

  }
  // __NR_exit = 60
  inline void exit(int res)
  {
    asm("syscall\n"
        : "=a"(res)
        : "a"(60), "D"(res)
        : "rcx", "r11", "memory");
    while(1)
      sleep(1);
  }

  // __NR__ wait4 = 61 

  inline int wait4(pid_t upid, int32_p stat_p, int opt, rusage_p ru)
  {

    uint64_t res;

    __asm__ volatile(
             "\tsyscall;\n"
             : "=a"(res)
             : "0"(61), "D"(upid), "S"(stat_p), "d"(opt), "g"(ru)
             : "rcx", "memory", "r8", "r9");

    return chk_return<int>(res);
  }
  inline int waitpid(pid_t pid, int32_p wstat, int opt)
  {
    return wait4(pid,wstat,opt,NULL);
  }
  inline int wait(int32_p wstat)
  {
    return waitpid(-1,wstat,0);
  }

  // __NR__ kill=62
  inline int kill(pid_t pid, int sig)
  {
    uint64_t res= 0xfeebdaed;
    asm("\tsyscall;\n"
        : "=a"(res)
        : "0"(62), "D"(pid), "S"(sig)
        : "rcx", "r11", "memory");
    return chk_return<int>(res);
  }

  // __NR__ uname = 63 

  inline int uname(utsname_p name)
  {
    time_t res= -1;
    asm("syscall\n"
        : "=a"(res)
        : "a"(63), "D"(name)
        : "rcx", "r11", "memory");
    return chk_return<int>(res);
  }

  // __NR__ rename = 82
  inline int rename(istr_t oldname, istr_t newname)
  {
    uint64_t res= 0xfeebdaed;
    asm("\tsyscall;\n"
        : "=a"(res)
        : "0"(82), "D"(oldname), "S"(newname)
        : "rcx", "r11", "memory");
    return chk_return<int>(res);
  }
  //#define __NR_time 201
  inline time_t time(time_t* buf)
  {
    time_t res= -1;
    asm("syscall\n"
        : "=a"(res)
        : "a"(201), "D"(buf)
        : "rcx", "r11", "memory");
    return chk_return<int>(res);
  }
  // __NR_getdents = 217
  inline ssize_t getdents(fd_t fd, linux_dirent64* buf, size_t len)
  {
    long res;
    asm("syscall"
        : "=a"(res)
        : "a"(217), "D"(fd), "S"(buf), "d"(len)
        : "rcx", "r11", "memory");
    return chk_return<int>(res);
  }
  // __NR__ pipe2 = 293 

  inline int pipe2(fd_p fds, int flags)
  {
    uint64_t res= 0xfeebdaed;
    asm("\tsyscall;\n"
        : "=a"(res)
        : "0"(293), "D"(fds), "S"(flags)
        : "rcx", "r11", "memory");
    return chk_return<int>(res);
  }
  // __NR__ utimensat = 280 
  inline int utimensat(fd_t dfd, istr_t filename, timespec_p utimes, int flags)
  {

    uint64_t res;

    __asm__ volatile(
             "\tsyscall;\n"
             : "=a"(res)
             : "0"(280), "D"(dfd), "S"(filename), "d"(utimes), "g"(flags)
             : "rcx", "memory", "r8", "r9");

    return chk_return<int>(res);
  }
} // namespace sys

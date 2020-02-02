#ifndef syscall_hh
#define syscall_hh syscall_hh

#include "types.hh"
#include "errno.hh"

#if 1
#define AAI __attribute__ ((__always_inline__))
#else
#define AAI
#endif

namespace sys {
#define linux_dirent64 linux_dirent

  struct stat_t {
    uint64_t  st_dev;
    uint64_t  st_ino;
    uint32_t  st_mode;
    uint32_t  st_nlink;
    uint32_t  st_uid;
    uint32_t  st_gid;
    uint64_t  st_rdev;
    uint64_t  __pad1;
    int64_t   st_size;
    int32_t   st_blksize;
    int32_t   __pad2;
    int64_t   st_blocks;
    int64_t   st_atime;
    uint64_t  st_atime_nsec;
    int64_t   st_mtime;
    uint64_t  st_mtime_nsec;
    int64_t   st_ctime;
    uint64_t  st_ctime_nsec;
    uint32_t  __unused4;
    uint32_t  __unused5;
  };
  struct pollfd_t {
    fd_t   fd;
    short events;
    short revents;
  };

  extern "C" {
  };
  enum open_mode {
    o_default = 0664
  };
  enum open_flags {
    o_rdonly  =  0000,
    o_wronly  =  0001,
    o_rdwr    =  0002,
    o_mask    =  0003,
    o_creat      =  00000100,
    o_excl       =  00000200,
    o_noctty     =  00000400,
    o_trunc      =  00001000,
    o_append     =  00002000,
    o_nonblock   =  00004000,
    o_dsync      =  00010000,
    o_fasync     =  00020000,
    o_direct     =  00040000,
    o_largefile  =  00100000,
    o_directory  =  00200000,
    o_nofollow   =  00400000,
    o_noatime    =  01000000,
    o_cloexec    =  02000000,
  };
  inline open_flags operator|(open_flags lhs, open_flags rhs){
    return open_flags(int(lhs)|int(rhs));
  };
  inline open_flags operator&(open_flags lhs, open_flags rhs){
    return open_flags(int(lhs)&int(rhs));
  };
}

extern "C" {
  void *malloc(size_t);
  void free(void *);
  void *realloc(void *ptr, size_t size);
  inline void* sbrk (intptr_t increment)AAI;
  inline int   strcmp(const char *s1, const char *s2) AAI;
  inline void* memset(void *s, int c, size_t n)AAI;
  inline void* memcpy(void *dst, const void *src, size_t n)AAI;
  inline int   memcmp(const void *dst, const void *src, size_t n)AAI;
  inline void* memmove(void *dst, const void *src, size_t n)AAI;
  inline void* memchr(const void *_mem, int c, size_t n)AAI;
  inline char* strcpy(char *d, const char *s)AAI;
  inline char* strncpy(char *dst, const char *src, size_t n)AAI;
  inline char* strncpy(char *dst, const char *src, size_t n)AAI;
  inline size_t strlen(const char *s)AAI;
  inline void * memmove(void*_dst, const void *_src, size_t n)
  {
    char *dst((char*)_dst);
    const char *src((const char*)_src);
    if(dst<src || dst>src+n)
      return memcpy(dst,src,n);
    while(n--)
      dst[n]=src[n];
    return dst;
  }
  void exit(int res);
  inline void * memchr(const void *_mem, int c, size_t n)
  {
    const char *mem=(const char*)_mem;
    for(size_t i=0;i<n;i++)
      if(mem[i]==c)
        return (void*)&mem[i];
    return nullptr;
  };
  inline size_t strcspn(const char *s, const char *reject)
  {
    char rej[256];
    memset(rej,0,sizeof(rej));
    while(*reject)
      rej[*reject++]=1;
    rej[0]=1;
    size_t i=0;
    while(!rej[s[i]])
      ++i;
    return i;
  };
  inline char *strchr(const char *s, int c){
    char ch;
    while((ch=*s++)!=c) {
      if(!ch)
        return nullptr;
    }
    return (char*)s;
  };
  inline int strncmp(const char *lhs, const char *rhs, size_t n)
  {
    for(int i=0;i<n;i++){
      int res=lhs[i]-rhs[i];
      if(res)
        return res;
      if(!lhs[i])
        break;
    };
    return 0;
  };
  inline size_t strlen(const char *s)
  {
    const char *p(s);
    while(*p)
      ++p;
    return p-s;
  };
  inline int strcmp(const char *s1, const char *s2)
  {
    for(;;){
      int d=*s1-*s2;
      if(d)
        return d<0?-1:1;
      if(!*s1)
        return 0;
      ++s1,++s2;
    };
  };
  inline void *memset(void *s, int c, size_t n){
    char *b=(char*)s;
    for(int i=0;i<n;i++)
      b[i]=c;
    return s;
  };
  inline void *memcpy(void *dest, const void *src, size_t n){
    char *d((char*)dest), *s((char*)src);
    for(int i=0;i<n;i++)
      d[i]=s[i];
    return dest;
  };
  inline int memcmp(const void *_s1, const void *_s2, size_t n)
  {
    int res=0;
    const char *s1=(const char*)_s1;
    const char *s2=(const char*)_s2;
    for(size_t i=0;i<n;i++){
      if((res=s1[i]-s2[i]))
        break;
    };
    return res;
  };
  inline char* strcpy(char *d, const char *s){
    size_t p=0;
    for(;;){
      if(not(d[p]=s[p]))
        return d;
      ++p;
    };
  };
  inline char * strncpy(char *dst, const char *src, size_t n)
  {
    size_t i;

    for (i = 0; i < n && src[i] != '\0'; i++)
      dst[i] = src[i];
    for ( ; i < n; i++)
      dst[i] = '\0';

    return dst;
  }
}
#define chk_return2(val,cast) return (cast)(val<0?set_errno(val):val)
#define chk_return(val) return (val<0?set_errno(val):val)
namespace sys 
{
  extern "C" {
    inline int nanosleep(timespec_p rqtp, timespec_p rmtp) AAI;
    inline int close(fd_t fd) AAI;
    inline int stat(const char *pathname, struct stat *statbuf) AAI;
    inline fd_t open(const char *pathname, open_flags flags, open_mode mode) AAI;
    inline void _exit(int res) AAI;
    inline time_t time(time_t *) AAI;
    inline ssize_t getdents(fd_t fd, linux_dirent64 *buf, size_t len) AAI;
    inline ssize_t read(fd_t fd, char *buf, size_t len) AAI;
    inline ssize_t sys_write( fd_t fd,  const char *buf,  size_t len) AAI;
  }

  // __NR_read=0
  inline ssize_t read(fd_t fd, char *buf, size_t len)
  {
    long res;
    asm (
        "syscall"
        : "=a"(res)
        : "a"(0), "D"(fd), "S"(buf),"d"(len)
        : "rcx", "r11", "memory");
    chk_return(res);
  };
  // __NR_write=1
  inline ssize_t sys_write( fd_t fd,  const char *buf,  size_t len)
  {
    long res;
    asm (
        "syscall\n"
        : "=a"(res)
        : "a"(1), "D"(fd), "S"(buf),"d"(len)
        : "rcx", "r11", "memory"
        );
    chk_return(res);
  };
  // __NR_open=2
  inline fd_t open(const char *pathname, open_flags flags, open_mode mode=o_default)
  {
    int fd=-1;
    asm (
        "syscall\n"
        : "=a"(fd)
        : "0"(2), "D"(pathname),"S"(flags), "d"(mode)
        : "rcx", "r11", "memory"
        );
    chk_return(fd);
  };
  // __NR_close=3
  inline int close(fd_t fd) 
  {
    int res=-1;
    asm (
        "syscall\n"
        : "=a"(fd)
        : "0"(3), "D"(fd)
        : "rcx", "r11", "memory"
        );
    chk_return(res);
  }
  // __NR_stat=4
  inline int stat(const char *pathname, struct stat *statbuf)
  {
    int res=-1;
    asm (
        "syscall\n"
        : "=a"(res)
        : "a"(4), "D"(pathname), "S"(statbuf)
        : "rcx", "r11", "memory"
        );
    chk_return(res);
  };
  // __NR__ lseek = 8 
  // inline int lseek(fd_t fd, off_t offset, unsigned origin)
  enum origin_t { set=0, cur=1, end=2 };
  inline off_t lseek(fd_t fd, off_t off, origin_t origin)
  {
    off_t res;
    asm (
        "syscall\n"
        : "=a"(res)
        : "0"(8), "D"(fd),"S"(off), "d"(origin)
        : "rcx", "r11", "memory"
        );
    chk_return(res);
  };


  enum mmap_prot_t {
    // For MMAP.
    prot_none     = 0x0,
    prot_read     = 0x1,
    prot_write    = 0x2,
    prot_exec     = 0x4,
  };



  enum mmap_flag_t {
    map_private        =  0x02,
    map_shared         =  0x01,
    map_fixed          =  0x10,
    map_anon           =  0x20,
    map_anonymous      =  map_anon,
    map_growsdown      =  0x00100,
    map_noreserve      =  0x04000,
    map_nonblock       =  0x10000,
    map_populate       =  0x08000,
    map_stack          =  0x20000,
  };
  // __NR_mmap=9
  inline char *mmap(
      void *addr, size_t length, int prot, int flags, fd_t fd, off_t off
      )
  {

    uint64_t res;

    __asm__ volatile (
        "\tmovq %5,%%r10 ;\n"
        "\tmovq %6,%%r8 ;\n"
        "\tmovq %7, %%r9; \n"
        "\tsyscall;\n"
        : "=a" (res)
        : "0" (9), "D" (addr), "S" (length), "d" (prot),
        "g" (flags), "g" (long(fd)), "g" (long(off))
        : "r11","rcx","memory", "r10", "r8", "r9" );

    chk_return2(res,char*);
  }
  // __NR_sigaction = 13
  inline int rt_sigaction(
      int sig,
      sigaction_p act,
      sigaction_p oact
      )
  {

    uint64_t res;

    asm(
        "\tmovq %5,%%r10 ;\n"
        "\tsyscall;\n"
        : "=a" (res)
        : "0" (13), "D" (sig), "S" (act), "d" (oact), "g"(sizeof(sigset_t))
        : "r11","rcx","memory"
       );

    chk_return(res);
  };
  // __NR_sigreturn=15
  inline void rt_sigreturn()
  {
    int res=-1;
    asm (
        "syscall\n"
        : "=a"(res)
        : "0"(15)
        : "rcx", "r11", "memory"
        );
    if(res<0)
      set_errno(res);
  }
//     };
//     inline char *mmap(
//         void *addr, size_t length, int prot, int flags, fd_t fd, off_t off
//         )
  // __NR__ select = 23 
  // __NR_dup = 32
  inline int dup(fd_t fd) {
    int res=-1;
    asm (
        "syscall\n"
        : "=a"(res)
        : "0"(32), "D"(fd)
        : "rcx", "r11", "memory"
        );
    chk_return(res);
  };
  // __NR_dup = 33
  inline int dup2(fd_t ofd, fd_t nfd)
  {
    int res=-1;
    asm (
        "syscall\n"
        : "=a"(res)
        : "a"(33), "D"(ofd), "S"(nfd)
        : "rcx", "r11", "memory"
        );
    chk_return(res);
  };
  // __NR_nanosleep = 35
  inline int nanosleep(timespec_p rqtp, timespec_p rmtp) {
    uint64_t res=0xfeebdaed;
    asm (
        "\tsyscall;\n"
        : "=a" (res)
        : "0" (35), "D" (rqtp), "S" (rmtp)
        : "rcx", "r11", "memory"
        );
    chk_return(res);
  }
  // __NR_alarm = 37
  inline int alarm(unsigned long delay)
  {
    int res=-1;
    asm (
        "syscall\n"
        : "=a"(res)
        : "0"(37), "D"(delay)
        : "rcx", "r11", "memory"
        );
    chk_return(res);
  }
  // __NR_getpid = 39
  inline int getpid()
  {
    int res=-1;
    asm (
        "syscall\n"
        : "=a"(res)
        : "0"(39)
        : "rcx", "r11", "memory"
        );
    chk_return(res);
  }
  // __NR_exit = 60
  inline void _exit(int res)
  {
    int exit_val;
    exit_val=res&0xff;
    asm (
        "syscall\n"
        : "=a"(res)
        : "a"(60), "D"(exit_val)
        : "rcx", "r11", "memory"
        );
    while(1);

  };

  // __NR__ rename = 82 
  inline int rename(istr_t oldname, istr_t newname)
  {
    uint64_t res=0xfeebdaed;
    asm (
        "\tsyscall;\n"
        : "=a" (res)
        : "0" (82), "D" (oldname), "S" (newname)
        : "rcx", "r11", "memory"
        );
    chk_return(res);
  };
  //#define __NR_time 201
  inline time_t time(time_t *buf) throw() {
    time_t res=-1;
    asm (
        "syscall\n"
        : "=a"(res)
        : "a"(201), "D"(buf)
        : "rcx", "r11", "memory"
        );
    chk_return(res);
  };
  // __NR_getdents = 217
  inline ssize_t getdents(fd_t fd, linux_dirent64 *buf, size_t len)
  {
    long res;
    asm (
        "syscall"
        : "=a"(res)
        : "a"(217), "D"(fd), "S"(buf),"d"(len)
        : "rcx", "r11", "memory");
    chk_return(res);
  };
};

namespace sys {

  inline ssize_t write(int fd, const char *buf, size_t len) AAI;
  inline ssize_t write(int fd, const char *buf, const char *end) AAI;
  inline ssize_t write(fd_t fd, const char *buf) AAI;

  inline ssize_t write(int fd, const char *buf, size_t len)
  {
    return sys_write(fd,buf,len);
  };
  inline ssize_t write(int fd, const char *buf, const char *end)
  {
    return sys_write(fd,buf,end-buf);
  };

  inline ssize_t write(fd_t fd, const char *buf){
    const char *end=buf;
    while(*end)
      ++end;
    return sys_write(fd,buf,end-buf);
  };

  inline const char*full_write(int fd, const char * const beg, const char *end)
  {
    const char*pos=beg;
    while(pos!=end){
      ssize_t res=sys_write(fd,pos,end-pos);
      if(res<0)
        return nullptr;
      pos+=res;
    };
    return pos;
  };
  inline ssize_t full_write(int fd, const char * const beg, size_t len){
    return full_write(fd,beg,beg+len)-beg;
  };
};

#define L(x) x,sizeof(x)-1


namespace std {
  void terminate() noexcept __attribute__((__noreturn__));
  using ::size_t;
  using ::free;
  using ::malloc;
  using ::realloc;
  using ::memset;
  extern const nothrow_t nothrow;
//     enum align_val_t {
//     };
  typedef void (*new_handler)();
};
extern "C" {
  void abort() __attribute__((__noreturn__));
  inline void abort()
  {
    do {
      asm("int3");
    } while(true);
  };
};

#undef AAI
#define _GLIBCXX_NOEXCEPT noexcept
#ifndef _GLIBCXX_NOTHROW
#define _GLIBCXX_NOTHROW
#endif
#endif

#ifndef syscall_hh
#define syscall_hh syscall_hh

#include <types.hh>

#if 0
#define AAI __attribute__ ((__always_inline__))
#else
#define AAI
#endif

#define O_ACCMODE	00000003
#define O_RDONLY	00000000
#define O_WRONLY	00000001
#define O_RDWR		00000002
#define O_CREAT		00000100
#define O_EXCL		00000200
#define O_NOCTTY	00000400
#define O_TRUNC		00001000
#define O_APPEND	00002000
#define O_NONBLOCK	00004000
#define O_DSYNC		00010000
#define FASYNC		00020000
#define O_DIRECT	00040000
#define O_LARGEFILE	00100000
#define O_DIRECTORY	00200000
#define O_NOFOLLOW	00400000
#define O_NOATIME	01000000
#define O_CLOEXEC	02000000
#define __O_SYNC	04000000
#define O_SYNC		(__O_SYNC|O_DSYNC)
#define O_PATH		010000000
#define __O_TMPFILE	020000000

// For MMAP.
#define  PROT_READ      0x1
#define  PROT_WRITE     0x2
#define  PROT_EXEC      0x4
#define  PROT_NONE      0x0
#define  MAP_PRIVATE    0x02
#define  MAP_SHARED     0x01
#define  MAP_FIXED      0x10
#define  MAP_ANONYMOUS  0x20

#define linux_dirent64 linux_dirent

struct stat {
	uint64_t	st_dev;
	uint64_t	st_ino;
	uint32_t	st_mode;
	uint32_t	st_nlink;
	uint32_t	st_uid;
	uint32_t	st_gid;
	uint64_t	st_rdev;
	uint64_t	__pad1;
	int64_t   st_size;
	int32_t	  st_blksize;
	int32_t	  __pad2;
	int64_t   st_blocks;
	int64_t   st_atime;
	uint64_t	st_atime_nsec;
	int64_t		st_mtime;
	uint64_t	st_mtime_nsec;
	int64_t		st_ctime;
	uint64_t	st_ctime_nsec;
	uint32_t	__unused4;
	uint32_t	__unused5;
};
struct pollfd {
	fd_t   fd;
	short events;
	short revents;
};

extern "C" {
  extern long errno;
  void exit(int res);
  inline ssize_t set_errno(long err)AAI;
  inline ssize_t set_errno(long err)
  {
    if(err>=0)
      return err;
    errno=-err;
    return -1;
  }
};
enum open_mode {
  o_default = 0
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
extern "C" {
	inline fd_t open(const char *pathname, open_flags flags, open_mode mode) AAI;
        inline int sys_close(fd_t fd) AAI;
	inline int stat(const char *pathname, struct stat *statbuf) AAI;
	inline ssize_t getdents(fd_t fd, linux_dirent64 *buf, size_t len) AAI;
	inline ssize_t read(fd_t fd, char *buf, size_t len) AAI;
	inline ssize_t sys_write( fd_t fd,  const char *buf,  size_t len) AAI;
	inline time_t time(time_t *) AAI;
	inline void _exit(int res) AAI;
	inline int nanosleep(timespec_p rqtp, timespec_p rmtp) AAI;
	
#define chk_return(val) if(val<0)return set_errno(val) else return fal;

	// __NR_read=0
	inline ssize_t read(fd_t fd, char *buf, size_t len)
	{
		long res;
		asm (
				"syscall"
				: "=a"(res)
				: "a"(0), "D"(fd), "S"(buf),"d"(len)
				: "rcx", "r11", "memory");
                return res;
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
		return set_errno(res);
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
		return set_errno(fd);
	};
	// __NR_close=3
        inline int sys_close(fd_t fd) 
	{
		int res=-1;
		asm (
				"syscall\n"
				: "=a"(fd)
				: "0"(3), "D"(fd)
				: "rcx", "r11", "memory"
				);
		return res;
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
		return set_errno(res);
	};
	// __NR_mmap=9
	inline char *mmap(
			void *addr, size_t length, int prot, int flags, fd_t fd, off_t off
			)
	{

		uint64_t ret;

		__asm__ volatile (
				"\tmovq %5,%%r10 ;\n"
				"\tmovq %6,%%r8 ;\n"
				"\tmovq %7, %%r9; \n"
				"\tsyscall;\n"
				: "=a" (ret)
				: "0" (9), "D" (addr), "S" (length), "d" (prot),
				"g" (flags), "g" (fd), "g" (off)
				: "r11","rcx","memory", "r10", "r8", "r9" );

		return (char*)set_errno(ret);
	}
	// __NR_sigaction = 13
	inline int rt_sigaction(
			int sig,
			sigaction_p act,
			sigaction_p oact
			)
	{

		uint64_t ret;

		asm(
				"\tmovq %5,%%r10 ;\n"
				"\tsyscall;\n"
				: "=a" (ret)
				: "0" (13), "D" (sig), "S" (act), "d" (oact), "g"(sizeof(sigset_t))
				: "r11","rcx","memory"
				);

		return (int)set_errno(ret);
	};
	// __NR_sigprocmask=14
	inline int rt_sigprocmask(int how, sigset_p nset, sigset_p oset)
	{
		int ret=-1;
		asm(
				"\tmovq %5,%%r10 ;\n"
				"\tsyscall;\n"
				: "=a" (ret)
				: "0" (14), "D" (how), "S" (nset), "d" (oset), "g"(sizeof(sigset_t))
				: "r11","rcx","memory"
				);

		return set_errno(ret);
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
		set_errno(res);
	}

	// __NR_dup = 32
	inline int dup(fd_t fd) {
		int res=-1;
		asm (
				"syscall\n"
				: "=a"(fd)
				: "0"(32), "D"(fd)
				: "rcx", "r11", "memory"
				);
		return set_errno(res);
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
		return set_errno(res);
	};
	// __NR_nanosleep = 35
	inline int nanosleep(timespec_p rqtp, timespec_p rmtp) {
		uint64_t ret=0xfeebdaed;
		asm (
				"\tsyscall;\n"
				: "=a" (ret)
				: "0" (35), "D" (rqtp), "S" (rmtp)
				: "rcx", "r11", "memory"
				);
		return set_errno(ret);
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
		return set_errno(res);
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
		return set_errno(res);
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
	}
	// __NR_getdents = 217
	inline ssize_t getdents(fd_t fd, linux_dirent64 *buf, size_t len)
	{
		long res;
		asm (
				"syscall"
				: "=a"(res)
				: "a"(217), "D"(fd), "S"(buf),"d"(len)
				: "rcx", "r11", "memory");
		return set_errno(res);
	};
};

inline int sign(int val) AAI;
inline int sign(int val){
	if(val<0)
		return -1;
	else if (val>0)
		return 1;
	else
		return 0;
};
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
};
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
inline const char *strchr(const char *s, int c){
	char ch;
	while((ch=*s++)!=c) {
		if(!ch)
			return nullptr;
	}
	return s;
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
			return sign(d);
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
		if(res=s1[i]-s2[i])
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

inline ssize_t full_write(int fd, const char * const beg, const char *end)AAI;

inline ssize_t write(int fd, const char *buf, size_t len) AAI;
inline ssize_t write(int fd, const char *buf, const char *end) AAI;
inline ssize_t write(fd_t fd, const char *buf) AAI;

inline ssize_t write(int fd, const char *buf, size_t len)
{
	return sys_write(fd,buf,len);
};
inline ssize_t write(int fd, const char *buf, const char *end)
{
	return write(fd,buf,end-buf);
};

inline ssize_t write(fd_t fd, const char *buf){
	return write(fd,buf,strlen(buf));
};
inline ssize_t full_write(int fd, const char * const beg, const char *end){
	const char*pos=beg;
	while(pos!=end){
		ssize_t res=sys_write(fd,pos,end-pos);
		if(res<0)
			return -1;
		pos+=res;
	};
	return pos-beg;
};

#define L(x) x,sizeof(x)-1

extern "C" {
//#define __NR_time 201
	inline time_t time(time_t *buf) {
		time_t res=-1;
		asm (
				"syscall\n"
				: "=a"(res)
				: "a"(4), "D"(buf)
				: "rcx", "r11", "memory"
				);
		return res;
	};
};

namespace std {
	void abort() __attribute__((__noreturn__));
	inline void abort(){
		do {
			asm("int3");
		} while(true);
	};
	void terminate() noexcept __attribute__((__noreturn__));
	typedef ::size_t size_t;
	using ::free;
	using ::malloc;
	using ::realloc;
	using ::memset;
	enum nothrow_t {
	};
	extern const nothrow_t nothrow;
	enum align_val_t {
	};
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
inline open_flags operator|(open_flags lhs, open_flags rhs){
  return open_flags(int(lhs)|int(rhs));
};
inline open_flags operator&(open_flags lhs, open_flags rhs){
  return open_flags(int(lhs)|int(rhs));
};

#undef AAI
#define _GLIBCXX_NOEXCEPT noexcept
#define _GLIBCXX_NOTHROW
#endif

#ifndef syscall_hh
#define syscall_hh syscall_hh

#include <types.hh>
#include <syscall_fwd.hh>

#define AAI __attribute__ ((__always_inline__))

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
	inline ssize_t set_errno(long err)
		__attribute__ ((__always_inline__));
	inline ssize_t set_errno(long err)
	{
		if(err>=0)
			return err;
		errno=-err;
		return -1;
	}


	// Primary System Calls.  These are direct.

};
extern "C" {

	inline fd_t open(const char *pathname, int flags, int mode) AAI;
	inline int close(fd_t fd) AAI;
	inline int stat(const char *pathname, struct stat *statbuf) AAI;
	inline ssize_t getdents(fd_t fd, linux_dirent64 *buf, size_t len) AAI;
	inline ssize_t read(fd_t fd, char *buf, size_t len) AAI;
	inline ssize_t sys_write( fd_t fd,  const char *buf,  size_t len) AAI;
	inline time_t time(time_t *) AAI;
	inline void _exit(int res) AAI;

	// __NR_read=0
	inline ssize_t read(fd_t fd, char *buf, size_t len)
	{
		long res;
		asm (
				"syscall"
				: "=a"(res)
				: "a"(0), "D"(fd), "S"(buf),"d"(len)
				: "rcx", "r11", "memory");
		return set_errno(res);
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
	inline fd_t open(const char *pathname, int flags, int mode=0)
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
	inline int close(fd_t fd)
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
	inline char *mmap(
			void *addr, size_t length, int prot, int flags, fd_t fd, off_t off
			)
	{

		uint64_t ret;

		__asm__ volatile (
				"\tnop;\n"
				"\tmovq %5,%%r10 ;\n"
				"\tmovq %6,%%r8 ;\n"
				"\tmovq %7, %%r9; \n"
				"\tnop;\n"
				"\tsyscall;\n"
				: "=a" (ret)
				: "0" (9), "D" (addr), "S" (length), "d" (prot),
				"g" (flags), "g" (fd), "g" (off)
				: "r11","rcx","memory", "r10", "r8", "r9" );

		return (char*)set_errno(ret);
	}
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
	inline void *sbrk (intptr_t increment)AAI;
	inline int strcmp(const char *s1, const char *s2)AAI;
	inline void *memset(void *s, int c, size_t n)AAI;
	inline void *memcpy(void *dest, const void *src, size_t n)AAI;
	inline char* strcpy(char *d, const char *s)AAI;
	inline char * strncpy(char *dst, const char *src, size_t n)AAI;
	inline char * strncpy(char *dst, const char *src, size_t n)AAI;
	inline size_t strlen(const char *s)AAI;
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

#define L(x) x,sizeof(x)-1

extern "C" {
	inline void abort(){
		do {
			asm("int3");
		} while(true);
	};
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

#endif

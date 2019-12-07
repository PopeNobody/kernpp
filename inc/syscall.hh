#include <types.hh>

#define O_ACCMODE	00000003
#define O_RDONLY	00000000
#define O_WRONLY	00000001
#define O_RDWR		00000002
#define O_CREAT		00000100	/* not fcntl */
#define O_EXCL		00000200	/* not fcntl */
#define O_NOCTTY	00000400	/* not fcntl */
#define O_TRUNC		00001000	/* not fcntl */
#define O_APPEND	00002000
#define O_NONBLOCK	00004000
#define O_DSYNC		00010000	/* used to be O_SYNC, see below */
#define FASYNC		00020000	/* fcntl, for BSD compatibility */
#define O_DIRECT	00040000	/* direct disk access hint */
#define O_LARGEFILE	00100000
#define O_DIRECTORY	00200000	/* must be a directory */
#define O_NOFOLLOW	00400000	/* don't follow links */
#define O_NOATIME	01000000
#define O_CLOEXEC	02000000	/* set close_on_exec */
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
	unsigned long	st_dev;		/* Device.  */
	unsigned long	st_ino;		/* File serial number.  */
	unsigned int	st_mode;	/* File mode.  */
	unsigned int	st_nlink;	/* Link count.  */
	unsigned int	st_uid;		/* User ID of the file's owner.  */
	unsigned int	st_gid;		/* Group ID of the file's group. */
	unsigned long	st_rdev;	/* Device number, if device.  */
	unsigned long	__pad1;
	long		st_size;	/* Size of file, in bytes.  */
	int		st_blksize;	/* Optimal block size for I/O.  */
	int		__pad2;
	long		st_blocks;	/* Number 512-byte blocks allocated. */
	long		st_atime;	/* Time of last access.  */
	unsigned long	st_atime_nsec;
	long		st_mtime;	/* Time of last modification.  */
	unsigned long	st_mtime_nsec;
	long		st_ctime;	/* Time of last status change.  */
	unsigned long	st_ctime_nsec;
	unsigned int	__unused4;
	unsigned int	__unused5;
};
struct pollfd {
	fd_t   fd;         /* file descriptor */
	short events;     /* requested events */
	short revents;    /* returned events */
};

extern "C" {
	extern int errno;
	inline ssize_t set_errno(ssize_t err)
		__attribute__ ((__always_inline__));
	inline ssize_t set_errno(ssize_t err)
	{
		if(err>=0)
			return err;
		errno=err;
		return -1;
	}


	// Primary System Calls.  These are direct.

};
extern "C" {
#define AAI __attribute__ ((__always_inline__))

	inline time_t time(time_t *) AAI;
	inline void exit(int res) AAI;
	inline ssize_t getdents(fd_t fd, linux_dirent64 *buf, size_t len) AAI;

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
	inline ssize_t write( fd_t fd,  const char *buf,  size_t len)
	{
		static long res;
		asm (
				"syscall\n" 
				: "=a"(res) 
				: "a"(1), "D"(fd), "S"(buf),"d"(len)
				: "rcx", "r11", "memory"
				);
		return set_errno(res);
	};
	// __NR_open=2
	inline fd_t open(const char *pathname, int flags)
	{
		int fd=-1;
		asm (
				"syscall\n" 
				: "=a"(fd) 
				: "0"(2), "D"(pathname),"S"(flags)
				: "rcx", "r11", "memory"
				);
		return fd;
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
	inline void exit(int res)
	{
		static int exit_val;
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
};

inline size_t strlen(const char *s)
{
	const char *p(s);
	while(*p)
		++p;
	return p-s;
};
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
	void *sbrk (intptr_t increment);
	int strcmp(const char *s1, const char *s2);
	void *memset(void *s, int c, size_t n);
	void *memcpy(void *dest, const void *src, size_t n);
	char* strcpy(char *d, const char *s);
	char * strncpy(char *dst, const char *src, size_t n);
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

inline ssize_t write(int fd, const char *buf)
	__attribute__ ((__always_inline__));


inline ssize_t write(int fd, const char *buf, const char *end)
{
	return write(fd,buf,end-buf);
};
inline ssize_t write(int fd, char ch)
	__attribute__ ((__always_inline__));
inline ssize_t write(int fd, char ch)
{
	return write(fd,&ch,1);
}

inline ssize_t write(int fd, const char *buf)
{
	return write(fd,buf,strlen(buf));
};



extern "C" {
	inline void abort(){
		exit(1);
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

#include <errno.hh>
#ifndef types_hh
#define types_hh types_hh

typedef char *str_t;
typedef const char *cstr_t;
typedef signed char int8_t;
typedef unsigned char uint8_t;
typedef int   int32_t;
typedef long  int64_t;
typedef unsigned uint32_t;
typedef unsigned long uint64_t;
typedef unsigned short int uint16_t;

struct iocb;
struct fd_set;
struct sigaction;
struct sigset_t;
struct iovec;
struct timeval;
struct sockaddr;
struct shmid_ds;
struct itimerval;
struct msghdr;
struct rusage;
struct utsname;
struct sembuf;
struct msgbuf;
struct msqid_ds;
struct linux_dirent;
struct linux_dirent64;
struct sigevent;
struct timer_t;
struct timezone;
struct rlimit;
struct sysinfo;
struct cap_user_header;
struct siginfo_t;
struct stack_t;
struct utimbuf;
struct cap_user_data;
struct ustat;
struct statfs;
struct sched_param;
struct sysctl_args;
struct task_struct;
struct timex;
struct vptr_t;
struct pt_regs;
struct aio_context_t;
struct io_event;
struct iocb;
struct itimerspec;
struct epoll_event;
struct mq_attr;
struct stat;
typedef stat* stat_p;
typedef iocb* iocb_p;
typedef cap_user_header* cap_user_header_t;
typedef cap_user_data* cap_user_data_t;
typedef sysinfo* sysinfo_p;
typedef statfs* statfs_p;
typedef int key_t;
typedef int sig_t;
typedef int uid_t;
typedef int gid_t;
typedef int umode_t;
//   typedef int64_t quad_t;
//   typedef char_ptr caddr_t;
//   typedef int32_t daddr_t;
typedef int32_t key_t;
typedef int32_t pid_t;
//   typedef int32_t sig_atomic_t;
//   typedef int64_t blkcnt64_t;
//   typedef int64_t blkcnt_t;
//   typedef int64_t blksize_t;
//   typedef int64_t fsword_t;
//   typedef int64_t intmax_t;
typedef long errno_t;
typedef int64_t intptr_t;
typedef uint64_t uintptr_t;
typedef int64_t off64_t;
typedef uint32_t fd_t;
typedef int64_t clock_t;
typedef int64_t off_t;
typedef int64_t suseconds_t;
typedef int64_t syscall_slong_t;
typedef int32_t clockid_t;
typedef int64_t time_t;
typedef uint64_t ptrdiff_t;
typedef uint32_t mode_t;
typedef uint64_t size_t;
typedef int64_t ssize_t;
typedef signed int __int32_t;
typedef signed long int __int64_t;
typedef signed short int __int16_t;
typedef struct { int __val[2]; } __fsid_t;
typedef uint8_t __u_char;
typedef uint32_t __gid_t;
typedef uint32_t __id_t;
typedef uint32_t __socklen_t;
typedef uint32_t __uid_t;
typedef uint32_t __u_int;
typedef uint32_t __uint32_t;
typedef uint32_t __useconds_t;
typedef uint64_t __dev_t;
typedef uint64_t __fsblkcnt64_t;
typedef uint64_t __fsblkcnt_t;
typedef uint64_t __fsfilcnt64_t;
typedef uint64_t __fsfilcnt_t;
typedef uint64_t __ino64_t;
typedef uint64_t __ino_t;
typedef uint64_t __nlink_t;
typedef uint64_t __rlim64_t;
typedef uint64_t __rlim_t;
typedef uint64_t __syscall_ulong_t;
typedef uint64_t __uint64_t;
typedef uint64_t __uintmax_t;
typedef uint64_t __u_long;
typedef uint64_t __u_quad_t;
typedef uint64_t ino64_t;
typedef unsigned short int __u_short;
typedef void * __timer_t;
struct timespec
{
  time_t tv_sec;
  int64_t tv_nsec;
};
struct linux_dirent {
	ino64_t        d_ino;    /* 64-bit inode number */
	off64_t        d_off;    /* 64-bit offset to next structure */
	unsigned short d_reclen; /* Size of this dirent */
	unsigned char  d_type;   /* File type */
	char           d_name[]; /* Filename (null-terminated) */

	linux_dirent *next() {
		return (linux_dirent*)(((char*)this)+this->d_reclen);
	};
};
#endif

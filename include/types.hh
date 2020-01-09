#include <errno.hh>
#ifndef types_hh
#define types_hh types_hh

typedef char* ostr_t;
typedef const char* istr_t;
typedef istr_t istr_v[];
typedef signed char int8_t;
typedef unsigned char uint8_t;
typedef int   int32_t;
typedef int32_t* int32_p;
typedef long  int64_t;
typedef unsigned uint32_t;
typedef uint32_t* uint32_p;
typedef unsigned long uint64_t;
typedef uint64_t* uint64_p;
typedef unsigned short int uint16_t;
typedef void* void_p;

struct iocb;
struct fd_set;
typedef fd_set* fd_set_p;
struct sigaction_t {
	void (*sa_handler) (int);
	unsigned long sa_flags;
	void (*sa_restorer) (void);
	unsigned long sa_mask;
};
typedef sigaction_t* sigaction_p;
typedef uint64_t sigset_t;
typedef sigset_t *sigset_p;
struct iovec;
typedef iovec* iovec_p;
struct timeval;
typedef timeval* timeval_p;
struct sockaddr;
typedef sockaddr* sockaddr_p;
struct shmid_ds;
typedef shmid_ds* shmid_ds_p;
struct itimerval;
typedef itimerval* itimerval_p;
struct msghdr;
typedef msghdr* msghdr_p;
struct rusage;
typedef rusage* rusage_p;
struct utsname;
typedef utsname* utsname_p;
struct sembuf;
typedef sembuf* sembuf_p;
struct msgbuf;
typedef msgbuf* msgbuf_p;

struct msqid_ds;
typedef msqid_ds* msqid_ds_p;
typedef int qid_t;
struct linux_dirent;
typedef linux_dirent* linux_dirent_p;
struct linux_dirent64;
typedef linux_dirent64* linux_dirent64_p;
struct sigevent;
typedef sigevent* sigevent_p;
struct timer_t;
typedef timer_t* timer_p;
struct timezone;
typedef timezone* timezone_p;
struct rlimit;
typedef rlimit* rlimit_p;
struct rlimit64;
struct file_handle;
typedef file_handle* file_handle_p;
typedef rlimit64* rlimit64_p;
struct sysinfo;
struct cap_user_header;
struct siginfo_t;
typedef siginfo_t* siginfo_p;
struct stack_t;
typedef stack_t* stack_p;
struct utimbuf;
typedef utimbuf* utimbuf_p;
struct cap_user_data;
struct ustat;
typedef ustat* ustat_p;
struct statfs;
struct bpf_attr;
typedef bpf_attr* bpf_attr_p;
struct sched_attr;
typedef sched_attr* sched_attr_p;
struct sched_param;
typedef sched_param* sched_param_p;
struct sysctl_args;
typedef sysctl_args* sysctl_args_p;
struct task_struct;
typedef task_struct* task_struct_p;
struct timex;
typedef timex* timex_p;
struct vptr_t;
struct pt_regs;
typedef pt_regs* pt_regs_p;
struct aio_context_t;
typedef aio_context_t* aio_context_p;
struct io_event;
typedef io_event* io_event_p;
struct iocb;
struct itimerspec;
typedef itimerspec* itimerspec_p;
struct epoll_event;
typedef epoll_event* epoll_event_p;
struct mq_attr;
typedef mq_attr* mq_attr_p;
struct stat;
struct pollfd;
typedef pollfd* pollfd_p;
typedef stat* stat_p;
typedef iocb* iocb_p;
typedef cap_user_header* cap_user_header_t;
typedef int mqd_t;
typedef cap_user_data* cap_user_data_t;
typedef sysinfo* sysinfo_p;
typedef statfs* statfs_p;
typedef int key_t;
typedef key_t* key_p;
typedef int sig_t;
typedef sig_t* sig_p;
typedef int uid_t;
typedef uid_t* uid_p;
typedef int gid_t;
typedef gid_t* gid_p;
typedef int umode_t;
struct kexec_segment;
typedef kexec_segment* kexec_segment_p;
struct robust_list_head;
typedef robust_list_head* robust_list_head_p;
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
typedef fd_t* fd_p;
typedef int64_t clock_t;
typedef int64_t off_t;
typedef off_t* off_p;
struct perf_event_attr;
typedef perf_event_attr* perf_event_attr_p;
typedef int64_t suseconds_t;
typedef int64_t syscall_slong_t;
typedef int32_t clockid_t;
typedef int64_t time_t;
typedef time_t* time_p;
namespace std {
typedef int64_t ptrdiff_t;
};
using std::ptrdiff_t;
typedef uint32_t mode_t;
typedef uint64_t size_t;
typedef uint64_t* size_p;
typedef int64_t ssize_t;
typedef signed int __int32_t;
typedef signed long int __int64_t;
typedef signed short int __int16_t;
typedef uint64_t __fsid_t;
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
struct timeval
{
  time_t tv_sec;
  int64_t tv_nsec;
};
struct timespec
{
  time_t tv_sec;
  int64_t tv_nsec;
};
enum ftype_t {
	DT_UNKNOWN = 0,
	DT_FIFO = 1,
	DT_CHR = 2,
	DT_DIR = 4,
	DT_BLK = 6,
	DT_REG = 8,
	DT_LNK = 10,
	DT_SOCK = 12,
	DT_WHT = 14
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
struct iovec {
	void  *iov_base;
	size_t iov_len;
};

typedef timespec* timespec_p;

#define NULL nullptr
//#define offsetof(type, field)	((long) &((type *)0)->field)
#define offsetof(TYPE, MEMBER) __builtin_offsetof (TYPE, MEMBER)

#endif

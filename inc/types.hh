#ifndef types_hh
#define types_hh types_hh

typedef __int128_t int128_t;
typedef __uint128_t uint128_t;
#include "wrap.hh"

typedef char* ostr_t;
typedef const char* istr_t;
typedef istr_t istr_v[];
typedef istr_t *istr_p;
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
typedef long int __fd_mask;
namespace sys {
  struct fdset_t;
  typedef fdset_t* fdset_p;
};
//   {
//     __fd_mask fds_bits[1024 / (8 * (int) sizeof (__fd_mask))];
//   };

struct sigaction_t {
	void (*sa_handler) (int);
	unsigned long sa_flags;
	void (*sa_restorer) (void);
	unsigned sa_mask[2];
};
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
typedef sigaction_t* sigaction_p;
typedef uint64_t sigset_t;
typedef sigset_t *sigset_p;
struct iovec;
typedef iovec* iovec_p;
struct timeval;
typedef timeval timeval_t;
typedef timeval_t* timeval_p;
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
struct utsname
{
  char sysname[65];
  char nodename[65];
  char release[65];
  char version[65];
  char machine[65];
  char domainname[65];
};
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
typedef linux_dirent linux_dirent64;
typedef linux_dirent64* linux_dirent64_p;
struct sigevent;
typedef sigevent* sigevent_p;
typedef void *timer_t;
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
struct statfs_t;
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
struct stat_t;
struct pollfd;
typedef pollfd* pollfd_p;
typedef stat_t * stat_p;
typedef iocb* iocb_p;
typedef cap_user_header* cap_user_header_t;
typedef int mqd_t;
typedef cap_user_data* cap_user_data_t;
typedef sysinfo* sysinfo_p;
typedef statfs_t* statfs_p;
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
typedef int64_t intptr_t;
typedef uint64_t uintptr_t;
typedef int64_t off64_t;
//   typedef uint32_t fd_t;
namespace sys {
  typedef fd_t* fd_p;
  struct pollfd_t {
    fd_t   fd;
    short events;
    short revents;
  };
}
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
typedef uint64_t* size_p;
namespace std {
typedef uint64_t size_t;
typedef int64_t ssize_t;
}
using std::ssize_t;
using std::size_t;
typedef uint64_t ino64_t;
struct timeval
{
  time_t tv_sec;
  int64_t tv_usec;
};
struct timespec
{
  time_t tv_sec;
  int64_t tv_nsec;
};
typedef timespec timespec_t;
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
class linux_dirent {
	ino64_t        d_ino;    /* 64-bit inode number */
	off64_t        d_off;    /* 64-bit offset to next structure */
	unsigned short d_reclen; /* Size of this dirent */
	char           d_name[]; /* Filename (null-terminated) */
  public:
  ino64_t ino() const {
    return d_ino;
  };
  unsigned short reclen() const {
    return d_reclen;
  };
  const char *name() const {
    return d_name;
  };
  int type() const {
    return (((char*)this)+reclen())[-1];
  };
};
namespace fmt {
  struct fmt_t;
};
struct iovec {
	const void  *iov_base;
	size_t iov_len;
  iovec()
    : iov_base(0), iov_len(0)
  {
  };
  iovec(const void *iov_base, size_t iov_len=-1)
    : iov_base((void*)iov_base), iov_len(iov_len)
  {
    if(iov_len>=0)
      return;
    const char *beg=(const char *)iov_base;
    const char *end=beg;
    while(*end)
      ++end;
    iov_len=end-beg;
  };
  template<class val_t>
  static iovec mk_iov(val_t *beg, val_t *end) {
    return iovec((void*)beg, (end-beg)*sizeof(val_t));
  };
};

typedef timespec* timespec_p;

#ifndef NULL
#define NULL nullptr
#endif
//#define offsetof(type, field)	((long) &((type *)0)->field)
#define offsetof(TYPE, MEMBER) __builtin_offsetof (TYPE, MEMBER)

#endif

#include "c_str.hh"

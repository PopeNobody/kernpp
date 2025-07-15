#include "syscall.hh"
#include "vpipe.hh"
#include <fmt.hh>
constexpr  static  int  TCGETS       =  0x5401;
constexpr  static  int  TCSETS       =  0x5402;
constexpr  static  int  TCSETSW      =  0x5403;
constexpr  static  int  TIOCGRANTPT  =  0x5403;
constexpr  static  int  TIOCGWINSZ   =  0x5413;
constexpr  static  int  TIOCNOTTY    =  0x5422;
constexpr  static  int  TIOCSWINSZ   =  0x5414;
constexpr  static  int  TIOCGPTPEER  =  0x5441;
constexpr  static  int  TIOCSPTLCK   =  0x40045431;
namespace sys {
  static collect::bitset_t<128> transient = {
    EINTR,
    EAGAIN,
    EWOULDBLOCK,
  };
  inline bool err_retry_on_transient(errno_t err) {
    return transient.is_set(err);
  }
  void err_die_if_stdin_tty(sys::errno_t err) {
    if(isatty(0))
      pexit(3,"stdin is a tty, but can't open /dev/tty");
  }
  fd_t openpt(int flags, errhand_t) {
    return (fd_t)open("/dev/ptmx",o_rdwr,err_log);
  };
  int unlockpt(fd_t fd,bool ilock,errhand_t hand) {
    uint64_t lock=!ilock;
    return ioctl(fd,TIOCSPTLCK,uint64_t(&lock),hand)<0 ? -1 : 0;
  };
  int grantpt(fd_t fd,errhand_t hand) {
    return ioctl(fd,TIOCGRANTPT,0);
  };
  fd_t getpt_peer(fd_t fd,open_flags flags,errhand_t hand) {
    fd_t res=ioctl(fd,TIOCGPTPEER,flags,hand);
    return res;
  };
  void drop_ctty(fd_t fd, errhand_t hand){
    fd_t res=ioctl(fd,TIOCNOTTY,0,hand);
  };
};
using fmt::fmt_t;
using sys::write;
//   normal:
//   00000000: 0045 0000 0500 0000 bf00 0000 3b8a 0000  .E..........;...
//   00000010: 0003 1c7f 1504 0001 0011 131a 0012 0f17  ................
//   00000020: 1600 0000 0000 0000 0000 0000 0000 0000  ................
//   00000030: 0000 0000 0f00 0000 0f00 0000            ............

typedef unsigned char cc_t;
typedef unsigned int speed_t;
typedef unsigned int tcflag_t;

struct termios {
  tcflag_t c_iflag;
  tcflag_t c_oflag;
  tcflag_t c_cflag;
  tcflag_t c_lflag;
  cc_t c_line;
  cc_t c_cc[32];
  speed_t c_ispeed;
  speed_t c_ospeed;
};
union trans_t {
  uint32_t uints[32];
  struct termios data;
};
trans_t sane = {
  { 
    0x0045, 0x0000, 0x0500, 0x0000, 0xbf00, 0x0000, 0x3b8a, 0x0000,
    0x0003, 0x1c7f, 0x1504, 0x0001, 0x0011, 0x131a, 0x0012, 0x0f17,
    0x1600, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
    0x0000, 0x0000, 0x0f00, 0x0000, 0x0f00, 0x0000, 
  }
};

int vpipe::term_set_sane(fd_t fd) {
  trans_t before;
  sys::ioctl(fd,TCGETS,(uint64_t)&before.data);
  for(int i=0;i<32;i++){
    write(1,fmt::fmt_t(before.uints[i]));
  };
  int res= sys::ioctl(fd,TCSETSW,(uint64_t)&sane.data);
  sys::ioctl(fd,TCGETS,(uint64_t)&before.data);
  for(int i=0;i<32;i++){
    write(1,fmt::fmt_t(before.uints[i]));
  };
  return res;
};
void dump_trans(const trans_t &data)
{
  sys::write(1,"\r\n");
  for(int i=0;i<32;i++){
    write(1,fmt::fmt_t(data.uints[i],16,8));
    if((i+1)%8)
      continue;
    sys::write(1,"\r\nXXX\r\n");
    sys::write(1,"\r\n");
  };
};
int system(const char *cmd) {
  char bash[]="/bin/bash";
  char flag[]="-c";
  char *argv[] = {
    bash, flag, (char*)cmd, 0
  };
  int status;
  pid_t pid=sys::fork();
  if(pid) {
    pid_t kid=sys::waitpid(pid,&status,0);
    using sys::write;
    write(1,"\r\n");
    write(1,fmt_t(pid));
    write(1," returned ");
    write(1,fmt_t(status));
    write(1,"\r\n");
  } else {
    sys::execve(argv[0],(char*const*)argv,0);
    sys::pexit(2,"execve");
  };
  return status;
};
//   RAW:
//   00000000: 0040 0000 0400 0000 bf00 0000 300a 0000  .@..........0...
//   00000010: 0003 1c7f 1504 0001 0011 131a 0012 0f17  ................
//   00000020: 1600 0000 0000 0000 0000 0000 0000 0000  ................
//   00000030: 0000 0000 0f00 0000 0f00 0000            ............

int vpipe::term_set_raw(fd_t fd) {
  const trans_t raw = {
    {
      0x0040, 0x0000, 0x0400, 0x0000, 0xbf00, 0x0000, 0x300a, 0x0000,
      0x0003, 0x1c7f, 0x1504, 0x0001, 0x0011, 0x131a, 0x0012, 0x0f17,
      0x1600, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
      0x0000, 0x0000, 0x0f00, 0x0000, 0x0f00, 0x0000, 
    }
  };
  int res= sys::ioctl(fd,TCSETS,(uint64_t)&raw.data);
  return res;
};
struct winsize_t {
  unsigned short ws_row;
  unsigned short ws_col;
  unsigned short ws_xpixel;   /* unused */
  unsigned short ws_ypixel;   /* unused */
};
static winsize_t winsize;
int vpipe::get_term_size(fd_t fd, uint16_t &ws_row, uint16_t &ws_col){
  int res = sys::ioctl(fd,TIOCGWINSZ,(uint64_t)&winsize);
  if(res<0)
    sys::pexit(3,"ioctl");
  ws_row=winsize.ws_row;
  ws_col=winsize.ws_col;
  return res;
};
bool sys::isatty(fd_t fd) {
  using enum sys::errno_t;
  uint16_t r,c;
  if(vpipe::get_term_size(fd,r,c)){
    using sys::errno;
    if(errno!=EBADF)
      errno=ENOTTY;
    return 0;
  } else {
    return 1;
  };
};
int vpipe::set_term_size(fd_t fd, uint16_t ws_row, uint16_t ws_col){
  winsize.ws_row=ws_row;
  winsize.ws_col=ws_col;
  int res = sys::ioctl(fd,TIOCSWINSZ,(uint64_t)&winsize);
  if(res<0)
    sys::pexit(3,"ioctl");
  return res;
};

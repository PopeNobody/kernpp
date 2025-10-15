#include "syscall.hh"
#include "vpipe.hh"
#include <fmt.hh>
struct winsize_t {
  unsigned short ws_row;
  unsigned short ws_col;
  unsigned short ws_xpixel;   /* unused */
  unsigned short ws_ypixel;   /* unused */
};
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
namespace vpipe {
  using std::uint64_t;
  struct holder_t {
    termios ios;
    bool ok;
    holder_t()
      :ok(false)
    {
      for(int i=0;i<3;i++){
        if(sys::ioctl(i,TCGETS,uint64_t(&ios),sys::err_ignore)==0) {
          ok=true;
          return;
        };
      };
      memset(&ios,0,sizeof(ios));
    };
    ~holder_t()
    {
      restore();
    };
    int restore() {
      if(!ok)
        return 0;
      for(int i=0;i<3;i++){
        if(sys::ioctl(i,TCSETSW,uint64_t(&ios),sys::err_ignore)==0) {
          ok=true;
          return 0;
        };
      };
      return -1;
    };
  };
  holder_t holder;
}
int vpipe::term_set_sane(fd_t fd) {
  return holder.restore();
};
// void dump_trans(const trans_t &data)
// {
//   sys::write(1,"\r\n");
//   for(int i=0;i<32;i++){
//     write(1,fmt::fmt_t(data.uints[i],16,8));
//     if((i+1)%8)
//       continue;
//     sys::write(1,"\r\nXXX\r\n");
//     sys::write(1,"\r\n");
//   };
// };
namespace vpipe {
  void cfmakeraw(termios &t);
};
#define ICANON                            2
#define ECHO                              8
#define ISIG                              1
#define ICRNL                           256
#define INPCK                            16
#define ISTRIP                           32
#define OPOST                             1
#define VINTR                             0
#define VQUIT                             1
#define VERASE                            2
#define VKILL                             3
#define VEOF                              4
#define VTIME                             5
#define VMIN                              6
#define TCSANOW                           0
#define IEXTEN                        32768
#define BRKINT                            2
#define IXON                           1024
#define CS8                           48
extern "C" {
  int int_out(int val) {
    using fmt::int_t;
    int_t ival=val;
    fmt_t fmt(ival);
    return write(1,fmt);
  }
};
void vpipe::cfmakeraw(termios &t) {
    t.c_lflag &= ~(ECHO | ICANON | ISIG | IEXTEN);   // no echo, no canonical mode, no ^C/^Z/etc
    t.c_iflag &= ~(BRKINT | ICRNL | INPCK | ISTRIP | IXON); // no input translations or flow control
    t.c_oflag &= ~(OPOST);                          // raw output
    t.c_cflag |= (CS8);                             // 8-bit chars

    t.c_cc[VMIN]  = 1;  // return each byte
    t.c_cc[VTIME] = 0;  // no timeout
}
int vpipe::term_set_raw(fd_t fd) {
  termios raw = holder.ios;
  cfmakeraw(raw);
  return sys::ioctl(fd,TCSETSW,uint64_t(&raw),sys::err_ignore);

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

#include "syscall.hh"
#include "vpipe.hh"
constexpr static int TCGETS=0x5401;
constexpr static int TCSETS=0x5302;
constexpr static int TIOCGWINSZ=0x5413;
constexpr static int TIOCSWINSZ=0x5414;

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
trans_t cooked = {
  { 
    0x0045, 0x0000, 0x0500, 0x0000, 0xbf00, 0x0000, 0x3b8a, 0x0000,
    0x0003, 0x1c7f, 0x1504, 0x0001, 0x0011, 0x131a, 0x0012, 0x0f17,
    0x1600, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
    0x0000, 0x0000, 0x0f00, 0x0000, 0x0f00, 0x0000, 
  }
};

int term_set_cooked(int fd) {
  return sys::ioctl(fd,TCSETS,(uint64_t)&cooked.data);
};
trans_t raw = {
  {
    0x0040, 0x0000, 0x0400, 0x0000, 0xbf00, 0x0000, 0x300a, 0x0000,
    0x0003, 0x1c7f, 0x1504, 0x0001, 0x0011, 0x131a, 0x0012, 0x0f17,
    0x1600, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
    0x0000, 0x0000, 0x0f00, 0x0000, 0x0f00, 0x0000, 
  }
};
int term_set_raw(int fd) {
  return sys::ioctl(fd,TCSETS,(uint64_t)&raw.data);
};
//   RAW:
//   00000000: 0040 0000 0400 0000 bf00 0000 300a 0000  .@..........0...
//   00000010: 0003 1c7f 1504 0001 0011 131a 0012 0f17  ................
//   00000020: 1600 0000 0000 0000 0000 0000 0000 0000  ................
//   00000030: 0000 0000 0f00 0000 0f00 0000            ............

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
int vpipe::set_term_size(fd_t fd, uint16_t ws_row, uint16_t ws_col){
  winsize.ws_row=ws_row;
  winsize.ws_col=ws_col;
  int res = sys::ioctl(fd,TIOCSWINSZ,(uint64_t)&winsize);
  if(res<0)
    sys::pexit(3,"ioctl");
  return res;
};

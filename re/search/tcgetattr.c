#include <termios.h>
//   #ifdef __USE_XOPEN_EXTENDED
//   /* The next four functions all take a master pseudo-tty fd and
//      perform an operation on the associated slave:  */
//   
//   /* Chown the slave to the calling user.  */
//   extern int grantpt (int __fd) __THROW;
//   
//   /* Release an internal lock so the slave can be opened.
//      Call after grantpt().  */
//   extern int unlockpt (int __fd) __THROW;
//   
//   /* Return the pathname of the pseudo terminal slave associated with
//      the master FD is open on, or NULL on errors.
//      The returned storage is good until the next call to this function.  */
//   extern char *ptsname (int __fd) __THROW __wur;
//   #endif
#define _XOPEN_SOURCE
#define __USE_XOPEN_EXTENDED
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <sys/ioctl.h>

#define termios XXXXXXXXXX
#include <asm/termbits.h>
#undef termios

int dprintf(int, char*, ...);
void exit(int);
void perror(const char *func);

int find_tty() {
  for(int fd=0;fd<64;fd++) {
    if(isatty(fd))
      return fd;
  };
  dprintf(2,"no tty found");
  exit(1);
};
//   normal:
//
//   00000000: 0045 0000 0500 0000 bf00 0000 3b8a 0000  .E..........;...
//   00000010: 0003 1c7f 1504 0001 0011 131a 0012 0f17  ................
//   00000020: 1600 0000 0000 0000 0000 0000 0000 0000  ................
//   00000030: 0000 0000 0f00 0000 0f00 0000            ............
//   RAW:
//   00000000: 0040 0000 0400 0000 bf00 0000 300a 0000  .@..........0...
//   00000010: 0003 1c7f 1504 0001 0011 131a 0012 0f17  ................
//   00000020: 1600 0000 0000 0000 0000 0000 0000 0000  ................
//   00000030: 0000 0000 0f00 0000 0f00 0000            ............
//   typedef unsigned char cc_t;
//   typedef unsigned int speed_t;
//   typedef unsigned int tcflag_t;
//   struct termios
//     {
//       tcflag_t c_iflag;  4 bytes  4
//       tcflag_t c_oflag;  4 bytes  8
//       tcflag_t c_cflag;  4 bytes 12
//       tcflag_t c_lflag;  4 bytes 16
//       cc_t c_line;       1 byte  17
//       cc_t c_cc[32];    32 bytes 49
//       speed_t c_ispeed;  4 bytes 53
//       speed_t c_ospeed;  4 bytes 57
//   
//     };
struct termios data;
void save(const char *name){
  int of = open(name,O_WRONLY|O_TRUNC|O_CREAT,0644);
  if(of<0) {
    perror("open");
    exit(1);
  };
  char *b=(char*)&data;
  char *e=b+sizeof(data);
  while(b<e) {
    int res=write(of,b,e-b);
    if(res<=0) {
      perror("write");
      exit(1);
    };
    b+=res;
  };
  dprintf(2,"wrote %d bytes\n",sizeof(data));
};
#define str(x) (#x)
//constexpr static int TCSETS=0;
//constexpr static int TCGETS=0;
//constexpr static int TIOCGWINSZ=0;
//constexpr static int TIOCSWINSZ=0;
void pty() {
  int mfd=open("/dev/ptmx",O_RDWR|O_NOCTTY);
  int res=unlockpt(mfd);
  int sfd=ioctl(mfd,TIOCGPTPEER,O_RDWR|O_NOCTTY);
  dprintf(2,"mfd: %d\n", mfd);
  dprintf(2,"res: %d\n", res);
  dprintf(2,"sfd: %d\n", sfd);

};
int main(int, char**, char**) {
  int fd = find_tty();
  dprintf(2,"%-12s %16x\n",str(TIOCGPTPEER), TIOCGPTPEER);
  dprintf(2,"%-12s %16x\n",str(TCGETS),TCGETS);
  dprintf(2,"%-12s %16x\n",str(TCSETS),TCSETS);
  dprintf(2,"%-12s %16x\n",str(TCSETSW),TCSETSW);
  dprintf(2,"%-12s %16x\n",str(TIOCGWINSZ),TIOCGWINSZ);
  dprintf(2,"%-12s %16x\n",str(TIOCSWINSZ),TIOCSWINSZ);
  dprintf(2,"%-12s %16x\n",str(TIOCSPTLCK),TIOCSPTLCK);
  pty(); 
  tcgetattr(fd,&data);
  dprintf(2,"read term %s\n","data.bin");
  save("data.bin");
  dprintf(2,"set raw:  %s\n","data.raw");
  cfmakeraw(&data);
  save("data.raw");
  return 0;
}

/* gen_all_syscall_constants.c */

#define _POSIX_C_SOURCE 200000L
#include <stdio.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <string.h>
#include <termios.h>
#include <signal.h>
#include <sys/syscall.h>
#include <sys/socket.h>
#include <sys/stat.h>
#include <poll.h>
#include <sys/epoll.h>
#include <netinet/in.h>
#include <netinet/tcp.h>
#include <linux/if.h>
#include <linux/if_tun.h>
#include <linux/sockios.h>
#include <unistd.h>

struct pair {
  char tag[20];
  union {
    uint64_t val64[1];
    struct {
      uint32_t pad32[1];
      uint32_t val32[1];
    };
    struct {
      uint16_t pad16[3];
      uint16_t val16[1];
    };
    struct {
      uint8_t pad8[7];
      uint8_t val8[1];
    };
  };
};
// note:  this has to have the comma, which is weird, but
// sometimes it is a semicolon
#define P(name) { \
  #name, \
  {name} \
},
struct pair vals[] = {
#include "find_all_values_list.h"
};

size_t maxlen=0;
int display(const char *name, int64_t val){
  long res; 
  char buf[128];
  const char *fmt;
  size_t len=strlen(name);
  if(len>maxlen)
    maxlen=len;
  if(val<(1llU<<8)) 
    fmt="%s%-13s %18s"   "%3ld\n";
  else if(val<(1llU<<16)) 
    fmt="%s%-13s %16s"   "%5ld\n";
  else if(val<(1llU<<32)) 
    fmt="%s%-13s %11s"  "%10ld\n";
  else 
    fmt="%s%-13s %1s"   "%20ld\n";
  printf(fmt," ",name," ",val);
  return write(1,buf,res); 
};

int main() {

// note:  this has to have the semicolon, which is weird, but
// sometimes it is a comma

#define P(name) display(#name,(name));

#include "find_all_values_list.h"
 dprintf(2,"%10lu\n",maxlen);
  return 0;
}

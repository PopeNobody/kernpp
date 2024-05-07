#include "calls.hh"
#include "fd_set.hh"
#include "debug.hh"

#include <bitset>
#include <cstring>
#include <fcntl.h>
#include <functional>
#include <pty.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <sys/select.h>
#include <sys/signal.h>
#include <sys/wait.h>
#include <termios.h>
#include <unistd.h>

namespace x {
  extern fdset_t all_rfds;
  extern fdset_t all_wfds;
  extern int save_fd;
  extern void read_fd(int);
  inline ssize_t write_all(int src, const char *b, ssize_t size);
  inline ssize_t write_all(int src, const char *b, const char *e) {
    return write_all(src,b,e);
  };
  void new_input(int ifd);
  inline ssize_t write_full(int src, const char *b, ssize_t size) {
    ssize_t nw=0;
    while(nw<size){
      ssize_t tr=xwrite(src,b+nw,size-nw);
      nw+=tr;
    };
    return nw;
  };
  inline ssize_t write_full(int src, const char *b, const char *e) {
    return write_full(src,b,e);
  };
  void sigint(int sig);
  int dev_null();
  int try_connect(const char *path,handler_t hand);
  int try_connect(handler_t hand);
  void sig_announce(int sig);
  const addr_t &sim_addr();
};
using namespace x;



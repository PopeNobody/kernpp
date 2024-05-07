#ifndef calls_h
#define calls_h

#include <unistd.h>
#include <termios.h>
#include <boost/array.hpp>
#include <stdio.h>
#include <stdlib.h>
#include "hand.hh"
#include "addr.hh"

namespace x {
  using boost::array;
  void vlogf(const char *fmt, va_list list);
  void logf(const char *fmt, ...);
  int xbind(int fd, const addr_t &sun, handler_t hand=err_fail);
  int xclose(int fd, handler_t hand=err_fail);
  int xconnect(int fd, const addr_t &sun, handler_t hand=err_fail);
  int xconnect(int fd, const char *, handler_t hand=err_fail);
  int xlisten(int fd, int backlog, handler_t hand=err_fail);
  int xsocket(int af, int type, int prot, handler_t hand=err_fail);
  int xaccept(int listener, handler_t hand=err_fail);
  int xunlink(const char *path, handler_t hand=err_fail);
  int xtcgetattr(int fd, termios *ios, handler_t hand=err_fail);
  int xtcsetattr(int fd, int action, termios *ios, handler_t hand=err_fail);
  int xdup2(int, int, handler_t hand=err_fail);
  int xdup(int, handler_t hand=err_fail);
  int xpipe(int fds[], handler_t hand=err_fail);
  int xshutdown(int fd, bool read, bool write, handler_t hand=err_fail);
  ssize_t xread(int fd, char *buf,ssize_t bsize, handler_t hand=err_fail);
  ssize_t xwrite(int fd, const char *buf,ssize_t bsize, handler_t hand=err_fail);
  ssize_t xwrite(int fd, const char *buf,handler_t hand=err_fail);
  void pexit(const char *func);
  void resetterm(int, void *arg);
  int xopen(const char *path, int flags, handler_t hand=err_fail);
  int xopen(const char *path, int flags, int mode, handler_t hand=err_fail);
  void getterm();
  void fixterm(); 
}
#endif

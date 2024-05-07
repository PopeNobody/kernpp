#ifndef debug_hh
#define debug_hh debug_hh
#include <stdarg.h>
#include <stdio.h>
namespace x {
  extern int DEBUG;
  int vdebug(int fd, const char *fmt, va_list list);
  int debug(int fd, const char *fmt, ...) ;
}
#endif // debug_hh

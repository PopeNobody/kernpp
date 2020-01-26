#ifndef debug_hh
#define debug_hh debug_hh

#include <c_str.hh>
#include <fmt.hh>
#include <errno.h>

void _debug(const char *file, unsigned line, const char *name, fmt::hex_t val);
void _debug(const char *file, unsigned line, const char *name, size_t val );
void _debug(const char *file, unsigned line, const char *name, int val);
void _debug(const char *file, unsigned line, const char *name, const char *val );
void _debug(const char *file, unsigned line, const char *name, void *val );
void _debug(const char *file, unsigned line, const char *name, c_str val );
void _debug(const char *file, unsigned line, const char *name, time_t val );
#define debug(x) do{_debug(__FILE__,__LINE__, #x, x);}while(0)

#ifndef trace
#define trace() do{ ; } while(0)
#endif

namespace sys {
  typedef int errno_t;
  const c_str &strerror(errno_t err=errno);
  void perror(const c_str &msg1, const c_str &msg2);
  void pexit(const c_str &msg1, const c_str &msg2);
  void perror(const c_str &msg1);
  void pexit(const c_str &msg1);
  void do_warn_fail(
      const char *file, unsigned line, 
      bool res, const char *text,
      bool getbetter
      );
};

#define POS __FILE__,__LINE__

#define warnif(x) sys::do_warnif(POS,x,#x,true)
#define dieif(x) sys::do_warnif(POS,x,#x,true)

#define dieunless(x) dieif(!x)
#define warnunless(x) warnif(!x)


#endif

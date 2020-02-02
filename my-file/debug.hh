#ifndef debug_hh
#define debug_hh debug_hh

#include <c_str.hh>
#include <fmt.hh>

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

#endif

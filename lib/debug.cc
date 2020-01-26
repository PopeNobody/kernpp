#include <debug.hh>
#include <fmt.hh>
#include <write_buf.hh>

using fmt::fmt_t;
void _debug(const char *file, unsigned line, const char *name, c_str val) 
{
  write_buf<> buf(2);
  buf.put(file);
  buf.put(":");
  buf.fmt(line);
  buf.put(":");
  buf.put(name);
  buf.put("=\"");
  buf.put(val);
  buf.putln("\"");
};
void _debug(const char *file, unsigned line, const char *name, const char * val) 
{
  fmt_t linefmt(line);
  write_buf<> buf(2);
  buf.put(file);
  buf.put(":");
  buf.put(linefmt);
  buf.put(":");
  buf.put(name);
  buf.put("=\"");
  buf.put(val);
  buf.putln("\"");
};
void _debug(const char *file, unsigned line, const char *name, void *val) 
{
  fmt_t linefmt(line);
  write_buf<> buf(2);
  buf.put(file);
  buf.put(":");
  buf.put(linefmt);
  buf.put(":");
  buf.put(name);
  buf.put("=");
  buf.putln(fmt_t(val));
};
void _debug(const char *file, unsigned line, const char *name, int val) 
{
  fmt_t linefmt(line);
  write_buf<> buf(2);
  buf.put(file);
  buf.put(":");
  buf.put(linefmt);
  buf.put(":");
  buf.put(name);
  buf.put("=");
  buf.putln(fmt_t(val));
};
void _debug(const char *file, unsigned line, const char *name, size_t val) 
{
  fmt_t linefmt(line);
  write_buf<> buf(2);
  buf.put(file);
  buf.put(":");
  buf.put(linefmt);
  buf.put(":");
  buf.put(name);
  buf.put("=");
  buf.putln(fmt_t(val));
};
static time_t first=sys::time(0);
static time_t last=first;
void _debug(const char *file, unsigned line, const char *name, time_t val) 
{
  fmt_t linefmt(line);
  write_buf<> buf(2);
  buf.put(file);
  buf.put(":");
  buf.put(linefmt.get());
  buf.put(":");
  buf.put(c_str(name));
  buf.put("=");
  buf.fmt(val-first);
  buf.put(" -- ");
  buf.fmtln(val-last);
  last=val;
};

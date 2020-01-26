#include <debug.hh>
#include <fmt.hh>
#include <write_buf.hh>

using fmt::fmt_t;
namespace {
  write_buf<> get_buf(const char *file, unsigned line)
  {
    write_buf<> buf(2);
    buf.put(file);
    buf.put(c_str::colon);
    buf.fmt(line);
    buf.put(c_str::colon);
    return buf;
  };
};
void _debug(const char *file, unsigned line, const char *name, c_str val) 
{
  auto buf(get_buf(file,line));
  buf.put(name);
  buf.put("=\"");
  buf.put(val);
  buf.putln("\"");
};
void _debug(const char *file, unsigned line, const char *name, const char * val) 
{
  auto buf(get_buf(file,line));
  buf.put(name);
  buf.put("=\"");
  buf.put(val);
  buf.putln("\"");
};
void _debug(const char *file, unsigned line, const char *name, void *val) 
{
  auto buf(get_buf(file,line));
  buf.put(name);
  buf.put("=");
  buf.fmtln(val);
};
void _debug(const char *file, unsigned line, const char *name, int val) 
{
  auto buf(get_buf(file,line));
  buf.put(name);
  buf.put("=");
  buf.fmtln(val);
};
void _debug(const char *file, unsigned line, const char *name, size_t val) 
{
  auto buf(get_buf(file,line));
  buf.put(name);
  buf.put("=");
  buf.fmtln(val);
  buf.put(name);
  buf.put("=");
  buf.fmtln(val);
};
static time_t first=time(0);
static time_t last=first;
void _debug(const char *file, unsigned line, const char *name, time_t val) 
{
  auto buf(get_buf(file,line));
  buf.put(name);
  buf.put("=");
  buf.fmtln(val);
  buf.put(name);
  buf.put("=");
  buf.fmt(val-first);
  buf.put(" -- ");
  buf.fmtln(val-last);
  last=val;
};

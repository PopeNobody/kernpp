#include <errno.hh>
#include <write_buf.hh>

namespace sys {
  void perror(const c_str &msg)
  {
    static const c_str null;
    perror(null,msg);
  };
  void pexit(const c_str &msg)
  {
    perror(msg);
    exit(1);
  };
  const c_str &strerror(errno_t err){
    static const c_str msg("Unknown Error");
    return msg;
  };
  void perror(const c_str &msg1, const c_str &msg2)
  {
    write_buf<> buf(2);
    if(msg1) {
      buf.put(msg1);
      buf.put(":");
    };
    if(msg2) {
      buf.put(msg2);
      buf.put(":");
    };
    buf.putln(strerror(errno));
  };
  void pexit(const c_str &msg1, const c_str &msg2)
  {
    perror(msg1,msg2);
    exit(1);
  };
  void do_warn_fail(
      const char *file, unsigned line, 
      bool res, const char *msg, 
      bool getbetter
      )
  {
    {
      write_buf<> buf(2);
      buf.put(file);
      buf.put(c_str::colon);
      buf.fmt(line);
      buf.put(c_str::colon);
      buf.put(msg);
      buf.put(c_str::newline);
    };
    if(!getbetter)
      abort();
  };
};

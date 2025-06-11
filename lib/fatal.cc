#include <fatal.hh>
#include <error.hh>
#include <c_str.hh>
using err::pexit;
int fatal::open(const char *path, open_flags flags) {
  return fatal::open(path,flags,sys::o_default);
};
int fatal::open(const char *path, open_flags flags, open_mode mode) {
  int ifd = sys::open(path,sys::o_rdonly);
  if(ifd<0){
    buf_t<2048> buf = { "error: open: ", 0 };
    char *dst=algo::end(buf.buf);
    const char *src=path;
    algo::cpy(src,dst);
    pexit(3,buf.buf);
  }
  return 0;
}

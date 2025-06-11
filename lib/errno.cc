#include <errno.hh>
#include <syscall.hh>
#include <buf.hh>
#include <errno.hh>
#include <error.hh>
#include <c_str.hh>

namespace err {
  c_str null;
errno_t errno;
ssize_t set_errno(ssize_t err)
{
  if(err>=0)
    return err;
  asm("int3");
  {
    buf_ns::buf_t<80> buf(2);
    // XXX why is 11 a special case?
    if(err!=11)
      buf.println("setting error to=",-err);
    sys::sleep(5);
  };
  errno=(errno_t)-err;
  return -1;
}
void perror(const c_str &msg)
{
  perror(null,msg);
};
void perror(const c_str &msg1, const c_str &msg2)
{
  buf_ns::buf_t<256> buf(2);
  if(msg1) {
    buf.print(msg1);
    buf.print(":");
  };
  if(msg2) {
    buf.print(msg2);
    buf.print(":");
  };
  buf.println(strerror(errno));
};
void pexit(int, const c_str &msg1, const c_str &msg2)
{
  perror(msg1,msg2);
  sys::exit(1);
};
void pexit(int res, const c_str &msg)
{
  pexit(res,msg,0);
};
void pexit(int res) {
  pexit(res,0,0);
};
};

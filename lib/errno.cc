#include <errno.hh>
#include <syscall.hh>

namespace sys {
  void die(int res, cc_str msg1, cc_str msg2, cc_str msg3) {
    if(msg1.size())
      write(2,msg1);
    if(msg2.size())
      write(2,msg2);
    if(msg3.size())
      write(3,msg3);
    exit(res);
  };
  void pexit(int res, const c_str&msg1) {
    pexit(res,msg1,"");
  };
  void pexit(int res, const c_str&msg1, const c_str &msg2) {
    if(msg1.size())
      write(2,msg1);
    if(msg2.size())
      write(2,msg2);
    exit(res);
  }

  errno_t errno;
  void set_errno(errno_t val, errhand_t hand) {
    int lval=val;
    if(lval>=0 || uint64_t(lval) <=4095)
      return;
    errno=(errno_t)int(-lval);
    hand(errno); 
  };
  void set_errno(errno_t val) {
    set_errno(val,err_log);
  };
  void err_log(errno_t err) {
    fmt::buf_t<512> buf(2);
    buf.a_str(__PRETTY_FUNCTION__);
    buf.a_str(": errno=");
    buf.a_int(err,false);
    buf.a_str(": ");
    buf.a_str(strerror(errno));
    buf.a_str("\n");
    buf.write();
  };
  void err_ignore(errno_t err) {
//       write(2,__PRETTY_FUNCTION__);
//       write(2,": errno=");
//       write(2,fmt::fmt_t(err));
//       write(2,": ");
//       write(2,strerror(errno));
//       write(2,"\n");
  };
  using fmt::buf_t;
  void err_retry_on_trans_error(errno_t err) {
    buf_t<512> buf(2);
    buf.a_str(__PRETTY_FUNCTION__);
    buf.a_str(": errno=");
    buf.a_int(err,false);
    buf.a_str(": ");
    buf.a_str(strerror(errno));
    buf.a_str("\n");
  };
  void err_fatal(errno_t err) {
    buf_t<512> buf(2);
    buf.a_str(__PRETTY_FUNCTION__);
    buf.a_str(": errno=");
    buf.a_int(err,false);
    buf.a_str(": ");
    buf.a_str(strerror(errno));
    buf.a_str("\n");
    exit(1);
  };
  void perror(const c_str &msg1, const c_str &msg2)
  {
    if(msg1) {
      write(2,msg1);
      write(2,":");
    };
    if(msg2) {
      write(2,msg2);
      write(2,":");
    };
    write(2,strerror(errno));
  };
};

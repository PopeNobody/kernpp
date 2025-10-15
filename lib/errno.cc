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
    long lval=(long)val;
    if(lval>=0 || lval <=4095)
      return;
    hand(errno=val); 
  };
  void set_errno(errno_t val) {
    long lval=(long)val;
    if(lval>=0 || lval <=4095)
      return;
    errno=val; 
  };
  void err_log(errno_t err) {
    write(2,"errno=");
    c_str str=strerror(err);
    write(2,str);
    write(2,"\n");
  };
  void err_ignore(errno_t err) {
    write(2,"errno=");
    write(2,fmt::fmt_t(err));
    write(2,"\n");
  };
  void err_retry_on_trans_error(errno_t err) {
    write(2,"errno=");
    write(2,fmt::fmt_t(err));
    write(2,"\n");
  };
  void err_fatal(errno_t err) {
    write(2,"errno=");
    write(2,fmt::fmt_t(err));
    write(2,"\n");
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

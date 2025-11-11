#pragma once

#include "types.hh"
#include "errno_enum.hh"
#include "attrs.hh"

namespace str {
  struct c_str;
};
namespace sys {
  using str::c_str;
  using std::errno_t;

  extern std::errno_t errno;
  const c_str &strerror(std::errno_t err=errno);
  void perror(const c_str &msg1, const c_str &msg2);
  inline void perror(const char *msg1, const char *msg2) {
    perror(c_str(msg1),c_str(msg2));
  };
  inline void perror(const c_str &msg1) {
    perror(msg1,c_str());
  };
  inline void perror(const char *msg1) {
    perror(c_str(msg1),c_str());
  };


  void die(int res, const char *m1) NOR;
  void die(int res, const char *msg1, const char *msg2) NOR;
  void die(int res, const char *msg1, const char *msg2, const char *msg3)NOR;

  void die(const char *msg1, const char *msg2) NOR;
  void die(const char *msg1) NOR;
  typedef const c_str &cc_str; 
  void die(int res, cc_str msg1, cc_str msg2, cc_str msg3) NOR;
  inline void die(int res, const char *msg1, const char *msg2, const char *msg3) {
    die(res,c_str(msg1),c_str(msg2),c_str(msg3));
  };
  inline void die(int res, const char *msg1, const char *msg2){
    die(res,c_str(msg1),c_str(msg2),c_str());
  };
  inline void die(const char *msg1, const char *msg2) {
    die(1,c_str(msg1),c_str(msg2),c_str());
  };
  inline void die(const char *msg1) {
    die(1,c_str(msg1),c_str(),c_str());
  };
  
  void pexit(int res, const c_str&msg1, const c_str &msg2) NOR;
  void pexit(int res, const c_str&msg1) NOR;

  void pexit(int res, const char *msg1, const char *msg2) NOR;
  void pexit(const char *msg1, const char *msg2) NOR;
  void pexit(int res, const char *msg1) NOR;
  void pexit(const char *msg1) NOR;

  inline void pexit(int res, const char *msg1, const char *msg2) {
    pexit(res,c_str(msg1),c_str(msg2));
  };
  inline void pexit(int res, const char *msg1) {
    pexit(res,c_str(msg1));
  };
  inline void pexit(const char *msg1) {
    pexit(1,c_str(msg1));
  };
  inline void pexit(const char *msg1, const char *msg2) {
    pexit(2,c_str(msg1),c_str(msg2));
  };

  void die(int res, const char * msg1);
  void die(int res, const char * msg1, const char * msg2);
  void die(int res, const c_str &msg1);
  void die(int res, const c_str &msg1, const c_str &msg2);
  inline void die(const c_str &msg1) {
    die(99,msg1);
  };
  inline void die(const c_str &msg1, const c_str &msg2) {
    die(99,msg1,msg2);
  };
};
#include "c_str.hh"

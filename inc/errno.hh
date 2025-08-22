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
  const c_str strerror(std::errno_t err=errno);
  void perror(const char *msg1, const char *msg2);
  void perror(const char *msg1);


  void die(int res, const char *m1) NOR;
  void die(int res, const char *msg1, const char *msg2)NOR;
  void die(const char *msg1, const char *msg2)NOR;
  void die(const char *msg1);
  void pexit(int res, const char *msg1) NOR;
  void pexit(int res, const char *msg1, const char *msg2) NOR;
  
  void pexit(int res, const char *msg1, const char *msg2);
  void pexit(int res, const char *msg1);
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

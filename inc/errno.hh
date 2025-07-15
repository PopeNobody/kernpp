#pragma once

#include "types.hh"
#include "errno_enum.hh"

namespace str {
  struct c_str;
};
#include "attrs.hh"
namespace sys {
  using str::c_str;


  extern errno_t errno;
  const c_str strerror(errno_t err=errno);
  void perror(const c_str &msg1, const c_str &msg2);
  void perror(const c_str &msg1);


  void pexit(int res, const c_str &msg1, const c_str &msg2) NOR;
  void pexit(int res, const c_str &msg1, const c_str &msg2);
  void pexit(int res, const c_str &msg1) NOR;
  void pexit(int res, const c_str &msg1);
  void die(int res, const c_str &m1) NOR;
  void die(int res, const c_str &msg1);
  void die(int res, const c_str &msg1, const c_str &msg2)NOR;
  void die(int res, const c_str &msg1, const c_str &msg2);
//     inline void perror(const c_str &msg1, const c_str &msg2) {
//       perror(errno msg1,msg2);
//     };
//     inline void pexit(const c_str &msg1, const c_str &msg2) {
//       pexit(errno,msg1,msg2);
//     };
//     inline void perror(const c_str &msg1) {
//       c_str msg2;
//       perror(errno,msg1,msg2);
//     };
//     inline void pexit(const c_str &msg1) {
//       c_str msg2;
//       pexit(errno,msg1,msg2);
//     };
};
#include "attrs.hh"
#include "c_str.hh"

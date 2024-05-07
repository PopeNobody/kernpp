#pragma once
typedef unsigned long size_t;
typedef long ssize_t;

namespace x {
  [[noreturn]]
    bool err_fail(const char *func);
  [[noreturn]]
    void pexit(const char *func);
  bool err_ignore(const char *func);
  bool err_warn(const char *func);
  typedef decltype(err_fail) handler_t;
};

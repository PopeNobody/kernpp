#pragma once

typedef unsigned long size_t;

template<class _val_t,size_t _sz>
struct array {
  using val_t = _val_t;
  static constexpr size_t sz = _sz;
  val_t vals[sz];
};
template<size_t>
struct any_holder_t {
};
template<class val_t>
struct any_value {
  const char *tag;
  val_t val;  
};
constexpr size_t max_size=64;
using any_holder=any_holder_t<max_size>;

any_holder get_value(const char *name);

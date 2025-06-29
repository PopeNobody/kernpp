#pragma once

namespace test_ns {
template<class it>
class range_t {
  struct body_t {
    it beg;
    it end;
    body_t(it b, it e)
      : beg(b),end(e)
    {
    }
  };
  body_t body;
  range_t(it b, it e)
    : body(b,e)
  {
  }
};
template<class t,size_t n>
t *iend(t(&a)[n]) {
  return a+n;
}
template<class t,size_t n>
t *xend(t(&a)[n]) {
  return iend(a)-1;
}
template<class it, class vt>
it set(it l, it r, vt v)
{
  while(l<r)
    *l++=v;
  return l;
}
}

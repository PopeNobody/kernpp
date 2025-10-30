#include "c_str.hh"
#include "itr-ops.hh"
using str::c_str;
const c_str c_str::null_str="";
const c_str c_str::colon=":";
const c_str c_str::newline="\n";
using strong_ordering=std::strong_ordering;

strong_ordering str::cmp(size_t lhs, size_t rhs) {
  return (lhs-rhs)<=>0;
};

strong_ordering str::cmp(const c_str &lhs, const c_str &rhs)
{
  auto len=std::min(lhs.size(),rhs.size());
  for(int i=0;i<len;i++) {
    if(lhs[i]!=rhs[i])
      return lhs[i]<=>rhs[i];
  };
  return lhs.size()<=>rhs.size();
};

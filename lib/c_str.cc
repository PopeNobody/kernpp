#include <c_str.hh>

const char c_str::null_str[1]="";
const c_str c_str::colon=":";
const c_str c_str::newline="\n";

int c_str::cmp(size_t lhs, size_t rhs) {
  return lhs-rhs;
};
int c_str::cmp(const c_str &lhs, const c_str &rhs)
{
  int res = cmp(lhs.len(),rhs.len());
  if(!res)
    res=strncmp(lhs.beg,rhs.beg,lhs.len());
  return res;
};

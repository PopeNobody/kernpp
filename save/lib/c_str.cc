#include "c_str.hh"
#include "min.hh"
#include "itr-ops.hh"

using str::c_str;
//   bool std::lt(const c_str &lhs, const c_str &rhs) {
//     auto msize=std::min(lhs.size(),rhs.size());
//     for(auto i=0*msize;i<msize;i++){
//       if(lhs[i]!=rhs[i])
//         return lhs[i]<rhs[i]?true:false;
//     };
//     return lhs.size()<rhs.size();
//   };
str::c_str::c_str(char *b, char *e )
  :body(b,e)
{
  if(!body.beg)
    body.end=0;
  if(!body.end)
    body.end=body.beg+itr::len(body.beg);
};

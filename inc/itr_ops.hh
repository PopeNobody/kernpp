#pragma once
#include "template-glue.hh"
#include "c_str.hh"
namespace itr {
  using std::min;
	template<class dst_t, class val_t>
  inline dst_t fill(dst_t beg, dst_t end, val_t val){
    while(beg!=end)
      *beg++=val;
    return beg;
  };
  template<class dst_t, class src_t>
  inline dst_t rcopy_n(dst_t db, src_t sb,size_t n){
    db+=n;
    sb+=n;
    while(n--)
      *--db=*--sb;
    return db;
  };
  template<class dst_t, class src_t>
  inline dst_t fcopy_n(dst_t db, src_t sb,size_t n){
    while(n--)
      *db++=*sb++;
    return db;
  };
  template<class dst_t, class src_t>
  inline dst_t copy_n(dst_t db, src_t sb, size_t n){
    if(&*db<&*sb)
      return fcopy_n(db,sb,n);
    else
      return rcopy_n(db,sb,n);
  };
  template<class dst_t, class src_t>
  inline dst_t copy(dst_t db, dst_t de, src_t sb, src_t se)
  {
    return copy_n(db,sb,min(se-sb,de-db));
  };
  using str::c_str;
  char *copy(char *db, char *de, c_str str);
  template<class itr_t, class val_t>
    inline auto find_val(itr_t db, itr_t de, val_t val){
      while(db!=de)
        if(*db==val)
          break;
        else
          db++;
      return db;
    };
  template<class itr_t, class pred_t>
    inline auto find_pred(itr_t db, itr_t de, pred_t pred)
    {
      while(db!=de) {
        if(pred(*db))
          break;
      };
      return db;
    }
  inline size_t len(const char *beg, const char *end=0){
    size_t max=end?end-beg:size_t(-1);
    size_t i;
    for(i=0;beg[i];i++)
      ; // say nothing, act natural
    return i;
  };
};

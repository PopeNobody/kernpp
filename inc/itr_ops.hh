#pragma once
#include "template-glue.hh"
#include "c_str.hh"
namespace str {
  struct c_str;
};
namespace itr {
  using std::min;
	template<class dst_t, class val_t>
  inline dst_t fill(dst_t beg, dst_t end, val_t val){
    while(beg!=end)
      *beg++=val;
    return beg;
  };
  template<class dst_t, class src_t>
  inline dst_t rcopy_n(dst_t db, src_t sb,size_t N){
    size_t n(N);
    db+=n;
    *db=0;
    sb+=n;
    while(n--)
      *--db=*--sb;
    return db+N;
  };
  template<class dst_t, class src_t>
  inline dst_t fcopy_n(dst_t db, src_t sb,size_t n){
    while(n--)
      *db++=*sb++;
    return db;
  };
  void fuck_off(int res, const char *msg);
  template<class dst_t, class src_t>
  inline dst_t copy_n(dst_t db, src_t sb, size_t n){
    dst_t res;
    if(n>=0 && n<=4096) {
      if(&*db<&*sb)
        res= fcopy_n(db,sb,n);
      else
        res= rcopy_n(db,sb,n);
    } else {
      fuck_off(2,"fuck!\n");
    };
    return res;
  };
  template<class dst_t, class src_t>
  inline dst_t copy(dst_t db, dst_t de, src_t sb, src_t se)
  {
    return copy_n(db,sb,min(se-sb,de-db));
  };
  inline char *copy(char *db, char *de, void *sb, size_t sl)
  {
    return copy(db,de,(char*)sb,((char*)sb)+sl);
  };
  inline char *copy(char *db, char *de, str::c_str str);
  inline char *copy(char *db, char *de, iovec vec) {
    return copy(db,de,vec.iov_base,vec.iov_len);
  };
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
  inline int str_cmp(const char *lhs, const char *rhs)
  {
    while(*lhs && *rhs){
      if(*lhs!=*rhs)
        return (lhs>rhs?-1:1);
    };
    if(*lhs)
      return -1;
    if(*rhs)
      return 1;
    return 0;
  };
};

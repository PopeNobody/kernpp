#pragma once
#include "c_str.hh"
#include "min.hh"
namespace itr {
  char *copy(char *db, char *de, const str::c_str &str);
  char *copy(char *db, char *de, const fmt::fmt_t &str);
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
  template<class dst_t, class src_t>
  inline dst_t copy_n(dst_t db, src_t sb, size_t n){
    dst_t res;
    if(&*db<&*sb)
      res= fcopy_n(db,sb,n);
    else
      res= rcopy_n(db,sb,n);
    return res;
  };
  template<class dst_t, class src_t>
  inline dst_t copy(dst_t db, dst_t de, src_t sb)
  {
    src_t se(sb);
    while(*se)
      se++;
    return copy_n(db,sb,min(se-sb,de-db));
  };
  template<class dst_t, class src_t>
  inline dst_t copy(dst_t db, dst_t de, src_t sb, src_t se)
  {
    return copy_n(db,sb,std::min(se-sb,de-db));
  };
  template<class dst_t>
  inline dst_t copy(dst_t db, dst_t de, const char *sb)
  {
    const char *se=sb;
    while(*se)
      ++se;
    using std::min;
    return copy_n(db,sb,min(se-sb,de-db));
  };
  template<class dst_t, class src_t>
  inline char *copy(dst_t *db, dst_t *de, const src_t *sb, ssize_t sl)
  {
    return copy(db,de,(char*)sb,((char*)sb)+sl);
  };
  template<class val_t>
  inline char *copy(val_t *db, val_t *de, const void *sb, ssize_t sl)
  {
    return copy(db,de,(char*)sb,((char*)sb)+sl);
  };
  char *copy(char *db, char *de, const str::c_str &str);
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
      if(i==max)
        break;
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
  inline int str_cmp(const char *lhs, const char *rhs, size_t n) {
    for(size_t i=0;i<n;i++) {
      int del=lhs[i]-rhs[i];
      if(del)
        return del;
      if(lhs[i]==0)
        return 0;
    };
    return 0;
  };
};

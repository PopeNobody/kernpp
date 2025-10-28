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
  // Added: generic copy accepting arbitrary input and output iterators as template parameters.
  template<class OutputIt, class InputIt>
  OutputIt copy(OutputIt db, OutputIt de, InputIt sb, InputIt se) {
    // Copy from [sb,se), writing to db, as much as will fit in [db,de)
    for(; db != de && sb != se; ++db, ++sb) {
      *db = *sb;
    }
    return db;
  }
  // Added: generic copy accepting a range denoted by Input iterators, to output iterator with unknown end (like back_inserter).
  template<class OutputIt, class InputIt>
  OutputIt copy(OutputIt db, InputIt sb, InputIt se) {
    // Copy from [sb,se) to output iterator db
    for(; sb != se; ++db, ++sb) {
      *db = *sb;
    }
    return db;
  }
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
        ++db;
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
      ++lhs;
      ++rhs;
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

// Note: The two new copy overloads, using OutputIt/InputIt template parameters, make the copy function usable for copying from e.g. std::list<T>::iterator or any arbitrary input/output iterators, as requested.
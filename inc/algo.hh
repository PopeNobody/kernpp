#pragma once
namespace algo {
  template<class itr_t>
  inline size_t len(itr_t beg){
    itr_t pos=beg;
    for(;*pos;++pos)
      ;
    return pos-beg;
  };
  template<class itr_t>
  inline auto beg(itr_t beg){
    return beg;
  };
  template<class itr_t>
  inline auto end(itr_t beg){
    return algo::beg(beg)+len(beg);
  };
  template<class itr1_t,class itr2_t>
    inline auto cpy(itr1_t src, itr2_t dst) {
      while(*src)
        *dst++=*src++;
    };
  template<class itr1_t,class itr2_t>
    inline auto cpy(itr1_t src, itr1_t end, itr2_t dst) {
      while(src!=end)
        *dst++=*src++;
    };
  template<class val_t>
  inline val_t &min(val_t rhs, val_t lhs)
  {
    return rhs>lhs?lhs:rhs;
  }
  template<class itr_t, class val_t>
    inline itr_t set(itr_t beg, itr_t end, val_t val){
      while(*beg!=*end)
        *beg++=val;
      return beg;
    };
};

#pragma once
namespace collect {
  template<class T, size_t _N>
    struct array_t {
      using val_t=T;
      static constexpr size_t size=_N;
      val_t val[size];
      struct itr_t {
        array_t &arr;
        size_t pos=0;
        const val_t *get() const {
          return arr.val+pos;
        }
        val_t *get() {
          return arr.val+pos;
        }
        val_t &operator*(){
          return *get();
        };
        const val_t &operator*() const {
          return *get();
        };
        val_t *operator->() {
          return get();
        };
        const val_t *operator->() const {
          return get();
        };
        val_t &operator[](size_t idx){
          if(pos+idx>=size)
            sys::pexit(1,"overflow");
          return *(get()+idx);
        };
        const val_t &operator[](size_t idx) const{
          if(pos+idx>=size)
            sys::pexit(1,"overflow");
          return *(get()+idx);
        };
        itr_t(array_t &arr)
          : arr(arr),pos(0)
        {
        };
      };
    };
}

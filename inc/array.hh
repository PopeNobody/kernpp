#pragma once
#include "types.hh"
namespace collect {
  template<size_t _size>
    struct space_t {
      static constexpr size_t size=_size;
      typedef char data_t[size];
      space_t() {
        memset(this,0,sizeof(*this));
      };
    };
  template<class T, size_t S=sizeof(T)>
    struct slot_t : public space_t<S> {
      static constexpr size_t size=S;
      T *get();
      const T* get() const;
      template<class ... Args>
        T *init(Args ...args)
        {
        };
    };

  template<class T, size_t N, size_t S=sizeof(T)>
    struct array_t {
      typedef T val_t;
      static constexpr size_t size=N;
      typedef slot_t<val_t,S> slot_t;
      typedef slot_t data_t[N];
      struct body_t {
        data_t data;
        size_t off;
        size_t len;
        body_t()
          :off(0),len(0)
        {
        }
        slot_t &slot(size_t idx){
          xassert(idx<size);
          return data[idx];
        };
      };
      body_t body;
      array_t()
      {
      };
      size_t len() const {
        return body.len;
      }
      void push_back(const val_t &val)
      {
        assert(len()<N);
      };
    };
};

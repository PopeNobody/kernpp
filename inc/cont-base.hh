#pragma once

namespace cont {
  template<class T, size_t num=1>
    struct ptr_t {
      typedef T val_t;
      typedef const T val_T;
      typedef val_t *val_p;
      typedef val_t &val_r;
      typedef const val_t *val_P;
      typedef const val_t &val_R;
      val_p ptr=0;
      size_t size=0;
      ptr_t(val_p ptr=0)
        : ptr(ptr)
      {
      }
      ~ptr_t()
      {
        delete ptr;
      };
      val_R operator*() const {
        return *ptr;
      }
      val_P operator->() const {
        return *ptr;
      };
      val_r operator*() {
        return *ptr;
      }
      val_p operator->() {
        return *ptr;
      };
      val_r operator[](size_t idx) {
        assert(idx<size);
        return ptr[idx];
      };
    };
};

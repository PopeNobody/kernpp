#pragma once
#include "syscall.hh"
namespace std {
  typedef unsigned long size_t;
  typedef long ssize_t;

  template<class T>
    void swap(T &t1, T&t2)
    {
      T t3(t1);
      t1=t2;
      t2=t3;
    };
  template<class T>
    T &max(T &t1) {
      return t1;
    };
  template<class T>
    T &max(T &t1, T &t2) {
      return (t1<t2?t2:t1);
    };
  template<class T>
    T &max(T &t1, T &t2, T &t3) {
      return max(t1,max(t2,t3));
    };
  template<class T>
    const T &max(const T &t1) {
      return t1;
    };
  template<class T>
    const T &max(const T &t1, const T &t2) {
      return (t1<t2?t2:t1);
    };
  template<class T>
    const T &max(const T &t1, const T &t2, const T &t3) {
      return max(t1,max(t2,t3));
    };
};
namespace cont {
  using std::swap;
  using std::max;
  using std::size_t;

  template<class T>
    struct value_t
    {
      typedef T val_t;
      typedef const T val_T;
      typedef T *val_p;
      typedef const T *val_P;
      typedef T &val_r;
      typedef const T &val_R;
    };
  template<class T>
    struct array_t : public value_t<T>
    {
      typedef T val_t;
      typedef const T val_T;
      typedef T *val_p;
      typedef const T *val_P;
      typedef T &val_r;
      typedef const T &val_R;
      const size_t cap;
      size_t len;
      val_t arr[];
      val_P get(size_t idx=0) const {
        return arr+idx;
      };
      val_p get(size_t idx=0) {
        return arr+idx;
      };
      static array_t<T> *mk_arr(size_t cap, size_t len = 0, const T *b = nullptr, const T *e = nullptr)
      {
        // Allocates an array_t<T> with capacity 'cap' and optionally fills
        // in elements from b to e (if provided), up to len.
        assert(cap < (1<<20));
        const size_t size = sizeof(array_t<T>) + cap * sizeof(T);
        char *chars = new char[size];
        memset(chars, 0, size);
        array_t<T> *res = (array_t<T>*)chars;
        ((size_t&)res->cap) = cap;
        res->len = len > cap ? cap : len;
        if (b && e) {
          size_t n = std::min((size_t)(e-b), res->len);
          for (size_t i=0; i<n; ++i)
            res->arr[i] = b[i];
          for (size_t i=n; i<res->len; ++i)
            res->arr[i] = T();
        } else {
          for (size_t i=0; i<res->len; ++i)
            res->arr[i] = T();
        }
        return res;
      }
    };
  template<class T>
    struct vector_t : public value_t<T>
    {
      typedef value_t<T>::val_t val_t;
      typedef value_t<T>::val_p val_p;
      typedef value_t<T>::val_r val_r;
      typedef value_t<T>::val_T val_T;
      typedef value_t<T>::val_P val_P;
      typedef value_t<T>::val_R val_R;
      typedef array_t<T> body_t;
      body_t *arr;
      static array_t<T> *mk_arr(size_t cap, size_t len = 0, const T *b = nullptr, const T *e = nullptr)
      {
        return array_t<T>::mk_arr(cap, len, b, e);
      };
      template<class itr_t>
      static array_t<T> *mk_arr(size_t cap, itr_t b, itr_t e)
      {
        // In this variant, cap=0 means we want to match the size (e-b)
        size_t req = e > b ? size_t(e-b) : 0;
        if (cap < req) cap = req;
        return mk_arr(cap, req, b, e);
      };
      void ensure_cap(size_t cap)
      {
        if(cap<=arr->cap)
          return;
        body_t *tmp=arr;
        arr=mk_arr(cap,beg(),end());
        delete tmp;
      };
      void swap(vector_t &rhs)
      {
        std::swap(arr,rhs.arr);
      };
      vector_t()
        :arr(mk_arr(0,(T*)0,(T*)0))
      {
      };
      template<class itr_t>
      vector_t(const itr_t &b, const itr_t &e)
        :arr(mk_arr(0,b,e))
      {
      };
      vector_t(size_t size)
        :arr(mk_arr(size))
      {
      };
      val_t &operator[](size_t n)
      {
        assert(n<len());
        return *get(n);
      };
      const val_t &operator[](size_t n) const
      {
        assert(n<len());
        return beg()[n];
      };
      size_t cap() const {
        return arr->cap;
      };
      size_t len() const {
        return arr->len;
      };
      const val_P get(size_t idx) const {
        assert(idx<(2<<20));
        return arr->arr+idx;
      };
      const val_p get(size_t idx) {
        assert(idx<(2<<20));
        return arr->arr+idx;
      };
      const val_t *beg() const {
        return get(0);
      };
      const val_t *end() const {
        return get(len());
      };
      void push_back(val_R obj)
      {
        ensure_cap(len()+1);
        arr->arr[arr->len++]=obj;
      };
    };
}

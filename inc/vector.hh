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
    };
//     template<class T>
//       struct arrhold_t : public value_t<T>
//     {
//       typedef T val_t;
//       typedef const T val_T;
//       typedef T *val_p;
//       typedef const T *val_P;
//       typedef T &val_r;
//       typedef const T &val_R;
//       typedef array_t<T> arr_t;
//       typedef array_t<T> *arr_p;
//       typedef const array_t<T> arr_T;
//       typedef const array_t<T> *arr_P;
//       arr_p arr;
//       arrhold_t(size_t cap)
//         : arr(array_t<T>::mk_arr(cap))
//       {
//       };
//       arrhold_t(array_t<T> *val)
//         :arr(val)
//       {
//       };
//       arrhold_t(arrhold_t &rhs)
//         : arr(rhs.arr)
//       {
//       };
//       operator bool() const {
//         return !!arr;
//       };
//       void ensure_cap(size_t cap)
//       {
//         if(arr->cap>=cap)
//           return;
//         arrhold_t copy(cap);
//       };
//       arr_p operator->() {
//         return arr;
//       };
//       arr_P operator->() const {
//         return arr;
//       };
//       val_p get(size_t pos=0) {
//         return arr->get(pos);
//       };
//       val_P get(size_t pos=0) const {
//         return arr->get(pos);
//       };
//     };
  template<class T>
    struct vector_t : public value_t<T>
    {
      typedef value_t<T>::val_t val_t;
      typedef value_t<T>::val_p val_p;
      typedef value_t<T>::val_r val_r;
      typedef value_t<T>::val_T val_T;
      typedef value_t<T>::val_P val_P;
      typedef value_t<T>::val_R val_R;
//         typedef array_t<T> arr_t;
      typedef array_t<T> body_t;
      body_t *arr;
      static array_t<T> *mk_arr(size_t cap)
      {
        assert(cap<(1<<20));
        const size_t size=sizeof(array_t<T>)+cap*sizeof(T);
        char *chars=new char[size];
        memset(chars,0,size);
        array_t<T> *res = (array_t<T>*)chars;
        ((size_t&)res->cap)=cap;
        res->len=0;
        return res;
      };
      template<class itr_t>
      static array_t<T> *mk_arr(size_t cap, itr_t b, itr_t e)
      {
        array_t<T> *res = mk_arr(cap);
        cap=cap?cap:1;
        cap=cap+31;
        cap-=cap%32;
        itr_t p(b);
        while(p!=e)
          res->arr[res->len++]=(T)*p++;
        size_t len=e-b;
        while(res->len < len)
          res->arr[res->len++]=T();
        return res;
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
        :arr(mk_arr(e-b,b,e))
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

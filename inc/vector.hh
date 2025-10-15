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
      static array_t *mk_arr(size_t cap, size_t len=0, T *beg=0, T *end=0)
      {
        const size_t size=sizeof(array_t)+cap*sizeof(T);
        char *chars=new char[size];
        memset(chars,-1,size);
        array_t *res = (array_t*)chars;
        ((size_t&)res->cap)=cap;
        res->len=0;
        while(beg!=end)
          res->arr[res->len++]=*beg++;
        while(res->len < len)
          res->arr[res->len++]=T();
        return res;
      };
    };
  template<class T>
    struct arrhold_t : public value_t<T>
  {
    typedef T val_t;
    typedef const T val_T;
    typedef T *val_p;
    typedef const T *val_P;
    typedef T &val_r;
    typedef const T &val_R;
    typedef array_t<T> arr_t;
    typedef array_t<T> *arr_p;
    typedef const array_t<T> arr_T;
    typedef const array_t<T> *arr_P;
    arr_p arr;
    arrhold_t(arr_p arr=0)
      : arr(arr)
    {
    };
    arrhold_t(arrhold_t &rhs)
      : arr(rhs.arr)
    {
    };
    operator bool() const {
      return !!arr;
    };
    static arrhold_t mk_arr(size_t cap, size_t len=0, T *beg=0, T *end=0)
    {
      arrhold_t arr;
      arr=array_t<T>::mk_array(cap,len,beg,end);
      return arr;
    };
    void ensure_cap(size_t cap)
    {
      if(arr->cap>=cap)
        return;
    };
    arr_p operator->() {
      return arr;
    };
    arr_P operator->() const {
      return arr;
    };
    val_p get(size_t pos=0) {
      return arr->get(pos);
    };
    val_P get(size_t pos=0) const {
      return arr->get(pos);
    };
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
//         typedef array_t<T> arr_t;
      typedef arrhold_t<T> arr_t;
      arr_t arr;
      void ensure_cap(size_t cap)
      {
        arr.ensure_cap(cap);
      };
      void swap(vector_t &rhs)
      {
        std::swap(arr,rhs.arr);
      };
      vector_t()
      {
      };
      template<class oval_p>
      vector_t(oval_p b, oval_p e)
      : arr(e-b)
      {
        arr.ensure(e-b); 
        while(b!=e) {
          push_back(*b++);
        };
      };
      vector_t(size_t size)
      {
        ensure_cap(size);
      };
      template<class oval_p>
      vector_t(size_t size, oval_p b, oval_p e)
      {
        ensure_cap(size);
        while(b!=e)
          push_back(*b++);
      };
      val_t &operator[](size_t n)
      {
        assert(n<len());
        return beg()[n];
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
      const val_t *beg() const {
        return arr.get();
      };
      const val_t *end() const {
        return arr.get()+len();
      };
      val_t *beg() {
        return arr.get();
      };
      val_t *end() {
        return beg()+len();
      };
      val_r &back() {
        return beg()[len()-1];
      };
      void push_back(val_R obj)
      {
        ensure_cap(len()+1);
        back()=obj;
      };
      val_p get(size_t pos=0) {
        return arr.get()+pos;
      };
      val_P get(size_t pos=0) const {
        return arr.get()+pos;
      };
    };
}

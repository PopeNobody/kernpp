#pragma once
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
    struct vector_t
    {
      typedef T val_t;
      typedef const T val_T;
      typedef val_t *val_p;
      typedef const val_t *val_P;
      typedef val_t &val_r;
      typedef const val_t &val_R;
      struct ptr_t {
        val_p arr=0;
        size_t len=0;
        size_t size=0;
        ptr_t(val_p arr=0)
          :arr(arr)
        {
        }
        ~ptr_t()
        {
          delete arr;
        };
        val_p get() {
          return arr;
        };
        val_P get() const {
          return arr;
        };
      };
      ptr_t ptr;
      void ensure(size_t new_size)
      {
        if(new_size<=size())
          return;
        vector_t vec(new_size,beg(),end());
        swap(vec);
      }
      void swap(vector_t &rhs)
      {
        std::swap(ptr,rhs.ptr);
      };
      vector_t()
      {
      };
      template<class oval_p>
      vector_t(oval_p b, oval_p e)
      {
        ensure(e-b); 
        while(b!=e) {
          push_back(*b++);
        };
      };
      template<class oval_p>
      vector_t(size_t size, oval_p b, oval_p e)
      {
        ensure(size); 
        while(b!=e) {
          push_back(*b++);
        };
      };
      val_t &operator[](size_t n)
      {
        assert(n<size());
        return beg()[n];
      };
      const val_t &operator[](size_t n) const
      {
        assert(n<size());
        return beg()[n];
      };
      size_t size() const {
        return ptr.size;
      };
      size_t len() const {
        return ptr.len;
      };
      const val_t *beg() const {
        return ptr.get();
      };
      const val_t *end() const {
        return ptr.get()+len();
      };
      val_t *beg() {
        return ptr.get();
      };
      val_t *end() {
        return beg()+len();
      };
      val_r &back() {
        return end()[-1];
      };
      void push_back(val_R obj)
      {
        ensure(len()+1);
        back()=obj;
      };
    };
}

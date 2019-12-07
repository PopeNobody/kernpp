#ifndef array_hpp
#define array_hpp array_hpp

  template<bool, typename _Tp = void>
    struct enable_if
    { };


  template<typename _Tp>
    struct enable_if<true, _Tp>
    { typedef _Tp type; };

  void
  __throw_out_of_range_fmt(const char*, ...) __attribute__((__noreturn__))
    __attribute__((__format__(__gnu_printf__, 1, 2)));
//   namespace mincpp 
//   {

  template<typename _Tp, _Tp __v>
    struct integral_constant
    {
      static constexpr _Tp value = __v;
      typedef _Tp value_type;
      typedef integral_constant<_Tp, __v> type;
      constexpr operator value_type() const noexcept { return value; }




      constexpr value_type operator()() const noexcept { return value; }

    };

  template<typename _Tp, _Tp __v>
    constexpr _Tp integral_constant<_Tp, __v>::value;


  typedef integral_constant<bool, true> true_type;


  typedef integral_constant<bool, false> false_type;

  template<bool __v>
    using __bool_constant = integral_constant<bool, __v>;

     template<typename _Tp, size_t _Nm>
       struct __array_traits
       {
         typedef _Tp _Type[_Nm];
         //typedef __is_swappable<_Tp> _Is_swappable;
         //typedef __is_nothrow_swappable<_Tp> _Is_nothrow_swappable;
   
         static constexpr _Tp&
         _S_ref(const _Type& __t, size_t __n) noexcept
         { return const_cast<_Tp&>(__t[__n]); }
   
         static constexpr _Tp*
         _S_ptr(const _Type& __t) noexcept
         { return const_cast<_Tp*>(__t); }
       };
   
    template<typename _Tp>
      struct __array_traits<_Tp, 0>
      {
        struct _Type { };
        typedef true_type _Is_swappable;
        typedef true_type _Is_nothrow_swappable;
   
        static constexpr _Tp&
        _S_ref(const _Type&, size_t) noexcept
        { return *static_cast<_Tp*>(nullptr); }
   
        static constexpr _Tp*
        _S_ptr(const _Type&) noexcept
        { return nullptr; }
      };
  template<typename _Tp, size_t _Nm>
    struct array
    {
      typedef _Tp value_type;
      typedef value_type* pointer;
      typedef const value_type* const_pointer;
      typedef value_type& reference;
      typedef const value_type& const_reference;
      typedef value_type* iterator;
      typedef const value_type* const_iterator;
      typedef size_t size_type;
      typedef ptrdiff_t difference_type;
//         typedef reverse_iterator<iterator> reverse_iterator;
//         typedef reverse_iterator<const_iterator> const_reverse_iterator;


      typedef __array_traits<_Tp, _Nm> _AT_Type;
      typename _AT_Type::_Type _M_elems;




      void
      fill(const value_type& __u)
      { fill_n(begin(), size(), __u); }

      void
      swap(array& __other)
      noexcept(_AT_Type::_Is_nothrow_swappable::value)
      { swap_ranges(begin(), end(), __other.begin()); }


      iterator
      begin() noexcept
      { return iterator(data()); }

      const_iterator
      begin() const noexcept
      { return const_iterator(data()); }

      iterator
      end() noexcept
      { return iterator(data() + _Nm); }

      const_iterator
      end() const noexcept
      { return const_iterator(data() + _Nm); }

//         reverse_iterator
//         rbegin() noexcept
//         { return reverse_iterator(end()); }
//   
//         const_reverse_iterator
//         rbegin() const noexcept
//         { return const_reverse_iterator(end()); }

//         reverse_iterator
//         rend() noexcept
//         { return reverse_iterator(begin()); }
//   
//         const_reverse_iterator
//         rend() const noexcept
//         { return const_reverse_iterator(begin()); }

      const_iterator
      cbegin() const noexcept
      { return const_iterator(data()); }

      const_iterator
      cend() const noexcept
      { return const_iterator(data() + _Nm); }

//         const_reverse_iterator
//         crbegin() const noexcept
//         { return const_reverse_iterator(end()); }
//   
//         const_reverse_iterator
//         crend() const noexcept
//         { return const_reverse_iterator(begin()); }


      constexpr size_type
      size() const noexcept { return _Nm; }

      constexpr size_type
      max_size() const noexcept { return _Nm; }

      constexpr bool
      empty() const noexcept { return size() == 0; }


      reference
      operator[](size_type __n) noexcept
      { return _AT_Type::_S_ref(_M_elems, __n); }

      constexpr const_reference
      operator[](size_type __n) const noexcept
      { return _AT_Type::_S_ref(_M_elems, __n); }

      reference
      at(size_type __n)
      {
 if (__n >= _Nm)
   __throw_out_of_range_fmt(("array::at: __n (which is %zu) " ">= _Nm (which is %zu)")
                                 ,
     __n, _Nm);
 return _AT_Type::_S_ref(_M_elems, __n);
      }

      constexpr const_reference
      at(size_type __n) const
      {


 return __n < _Nm ? _AT_Type::_S_ref(_M_elems, __n)
   : (__throw_out_of_range_fmt(("array::at: __n (which is %zu) " ">= _Nm (which is %zu)")
                                    ,
        __n, _Nm),
      _AT_Type::_S_ref(_M_elems, 0));
      }

      reference
      front() noexcept
      { return *begin(); }

      constexpr const_reference
      front() const noexcept
      { return _AT_Type::_S_ref(_M_elems, 0); }

      reference
      back() noexcept
      { return _Nm ? *(end() - 1) : *end(); }

      constexpr const_reference
      back() const noexcept
      {
 return _Nm ? _AT_Type::_S_ref(_M_elems, _Nm - 1)
             : _AT_Type::_S_ref(_M_elems, 0);
      }

      pointer
      data() noexcept
      { return _AT_Type::_S_ptr(_M_elems); }

      const_pointer
      data() const noexcept
      { return _AT_Type::_S_ptr(_M_elems); }
    };
  template<typename _Tp, size_t _Nm>
    inline bool
    operator==(const array<_Tp, _Nm>& __one, const array<_Tp, _Nm>& __two)
    { return equal(__one.begin(), __one.end(), __two.begin()); }

  template<typename _Tp, size_t _Nm>
    inline bool
    operator!=(const array<_Tp, _Nm>& __one, const array<_Tp, _Nm>& __two)
    { return !(__one == __two); }

  template<typename _Tp, size_t _Nm>
    inline bool
    operator<(const array<_Tp, _Nm>& __a, const array<_Tp, _Nm>& __b)
    {
      return lexicographical_compare(__a.begin(), __a.end(),
       __b.begin(), __b.end());
    }

  template<typename _Tp, size_t _Nm>
    inline bool
    operator>(const array<_Tp, _Nm>& __one, const array<_Tp, _Nm>& __two)
    { return __two < __one; }

  template<typename _Tp, size_t _Nm>
    inline bool
    operator<=(const array<_Tp, _Nm>& __one, const array<_Tp, _Nm>& __two)
    { return !(__one > __two); }

  template<typename _Tp, size_t _Nm>
    inline bool
    operator>=(const array<_Tp, _Nm>& __one, const array<_Tp, _Nm>& __two)
    { return !(__one < __two); }


  template<typename _Tp, size_t _Nm>
    inline


    typename enable_if<
      __array_traits<_Tp, _Nm>::_Is_swappable::value
    >::type



    swap(array<_Tp, _Nm>& __one, array<_Tp, _Nm>& __two)
    noexcept(noexcept(__one.swap(__two)))
    { __one.swap(__two); }


  template<typename _Tp, size_t _Nm>
    typename enable_if<
      !__array_traits<_Tp, _Nm>::_Is_swappable::value>::type
    swap(array<_Tp, _Nm>&, array<_Tp, _Nm>&) = delete;


  template<size_t _Int, typename _Tp, size_t _Nm>
    constexpr _Tp&
    get(array<_Tp, _Nm>& __arr) noexcept
    {
      static_assert(_Int < _Nm, "array index is within bounds");
      return __array_traits<_Tp, _Nm>::
 _S_ref(__arr._M_elems, _Int);
    }

  template<size_t _Int, typename _Tp, size_t _Nm>
    constexpr _Tp&&
    get(array<_Tp, _Nm>&& __arr) noexcept
    {
      static_assert(_Int < _Nm, "array index is within bounds");
      return move(get<_Int>(__arr));
    }

  template<size_t _Int, typename _Tp, size_t _Nm>
    constexpr const _Tp&
    get(const array<_Tp, _Nm>& __arr) noexcept
    {
      static_assert(_Int < _Nm, "array index is within bounds");
      return __array_traits<_Tp, _Nm>::
 _S_ref(__arr._M_elems, _Int);
    }


//}

#endif

#ifndef reverse_iterator_hh
#define reverse_itreator_hh
namespace std
{
  typedef decltype(((char*)0)-((char*)0)) ptrdiff_t;

  template<typename _Tp>
    inline constexpr _Tp*
    __addressof(_Tp& __r) noexcept
    { return __builtin_addressof(__r); }
  template<typename...>
    using void_t=void;

  template<typename _Iterator, typename = void_t<>>
    struct iterator_traits { };

  template<typename _Category, typename _Tp, typename _Distance = ptrdiff_t,
           typename _Pointer = _Tp*, typename _Reference = _Tp&>
    struct iterator
    {

      typedef _Category iterator_category;

      typedef _Tp value_type;

      typedef _Distance difference_type;

      typedef _Pointer pointer;

      typedef _Reference reference;
    };
  template<typename _Iterator>
    struct iterator_traits<_Iterator,
        void_t<typename _Iterator::iterator_category,
          typename _Iterator::value_type,
          typename _Iterator::difference_type,
          typename _Iterator::pointer,
          typename _Iterator::reference>>
    {
      typedef typename _Iterator::iterator_category iterator_category;
      typedef typename _Iterator::value_type value_type;
      typedef typename _Iterator::difference_type difference_type;
      typedef typename _Iterator::pointer pointer;
      typedef typename _Iterator::reference reference;
    };
  template <typename _Iterator>
  class reverse_iterator
      : public iterator<
                 typename iterator_traits<_Iterator>::iterator_category,
                 typename iterator_traits<_Iterator>::value_type,
                 typename iterator_traits<_Iterator>::difference_type,
                 typename iterator_traits<_Iterator>::pointer,
                 typename iterator_traits<_Iterator>::reference>
  {
  protected:
    _Iterator current;

    typedef iterator_traits<_Iterator> traits_type;

  public:
    typedef _Iterator                               iterator_type;
    typedef typename traits_type::difference_type difference_type;
    typedef typename traits_type::pointer         pointer;
    typedef typename traits_type::reference       reference;
# 126 "/usr/include/c++/7/bits/stl_iterator.h" 3
    constexpr reverse_iterator()
        : current()
    {
    }


    explicit constexpr reverse_iterator(iterator_type __x)
        : current(__x)
    {
    }


    constexpr reverse_iterator(const reverse_iterator& __x)
        : current(__x.current)
    {
    }


    template <typename _Iter>
    constexpr reverse_iterator(const reverse_iterator<_Iter>& __x)
        : current(__x.base())
    {
    }


    constexpr iterator_type base() const
    {
      return current;
    }
# 168 "/usr/include/c++/7/bits/stl_iterator.h" 3
    constexpr reference operator*() const
    {
      _Iterator __tmp= current;
      return *--__tmp;
    }
# 182 "/usr/include/c++/7/bits/stl_iterator.h" 3
    constexpr pointer operator->() const
    {
      return std::__addressof(operator*());
    }


    constexpr reverse_iterator& operator++()
    {
      --current;
      return *this;
    }


    constexpr reverse_iterator operator++(int)
    {
      reverse_iterator __tmp= *this;
      --current;
      return __tmp;
    }


    constexpr reverse_iterator& operator--()
    {
      ++current;
      return *this;
    }


    constexpr reverse_iterator operator--(int)
    {
      reverse_iterator __tmp= *this;
      ++current;
      return __tmp;
    }


    constexpr reverse_iterator operator+(difference_type __n) const
    {
      return reverse_iterator(current - __n);
    }


    constexpr reverse_iterator& operator+=(difference_type __n)
    {
      current-= __n;
      return *this;
    }


    constexpr reverse_iterator operator-(difference_type __n) const
    {
      return reverse_iterator(current + __n);
    }


    constexpr reverse_iterator& operator-=(difference_type __n)
    {
      current+= __n;
      return *this;
    }


    constexpr reference operator[](difference_type __n) const
    {
      return *(*this + __n);
    }
  };
# 300 "/usr/include/c++/7/bits/stl_iterator.h" 3
  template <typename _Iterator>
  inline constexpr bool operator==(const reverse_iterator<_Iterator>& __x,
                                   const reverse_iterator<_Iterator>& __y)
  {
    return __x.base() == __y.base();
  }

  template <typename _Iterator>
  inline constexpr bool operator<(const reverse_iterator<_Iterator>& __x,
                                  const reverse_iterator<_Iterator>& __y)
  {
    return __y.base() < __x.base();
  }

  template <typename _Iterator>
  inline constexpr bool operator!=(const reverse_iterator<_Iterator>& __x,
                                   const reverse_iterator<_Iterator>& __y)
  {
    return !(__x == __y);
  }

  template <typename _Iterator>
  inline constexpr bool operator>(const reverse_iterator<_Iterator>& __x,
                                  const reverse_iterator<_Iterator>& __y)
  {
    return __y < __x;
  }

  template <typename _Iterator>
  inline constexpr bool operator<=(const reverse_iterator<_Iterator>& __x,
                                   const reverse_iterator<_Iterator>& __y)
  {
    return !(__y < __x);
  }

  template <typename _Iterator>
  inline constexpr bool operator>=(const reverse_iterator<_Iterator>& __x,
                                   const reverse_iterator<_Iterator>& __y)
  {
    return !(__x < __y);
  }


  template <typename _IteratorL, typename _IteratorR>
  inline constexpr bool operator==(const reverse_iterator<_IteratorL>& __x,
                                   const reverse_iterator<_IteratorR>& __y)
  {
    return __x.base() == __y.base();
  }

  template <typename _IteratorL, typename _IteratorR>
  inline constexpr bool operator<(const reverse_iterator<_IteratorL>& __x,
                                  const reverse_iterator<_IteratorR>& __y)
  {
    return __y.base() < __x.base();
  }

  template <typename _IteratorL, typename _IteratorR>
  inline constexpr bool operator!=(const reverse_iterator<_IteratorL>& __x,
                                   const reverse_iterator<_IteratorR>& __y)
  {
    return !(__x == __y);
  }

  template <typename _IteratorL, typename _IteratorR>
  inline constexpr bool operator>(const reverse_iterator<_IteratorL>& __x,
                                  const reverse_iterator<_IteratorR>& __y)
  {
    return __y < __x;
  }

  template <typename _IteratorL, typename _IteratorR>
  inline constexpr bool operator<=(const reverse_iterator<_IteratorL>& __x,
                                   const reverse_iterator<_IteratorR>& __y)
  {
    return !(__y < __x);
  }

  template <typename _IteratorL, typename _IteratorR>
  inline constexpr bool operator>=(const reverse_iterator<_IteratorL>& __x,
                                   const reverse_iterator<_IteratorR>& __y)
  {
    return !(__x < __y);
  }
# 390 "/usr/include/c++/7/bits/stl_iterator.h" 3
  template <typename _IteratorL, typename _IteratorR>
  inline constexpr auto operator-(const reverse_iterator<_IteratorL>& __x,
                                  const reverse_iterator<_IteratorR>& __y)
           -> decltype(__y.base() - __x.base())
  {
    return __y.base() - __x.base();
  }


  template <typename _Iterator>
  inline constexpr reverse_iterator<_Iterator> operator+(
           typename reverse_iterator<_Iterator>::difference_type __n,
           const reverse_iterator<_Iterator>&                    __x)
  {
    return reverse_iterator<_Iterator>(__x.base() - __n);
  }


  template <typename _Iterator>
  inline constexpr reverse_iterator<_Iterator> __make_reverse_iterator(
           _Iterator __i)
  {
    return reverse_iterator<_Iterator>(__i);
  }


  template <typename _Iterator>
  inline constexpr reverse_iterator<_Iterator> make_reverse_iterator(
           _Iterator __i)
  {
    return reverse_iterator<_Iterator>(__i);
  }


  template <typename _Iterator>
  auto __niter_base(reverse_iterator<_Iterator> __it)
           -> decltype(__make_reverse_iterator(__niter_base(__it.base())))
  {
    return __make_reverse_iterator(__niter_base(__it.base()));
  }

  template <typename _Iterator>
  struct __is_move_iterator<reverse_iterator<_Iterator>>
      : __is_move_iterator<_Iterator>
  {
  };

  template <typename _Iterator>
  auto __miter_base(reverse_iterator<_Iterator> __it)
           -> decltype(__make_reverse_iterator(__miter_base(__it.base())))
  {
    return __make_reverse_iterator(__miter_base(__it.base()));
  }
}; // namespace std
#endif

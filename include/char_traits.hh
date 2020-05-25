#ifndef _CHAR_TRAITS_H
#define _CHAR_TRAITS_H 1


namespace std
{
  typedef unsigned long size_t;

  template<typename iitr, typename oitr>
    void copy(iitr src, iitr end, oitr dst)
    {
      while(src!=end)
        *dst++=*src++;
    };
  /**
   *  @brief  Mapping from character type to associated types.
   *
   *  @note This is an implementation class for the generic version
   *  of char_traits.  It defines int_type, off_type, pos_type, and
   *  state_type.  By default these are unsigned long, streamoff,
   *  streampos, and mbstate_t.  Users who need a different set of
   *  types, but who don't need to change the definitions of any function
   *  defined in char_traits, can specialize __gnu_cxx::_Char_types
   *  while leaving __gnu_cxx::char_traits alone. */
  template <typename _CharT>
  struct _Char_types
  {
    typedef unsigned long int_type;
    typedef size_t        pos_type;
    typedef size_t        off_type;
  };


  /**
   *  @brief  Base class used to implement std::char_traits.
   *
   *  @note For any given actual character type, this definition is
   *  probably wrong.  (Most of the member functions are likely to be
   *  right, but the int_type and state_type typedefs, and the eof()
   *  member function, are likely to be wrong.)  The reason this class
   *  exists is so users can specialize it.  Classes in namespace std
   *  may not be specialized for fundamental types, but classes in
   *  namespace __gnu_cxx may be.
   *
   *  See
   * https://gcc.gnu.org/onlinedocs/libstdc++/manual/strings.html#strings.string.character_types
   *  for advice on how to make use of this class for @a unusual character
   *  types. Also, check out include/ext/pod_char_traits.h.
   */
  template <typename _CharT>
  struct char_traits
  {
    typedef _CharT                                   char_type;
    typedef typename _Char_types<_CharT>::int_type   int_type;
    typedef typename _Char_types<_CharT>::pos_type   pos_type;
    typedef typename _Char_types<_CharT>::off_type   off_type;
    typedef typename _Char_types<_CharT>::state_type state_type;

    static void assign(char_type& __c1, const char_type& __c2)
    {
      __c1= __c2;
    }

    static bool eq(const char_type& __c1, const char_type& __c2)
    {
      return __c1 == __c2;
    }

    static bool lt(const char_type& __c1, const char_type& __c2)
    {
      return __c1 < __c2;
    }

    static int compare(const char_type* __s1,
                                            const char_type* __s2,
                                            std::size_t      __n);

    static  std::size_t length(const char_type* __s);

    static  const char_type* find(
             const char_type* __s, std::size_t __n, const char_type& __a);

    static char_type* move(char_type*       __s1,
                           const char_type* __s2,
                           std::size_t      __n);

    static char_type* copy(char_type*       __s1,
                           const char_type* __s2,
                           std::size_t      __n);

    static char_type* assign(char_type*  __s,
                             std::size_t __n,
                             char_type   __a);

    static char_type to_char_type(const int_type& __c)
    {
      return static_cast<char_type>(__c);
    }

    static int_type to_int_type(const char_type& __c)
    {
      return static_cast<int_type>(__c);
    }

    static bool eq_int_type(const int_type& __c1, const int_type& __c2)
    {
      return __c1 == __c2;
    }

    static int_type eof()
    {
      return static_cast<int_type>(-1);
    }

    static  int_type not_eof(const int_type& __c)
    {
      return !eq_int_type(__c, eof()) ? __c : to_int_type(char_type());
    }
  };

  template <typename _CharT>
   int char_traits<_CharT>::compare(
           const char_type* __s1, const char_type* __s2, std::size_t __n)
  {
    for(std::size_t __i= 0; __i < __n; ++__i)
      if(lt(__s1[__i], __s2[__i]))
        return -1;
      else if(lt(__s2[__i], __s1[__i]))
        return 1;
    return 0;
  }

  template <typename _CharT>
   std::size_t char_traits<_CharT>::length(
           const char_type* __p)
  {
    std::size_t __i= 0;
    while(!eq(__p[__i], char_type()))
      ++__i;
    return __i;
  }

  template <typename _CharT>
   const typename char_traits<_CharT>::char_type*
           char_traits<_CharT>::find(const char_type* __s,
                                     std::size_t      __n,
                                     const char_type& __a)
  {
    for(std::size_t __i= 0; __i < __n; ++__i)
      if(eq(__s[__i], __a))
        return __s + __i;
    return 0;
  }

  template <typename _CharT>
  typename char_traits<_CharT>::char_type* char_traits<_CharT>::move(
           char_type* __s1, const char_type* __s2, std::size_t __n)
  {
    if(__n == 0)
      return __s1;
    return static_cast<_CharT*>(
             __builtin_memmove(__s1, __s2, __n * sizeof(char_type)));
  }

  template <typename _CharT>
  typename char_traits<_CharT>::char_type* char_traits<_CharT>::copy(
           char_type* __s1, const char_type* __s2, std::size_t __n)
  {
    // NB: Inline std::copy so no recursive dependencies.
    std::copy(__s2, __s2 + __n, __s1);
    return __s1;
  }

  template<typename itr_t, typename val_t>
    void fill(itr_t dst, itr_t end, const val_t &val)
    {
      while(dst!=end)
        *dst++=val;
    };
  template<typename itr_t, typename val_t>
    void fill_n(itr_t dst, size_t num, const val_t &val)
    {
      fill(dst,dst+num,val);
    };
  template <typename _CharT>
  typename char_traits<_CharT>::char_type* char_traits<_CharT>::assign(
           char_type* __s, std::size_t __n, char_type __a)
  {
    // NB: Inline std::fill_n so no recursive dependencies.
    std::fill_n(__s, __n, __a);
    return __s;
  }

} // namespace std

//   namespace std _GLIBCXX_VISIBILITY(default)
//   {
//     _GLIBCXX_BEGIN_NAMESPACE_VERSION
//   
//   
//   
//     /// 21.1.3.1  char_traits specializations
//     template <>
//     struct char_traits<char>
//     {
//       typedef char      char_type;
//       typedef int       int_type;
//       typedef streampos pos_type;
//       typedef streamoff off_type;
//       typedef mbstate_t state_type;
//   
//       static _GLIBCXX17_CONSTEXPR void assign(
//                char_type& __c1, const char_type& __c2) _GLIBCXX_NOEXCEPT
//       {
//         __c1= __c2;
//       }
//   
//       static  bool eq(const char_type& __c1,
//                                         const char_type& __c2)
//                _GLIBCXX_NOEXCEPT
//       {
//         return __c1 == __c2;
//       }
//   
//       static  bool lt(const char_type& __c1,
//                                         const char_type& __c2)
//                _GLIBCXX_NOEXCEPT
//       {
//         // LWG 467.
//         return (static_cast<unsigned char>(__c1) <
//                 static_cast<unsigned char>(__c2));
//       }
//   
//       static _GLIBCXX17_CONSTEXPR int compare(const char_type* __s1,
//                                               const char_type* __s2,
//                                               size_t           __n)
//       {
//   #if __cplusplus > 201402
//         if(__builtin_constant_p(__n) && __constant_char_array_p(__s1, __n) &&
//            __constant_char_array_p(__s2, __n))
//           return __gnu_cxx::char_traits<char_type>::compare(__s1, __s2, __n);
//   #endif
//         if(__n == 0)
//           return 0;
//         return __builtin_memcmp(__s1, __s2, __n);
//       }
//   
//       static _GLIBCXX17_CONSTEXPR size_t length(const char_type* __s)
//       {
//   #if __cplusplus > 201402
//         if(__constant_string_p(__s))
//           return __gnu_cxx::char_traits<char_type>::length(__s);
//   #endif
//         return __builtin_strlen(__s);
//       }
//   
//       static _GLIBCXX17_CONSTEXPR const char_type* find(const char_type* __s,
//                                                         size_t           __n,
//                                                         const char_type& __a)
//       {
//   #if __cplusplus > 201402
//         if(__builtin_constant_p(__n) && __builtin_constant_p(__a) &&
//            __constant_char_array_p(__s, __n))
//           return __gnu_cxx::char_traits<char_type>::find(__s, __n, __a);
//   #endif
//         if(__n == 0)
//           return 0;
//         return static_cast<const char_type*>(
//                  __builtin_memchr(__s, __a, __n));
//       }
//   
//       static char_type* move(char_type*       __s1,
//                              const char_type* __s2,
//                              size_t           __n)
//       {
//         if(__n == 0)
//           return __s1;
//         return static_cast<char_type*>(__builtin_memmove(__s1, __s2, __n));
//       }
//   
//       static char_type* copy(char_type*       __s1,
//                              const char_type* __s2,
//                              size_t           __n)
//       {
//         if(__n == 0)
//           return __s1;
//         return static_cast<char_type*>(__builtin_memcpy(__s1, __s2, __n));
//       }
//   
//       static char_type* assign(char_type* __s, size_t __n, char_type __a)
//       {
//         if(__n == 0)
//           return __s;
//         return static_cast<char_type*>(__builtin_memset(__s, __a, __n));
//       }
//   
//       static  char_type to_char_type(const int_type& __c)
//                _GLIBCXX_NOEXCEPT
//       {
//         return static_cast<char_type>(__c);
//       }
//   
//       // To keep both the byte 0xff and the eof symbol 0xffffffff
//       // from ending up as 0xffffffff.
//       static  int_type to_int_type(const char_type& __c)
//                _GLIBCXX_NOEXCEPT
//       {
//         return static_cast<int_type>(static_cast<unsigned char>(__c));
//       }
//   
//       static  bool eq_int_type(
//                const int_type& __c1, const int_type& __c2) _GLIBCXX_NOEXCEPT
//       {
//         return __c1 == __c2;
//       }
//   
//       static  int_type eof() _GLIBCXX_NOEXCEPT
//       {
//         return static_cast<int_type>(_GLIBCXX_STDIO_EOF);
//       }
//   
//       static  int_type not_eof(const int_type& __c)
//                _GLIBCXX_NOEXCEPT
//       {
//         return (__c == eof()) ? 0 : __c;
//       }
//     };
//   
//   
//   #ifdef _GLIBCXX_USE_WCHAR_T
//     /// 21.1.3.2  char_traits specializations
//     template <>
//     struct char_traits<wchar_t>
//     {
//       typedef wchar_t    char_type;
//       typedef wint_t     int_type;
//       typedef streamoff  off_type;
//       typedef wstreampos pos_type;
//       typedef mbstate_t  state_type;
//   
//       static _GLIBCXX17_CONSTEXPR void assign(
//                char_type& __c1, const char_type& __c2) _GLIBCXX_NOEXCEPT
//       {
//         __c1= __c2;
//       }
//   
//       static  bool eq(const char_type& __c1,
//                                         const char_type& __c2)
//                _GLIBCXX_NOEXCEPT
//       {
//         return __c1 == __c2;
//       }
//   
//       static  bool lt(const char_type& __c1,
//                                         const char_type& __c2)
//                _GLIBCXX_NOEXCEPT
//       {
//         return __c1 < __c2;
//       }
//   
//       static _GLIBCXX17_CONSTEXPR int compare(const char_type* __s1,
//                                               const char_type* __s2,
//                                               size_t           __n)
//       {
//   #if __cplusplus > 201402
//         if(__builtin_constant_p(__n) && __constant_char_array_p(__s1, __n) &&
//            __constant_char_array_p(__s2, __n))
//           return __gnu_cxx::char_traits<char_type>::compare(__s1, __s2, __n);
//   #endif
//         if(__n == 0)
//           return 0;
//         else
//           return wmemcmp(__s1, __s2, __n);
//       }
//   
//       static _GLIBCXX17_CONSTEXPR size_t length(const char_type* __s)
//       {
//   #if __cplusplus > 201402
//         if(__constant_string_p(__s))
//           return __gnu_cxx::char_traits<char_type>::length(__s);
//         else
//   #endif
//           return wcslen(__s);
//       }
//   
//       static _GLIBCXX17_CONSTEXPR const char_type* find(const char_type* __s,
//                                                         size_t           __n,
//                                                         const char_type& __a)
//       {
//   #if __cplusplus > 201402
//         if(__builtin_constant_p(__n) && __builtin_constant_p(__a) &&
//            __constant_char_array_p(__s, __n))
//           return __gnu_cxx::char_traits<char_type>::find(__s, __n, __a);
//   #endif
//         if(__n == 0)
//           return 0;
//         else
//           return wmemchr(__s, __a, __n);
//       }
//   
//       static char_type* move(char_type*       __s1,
//                              const char_type* __s2,
//                              size_t           __n)
//       {
//         if(__n == 0)
//           return __s1;
//         return wmemmove(__s1, __s2, __n);
//       }
//   
//       static char_type* copy(char_type*       __s1,
//                              const char_type* __s2,
//                              size_t           __n)
//       {
//         if(__n == 0)
//           return __s1;
//         return wmemcpy(__s1, __s2, __n);
//       }
//   
//       static char_type* assign(char_type* __s, size_t __n, char_type __a)
//       {
//         if(__n == 0)
//           return __s;
//         return wmemset(__s, __a, __n);
//       }
//   
//       static char_type to_char_type(const int_type& __c)
//       {
//         return char_type(__c);
//       }
//   
//       static int_type to_int_type(const char_type& __c)
//       {
//         return int_type(__c);
//       }
//   
//       static bool eq_int_type(const int_type& __c1, const int_type& __c2)
//       {
//         return __c1 == __c2;
//       }
//   
//       static int_type eof()
//       {
//         return static_cast<int_type>(WEOF);
//       }
//   
//       static int_type not_eof(const int_type& __c)
//       {
//         return eq_int_type(__c, eof()) ? 0 : __c;
//       }
//     };
//   #endif //_
//   
//   } // namespace )

#endif // _CHAR_TRAITS_H

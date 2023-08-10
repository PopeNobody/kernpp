#ifndef _GLIBCXX_STRING_VIEW
#define _GLIBCXX_STRING_VIEW 1

namespace str
{
#define min(x,y) (y<x?y:x)
  void __xassert(bool val, const char *cont);
#define xassert(x) __xassert((x),#x)

  void exit(int res) __attribute__ ((__noreturn__));
  inline void abort() __attribute__ ((__noreturn__));
  inline void abort() { asm("int3"); exit(1); };
  typedef unsigned long size_t;
  class string_view
  {
  public:
    // types
    typedef char                    _CharT;
    typedef char                    value_type;

    using pointer                  = const _CharT*;
    using const_pointer            = const _CharT*;
    using reference                = const _CharT&;
    using const_reference          = const _CharT&;
    using const_iterator           = const _CharT*;
    using iterator                 = const_iterator;
//    using const_reverse_iterator   = reverse_iterator<const_iterator>;
//    using reverse_iterator         = const_reverse_iterator;
    typedef size_t size_type;
    typedef long difference_type;
    static constexpr size_type npos= size_type(-1);

    // [string.view.cons], construct/copy

    constexpr string_view() noexcept
        : _M_len{ 0 }
        , _M_str{ nullptr }
    {
    }

    constexpr string_view(const string_view&) noexcept=
             default;

    static size_t strlen(const char*str)
    {
      const char *pos(str);
      while(*pos)
        ++pos;
      return pos-str;
    };
    constexpr string_view(const _CharT* __str) noexcept
        : _M_len{ __str == nullptr ? 0 : strlen(__str) }
        , _M_str{ __str }
    {
    }

    constexpr string_view(const _CharT* __str,
                                size_type     __len) noexcept
        : _M_len{ __len }
        , _M_str{ __str }
    {
    }

    constexpr string_view& operator      =(
             const string_view&) noexcept= default;

    // [string.view.iterators], iterators

    constexpr const_iterator begin() const noexcept
    {
      return this->_M_str;
    }

    constexpr const_iterator end() const noexcept
    {
      return this->_M_str + this->_M_len;
    }

    constexpr const_iterator cbegin() const noexcept
    {
      return this->_M_str;
    }

    constexpr const_iterator cend() const noexcept
    {
      return this->_M_str + this->_M_len;
    }
#if 0
    constexpr const_reverse_iterator rbegin() const noexcept
    {
      return const_reverse_iterator(this->end());
    }

    constexpr const_reverse_iterator rend() const noexcept
    {
      return const_reverse_iterator(this->begin());
    }

    constexpr const_reverse_iterator crbegin() const noexcept
    {
      return const_reverse_iterator(this->end());
    }

    constexpr const_reverse_iterator crend() const noexcept
    {
      return const_reverse_iterator(this->begin());
    }

    // [string.view.capacity], capacity
#endif
    constexpr size_type size() const noexcept
    {
      return this->_M_len;
    }

    constexpr size_type length() const noexcept
    {
      return _M_len;
    }

    constexpr size_type max_size() const noexcept
    {
      return (npos - sizeof(size_type) - sizeof(void*)) /
             sizeof(value_type) / 4;
    }

    [[nodiscard]] constexpr bool empty() const noexcept
    {
      return this->_M_len == 0;
    }

    // [string.view.access], element access

    constexpr const _CharT& operator[](size_type __pos) const noexcept
    {
      // TODO: Assert to restore in a way compatible with the constexpr.
      // __glibcxx_assert(__pos < this->_M_len);
      return *(this->_M_str + __pos);
    }

    constexpr const _CharT& at(size_type __pos) const
    {
      return *(this->_M_str + __pos);
    }

    constexpr const _CharT& front() const noexcept
    {
      // TODO: Assert to restore in a way compatible with the constexpr.
      // __glibcxx_assert(this->_M_len > 0);
      return *this->_M_str;
    }

    constexpr const _CharT& back() const noexcept
    {
      // TODO: Assert to restore in a way compatible with the constexpr.
      // __glibcxx_assert(this->_M_len > 0);
      return *(this->_M_str + this->_M_len - 1);
    }

    constexpr const _CharT* data() const noexcept
    {
      return this->_M_str;
    }

    // [string.view.modifiers], modifiers:

    constexpr void remove_prefix(size_type __n) noexcept
    {
      this->_M_str+= __n;
      this->_M_len-= __n;
    }

    constexpr void remove_suffix(size_type __n) noexcept
    {
      this->_M_len-= __n;
    }

    constexpr void swap(string_view& __sv) noexcept
    {
      auto __tmp= *this;
      *this     = __sv;
      __sv      = __tmp;
    }


    // [string.view.ops], string operations:

    constexpr string_view substr(size_type __pos= 0,
                                       size_type __n  = npos) const
             noexcept(false)
    {
      __pos                 = _M_check(__pos, "string_view::substr");
      const size_type __rlen= min(__n, _M_len - __pos);
      return string_view{ _M_str + __pos, __rlen };
    }

    static constexpr int compare(const char *lb, const char *rb, size_t n)
    {
      auto le(lb+n);
      while(lb!=le)
      {
        int res(*lb-*rb);
        if(res)
          return res;
        ++lb; ++rb;
      };
      return 0;
    };
    static constexpr int compare(long lhs, long rhs)
    {
      return (rhs-lhs);
    };
    constexpr int compare(string_view __str) const noexcept
    {
      const size_type __rlen= min(this->_M_len, __str._M_len);

      int __ret= compare(this->_M_str, __str._M_str, __rlen);
      if(__ret == 0)
        __ret= compare(this->_M_len, __str._M_len);
      return __ret;
    }

    constexpr int compare(size_type         __pos1,
                          size_type         __n1,
                          string_view __str) const
    {
      return this->substr(__pos1, __n1).compare(__str);
    }

    constexpr int compare(size_type         __pos1,
                          size_type         __n1,
                          string_view __str,
                          size_type         __pos2,
                          size_type         __n2) const
    {
      return this->substr(__pos1, __n1)
               .compare(__str.substr(__pos2, __n2));
    }

    constexpr int compare(const _CharT* __str) const noexcept
    {
      return this->compare(string_view{ __str });
    }

    constexpr int compare(size_type     __pos1,
                          size_type     __n1,
                          const _CharT* __str) const
    {
      return this->substr(__pos1, __n1)
               .compare(string_view{ __str });
    }

    constexpr int compare(size_type     __pos1,
                          size_type     __n1,
                          const _CharT* __str,
                          size_type     __n2) const noexcept(false)
    {
      return this->substr(__pos1, __n1)
               .compare(string_view(__str, __n2));
    }

    static size_type length(const char *str)
    {
      const char *beg(str);
      while(*str)
        ++str;
      return str-beg;
    };

    constexpr size_type find(string_view v, size_type p) const
    {
      if(v.size()>size())
        return npos;
      size_type n(size()-v.size());
      for(size_type i=p;i<n;i++)
      {
        if(!string_view(_M_str,v.size()).compare(v))
          return i;
      };
      return npos;
    };
#if 0
    constexpr size_type rfind(string_view __str,
                              size_type         __pos= npos) const noexcept
    {
      return this->rfind(__str._M_str, __pos, __str._M_len);
    }

    constexpr size_type rfind(_CharT    __c,
                              size_type __pos= npos) const noexcept;

    constexpr size_type rfind(const _CharT* __str,
                              size_type     __pos,
                              size_type     __n) const noexcept;

    constexpr size_type rfind(const _CharT* __str,
                              size_type     __pos= npos) const noexcept
    {
      return this->rfind(__str, __pos, length(__str));
    }

    constexpr size_type find_first_of(string_view __str,
                                      size_type __pos= 0) const noexcept
    {
      return this->find_first_of(__str._M_str, __pos, __str._M_len);
    }
#endif
    constexpr size_type find(char c, size_type p) const noexcept
    {
      const size_type n(size());
      for(size_type i(p);i<n;i++) {
        if(_M_str[i]==c)
          return i;
      };
      return npos;
    };
#if 0
    constexpr size_type find_first_of(_CharT    __c,
                                      size_type __pos= 0) const noexcept
    {
      return this->find(__c, __pos);
    }

    constexpr size_type find_first_of(const _CharT* __str,
                                      size_type     __pos,
                                      size_type     __n) const noexcept;

    constexpr size_type find_first_of(const _CharT* __str,
                                      size_type __pos= 0) const noexcept
    {
      return this->find_first_of(__str, __pos, length(__str));
    }

    constexpr size_type find_last_of(string_view __str,
                                     size_type __pos= npos) const noexcept
    {
      return this->find_last_of(__str._M_str, __pos, __str._M_len);
    }

    constexpr size_type find_last_of(_CharT    __c,
                                     size_type __pos= npos) const noexcept
    {
      return this->rfind(__c, __pos);
    }

    constexpr size_type find_last_of(const _CharT* __str,
                                     size_type     __pos,
                                     size_type     __n) const noexcept;

    constexpr size_type find_last_of(const _CharT* __str,
                                     size_type __pos= npos) const noexcept
    {
      return this->find_last_of(__str, __pos, length(__str));
    }

    constexpr size_type find_first_not_of(
             string_view __str, size_type __pos= 0) const noexcept
    {
      return this->find_first_not_of(__str._M_str, __pos, __str._M_len);
    }

    constexpr size_type find_first_not_of(
             _CharT __c, size_type __pos= 0) const noexcept;

    constexpr size_type find_first_not_of(const _CharT* __str,
                                          size_type     __pos,
                                          size_type __n) const noexcept;

    constexpr size_type find_first_not_of(
             const _CharT* __str, size_type __pos= 0) const noexcept
    {
      return this->find_first_not_of(
               __str, __pos, length(__str));
    }

    constexpr size_type find_last_not_of(
             string_view __str, size_type __pos= npos) const noexcept
    {
      return this->find_last_not_of(__str._M_str, __pos, __str._M_len);
    }

    constexpr size_type find_last_not_of(
             _CharT __c, size_type __pos= npos) const noexcept;

    constexpr size_type find_last_not_of(const _CharT* __str,
                                         size_type     __pos,
                                         size_type     __n) const noexcept;

    constexpr size_type find_last_not_of(
             const _CharT* __str, size_type __pos= npos) const noexcept
    {
      return this->find_last_not_of(
               __str, __pos, length(__str));
    }
#endif
    constexpr size_type _M_check(size_type __pos, const char* __s) const
             noexcept(false)
    {
      if(__pos > this->size())
        abort();
      return __pos;
    }
    // NB: _M_limit doesn't check for a bad __pos value.
    constexpr size_type _M_limit(size_type __pos,
                                 size_type __off) const noexcept
    {
      const bool __testoff= __off < this->size() - __pos;
      return __testoff ? __off : this->size() - __pos;
    }
  private:

    size_t        _M_len;
    const _CharT* _M_str;
  };

  // [string.view.comparison], non-member string_view comparison
  // function

  constexpr bool operator==(
           string_view __x, string_view __y) noexcept
  {
    return __x.size() == __y.size() && __x.compare(__y) == 0;
  }

#if 0
  template <typename _CharT, typename _Traits>
  constexpr bool operator==(
           string_view __x,
           string_view
                    __y) noexcept
  {
    return __x.size() == __y.size() && __x.compare(__y) == 0;
  }
  template <typename _CharT, typename _Traits>
  constexpr bool operator==(
           string_view __x,
           string_view __y) noexcept
  {
    return __x.size() == __y.size() && __x.compare(__y) == 0;
  }
#endif

  constexpr bool operator!=(
           string_view __x,
           string_view __y) noexcept
  {
    return !(__x == __y);
  }


  constexpr bool operator<(string_view __x,
                           string_view __y) noexcept
  {
    return __x.compare(__y) < 0;
  }



  constexpr bool operator>(string_view __x,
                           string_view __y) noexcept
  {
    return __x.compare(__y) > 0;
  }



  constexpr bool operator<=(
           string_view __x,
           string_view __y) noexcept
  {
    return __x.compare(__y) <= 0;
  }


  constexpr bool operator>=(
           string_view __x,
           string_view __y) noexcept
  {
    return __x.compare(__y) >= 0;
  }

} // namespace str


#endif // _GLIBCXX_EXPERIMENTAL_STRING_VIEW

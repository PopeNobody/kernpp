#pragma once
namespace std {
  namespace __cmp_cat
  {
    using type = signed char;

    enum class _Ord : type { equivalent = 0, less = -1, greater = 1 };

    enum class _Ncmp : type { _Unordered = 2 };

    struct __unspec
    {
      constexpr __unspec(__unspec*) noexcept { }
    };
  }
  class strong_ordering
  {
    __cmp_cat::type _M_value;

    constexpr explicit
    strong_ordering(__cmp_cat::_Ord __v) noexcept
    : _M_value(__cmp_cat::type(__v))
    { }

  public:
    // valid values
    static const strong_ordering less;
    static const strong_ordering equal;
    static const strong_ordering equivalent;
    static const strong_ordering greater;

    // comparisons
    [[nodiscard]]
    friend constexpr bool
    operator==(strong_ordering __v, __cmp_cat::__unspec) noexcept
    { return __v._M_value == 0; }

    [[nodiscard]]
    friend constexpr bool
    operator==(strong_ordering, strong_ordering) noexcept = default;

    [[nodiscard]]
    friend constexpr bool
    operator< (strong_ordering __v, __cmp_cat::__unspec) noexcept
    { return __v._M_value < 0; }

    [[nodiscard]]
    friend constexpr bool
    operator> (strong_ordering __v, __cmp_cat::__unspec) noexcept
    { return __v._M_value > 0; }

    [[nodiscard]]
    friend constexpr bool
    operator<=(strong_ordering __v, __cmp_cat::__unspec) noexcept
    { return __v._M_value <= 0; }

    [[nodiscard]]
    friend constexpr bool
    operator>=(strong_ordering __v, __cmp_cat::__unspec) noexcept
    { return __v._M_value >= 0; }

    [[nodiscard]]
    friend constexpr bool
    operator< (__cmp_cat::__unspec, strong_ordering __v) noexcept
    { return 0 < __v._M_value; }

    [[nodiscard]]
    friend constexpr bool
    operator> (__cmp_cat::__unspec, strong_ordering __v) noexcept
    { return 0 > __v._M_value; }

    [[nodiscard]]
    friend constexpr bool
    operator<=(__cmp_cat::__unspec, strong_ordering __v) noexcept
    { return 0 <= __v._M_value; }

    [[nodiscard]]
    friend constexpr bool
    operator>=(__cmp_cat::__unspec, strong_ordering __v) noexcept
    { return 0 >= __v._M_value; }

    [[nodiscard]]
    friend constexpr strong_ordering
    operator<=>(strong_ordering __v, __cmp_cat::__unspec) noexcept
    { return __v; }

    [[nodiscard]]
    friend constexpr strong_ordering
    operator<=>(__cmp_cat::__unspec, strong_ordering __v) noexcept
    { return strong_ordering(__cmp_cat::_Ord(-__v._M_value)); }
  };

  // valid values' definitions
  inline constexpr strong_ordering
  strong_ordering::less(__cmp_cat::_Ord::less);

  inline constexpr strong_ordering
  strong_ordering::equal(__cmp_cat::_Ord::equivalent);

  inline constexpr strong_ordering
  strong_ordering::equivalent(__cmp_cat::_Ord::equivalent);

  inline constexpr strong_ordering
  strong_ordering::greater(__cmp_cat::_Ord::greater);
};
using std::strong_ordering;
template<class it>
int true_n(const it b){
  it e(b);
  while(*e)
    ++e;
  return e-b;
};
template<class it>
strong_ordering seq_cmp(it s1, it s2, unsigned n)
{
  while(n--){
    auto r=(s1<=>s2);
    if(r!=(0<=>0))
      return r;
  }
  return 0<=>0;
}
template<class t>
auto min(t l, t r){
  return l<r ? l : r;
};

#pragma once

namespace std {
  template< class T >
    constexpr T&& forward( remove_reference_t<T>& t ) noexcept
    {
      return (T&&)t;
    };
  template< class T >
    constexpr T&& forward( remove_reference_t<T>&& t ) noexcept
    {
      return t;
    };
}

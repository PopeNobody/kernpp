#pragma once
namespace std {
  template<typename _type>
    struct remove_reference {
      typedef _type type;
    };
  template<typename _type>
    struct remove_reference<_type&> {
      typedef _type type;
    };
  template<typename _type>
    struct remove_reference<_type&&> {
      typedef _type type;
    };
  template< class T >
    using remove_reference_t = typename remove_reference<T>::type;

  template <typename T>
    constexpr typename remove_reference<T>::type&& move(T&& t) noexcept {
      return static_cast<typename remove_reference<T>::type&&>(t);
    }
}

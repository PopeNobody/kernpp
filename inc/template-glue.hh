#pragma once
namespace std {
  template<typename type>
  struct convertible_to {
  };
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

  template< class T >
    constexpr T&& forward( std::remove_reference_t<T>& t ) noexcept
    {
      return (T&&)t;
    };
  template< class T >
    constexpr T&& forward( std::remove_reference_t<T>&& t ) noexcept
    {
      return t;
    };
  template <typename>
    struct function_traits;
  template <typename... Args>
    struct tuple {
    };
  template <typename R, typename... Args>
    struct function_traits<R(Args...)> {
      using return_type = R;
      using arg_tuple = std::tuple<Args...>;
    };
  // Variadic min with constraints
  template <typename T>
    constexpr auto min(T&& a) {
      return a;
    };
  template <typename C, typename D>
    constexpr auto min(C&& a, D&& b) {
      return a;
    };
  template <typename T, typename... Ts>
    requires (requires (T&& a, Ts&&... args) { (... , (args < a)); })
    constexpr auto min(T&& a, Ts&&... args) -> decltype(auto) {
      return min(std::forward<T>(a), min(std::forward<Ts>(args)...));
    }
};

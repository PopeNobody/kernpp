#pragma once
#include "types.hh"
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

  template <typename T>
    constexpr typename remove_reference<T>::type&& move(T&& t) noexcept {
      return static_cast<typename remove_reference<T>::type&&>(t);
    }


  template <typename>
    struct function_traits;
  //     template <typename R, typename... Args>
  //       struct function_traits<R(Args...)> {
  //         using return_type = R;
  //         using arg_tuple = std::tuple<Args...>;
  //       };
  // Variadic min with constraints
  template <typename T>
    constexpr auto min(T&& a) {
      return a;
    };
  template <typename C, typename D>
    constexpr auto min(C&& a, D&& b) {
      return a<b?a:b;
    };
  template <typename T, typename... Ts>
    requires (requires (T&& a, Ts&&... args) { (... , (args < a)); })
    constexpr auto min(T&& a, Ts&&... args) -> decltype(auto) {
      return min(std::forward<T>(a), min(std::forward<Ts>(args)...));
    }


  template <typename T>
    struct remove_cv { using type = T; };
  template <typename T>
    struct remove_cv<const T> { using type = T; };
  template <typename T>
    struct remove_cv<volatile T> { using type = T; };
  template <typename T>
    struct remove_cv<const volatile T> { using type = T; };


  template <typename T>
    using decay_t = typename remove_cv<typename remove_reference<T>::type>::type;
  // Primary template
  template <typename... Ts>
    struct tuple;

  // Base case: empty tuple
  template<>
    struct tuple<> {};

  // Recursive case:
  template <typename Head, typename... Tail>
    struct tuple<Head, Tail...> : tuple<Tail...> {
      Head head;

      tuple() = default;

      template <typename H, typename... T>
        tuple(H&& h, T&&... t)
        : tuple<Tail...>(std::forward<T>(t)...), head(std::forward<H>(h)) 
        {
        }
    };

  template <typename... Ts>
    constexpr auto make_tuple(Ts&&... args) {
      return tuple<std::decay_t<Ts>...>(std::forward<Ts>(args)...);
    }
  template <typename T>
    struct tuple_size;

  template <typename... Ts>
    struct tuple_size<tuple<Ts...>> {
      static constexpr size_t value = sizeof...(Ts);
    };


  // Primary helper
  template <size_t I, typename Tuple>
    struct tuple_element_helper;

  // Recursive case
  template <size_t I, typename Head, typename... Tail>
    struct tuple_element_helper<I, tuple<Head, Tail...>> {
      using type = typename tuple_element_helper<I - 1, tuple<Tail...>>::type;

      static type& get(tuple<Head, Tail...>& t) {
        return tuple_element_helper<I - 1, tuple<Tail...>>::get(t);
      }

      static const type& get(const tuple<Head, Tail...>& t) {
        return tuple_element_helper<I - 1, tuple<Tail...>>::get(t);
      }
    };

  // Base case
  template <typename Head, typename... Tail>
    struct tuple_element_helper<0, tuple<Head, Tail...>> {
      using type = Head;

      static type& get(tuple<Head, Tail...>& t) {
        return t.head;
      }

      static const type& get(const tuple<Head, Tail...>& t) {
        return t.head;
      }
    };

  // User-facing get<I>(tuple)
  template <size_t I, typename Tuple>
    auto& get(Tuple& t) {
      return tuple_element_helper<I, Tuple>::get(t);
    }

  template <size_t I, typename Tuple>
    const auto& get(const Tuple& t) {
      return tuple_element_helper<I, Tuple>::get(t);
    }
  template <size_t... Is>
    struct index_sequence {};

  template <size_t N, size_t... Is>
    struct make_index_sequence_impl : make_index_sequence_impl<N - 1, N - 1, Is...> {};

  template <size_t... Is>
    struct make_index_sequence_impl<0, Is...> {
      using type = index_sequence<Is...>;
    };

  template <size_t N>
    using make_index_sequence = typename make_index_sequence_impl<N>::type;

  // ----------------------------------------
  // tuple_for_each: apply a callable to each tuple element
  // ----------------------------------------
  template <typename Tuple, typename Func, size_t... Is>
    void tuple_for_each_impl(Tuple&& tup, Func&& func, index_sequence<Is...>) {
      (func(std::get<Is>(tup)), ...);
    }

  template <typename Tuple, typename Func>
    void tuple_for_each(Tuple&& tup, Func&& func) {
      constexpr size_t N = std::tuple_size<std::remove_reference_t<Tuple>>::value;
      tuple_for_each_impl(
          std::forward<Tuple>(tup),
          std::forward<Func>(func),
          make_index_sequence<N>{}
          );
    }

  // Type trait struct
  template <typename T1, typename T2>
    struct is_same {
      static constexpr bool value = false;
    };

  template <typename T>
    struct is_same<T, T> {
      static constexpr bool value = true;
    };

  // Helper inline constant
  template <typename T1, typename T2>
    inline constexpr bool is_same_v = is_same<T1, T2>::value;
};

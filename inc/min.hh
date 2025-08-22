#pragma once
#include "template-glue.hh"
namespace std {
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
};

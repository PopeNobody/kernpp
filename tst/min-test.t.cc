// Clean, constrained variadic min ensuring comparability, with reference return if possible.

//#include <utility>
//#include <type_traits>
//#include <concepts>

// Base case for two arguments with constraint

template <typename T, typename U>
requires requires (T&& a, U&& b) { { b < a } -> std::convertible_to<bool>; }
constexpr auto min(T&& a, U&& b) -> decltype(auto) {
    return (b < a) ? std::forward<U>(b) : std::forward<T>(a);
}

// Variadic min with constraints

template <typename T, typename... Ts>
requires (requires (T&& a, Ts&&... args) { (... , (args < a)); })
constexpr auto min(T&& a, Ts&&... args) -> decltype(auto) {
    return min(std::forward<T>(a), min(std::forward<Ts>(args)...));
}

int main() {
    int x = 5, y = 3, z = 7;
    auto& r = min(x, y, z); // returns reference to y
    return r; // returns 3
}

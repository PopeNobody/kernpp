// Clean, constrained variadic min ensuring comparability, with reference return if possible.
// Now includes a test with different comparable types.
#if 0
#include <utility>
#include <type_traits>
#include <concepts>
#include <string>

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

int main(int argc,char *const*argv,char *const*envp) {
    int x = 5, y = 3, z = 7;
    auto& r1 = min(x, y, z); // returns reference to y

    double a = 2.5;
    auto r2 = min(x, y, a);  // returns by value (mix of int and double)

    std::string s1 = "apple", s2 = "banana", s3 = "aardvark";
    auto& r3 = min(s1, s2, s3); // returns reference to s3

    return r1 + static_cast<int>(r2) + r3.size();
}
#endif

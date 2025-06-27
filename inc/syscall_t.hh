// syscall_t.hpp - Struct-based advanced syscall abstraction for your t++ system

#ifndef SYSCALL_T_HPP
#define SYSCALL_T_HPP

#include <tuple>
#include <source_location>
#include <cstdint>
#include <utility>
#include <cerrno>

// --- function_traits to extract argument tuple ---
template <typename>
struct function_traits;

template <typename R, typename... Args>
struct function_traits<R(Args...)> {
    using return_type = R;
    using arg_tuple = std::tuple<Args...>;
};

// --- syscall_t struct ---
template <long sysno, typename fn_t>
struct syscall_t {
    using fn_type = fn_t;
    using return_type = typename function_traits<fn_t>::return_type;
    using arg_tuple = typename function_traits<fn_t>::arg_tuple;

    // Default set_errno handler
    static void default_set_errno(int err, std::source_location loc = std::source_location::current()) {
        ::errno = err;
        (void)loc; // suppress unused warning if not used
    }

    // Customizable per-TU errno handler
    static inline void (*set_errno)(int, std::source_location) = default_set_errno;

    // Core syscall invocation
    template <typename... Args>
    static return_type call(Args&&... args, std::source_location loc = std::source_location::current()) {
        static_assert(sizeof...(Args) <= 6, "Syscalls support up to 6 arguments");

        long ret;
        register long rax asm("rax") = sysno;
        register long rdi asm("rdi");
        register long rsi asm("rsi");
        register long rdx asm("rdx");
        register long r10 asm("r10");
        register long r8  asm("r8");
        register long r9  asm("r9");

        auto tuple_args = std::forward_as_tuple(args...);
        if constexpr (sizeof...(Args) > 0) rdi = (long)std::get<0>(tuple_args);
        if constexpr (sizeof...(Args) > 1) rsi = (long)std::get<1>(tuple_args);
        if constexpr (sizeof...(Args) > 2) rdx = (long)std::get<2>(tuple_args);
        if constexpr (sizeof...(Args) > 3) r10 = (long)std::get<3>(tuple_args);
        if constexpr (sizeof...(Args) > 4) r8  = (long)std::get<4>(tuple_args);
        if constexpr (sizeof...(Args) > 5) r9  = (long)std::get<5>(tuple_args);

        asm volatile (
            "syscall"
            : "=a"(ret)
            : "a"(rax), "D"(rdi), "S"(rsi), "d"(rdx), "r"(r10), "r"(r8), "r"(r9)
            : "rcx", "r11", "memory"
        );

        if ((uint64_t)ret > (uint64_t)-4095) {
            set_errno(-ret, loc);
            return static_cast<return_type>(-1);
        }
        return static_cast<return_type>(ret);
    }

    // operator() as syntactic sugar
    template <typename... Args>
    return_type operator()(Args&&... args, std::source_location loc = std::source_location::current()) {
        return call(std::forward<Args>(args)..., loc);
    }
};

#endif // SYSCALL_T_HPP

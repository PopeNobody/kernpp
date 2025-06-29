// int_formatter_pipeline_test.cpp
// Standalone test harness for reusable int_formatter producing scoped int_formatted
// Safe, reusable, and aligned with writev + fmt pipeline
#include "syscall.hh"
//   #include <sys/uio.h>
//   #include <unistd.h>
//   #include <cstring>
//   #include <cstdint>
//   #include <cstdio>

// ----------------------------------------
// Small, static, malloc-free small_string
// ----------------------------------------
template <size_t N>
struct small_string {
    char buf[N] = {};
    size_t len = 0;

    void push_back(char c) {
        if (len < N) buf[len++] = c;
    }

    char* begin() { return buf; }
    const char* begin() const { return buf; }
    size_t size() const { return len; }
};

// ----------------------------------------
// int_formatted: holds the formatted buffer
// ----------------------------------------
struct int_formatted {
    small_string<32> buf;

    int_formatted(int value, int base, int width, char fill) {
        char tmp[32];
        char* p = tmp + sizeof(tmp);
        auto v = static_cast<uint32_t>(value);

        do {
            int digit = v % base;
            *--p = (digit < 10) ? ('0' + digit) : ('a' + digit - 10);
            v /= base;
        } while (v && p != tmp);

        while ((tmp + sizeof(tmp) - p) < width && p != tmp) {
            *--p = fill;
        }

        size_t len = tmp + sizeof(tmp) - p;
        std::memcpy(buf.buf, p, len);
        buf.len = len;
    }

    iovec to_iovec() const {
        return { .iov_base = (void*)buf.begin(), .iov_len = buf.size() };
    }
};

// ----------------------------------------
// int_formatter: reusable policy/config object
// ----------------------------------------
struct int_formatter {
    int base = 10;
    int width = 0;
    char fill = ' ';

    int_formatter(int b = 10, int w = 0, char f = ' ')
        : base(b), width(w), fill(f) {}

    auto format(int value) const {
        return int_formatted(value, base, width, fill);
    }
};

// ----------------------------------------
// fmt_holder: system-friendly pipeline wrapper
// ----------------------------------------
struct fmt_holder {
    const void* data;
    size_t size;

    fmt_holder(const void* d, size_t s) : data(d), size(s) {}

    iovec to_iovec() const {
        return { .iov_base = const_cast<void*>(data), .iov_len = size };
    }
};

// ----------------------------------------
// to_fmt free functions for pipeline
// ----------------------------------------
fmt_holder to_fmt(const char* s) {
    return fmt_holder(s, std::strlen(s));
}

fmt_holder to_fmt(const int_formatted& f) {
    iovec io = f.to_iovec();
    return fmt_holder(io.iov_base, io.iov_len);
}

// ----------------------------------------
// fill_iovecs_from_tuple
// ----------------------------------------
template <typename Tuple, size_t... Is>
void fill_iovecs_from_tuple(iovec* iovs, Tuple& tup, std::index_sequence<Is...>) {
    ((iovs[Is] = std::get<Is>(tup).to_iovec()), ...);
}

// ----------------------------------------
// write_pipe using writev
// ----------------------------------------
template <typename... Ts>
ssize_t write_pipe(int fd, Ts&&... args) {
    auto holders = std::make_tuple(to_fmt(std::forward<Ts>(args))...);
    constexpr size_t N = sizeof...(Ts);
    iovec iovs[N];
    fill_iovecs_from_tuple(iovs, holders, std::make_index_sequence<N>{});
    return ::writev(fd, iovs, N);
}

// ----------------------------------------
// Test main
// ----------------------------------------
int main() {
    int_formatter dec_fmt(10, 5, '0');      // Base 10, width 5, fill '0'
    int_formatter hex_fmt(16, 4, '0');      // Base 16, width 4, fill '0'

    auto f1 = dec_fmt.format(42);           // Produces "00042"
    auto f2 = hex_fmt.format(255);          // Produces "00ff"

    write_pipe(1, "Decimal padded: ", f1, "\n");
    write_pipe(1, "Hex padded: ", f2, "\n");

    return 0;
}

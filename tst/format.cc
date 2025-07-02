// fmt_holder_pipeline_test.cpp
// Self-contained, ready to play with, test harness for `fmt_holder`, `to_fmt`, and `writev` pipeline

#include "syscall.hh"
//   #include <unistd.h>
//   #include <cstring>
//   #include <cstdint>
//   #include <tuple>
//   #include <type_traits>
//   #include <cstdio>


// ----------------------------------------
// Simple small_string implementation
// ----------------------------------------
template <size_t N>
struct small_string {
    char buf[N] = {};
    size_t len = 0;

    void push_back(char c) {
        if (len < N) buf[len++] = c;
    }

    char* begin() { return buf; }
    char* end() { return buf + len; }
    const char* begin() const { return buf; }
    const char* end() const { return buf + len; }
    size_t size() const { return len; }
};


template <typename T>
char* format_integer_msb_first(T val, char* b, char* e) {
    char tmp[32];
    char* p = tmp + sizeof(tmp);
    
    if (val == 0) *--p = '0';
    else {
        while (val && p != tmp) {
            *--p = '0' + (val % 10);
            val /= 10;
        }
    }
    
    size_t len = tmp + sizeof(tmp) - p;
    if ((e - b) < ptrdiff_t(len)) return nullptr;
    memcpy(b, p, len);
    return b + len;
}

// ----------------------------------------
// fmt_holder struct
// ----------------------------------------
struct fmt_holder {
    const void* data;
    size_t size;
    small_string<64> owned_buf; // Adjust size as needed

    fmt_holder(const void* d, size_t s) : data(d), size(s) {}
    fmt_holder(small_string<64>&& buf) : data(buf.begin()), size(buf.size()), owned_buf(std::move(buf)) {}

    iovec to_iovec() const {
        return { .iov_base = const_cast<void*>(data), .iov_len = size };
    }
};

// ----------------------------------------
// to_fmt free functions (extensible)
// ----------------------------------------
fmt_holder to_fmt(const char* s) {
    return fmt_holder(s, itr::len(s));
}

fmt_holder to_fmt(const small_string<64>& s) {
    return fmt_holder(s.begin(), s.size());
}

fmt_holder to_fmt(int val) {
    small_string<64> buf;
    char* end = format_integer_msb_first(val, buf.buf, buf.buf + sizeof(buf.buf));
    buf.len = end ? (end - buf.buf) : 0;
    return fmt_holder(std::move(buf));
}

// ----------------------------------------
// Fill iovec[] from tuple
// ----------------------------------------
//   template <typename Tuple, size_t... Is>
//   void fill_iovecs_from_tuple(iovec* iovs, Tuple& tup, std::index_sequence<Is...>) {
//       ((iovs[Is] = std::get<Is>(tup).to_iovec()), ...);
//   }

// ----------------------------------------
// write function using writev pipeline
// ----------------------------------------
template <typename... Ts>
ssize_t write_pipe(int fd, Ts&&... args) {
//       auto holders = std::make_tuple(to_fmt(std::forward<Ts>(args))...);
//       constexpr size_t N = sizeof...(Ts);
//       iovec iovs[N];
//       fill_iovecs_from_tuple(iovs, holders, std::make_index_sequence<N>{});
//       return ::writev(fd, iovs, N);
  return 0;
}

// ----------------------------------------
// Test main
extern "C" {
int main() {
    small_string<64> s;
    s.push_back('H'); s.push_back('e'); s.push_back('l'); s.push_back('l'); s.push_back('o');

    write_pipe(1, s, ", number = ", 42, "\n");
    // Expected output: Hello, number = 42

    return 0;
}
};

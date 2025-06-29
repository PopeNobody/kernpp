extern "C" { int main(int argc,char *const*argv,char *const*envp); };
#include <syscall.hh>
int main(int argc,char *const*argv,char *const*envp) {
  return 0;
};

#if 0
// tst/syscall_raii_test.cc
// -----------------------------------------------------------
// Unit test for syscall_t + scoped_errno_handler with RAII
// Returns 42 on success, 24 on failure
// -----------------------------------------------------------

#include "syscall_t.hpp"
#include <unistd.h>
#include <string_view>
#include <cstring>
#include <iostream>

// syscall_t for mkdir
using mkdir_syscall = syscall_t<83, int(const char*, mode_t)>;

// Custom error handler that ignores EEXIST
void ignore_eexist_handler(int err, std::source_location loc = std::source_location::current()) {
    if (err == EEXIST) {
        // Optionally log: std::cerr << "Ignoring EEXIST at " << loc.file_name() << ":" << loc.line() << "\n";
        return;
    }
    ::errno = err;
    (void)loc;
}

int main(int argc,char *const*argv,char *const*envp) {
    const char *test_dir = "tst/syscall_raii_test_dir";
    
    try {
        {
            scoped_errno_handler<mkdir_syscall> guard(ignore_eexist_handler);

            // First mkdir should succeed
            int ret1 = mkdir_syscall::call(test_dir, 0777);
            if (ret1 == -1 && errno != 0) {
                std::cerr << "mkdir failed unexpectedly: " << strerror(errno) << "\n";
                return 24;
            }

            // Second mkdir should return -1, but our handler will suppress EEXIST
            int ret2 = mkdir_syscall::call(test_dir, 0777);
            if (ret2 == -1 && errno == EEXIST) {
                std::cerr << "EEXIST was not suppressed as expected.\n";
                return 24;
            }
        }

        // After guard, handler restored: EEXIST should now set errno
        int ret3 = mkdir_syscall::call(test_dir, 0777);
        if (!(ret3 == -1 && errno == EEXIST)) {
            std::cerr << "EEXIST was not set correctly after handler restoration.\n";
            return 24;
        }
    } catch (...) {
        std::cerr << "Unexpected exception thrown.\n";
        return 24;
    }

    // Success
    return 42;
}
#endif


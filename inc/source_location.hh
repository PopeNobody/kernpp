#pragma once
using loc_type = decltype(__builtin_source_location());
namespace std {
  struct source_location {
    struct __impl {
      const char* _M_file_name;
      const char* _M_function_name;
      unsigned _M_line;
      unsigned _M_column;
    };
    const __impl *impl;
    source_location(const void *impl=__builtin_source_location())
      : impl((__impl*)impl)
    {
    };
    static source_location current(const void *impl=__builtin_source_location())
    {
      return impl;
    };
    const char *file() const {
      return impl->_M_file_name;
    }
    const char *func() const {
      return impl->_M_function_name;
    }
    unsigned line() const {
      return impl->_M_line;
    };
  };
  typedef source_location src_t;
};

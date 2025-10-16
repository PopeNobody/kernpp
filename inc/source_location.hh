#pragma once
namespace std
{
  typedef unsigned uint32_t;
  struct source_location
  {
  public:
    struct __impl
    {
      const char* _M_file_name;
      const char* _M_function_name;
      unsigned _M_line;
      unsigned _M_column;
    };
    using __builtin_ret_type = decltype(__builtin_source_location());


    // [support.srcloc.cons], creation
    static consteval source_location
    current(__builtin_ret_type __p = __builtin_source_location()) noexcept
    {
      source_location __ret;
      __ret._M_impl = static_cast <const __impl*>(__p);
      return __ret;
    }

    constexpr source_location() noexcept { }

    // [support.srcloc.obs], observers
    constexpr uint32_t
    line() const noexcept
    { return _M_impl ? _M_impl->_M_line : 0u; }

    constexpr uint32_t
    column() const noexcept
    { return _M_impl ? _M_impl->_M_column : 0u; }

    constexpr const char*
    file_name() const noexcept
    { return _M_impl ? _M_impl->_M_file_name : ""; }

    constexpr const char*
    function_name() const noexcept
    { return _M_impl ? _M_impl->_M_function_name : ""; }

  private:
    const __impl* _M_impl = nullptr;
  };

} // namespace std
namespace sys {
  struct loc_t : public std::source_location {
    loc_t(const void *vp=__builtin_source_location())
    {
    };
  };
};

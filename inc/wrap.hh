#pragma once
namespace std {
  template<class T>
    struct wrap_t {
      using val_t=T;
      val_t val;
      wrap_t(const val_t &val)
        :val(val)
      {
      }
      wrap_t(const wrap_t &rhs)
        : val(rhs.val)
      {
      }
      operator val_t&() {
        return val;
      };
      operator val_t() const {
        return val;
      };
    };
  typedef unsigned uint32_t;
  struct fd_t : protected wrap_t<uint32_t>
  {
    fd_t()
      :wrap_t(-1)
    {
    };
    using wrap_t::wrap_t;
    using wrap_t::operator val_t&;
    using wrap_t::operator val_t;
  };
}

#include <syscall.hh>

template<size_t _size>
struct buf_t {
  static constexpr size_t size=_size;
  char buf[size-1];
  char end[1];
};
namespace fatal {
  using sys::open_flags;
  using sys::open_mode;
  int open(const char *path, open_flags flags, open_mode mode);
  int open(const char *path, open_flags flags);
};

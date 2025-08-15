#include "fmt.hh"

using namespace sys;
template <typename... Ts>
constexpr auto make_tuple(Ts&&... args) {
  return std::tuple<std::decay_t<Ts>...>(std::forward<Ts>(args)...);
}
template<class ... Args>
void *xxx_mmap( Args ... args ) {
  auto tup = make_tuple(args ...);
  write(2,__PRETTY_FUNCTION__);
  write(2,"\n");
  return 0;
};
namespace sys {
  uint64_t syscall6(
      uint64_t n, uint64_t a1, uint64_t a2, uint64_t a3, uint64_t a4,
      uint64_t a5, uint64_t a6
      );
};
const void *BAD=(void*)((char*)-1);
void *malloc(size_t size) {
  void *addr=0;
  int prot=prot_read|prot_write;
  int flag=map_private|map_anon;
  int fd=-1;
  int off=0;
  void *r=mmap( addr, size, prot, flag, fd, off);
  return r;
};
using sys::write;
  using fmt::fmt_t;

constexpr uint64_t mmap_bad=0xffffffffffffffff;
extern "C" {
  int main(int argc,char *const*argv,char *const*envp) {
    void *ptr1 = malloc(128);
    write(2,fmt_t(ptr1));
    void *ptr2 = malloc(128);
    write(2,fmt_t(ptr2));
    void *ptr3 = malloc(128);
    write(2,fmt_t(ptr3));
    void *ptr4 = malloc(128);
    write(2,fmt_t(ptr4));
    return 0;
  };
}


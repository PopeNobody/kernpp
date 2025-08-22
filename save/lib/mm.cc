#include "syscall.hh"
#include "vector.hh"

namespace std {
  template<class a1_t, class a2_t>
    struct pair {
      a1_t first;
      a2_t second;
    };
  void free(void *ptr);
}
typedef std::pair<void *,size_t> ptrsize_t;
std::vector_t<ptrsize_t> list;

namespace std{
  void *malloc(size_t size);
};
void std::free(void *ptr) {

};
void *std::malloc(size_t size) {
  void *addr=0;
  using namespace sys;
  int prot=prot_read|prot_write;
  int flag=map_private|map_anon;
  int fd=-1;
  int off=0;
  void *r=mmap( addr, size, prot, flag, fd, off);
  return r;
};

#include "fmt.hh"

using namespace sys;
const void *BAD=(void*)((char*)-1);
using sys::write;
using fmt::fmt_t;

constexpr uint64_t mmap_bad=0xffffffffffffffff;
template<class a1_t>
ssize_t write_ln(fd_t fd, a1_t a1) {
  ssize_t res=write(fd,a1);
  if(res>=0)
    res+=write(fd,"\n");
  return res;
};
namespace std {
  void *malloc(size_t);
};
using namespace std;
extern "C" {
  int main(int argc,char *const*argv,char *const*envp) {
    void *ptr2 = malloc(128);
    write_ln(2,fmt_t(ptr2));
    void *ptr1 = new char[1024*1024];
    write_ln(2,fmt_t(ptr1));
    void *ptr3 = malloc(128);
    write_ln(2,fmt_t(ptr3));
    void *ptr4 = malloc(128);
    write_ln(2,fmt_t(ptr4));
    return 0;
  };
}


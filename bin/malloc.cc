#include "syscall.hh"

extern "C" {
  int main(int, char**,char**) {
    sys::write(1,"Hello, World!\n");     
    return 0;
  };
}

template<class T, size_t N>
size_t countof(T (&str)[N]){
  return N;
};
template<class val1_t, class val2_t>
struct pair {
  val1_t v1;
  val2_t v2;
  pair()
  {
  };
  pair(const val1_t &v1, const val1_t &v2)
    : v1(v1), v2(v2)
  {
  };
};
struct block_t {
  typedef collect::array_t<void*,4096/sizeof(void*)> ptrs_t;
  ptrs_t ptrs;
  static constexpr size_t num=ptrs_t::size;
};
void *malloc(size_t size){
return 0;
};
void free(void*) {
};
extern "C" {
  int main(int argc,char *const*argv,char *const*envp) {
    const char *vecs[]={
      "this is a test\n",
      "this is only a test\n"
    };
//       using format::writev;
//       ssize_t res=writev(1,vecs[0],vecs[1]);
//       writev(1, "the last test returned: ", res);
    return 0;
  };
}


#include "syscall.hh"
#include "vector.hh"
namespace itr {
  using std::ssize_t;
  using std::size_t;
  template<class T>
  size_t len(const T*const beg, const T&sen=T()) {
    auto pos(beg);
    return pos-beg;    
  };
};
using namespace sys;
const void *BAD=(void*)((char*)-1);
using sys::write;

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
  using itr::len;
  int main(int argc,char *const*argv,char *const*envp) {
    char str[]="this is a string\n";
    std::vector_t<char> vec1(str,str+len(str));
    write(1,vec1.beg(),vec1.end());
    vec1.push_back('t');
    vec1.push_back('h');
    vec1.push_back('i');
    vec1.push_back('s');
    vec1.push_back('\n');
    std::vector_t<char> vec2(1024,str,str+len(str));
    return 0;
  };
}


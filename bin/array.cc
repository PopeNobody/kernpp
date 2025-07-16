#include "array.hh"
#include "syscall.hh"
#include "fmt.hh"
#include "c_str.hh"

struct stream_t {
  fd_t fd;
};
using collect::array_t;
using namespace fmt;
using sys::write;
using str::c_str;
template<class ... Args, class T>
auto last_arg(Args ... args, T t) {
  return t;
};
template<class ... Args>
auto _writeln(fd_t fd, Args ... args, sys::errhand_t hand){
  return 0;
};
template<class ... Args>
auto writeln(fd_t fd, Args ... args) {
//tuple tuple(std::forward args);
  return 0;
};
extern "C" {
  int main(int argc,char *const*argv,char *const*envp) {
    array_t<c_str,1024> array;
    writeln(1,fmt_t(array.len()));
    array.push_back("this is a test");
    writeln(1,fmt_t(array.len()));
    return 0;
  };
}


#include "syscall.hh"
#include "iostream.hh"
#include "source_location.hh"
using namespace stream;
struct loc_t : public std::source_location {
  loc_t(const void *vp=__builtin_source_location())
  {
    impl=(__impl*)vp;
  };
};
ostream &operator <<(ostream &lhs, const loc_t &rhs) {
  lhs << rhs.file() << ":" << rhs.line() << ":" << rhs.func() << endl;
  return lhs;
};
int main(int, char**, char**) {
  loc_t loc;
  cout << loc << endl;
  return 0;
};

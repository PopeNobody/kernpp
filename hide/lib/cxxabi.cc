#include <cxxabi.hh>

extern "C" {
  void 
  __cxa_bad_typeid() {
    sys::write(2,"test\n",5);
  }
}

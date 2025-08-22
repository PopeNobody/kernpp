#include "fmt.hh"
extern "C" {
  int main();
};
int main() {
    timeval_t tv{ 123456789, 987654 };
    int x = 42;
    const char* msg = " | ";
    float f = 3.14159;
    sys::write(1,fmt::fmt_t(x));
    sys::write(1,"\n");
    sys::write(1,msg); 
    sys::write(1,"\n");
    sys::write(1,fmt::fmt_t(tv));
    sys::write(1,"\n");
    sys::write(1,fmt::fmt_t(f));
    sys::write(1,"\n");
    return 0;
}

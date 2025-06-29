//   #include <cstdio>
#include "syscall.hh"
#include "fmt.hh"
using fmt::int_t;
using sys::write;

char *format_integer_msb_first(char *buf,char *end, int_t val, int base,
    int width=1, char fill='0')
{
  auto fmt=fmt::fmt_t(val,base,width,fill);
  c_str str=fmt;
  return str.copy(buf,end);
};

int main() {
    char buf[8] = {}; // intentionally small for testing
    uint64_t val = 123456789;

    char* end = format_integer_msb_first(buf, buf + sizeof(buf), val, 10);
    if (end) {
        write(1,"Formatted: ");
        write(1,buf);
        write(1,"\n");
    } else {
        write(1,"Buffer overflow, safe buffer: '");
        write(1,buf);
        write(1,"'\n");
    }
    return 0;
}

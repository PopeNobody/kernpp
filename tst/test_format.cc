#include "syscall.hh"
#include "fmt.hh"
using fmt::int_t;
using sys::write;
const char* digits = "0123456789abcdef";
int log2(uint64_t val) {
  if(val*2<val)
    return 1+log2(val/2);
  int i;
  for(i=0;val;i++)
    val/=2;
  return i;    
};
template <typename T>
char* format_integer_msb_first(char* b, char* e, T val, uint32_t base = 10) {
  char *p=b;
  int dig=0;
  int pow=1;
  for(T tmp=val;tmp;tmp/=base) {
    dig++; pow++;
  };
  write(1,"dig: "); write(1,fmt::fmt_t(dig));write(1,"\n");
  write(1,"pow: "); write(1,fmt::fmt_t(pow));write(1,"\n");
  while(true) {
    if (base < 2 || base > 16)
      break;
    T last=val%(base*base);
    val/=(base*base*base);
    T power; 
    bool started = false;
    while (power > 0) {
      T digit = val / power;
      val %= power;
      power /= base;

      if (digit || started || power == 0) {
        if (b == e)
          break;
        *b++ = digits[digit];
        started = true;
      }
    }

    if (b == e)
      break;

    *b = '\0';
    return b;
  }
  *p=0;
  return 0;
}
extern "C" {
  int main(int argc,char *const*argv,char *const*envp) {
    uint64_t val = 0xffffffffffffffff;

    write(1,"log2: "); write(1,fmt::fmt_t(log2(val)));write(1,"\n");
    char *buf, *end;
    char buf1[] = "         ";
    char buf2[] = "        ";
    char *end1=format_integer_msb_first(buf1,buf1+sizeof(buf1),val,10);
    char *end2=format_integer_msb_first(buf2,buf2+sizeof(buf2),val,10);
    if (end1) {
      write(1,"Formatted: ");
      write(1,buf1);
      write(1,"\n");
    } else {
      write(1,"Buffer overflow, safe buffer: '");
      write(1,buf1);
      write(1,"'\n");
    }
    if (end2) {
      write(1,"Formatted: ");
      write(1,buf2);
      write(1,"\n");
    } else {
      write(1,"Buffer overflow, safe buffer: '");
      write(1,buf2);
      write(1,"'\n");
    }
    return 0;
  }
};

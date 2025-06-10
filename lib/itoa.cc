#include "itoa.hh"
namespace sys {
  const char *itoa(unsigned long val, bool neg=false) {
    static char buf[3*sizeof(long)];
    char *end=buf+sizeof(buf)-1;
    char *pos=end;
    *--pos=0;
    *--pos='0';
    if(val){
      while(val){
        *pos--=(val%10)+'0';
        val/=10;
      };
      if(neg)
        *pos='-';
      else
        ++pos;
    }
    return pos;
  };
}

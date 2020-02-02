#include <math.h>
#include <stdio.h>

int main(int, char**) {
  typedef long double xld;
  long double max_size_t = 0xffffffff;
#define showl(x) fprintf(stderr, "%-40s %30.4LF\n", #x, (long double)x)
  showl(powl(2,10));
  showl(powl(10,10));
  showl(logl(powl(10,10))/logl(2));
  showl(powl(2,33.2192));
//     for(int i = 0; i < 81; i+=3){
//       showl(powl(2,i));
//       showl(powl(10,floorl(logl(powl(2,i))/logl(10))));
//     };
  return 0;
};
//     showl(logl(powl(2,63))/logl(1000));
//     showl(logl(powl(2,64))/logl(1000));
//     showl(logl(powl(2,65))/logl(1000));
//     showl(logl(powl(2,66))/logl(1000));
//     showl(powl(2,30));
//     showl(powl(1000,3));
//     showl(logl(powl(1000,3))/logl(2));
//     showl(sizeof(size_t));
//     showl(sizeof(short));
//     showl(sizeof(int));
//     showl(sizeof(long));
//     size_t st=0;
//     showl((long double)st);
//     --st;
//     showl((long double)st);
//     showl(logl(1000*1000*1000)/logl(10));
//     showl(logl(1000*1000*1000*100)/logl(1000));
//     showl(powl(256,sizeof(void*)));
//     showl(sizeof(long double));
//     showl(powl(2,64)/powl(10,9));
//     showl(max_size_t);
//     showl(powl(2,16));
//     showl(logl(max_size_t)/logl(2));
//     showl(powl(2,64));
//     showl(powl(2,63));
//     showl(logl(max_size_t)/logl(16));
//     showl(logl(max_size_t)/logl(2));
//     showl(powl(logl(max_size_t)/logl(2),2));
//     showl(powl(2,26));
//     showl(flen);
//     showl(powl(2,27));
//     showl(logl(flen)/logl(16));
//     showl(1+floorl(logl(flen)/logl(2)));
//     showl(powl(10,logl(len)/logl(10)));
//     showl(val);
//     showl(abs((float)size_t(-1)));
//     showl(0x1000000000);
//     showl(powl(16,9));
//     showl(powl(16,10));
//     showl(powl(10, 9));
//     showl(powl(10, 9.04));
//     showl(logl(val));
//     showl(log10l(val));
//     showl(logl(10));
//     showl(logl(val) / logl(10));
//     showl(powl(10, log10(val)));

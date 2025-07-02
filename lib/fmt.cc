#include "fmt.hh"

namespace fmt {
  void fmt_t::format(float f, int width, int prec){
  };
//     void format(str::c_str buf,int_t wrap, int base, int width, char fill) {
//       unsigned long val=wrap.abs;
//       unsigned long neg=wrap.neg;
//       if(width>=sizeof(buf)){
//         sys::write(2,"Error: width > ");
//         sys::write(2,fmt_t(sizeof(buf)));
//         sys::write(2,"\n");
//         width=sizeof(buf);
//       };
//       nul[0]=0;
//       off=(nul-buf);
//       do {
//         buf[--off]=digits[val%base];
//         val/=base;
//       } while(val);
//       while(off>(nul-buf)-width)
//         buf[--off]='0';
//       if(neg)
//         buf[--off]='-';
//       if(nul[0])
//         sys::exit(1);
//     };
};

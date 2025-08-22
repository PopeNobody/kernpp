#include "bitset.hh"
using collect::bitset_t;
using str::c_str;
struct bit_stream {
  c_str text;
  size_t pos;
  char mask;
  bit_stream(const c_str &text)
    : text(text), mask(1)
  {
  };
  bool get() {
    if(!mask) {
      mask=1;
      ++pos;
    } else {
      mask*=2;
    };
    return text[pos] & mask;
  };
  operator bool() const {
    return pos<text.size() || mask;
  };
};
using sys::write;
using sys::open;
using sys::read;
using sys::fd_t;
using fmt::fmt_t;
int main(int argc, const char *argv[], const char *envp[]){
  fd_t out(1);
  {
  timespec_t tm = { 8888, 2222 };
  fmt::fmt_t tmfmt("");
  tmfmt=tm;
  write(1,"\n\n\n-----\n");
  write(1,tmfmt);
  write(1,"\n-----\n\n\n");
  }
  {
  timeval_t tm = { 9999, 1111 };
  fmt::fmt_t tmfmt("");
  tmfmt=tm;
  write(1,"\n\n\n-----\n");
  write(1,tmfmt);
  write(1,"\n-----\n\n\n");
  }

//     constexpr static int size=160;
//     bitset_t<size> bs;
//     {
//       tm = { 1, 0 };
//       sys::write(out,"\ntm: ");
//       tmfmt=tm;
//       sys::write(out, tmfmt);
//       return 0;
//     }
//     if(0){
//       fd_t rfd=sys::open("/dev/urandom",sys::o_rdonly);
//       char rand[240];
//       char *rpos=rand;
//       size_t res =sys::read(rfd,rand,sizeof(rand)); 
//       sys::write(out,"res: ");
//       fmt::fmt_t fres(res);
//       sys::write(out,fres);
//       sys::write(out,"\n");
//       bit_stream str(c_str(rand,sizeof(rand)));
//       while(str) {
//         sys::write(out,"\n");
//         for(int i=0;i<8;i++) {
//           fmt::fmt_t bit(str.get()?'Y':'n');
//           sys::write(out,bit);
//         };
//         sys::write(out,"\n");
//         sys::nanosleep(&tm,0);
//       };
//     };
//     int i=0;
//     char buf[5+size+size/4];
//     memset(buf,0,sizeof(buf));
//     int j=0;
//     for(i=0;i<size;){
//       if(bs.test(i)){
//         buf[j++]='1';
//       } else {
//         buf[j++]='0';
//       };
//       if(++i%4)
//         continue;
//       buf[j++]=' ';
//     };
//     if(buf[j-1]==' '){
//       --j;
//     } else {
//       while(++i%4) {
//         buf[j++]='*';
//       };
//     };
//     buf[j]=0;
//     sys::write(1,"[");
//     sys::write(1,buf);
//     sys::write(1,"]\n");
  return 0;
};

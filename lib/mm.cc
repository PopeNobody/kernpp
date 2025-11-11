#include "syscall.hh"

using namespace sys;
extern "C" {
  using fmt::fmt_t;
  void free(void *vp) {
//       write(2,"free(");
//       write(2,fmt::fmt_t(vp));
//       write(2,")\n");
  };
  void *malloc(size_t sz) {
    size_t size=sz;
    size+=sizeof(size_t);
    size+=255;
    size-=size%256;
    char *beg=mmap(0,size,prot_read|prot_write,map_private|map_anon,-1,0);
    memset(beg,0,size);
    char *end=beg+size;
    size_t *psize=(size_t*)beg;
    beg=(char*)(psize+1);
//       write(2,"malloc(");
//       write(2,fmt::fmt_t(sz));
//       write(2,") => ");
//       write(2,fmt::fmt_t((void*)beg));
//       write(2,"\n");
    return beg;
  };

}

#include "syscall.hh"

using namespace sys;
extern "C" {
  using fmt::fmt_t;
  void free(void *vp) {
    write(2,"free(");
    write(2,fmt::fmt_t(vp));
    write(2,")\n");
  };
  void *malloc(size_t sz) {
    size_t size=sz;
    size+=sizeof(size_t);
    size+=255;
    size-=size%256;
    char *pos=mmap(0,size,prot_read|prot_write,map_private|map_anon,-1,0);
    *(size_t*)pos=sz;
    pos+=sizeof(size_t);
    memset(pos,0,sz);
    memset(pos+sz,0xff,size-sz);
    return pos;
  };

}

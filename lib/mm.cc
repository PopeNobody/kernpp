#if 0
#include <syscall.hh>
#include <fmt.hh>

namespace nn {
  int brk (void *addr);
  void * sbrk (ssize_t increment);
}
namespace fmt {
  inline int write_sphex(fd_t fd, size_t hex) {
    fmt::fmt_t buf(hex,16,8);
    return sys::write(fd, buf);
  };
  inline int write_dec(fd_t fd, size_t dec){
    fmt::fmt_t buf(dec,10);
    return sys::write(fd, buf);
  };
  struct fmtbuf_t {
  };
};
using namespace sys;
using namespace nn;

class block_l {
  enum magic_t { magic = 0xdeadbeef };
  struct block_t {
    magic_t magic1;
    block_t *next;
    magic_t magic2;
    size_t size;
    magic_t magic3;
    bool used;
    void combine() {
      if(!next)
        return;
      if(next->used)
        return;
      size+=sizeof(*next)+next->size;
      next=next->next;
    };
  };
  block_t *list;
  public:
  block_l()
    :list(0)
  {
  };
  void *malloc(size_t size)
  {
    void *res=_malloc(size);
    if(1){
      write(2,"malloc(");
      write(2,size);
      write(2,") => ");
      write(2,res);
      write(2,"\n");
    };
    return res;

  };

  void *_malloc(size_t size)
  {
    block_t **pos=&list;
    while(*pos) {
      block_t *blk=*pos;
      void *ptr = (void*)(blk+1);
      if( blk->magic1 != magic || blk->magic2 != magic || blk->magic3 != magic ) 
      {
      };
      if(!(*pos)->used && (*pos)->size>=size) {
        (*pos)->used=true;
        return *pos+1;
      };
      pos=&((*pos)->next);
    };
    block_t *blk=(block_t*)sbrk(size+sizeof(block_t));
    blk->magic1=blk->magic2=blk->magic3=magic;
    blk->used=true;
    blk->size=size;
    blk->next=0;
    *pos=blk;
    return blk+1;
  };
  ~block_l() {
    //show();
    list=0;
  };
  typedef char* char_p;
  void free(void *ptr){
    if(!ptr)
      return;
    block_t *blk=(block_t*)ptr;
    --blk;
    if( blk->magic1 != magic || blk->magic2 != magic || blk->magic3 != magic ) 
    {
      fmtbuf_t buf(
          __FILE__, ":", __LINE__, ":", "free: ", ptr, "blk: ", blk, 
          "magic1: ", (unsigned long)blk->magic1,
          "magic2: ", (unsigned long)blk->magic2,
          "magic3: ", (unsigned long)blk->magic3,
        );
      buf.write(2);      
    };
    if(!blk->used) {
      write(2,L("warning: double free of: "));
      write_ptr(2,ptr);
      write(2,L("\n"));
    };
    blk->used=false;
    for(blk=list;blk;blk=blk->next)
      blk->combine();
  };
  void show() {
    write(2,L("(---BLOCK LIST----\n"));
    for( block_t *blk=list; blk; blk=blk->next ) {
      write(2,L("blk: "));
      write_ptr(2,blk);
      write(2,L(" data: "));
      write_ptr(2,blk+1);
      write(2,L(" size: "));
      write_sphex(2,blk->size);
      write(2,L(" used: "));
      write_dec(2,blk->used);
      write(2,L("\n"));
      write(2,L("       "));
      write_ptr(2,char_p(blk)+blk->size+sizeof(*blk));
      write(2,L("\n"));
    };
    write(2,L("----BLOCK LIST---}\n"));
  };
};
block_l list;
void *malloc(size_t size) {
  return list.malloc(size);
};
void *realloc(void *ptr, size_t size) {
  char *optr=(char*)ptr;
  char *nptr=(char*)malloc(size);
  memcpy(nptr,optr,size);
  free(optr);
  return nptr;
};
void free(void *ptr) {
  list.free(ptr);
};
void *__curbrk;
namespace nn {
int brk (void *addr)
{
  char *newbrk;

  asm (
      "syscall\n" 
      : "=a"(newbrk) 
      : "0"(12), "D"(addr)
      : "rcx", "r11", "memory"
      );

  __curbrk=newbrk;

  if (newbrk < addr)
    {
      set_errno (ENOMEM);
      return -1;
    }

  return 0;
}
void * sbrk (ssize_t increment)
{
  void *oldbrk;

  /* If this is not part of the dynamic library or the library is used
     via dynamic loading in a statically linked program update
     __curbrk from the kernel's brk value.  That way two separate
     instances of brk and sbrk can share the heap, returning
     interleaved pieces of it.  */
  if (!__curbrk && (brk(0)<0))
    return (void*)-1;

  if (increment == 0)
    return __curbrk;

  oldbrk = __curbrk;
  if (increment > 0
      ? ((uintptr_t) oldbrk + (uintptr_t) increment < (uintptr_t) oldbrk)
      : ((uintptr_t) oldbrk < (uintptr_t) -increment))
    {
      set_errno (ENOMEM);
      return (void *) -1;
    }

  if (brk (ostr_t(oldbrk) + increment) < 0)
    return (void *) -1;

  return oldbrk;
}
}
#endif

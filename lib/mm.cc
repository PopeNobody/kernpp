#include <syscall.hh>
#include <fmt.hh>

using fmt::write_dec;
using fmt::write_ptr;
using fmt::write_hex;
namespace fmt {
inline char *fmt_sphex(unsigned long val, char *beg, char *end)
{
	int i=-2013;
	for(i=0;i<2*sizeof(val);i++){
		*--end=hex_dig(val);
		if((val/=0x10)==0)
			break;
	};
	for(;i<2*sizeof(val);i++)
		*--end=' ';
	return end;
};
inline int write_sphex(fd_t fd, size_t hex) {
	char buf[sizeof(hex)*4];
	return write(fd, fmt::fmt_sphex(hex,buf,&buf[sizeof(buf)-1]));
};
};
using fmt::write_sphex;
using fmt::fmt_sphex;

void assert_fail(const char *file, size_t line, const char *msg) {
  write(2,L("\n"));
  write(2,file);
  write(2,L(":"));
  write_dec(2,line);
  write(2,L(":assert("));
  write(2,msg);
  write(2,L(") failed\n"));
  exit(1);
};
#define assert(x) do{if(!(x))assert_fail(__FILE__,__LINE__,#x);}while(0)
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
#if 0
      write(2,L(__PRETTY_FUNCTION__));
			write(2,L("\n  this="));
			write_ptr(2,this);
      write(2,L("\n"));
#endif
			if(!next)
				return;
			if(next->used)
				return;
			assert(char_p(next)==char_p(this)+sizeof(*this)+size);
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
    block_t **pos=&list;
    while(*pos) {
      assert((*pos)->magic1 == magic);
      assert((*pos)->magic2 == magic);
      assert((*pos)->magic3 == magic);
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
    show();
    list=0;
  };
  typedef char* char_p;
  void free(void *ptr){
    if(!ptr)
      return;
    block_t *blk=(block_t*)ptr;
    --blk;
    assert(blk->magic1 == magic);
    assert(blk->magic2 == magic);
    assert(blk->magic3 == magic);
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
extern "C" {
	void mm_show() {
		list.show();
	};
};
void *malloc(size_t size) {
#if 1
	return list.malloc(size);
#else
	write(2,L("malloc("));
	write_dec(2,size);
	write(2,L(") => "));
  void *res=list.malloc(size);
	write_ptr(2,res);
	write(2,L("\n"));
	return res;
#endif
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

#include <syscall.hh>

void *malloc(size_t size)
{
	void *block;
	block = sbrk(size);
	if (block == (void*) -1)
		return nullptr;
	return block;
}
struct curbrk_t {
	char *val;
	curbrk_t()
		:val(0)
	{
	};
	void set(char *nval){
		val=nval;
	};
	operator void*() const {
		return val;
	};
};
curbrk_t __curbrk;

int brk (void *addr)
{
	char *newbrk;

	asm (
			"syscall\n" 
			: "=a"(newbrk) 
			: "0"(12), "D"(addr)
			: "rcx", "r11", "memory"
			);

	__curbrk.set(newbrk);

  if (newbrk < addr)
    {
      set_errno (ENOMEM);
      return -1;
    }

  return 0;
}
void * sbrk (intptr_t increment)
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

  if (brk (str_t(oldbrk) + increment) < 0)
    return (void *) -1;

  return oldbrk;
}

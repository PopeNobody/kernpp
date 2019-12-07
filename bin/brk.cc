#include <syscall.hh>
#include <array.hh>

struct num_fmt
{
	static char hex_dig(int val) {
		static char digs[]="0123456789abcdef";
		return digs[val&0xf];
	};
	static char *fmt_hex(uint64_t val, char *beg, char *end)
	{
		if(beg!=end)
			*--end=0;
		for(int i=0;i<2*sizeof(val);i++){
			*--end=hex_dig(val);
			val/=0x10;
		};
		return end;
	};
};

struct buf_t {
	enum {size=256-2*sizeof(int)};
	int pos;
	int fd;
	char text[size];
	buf_t(int fd)
		:pos(0), fd(fd)
	{
	};
	~buf_t()
	{
		flush();
	};
	size_t room() {
		return size-pos;
	};
	void flush() {
		if(pos) {
			write(fd,text,pos);
			memset(text,0,sizeof(text));
			pos=0;
		};
	};
	template<typename fmt_t>
	buf_t &stream(const fmt_t &fmt)
	{
		auto b(fmt.beg()), e(fmt.end());
		while(b!=e){
			text[pos++]=*b++;
			if(!room())
				flush();
		};
		return *this;
	};
};
struct str_fmt {
	const char *_beg;
	const char *_end;
	str_fmt(const char *beg,const char *end)
		:_beg(beg), _end(end)
	{
	};
	str_fmt(const char *beg, size_t len)
		:_beg(beg), _end(beg+len)
	{
	};
	str_fmt(const char *beg)
		:_beg(beg), _end(beg+strlen(beg))
	{
	};
	const char *beg() const {
		return _beg;
	};
	const char *end() const {
		return _end;
	};
};

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

int __brk (void *addr)
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
int alarm(int secs) {
	int res=-1;
	asm(
			"syscall\n"
			: "=a"(res)
			: "0"(37), "D"(secs)
			: "rcx", "r11", "memory"
		 );
	return set_errno(res);
};
int nanosleep(timespec* itm, timespec *otm=0) {
	int res=-1;
	asm(
			"syscall\n"
			: "=a"(res)
			: "0"(35), "D"(itm), "S"(otm)
			: "rcx", "r11", "memory"
		 );
	return set_errno(res);
};

void * __sbrk (intptr_t increment)
{
  void *oldbrk;

  /* If this is not part of the dynamic library or the library is used
     via dynamic loading in a statically linked program update
     __curbrk from the kernel's brk value.  That way two separate
     instances of __brk and __sbrk can share the heap, returning
     interleaved pieces of it.  */
	if (!__curbrk && (__brk(0)<0))
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

  if (__brk (str_t(oldbrk) + increment) < 0)
    return (void *) -1;

  return oldbrk;
}


time_t sleep(time_t sec, long nsec=0) {
	timespec goal = { sec, nsec };
	timespec rem = { 0, 0 };
	int res=nanosleep(&goal,&rem);
	return rem.tv_sec;
};

struct ptr_fmt {
	char text[4*sizeof(void*)+4];
	int pos=0;
	ptr_fmt(void *val)
	{
		union {
			void *ptr;
			uint64_t raw;
		};
		ptr=val;
		pos=num_fmt::fmt_hex(raw, text, text+sizeof(text))-text;
		if(pos>1)
			text[--pos]='x';
		if(pos>1)
			text[--pos]='0';
		if(pos>1)
			text[--pos]='p';
	};
	const char *beg() const {
		return text+pos;

	};
	const char *end() const {
		return text+sizeof(text)-1;
	};
};
template <typename val_t>
void do_disp(buf_t &buf, const char *tag, val_t val)
{
	char pad[30];

	memset(pad,'-',sizeof(pad));
	pad[sizeof(pad)-1]=0;
	{
		int pos=0;
		while(*tag && pos<sizeof(pad))
			pad[pos++]=*tag++;
	};
	str_fmt tag_fmt(pad);
	str_fmt del_fmt("  =>  ");
	str_fmt nl("\n");
	ptr_fmt ptr(val);
	buf
		.stream(tag_fmt)
		.stream(del_fmt)
		.stream(ptr)
		.stream(nl);
};
#define disp(x) do_disp(buf,#x,x)

int main(int argc, char**argv){
	ptr_fmt ptr(argv);
	buf_t buf(1);
	str_fmt nl("\n");
	disp(__sbrk(0));
	disp(nullptr);
	disp((char*)sizeof(buf));
	for(auto b(argv), e(argv+argc); b!=e; b++) {
		buf.stream(str_fmt(*b)).stream(nl);
	};
	__sbrk(0);
	char *orig=(char*)(void*)__curbrk;
	disp(__curbrk);
	disp(__sbrk(0));
	disp(__curbrk);
	disp(__sbrk(4096*16+12345));
	disp(__curbrk);
	disp(__sbrk(0));
	disp(__curbrk);
	disp(__sbrk(4096*16+12345));
	disp(__curbrk);

	return 0;
}

#include <syscall.hh>

template<size_t _size=256>
struct buf_t {
	enum {size=_size};
	char dummy1[5];
	char text[size];
	char dummy2[5];
	int pos;
	int fd;
	buf_t(int fd)
		:pos(0), fd(fd)
	{
		memset(dummy1,'*',sizeof(dummy1));
		memset(dummy2,'+',sizeof(dummy2));
		dummy1[sizeof(dummy1)]=0;
		dummy2[sizeof(dummy2)]=0;
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
			pos=0;
		};
	};
	static char hex_dig(int val) {
		static char digs[]="0123456789abcdef";
		return digs[val&0xf];
	};
#if 0
	buf_t &app(const char *beg, const char *end){
		while(beg!=end) {
			if(!room())
				flush();
			text[pos++]=*beg++;
			text[pos]=0;
		};
		return *this;
	};
	buf_t &pad(size_t n, const char *beg, size_t l)
 	{
		app(beg,beg+l);
		while(n>l){
			static char space[]=" ";
			app(space,space+1);
			--n;
		};
		return *this;
	};
	buf_t &pad(size_t n, const char *beg)
	{
		return pad(n,beg,strlen(beg));
	};
	buf_t &app(char ch) {
		return app(&ch,1+&ch);
	};
	buf_t &app(const char *beg, size_t len) {
		return app(beg,beg+len);
	};
	buf_t &app(const char *beg) {
		return app(beg,strlen(beg));
	};
	buf_t &app(size_t val, bool neg=false) {
		char buf[sizeof(val)*3+2];
		int end=sizeof(buf);
		int pos=end;
		buf[--pos]=0;
		if(val) {
			while(val) {
				buf[--pos]=hex_dig(val%10);
				val/=10;
			};
		} else {
			buf[--pos]='0';
		};
		if(neg){
			buf[--pos]='-';
		};
		return app(buf+pos,buf+end);
	};
	buf_t &app(void *ptr) {
		size_t val=size_t(ptr);
		char buf[sizeof(ptr)*2+4];
		int pos=sizeof(buf);
		buf[--pos]=0;
		for(int i=0;i<sizeof(ptr);i++){
			buf[--pos]=hex_dig(val);
			buf[--pos]=hex_dig(val>>4);
			val=val/0x100;
		};
		buf[--pos]='x';
		buf[--pos]='0';
		return app(buf+pos,buf+sizeof(buf));
	};
	buf_t &app(int val) {
		if(val<0)
			return app(-val,true);
		else
			return app(val,false);
	};
#endif
	struct item_t {
		virtual void fmt(buf_t &buf);
	};
	buf_t &app(item_t item){
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
//void *__curbrk=0;
enum {ENOMEM=12};

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

int main(int argc, char**argv){
	buf_t<256> buf(1);
	__sbrk(0);
	char *orig=(char*)(void*)__curbrk;
//   	FMT(__curbrk);
//   	FMT(__sbrk(0));
//   	FMT(__curbrk);
//   	FMT(__sbrk(4096*16+12345));
//   	FMT(__curbrk);
//   	FMT(__sbrk(0));
//   	FMT(__curbrk);
//   	FMT(__sbrk(4096*16+12345));
//   	FMT(__curbrk);

	return 0;
}

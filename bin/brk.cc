#include <syscall.hh>
#include <array.hh>
#include <fmt.hh>



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
	buf_t buf(1);
	for(int i=0;i<10000;i++){
		char *mem=(char*)malloc(100);
		disp(mem);
		memset(mem,0xde,100);
	};
	return 0;
}

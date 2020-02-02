#include <syscall.hh>
#include <new.hh>
#include <typeinfo.hh>
#include <assert.hh>
using namespace sys;
#if 0
using namespace fmt;

char *fmt_chr(char ch, char *beg, char *pos) {
  assert(beg<pos);
  *--pos=ch;
  return pos;
};
int main(int argc, char**argv) {
  bufferfd_t buf(1);
  char bigbuf[1024];
  char *endbuf=bigbuf+sizeof(bigbuf)-1;
  char *pos=endbuf;
  char *pad;
  for(size_t i=1;i;i+=12345)
  {
    pos=fmt_chr('\n',bigbuf,pos);
    pos=fmt_chr('|',bigbuf,pos);
    pad=pos-34;
    pos=fmt_dec(i,bigbuf,pos);
    while(pad<pos)
      *--pos=' ';
    pos=fmt_chr('|',bigbuf,pos);
    pad=pos-34;
    pos=fmt_hex(i,bigbuf,pos);
    while(pad<pos)
      *--pos=' ';
    pos=fmt_chr('|',bigbuf,pos);
    write(1,pos,endbuf-pos);
    pos=endbuf;
  };
  return 0;
};
#else
template<typename type>
class del_ptr
{
	type *ptr;
	public:
	del_ptr(type *__ptr)
		:ptr(__ptr)
	{
	}
	~del_ptr()
	{
		write(1,L("\n"));
		writeln(1,L(__PRETTY_FUNCTION__));
		delete ptr;
		write(1,L("\n"));
	}
	operator type *() const
	{
		return get();
	};
	type *get() const
	{
		return ptr;
	};
	type *rel()
	{
		type *res=ptr;
		ptr=0;
		return res;
	};
	del_ptr &operator=(type *rhs)
	{
		delete rel();
		ptr=rhs;
		return *this;
	}
	private:
	del_ptr &operator=(del_ptr &rhs);
};

int main(int, char**) {
	return 0;
};
#endif

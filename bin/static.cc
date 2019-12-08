#include <syscall.hh>
#include <fmt.hh>

extern "C" {
	static int calc() {
		write(2,L(__PRETTY_FUNCTION__));
		write(2,L("\n"));
		return 42;
	};
};
static int stat_int=calc();
using namespace fmt;
void write_hex(unsigned long val)
{
	union {
		char buf[32];
		char buf2[35];
	};
	char *end=buf+sizeof(buf)-1;
	char *str=end;
	*--str=0;
	*--str='\n';
	str=fmt_hex(val,buf,str);
	write(1,str,end);
};
template<typename type, size_t n>
void what_type(type (&t)[n]){
	write(1,L(__PRETTY_FUNCTION__));
};
template<typename type>
void what_type(const type &t) {
	write(1,L(__PRETTY_FUNCTION__));
};

inline int poll(pollfd ufds, uint32_t nfds, int64_t tm) __attribute__ ((__always_inline__));
int main(int, char**){
	write(1,L(__PRETTY_FUNCTION__));
//   	what_type(__PRETTY_FUNCTION__);
//   	what_type("test\n");
//   	char buf[]="This is a test\n";
//   	what_type(buf);
//   	write(1,"hi!\n",4);
//   	write_hex(stat_int);
//   	write_hex(calc());
	return 0;
};

#include <syscall.hh>
#include <new.hh>
//#include <cxxabi.h>

auto memcmp_addr=&memcmp;
auto memchr_addr=&memchr;
auto memcpy_addr=&memcpy;
auto memset_addr=&memset;
auto memmove_addr=&memmove;
auto strcmp_addr=&strcmp;
extern "C" {
	int __stack_chk_fail() {
		abort();
	};
};
class base {
	public:
	virtual ~base()
 	{
	};
};
class derived1 : public base {
	public:
	~derived1()
	{
	};
};
class derived2 : public base {
	public:
	~derived2()
	{
	};
};

int main(int, char**) {
//   	write(1,typeid(base()).name());
//   	write(1,L("\n"));
//   	write(1,typeid(derived1()).name());	
//   	write(1,L("\n"));
//   	write(1,typeid(derived2()).name());	
//   	write(1,L("\n"));
//   	try {
//   		throw "test";
//   	} catch (const char *ex) {
//   		write(1,ex);
//   	};
	return 0;
};

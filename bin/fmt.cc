#include <syscall.hh>
#include <new.hh>
#include <typeinfo.hh>
#include <fmt.hh>

size_t writeln(fd_t fd, const char *ptr, size_t size = 0)
{
	if(!size)
		size=strlen(ptr);
	size_t res=write(fd,ptr,size);
	res+=write(fd,L("\n"));
	return res;
}
class base {
	public:
		base()
		{
			writeln(1,L(__PRETTY_FUNCTION__));
		}
		virtual int xfunc(int i, int j)
		{
			writeln(1,L(__PRETTY_FUNCTION__));
		};
		virtual ~base()
		{
			writeln(1,L(__PRETTY_FUNCTION__));
		}
};
class derived1 : public virtual base {
	public:
		derived1()
		{
			writeln(1,L(__PRETTY_FUNCTION__));
		}
		virtual int xfunc(int i, int j)
		{
			writeln(1,L(__PRETTY_FUNCTION__));
		};
		virtual ~derived1()
		{
			writeln(1,L(__PRETTY_FUNCTION__));
		}
};
class derived2 : public virtual base {
	public:
		derived2()
		{
			writeln(1,L(__PRETTY_FUNCTION__));
		}
		virtual int xfunc(int i, int j)
		{
			writeln(1,L(__PRETTY_FUNCTION__));
		};
		virtual ~derived2()
		{
			writeln(1,L(__PRETTY_FUNCTION__));
		}
};
class derived12 : public virtual base, virtual derived1, virtual derived2
{
	public:
		derived12()
		{
			writeln(1,L(__PRETTY_FUNCTION__));
		}
		virtual int xfunc(int i, int j)
		{
			writeln(1,L(__PRETTY_FUNCTION__));
		};
		virtual ~derived12()
		{
			writeln(1,L(__PRETTY_FUNCTION__));
		}
};

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

template<typename type>
int write_ptr(fd_t fd, type *ptr) ;
template<>
int write_ptr<void>(fd_t fd, void *ptr) {
	char buf[sizeof(ptr)*4];
	return write(fd, fmt::fmt_ptr((void*)ptr,buf,&buf[sizeof(buf)-1]));
};
template<typename type>
int write_ptr(fd_t fd, type *ptr) 
{
	return write_ptr(fd,(void*)ptr);
};
template<typename type>
int write_ptr(fd_t fd, const del_ptr<type> &ptr) 
{
	return write_ptr(fd,(void*)ptr);
};
template<typename type>
int writeln_ptr(fd_t fd, type *ptr) 
{
	char buf[sizeof(ptr)*4];
	return writeln(fd, fmt::fmt_ptr((void*)ptr,buf,&buf[sizeof(buf)-1]));
}
template<typename type>
int writeln_ptr(fd_t fd, const del_ptr<type> &ptr) 
{
	return writeln_ptr(fd,(void*)ptr);
};
extern "C" void __cxa_bad_typeid () {
	write(2,L("bad typeid!\n"));
}
int main(int, char**) {
	writeln(1,typeid(base()).name());
	writeln(1,typeid(derived1()).name());	
	writeln(1,typeid(derived2()).name());	
	writeln(1,typeid(derived12()).name());	
	del_ptr<base> base_ptr=new base();
	del_ptr<base> derived1_ptr=new derived1();
	del_ptr<base> derived2_ptr=new derived2();
	del_ptr<base> derived12_ptr=new derived12();
#define show_val(t,x) \
	do { \
		write(1,#x "                                                  ",50); \
		writeln ## t(1,x); \
	}while(false)

	show_val(_ptr,base_ptr);
	show_val(_ptr,derived1_ptr);
	show_val(_ptr,derived2_ptr);
	show_val(_ptr,derived12_ptr);
	show_val(_ptr,dynamic_cast<base*>(derived12_ptr.get()));
	show_val(_ptr,dynamic_cast<derived1*>(derived12_ptr.get()));
	show_val(_ptr,dynamic_cast<derived2*>(derived12_ptr.get()));
//	show_val(,cplus_demangle(typeid(&derived2::xfunc).name(),0));

	auto &tid1=typeid(*base_ptr.get());
	write(1,L("tid1: "));
	writeln(1,tid1.name());
	write(1,L("dyc1: "));
	writeln_ptr(1,dynamic_cast<derived1*>(derived1_ptr.get()));
	write(1,L("dyc2: "));
	writeln_ptr(1,dynamic_cast<derived2*>(derived1_ptr.get()));
	write(1,L("dyc3: "));
	writeln_ptr(1,dynamic_cast<derived2*>(derived2_ptr.get()));
	write(1,L("dyc4: "));
	writeln_ptr(1,dynamic_cast<derived1*>(derived2_ptr.get()));
	writeln(1,typeid(dynamic_cast<derived1*>(derived1_ptr.get())).name());
#define show_typeid(x) \
	do { \
		write(1,L(#x " : ")); \
		writeln(1,typeid(x).name()); \
		write(1,L(#x "*: ")); \
		writeln(1,typeid(x*).name()); \
		write(1,L(#x "&: ")); \
		writeln(1,typeid(x&).name()); \
	}while(false)

#define show_int_typeid(x) \
	show_typeid(x); show_typeid(signed x); show_typeid(unsigned x);
	show_int_typeid(char);
	show_int_typeid(short);
	show_int_typeid(int);
	show_int_typeid(long);
	show_int_typeid(long long);

	write(1,typeid(derived1_ptr.get()).name());
	write(1,typeid(derived2_ptr.get()).name());

//   	try {
//   		throw "test";
//   	} catch (const char *ex) {
//   		write(1,ex);
//   	};
	return 0;
};

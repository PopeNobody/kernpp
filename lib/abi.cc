#include <syscall.hh>

extern "C" {
	void __cxa_pure_virtual() { 
		write_lit(2,"pure virtual function called\n");
		abort();
	}

	void __cxa_guard_release(void*)
	{
		write_lit(1,__PRETTY_FUNCTION__);
		write_lit(1,"\n");
	};
	void __cxa_guard_acquire(void*)
	{
		write_lit(1,"hi!\n");
		write_lit(1,"\n");
	};
	void * __dso_handle=(void*)&__dso_handle;

	int __cxa_atexit(
			void (*func) (void *), 
			void * arg, 
			void * dso_handle
			)
	{
		write_lit(2,__PRETTY_FUNCTION__);
		write_lit(2,"\n");
	}
}

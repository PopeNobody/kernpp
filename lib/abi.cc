#include <syscall.hh>

extern "C" {
	void __cxa_pure_virtual() { 
		write(2,L("pure virtual function called\n"));
		abort();
	}

	void __cxa_guard_release(void*)
	{
		write(1,L(__PRETTY_FUNCTION__));
		write(1,L("\n"));
	};
	void __cxa_guard_acquire(void*)
	{
		write(1,L("hi!\n"));
		write(1,L("\n"));
	};
	void * __dso_handle=(void*)&__dso_handle;

	typedef void (*atexit_func_t) (void *); 
	int atexit(atexit_func_t func);
	int __cxa_atexit(
			atexit_func_t func,
			void * arg, 
			void * dso_handle
			)
	{
		atexit(func);
	}
}

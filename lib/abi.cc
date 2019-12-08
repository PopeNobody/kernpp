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

	int __cxa_atexit(
			void (*func) (void *), 
			void * arg, 
			void * dso_handle
			)
	{
		write(2,L(__PRETTY_FUNCTION__));
		write(2,L("\n"));
	}
}

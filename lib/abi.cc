#include <syscall.hh>

extern "C" {
	void __cxa_pure_virtual() { 
		write(2,"pure virtual function called\n");
		abort();
	}

	void __cxa_guard_release(void*)
	{
		write(1,__PRETTY_FUNCTION__,sizeof(__PRETTY_FUNCTION__));
		write(1,"\n",1);
	};
	void __cxa_guard_acquire(void*)
	{
		write(1,"hi!\n",4);
		write(1,"\n",1);
	};
	void * __dso_handle=(void*)&__dso_handle;

	int __cxa_atexit(
			void (*func) (void *), 
			void * arg, 
			void * dso_handle
			)
	{
		write(2,__PRETTY_FUNCTION__);
		write(2,"\n");
	}
}

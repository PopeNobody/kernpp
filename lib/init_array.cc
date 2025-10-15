#include <types.hh>
#include <syscall.hh>
using std::size_t;
using std::ssize_t;
using std::uint8_t;
using sys::write;
extern void (*__preinit_array_start []) (void) __attribute__((weak));
extern void (*__preinit_array_end []) (void) __attribute__((weak));
extern void (*__init_array_start []) (void) __attribute__((weak));
extern void (*__init_array_end []) (void) __attribute__((weak));
extern void (*__fini_array_start []) (void) __attribute__((weak));
extern void (*__fini_array_end []) (void) __attribute__((weak));

#ifndef L
#define L(x) x,sizeof(x)-1
#endif
using std::fd_t;

extern "C" {
	void _init();
	void _fini();
	void exit(int return_code) __attribute__((noreturn));

	void libc_init() {
		size_t count, i;

		count = __preinit_array_end - __preinit_array_start;
		for (i = 0; i < count; i++)
			__preinit_array_start[i]();

		count = __init_array_end - __init_array_start;
		for (i = 0; i < count; i++)
			__init_array_start[i]();
	}

	void libc_fini() {
		ssize_t count, i;

		count = __fini_array_end - __fini_array_start;
		for (i = count - 1; i >= 0; i--)
    {
      __fini_array_start[i]();
    };

	}

#define MAX_ATEXIT 32

	typedef void(*atexit_func_t)(void);
	typedef void(*cxa_atexit_func_t)(void *);
	struct exit_func {
		enum {
			ef_none=0,
			ef_c,
			ef_cxa
		} flavor;
		union {
			struct {
				cxa_atexit_func_t func;
				void *arg;
			} cxa;
		 	struct {
				void *dummy;
				atexit_func_t func;
			} c;
		};
		void call() {
			switch(flavor) {
				case ef_c:
					c.func();
					break;
				case ef_cxa:
					cxa.func(cxa.arg);
					break;
				case ef_none:
					write(2,L("Tried to call 'ef_none' exit func\n"));
					break;
				default:
					write(2,L("Tried to call invalid exit func\n"));
					break;
			};
		};
		exit_func( atexit_func_t func )
			: flavor(ef_c)
		{
			c.func=func;
		};
		exit_func( cxa_atexit_func_t func, void *arg )
			: flavor(ef_cxa)
		{
			cxa.func=func;
			cxa.arg=arg;
		};
		exit_func()
			: flavor(ef_none)
		{
		};
	};
	char func_buf[MAX_ATEXIT*sizeof(exit_func)];
	exit_func *funcs=(exit_func*)(0+func_buf);
	static size_t nfunc=0;

	int __cxa_atexit(
			cxa_atexit_func_t func,
			void * arg, 
			void * dso_handle
			)
	{
		if(nfunc>=MAX_ATEXIT){
			write(2,L("Too many atexit funcs\n"));
			exit(1);
		};
		funcs[nfunc++]=exit_func(func,arg);
		return 0;
	}
	int atexit(atexit_func_t func) {

		funcs[nfunc++] = func;
		return 0;
	}
	void exit(int return_code) {
		int i=nfunc;
		while(i)
			funcs[--i].call();	
    libc_fini();
    sys::exit(return_code);
	}

}

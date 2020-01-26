#include <debug.hh>
typedef unsigned long size_t;
typedef long ssize_t;
typedef unsigned char uint8_t;

extern void (*__preinit_array_start []) (void) __attribute__((weak));
extern void (*__preinit_array_end []) (void) __attribute__((weak));
extern void (*__init_array_start []) (void) __attribute__((weak));
extern void (*__init_array_end []) (void) __attribute__((weak));
extern void (*__fini_array_start []) (void) __attribute__((weak));
extern void (*__fini_array_end []) (void) __attribute__((weak));

#define L(x) x,sizeof(x)-1
inline ssize_t write( fd_t fd,  const char *buf,  size_t len)
{
	long res;
	asm (
			"syscall\n"
			: "=a"(res)
			: "a"(1), "D"(fd), "S"(buf),"d"(len)
			: "rcx", "r11", "memory"
			);
	return res;
};
extern "C" {
	void _init();
	void _fini();
	void _exit(int return_code) __attribute__((noreturn));
	inline void _exit(int res)
	{
		int exit_val;
		exit_val=res&0xff;
		asm (
				"syscall\n" 
				: "=a"(res) 
				: "a"(60), "D"(exit_val)
				: "rcx", "r11", "memory"
				);
		while(1);
	}


	static void __libc_init_array() {
		size_t count, i;

		count = __preinit_array_end - __preinit_array_start;
		for (i = 0; i < count; i++)
			__preinit_array_start[i]();

		//_init();

		count = __init_array_end - __init_array_start;
		for (i = 0; i < count; i++)
			__init_array_start[i]();
	}

	static void __libc_fini_array() {
		ssize_t count, i;

		count = __fini_array_end - __fini_array_start;
		for (i = count - 1; i >= 0; i--)
                {
                  debug(i);
                  debug((void*)__fini_array_start[i]);
                  __fini_array_start[i]();
                };

		//_fini();
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
			_exit(1);
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

		__libc_fini_array();
		_exit(return_code);
	}

	void libc_init() {
		__libc_init_array();
	}
}

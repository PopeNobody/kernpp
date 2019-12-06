#include <syscall.hh>

extern "C" {
	int exit_val=-1;
	int errno=0;
};
extern "C" {
	void dump_args(int argc, char**argv) {
		while(*argv){
			write(1,*argv,strlen(*argv));
			write(1,"\n",1);
			++argv;
		};
	};
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
};

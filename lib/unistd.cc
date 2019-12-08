#include <syscall.hh>

namespace {
	int init_errno(){
		write(1,"init_errno()\n");
		return 0;
	};
};
extern "C" {
	int errno=init_errno();
};

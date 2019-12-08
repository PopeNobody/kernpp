#include <syscall.hh>

int main(int, char**argv) {
	if(!argv || !*argv) {
		write(2,L("missing program name"));
		return 1;
	};
	return 0;
};

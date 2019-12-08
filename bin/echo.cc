#include <syscall.hh>

void err_exit(const char *message){
	ssize_t res=write(2,message);
	exit(1);
};
int main(int argc, char*argv[]) {
	++argv;
	if(*argv)
		write(1, *argv++);
	while(*argv) {
		write(1,L(" "));
		write(1, *argv++);
	};
	write(1, L("\n"));
	return 0;
};

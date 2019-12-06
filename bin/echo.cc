#include <syscall.hh>

void err_exit(const char *message){
	ssize_t res=write(2,message);
	exit(1);
};
static char argv_null[]="no argv!\n";
int main(int argc, char*argv[]) {
	++argv;
	if(*argv)
		write(1, *argv++);
	while(*argv) {
		write(1," ",1);
		write(1, *argv++);
	};
	write(1, "\n", 1);
	return 0;
};

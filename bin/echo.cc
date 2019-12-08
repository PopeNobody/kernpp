#include <syscall.hh>

void err_exit(const char *message){
	ssize_t res=write(2,(char*)message);
	exit(1);
};
static char argv_null[]="no argv!\n";
int main(int argc, char*argv[]) {
	++argv;
	if(*argv)
		write(1, *argv++);
	while(*argv) {
		write_lit(1," ");
		write(1, *argv++);
	};
	write_lit(1, "\n");
	return 0;
};

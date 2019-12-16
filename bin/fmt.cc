#include <syscall.hh>

int main(int, char**) {
	char *name=0;
	write(1,L("TEST"));
	//name=typeid(name).name();	
	return 0;
};

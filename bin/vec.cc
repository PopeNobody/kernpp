#include <syscall.hh>

extern "C" {
	void *malloc(size_t size){
		if(!size)
			return nullptr;
	};
	void free(void *ptr)
	{
	};
};
int main(int, char**argv) {
	if(!argv || !*argv) {
		write(2,"missing program name");
		return 1;
	};
	return 0;
};

#include <syscall.hh>

int main(int, char**){
	void *addr=0;
	size_t length=16;
	size_t prot=0x3;
	size_t flags=0x21;
	int fd=-1;
	off_t offset=0;
	char *res1=mmap( 0, 4*1024, 0x3, 0x21, -1, 0);
	char *res2=mmap( res1, 4*2*1024, 0x3, 0x10|0x21, -1, 0);
	char *res3=mmap( res1, 4*4*1024, 0x3, 0x10|0x21, -1, 0);
	for(int i=0;i<9*1024;i++){
		res1[i]='a';
	}
	return 0;
};

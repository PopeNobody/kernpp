#include <syscall.hh>


//   static char hex_dig(char val)
//   {
//   	static char digs[]="0123456789abcdef";
//   	return digs[val&0xf];
//   };
//   static ssize_t fmt(int fd, uint64_t val){
//   	char buf[2+sizeof(val)*2 + 2];
//   	char *end=buf+sizeof(buf);
//   	char *pos=buf;
//   	*--end='\0';
//   	*--end='\n';
//   	*pos++='0';
//   	*pos++='x';
//   	while(end>pos){
//   		*--end=hex_dig(val);
//   		val/=0x10;
//   	};
//   	return write(fd,buf);
//   };
//   static ssize_t fmt(int fd, void * ptr){
//   	uint64_t val=uint64_t(ptr);
//   	char buf[2+sizeof(val)*2 + 2];
//   	char *end=buf+sizeof(buf);
//   	char *pos=buf;
//   	*--end='\0';
//   	*--end='\n';
//   	*pos++='0';
//   	*pos++='x';
//   	while(end>pos){
//   		*--end=hex_dig(val);
//   		val/=0x10;
//   	};
//   	return write(fd,buf);
//   };
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

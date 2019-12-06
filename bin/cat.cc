#include <syscall.hh>

ssize_t full_write(int fd, const char * const beg, const char *end){
	const char*pos=beg;
	while(pos!=end){
		ssize_t res=write(fd,pos,end-pos);
		if(res<0)
			return -1;
		pos+=res;
	};
	return pos-beg;
};
static char buf[1L<<16];
bool catfile(int fd) {
	ssize_t res=0;
	while((res=read(fd,buf,sizeof(buf)))>0)
	{
		ssize_t wres=full_write(1,buf,buf+res);
		if(wres!=res){
			write(2,"write error\n");
			return false;
		};
	}
	if(res<0)
		write(2,"read error\n");
	return !res;
};
int main(int argc, char**argv) {
	++argv;
	if(*argv) {
		while(*argv)
		{
			int fd=open(*argv,0);
			if(fd<0){
				write(2,"open error\n");
				return 1;
			};
			catfile(fd);
			close(fd);
			++argv;
		}	
	} else {
		catfile(0);
	};
	return 0;
};

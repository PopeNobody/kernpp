#include <syscall.hh>




int main(int, char**) {
	char buf[1024];
	ssize_t nr=read(0,buf,sizeof(buf));
	if(nr<0) {
		write(2,L("read(0,buf,sizeof(buf)) failed\n"));
		return 1;
	};
	char *pos=buf;
	char *end=buf+nr;
	while(pos<end) {
		ssize_t nw=write(1,pos,end-pos);
		if(nw<0) {
			write(2,L("write failed"));
			return 2;
		};
		pos+=nw;
	};

	return 0;
};

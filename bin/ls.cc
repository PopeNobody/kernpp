#include <syscall.hh>
#include <new.hh>
#include <fmt.hh>

enum open_mode {
	o_rdonly  =  0000,
	o_wronly  =  0001,
	o_rdwr    =  0002,
	o_mask    =  0003,
};
enum open_flags {
	o_creat      =  00000100,
	o_excl       =  00000200,
	o_noctty     =  00000400,
	o_trunc      =  00001000,
	o_append     =  00002000,
	o_nonblock   =  00004000,
	o_dsync      =  00010000,
	o_fasync     =  00020000,
	o_direct     =  00040000,
	o_largefile  =  00100000,
	o_directory  =  00200000,
	o_nofollow   =  00400000,
	o_noatime    =  01000000,
	o_cloexec    =  02000000,
};

void handle_error(errno_t err, const char *call)
{
	char buf[1024];
	char *pos=buf;
	char *end=buf+sizeof(buf);
	while(*call)
		*pos++=*call++;
	*pos++=':';
	call = " error\n";
	while(*call)
		*pos++=*call++;
	write(2,buf,pos-buf);
	exit(1);

};
char buffer[4096];
bool lsarg(const char *dirname){
	int fd = open(dirname,o_directory|o_rdonly);
	if(fd<0)
		return false;
	for(;;){
		int nread=getdents(fd,(linux_dirent*)buffer,sizeof(buffer)-4);
		if(nread<0)
			handle_error(errno_t(-nread), "getdents");
		else if (nread==0)
			return 0;
		auto beg = reinterpret_cast<linux_dirent*>(&buffer[0]);
		auto end = reinterpret_cast<linux_dirent*>(&buffer[nread]);
		while(beg!=end){
			if(*beg->d_name != '.') {
				write(1,beg->d_name,strlen(beg->d_name));
				write(1,"\n",1);
			};
			beg=beg->next();
		};
	};
};
using namespace fmt;
template <typename val_t>
ssize_t write_dec(val_t val, int width=0){
	bool neg=val<0;
	if(neg)
		val*=-1;
	char buf[sizeof(val)*4];
	char *end=buf+sizeof(buf);
	*--end=0;
	char *pos=end;
	pos=fmt_dec(val,buf,end);
	if(neg)
		*--pos='-';
	while(end-pos<width)
		*--pos=' ';
	return write(1,pos,end);
};

using namespace fmt;

int main(int argc, char**argv) 
{
	write_lit(1,"main called with argc=");
	write_dec(argc);
	write_lit(1,"\n");

	int *argl = new int[argc];
	for(int i=0;i<argc;i++) {
		argl[i]=strlen(argv[i]);
	};
	for(int i=0;i<argc;i++){
		write_dec(argl[i],10);
		write_lit(1," ");
		write(1,argv[i],argl[i]);	
		write_lit(1,"\n");
	};	

//	throw "test\n";
	return 0;
};

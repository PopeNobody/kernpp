#include <syscall.hh>
#include <new.hh>
#include <fmt.hh>
#include "getopt.h"

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
template<typename int_t>
void write_dec(fd_t fd, int_t val) {
	char buf[sizeof(val)*5];
	char *end=&buf[sizeof(buf)-1];
	char *str=fmt::fmt_dec(val,buf,end);
	while(str<end) {
		int res=write(fd,str,end);
		if(res<0)
			handle_error(errno,"write");
		str+=res;
	};
};
template<typename type_t>
struct free_ptr {
	type_t *ptr;
	free_ptr(type_t *ptr)
		: ptr(ptr)
	{
	};
	~free_ptr()
	{
		free(ptr);
	};
	operator type_t*() const
	{
		return ptr;
	};
};
void lsdir(int fd) {
	enum { size = 4096 };
	free_ptr<char> buf = (char*)malloc(size);
	for(;;){
		int nread=getdents(fd,(linux_dirent*)(char*)buf,size);
		if(nread<0)
			handle_error(errno_t(-nread), "getdents");
		else if (nread==0)
			return;
		auto beg = reinterpret_cast<linux_dirent*>(&buf[0]);
		auto end = reinterpret_cast<linux_dirent*>(&buf[nread]);
		while(beg!=end){
			if(*beg->d_name != '.') {
				write(1,beg->d_name);
				write(1,L("\n"));
			};
			beg=beg->next();
		};
	};
};
void lsarg(const char *path)
{
	int fd = open(path,o_directory|o_rdonly);
	if(fd>=0)
	{
		lsdir(fd);
	} else if ( errno == ENOTDIR ) {
		write(1,path);
		write(1,"\n",1);
	} else {
		write(2,"open: ");
		write(2,path);
		write(2," failed (");
		char buf[32];
		char *end=&buf[sizeof(buf)-1];
		char *str=fmt::fmt_dec(errno,buf,end);
		write(2,str,end);
		write(2,")\n");
	};
	close(fd);
};
using namespace fmt;

int main(int argc, char**argv) 
{
	char ch;
	while((ch=getopt(argc,argv,"s"))!=-1)
	{
		write(1,"getopt()=>");
		write(1,&ch,1);
		write(1,"\n");
	};
	if(optind<argc) {
		for(int i=optind;i<argc;i++){
			lsarg(argv[i]);
		};
	} else {
		lsarg(".");
	};
	return 0;
};

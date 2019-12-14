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
#define assert(x) do{auto r=(x);if(!r){handle_error(-1,#x);};}while(0)

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
#if 0
#define ENTER do { write(2,L(__PRETTY_FUNCTION__)); write(2,L("\n")); } while(0)
#else
#define ENTER do { ; } while(0)
#endif
template<typename type_t>
struct free_ptr {
	type_t *ptr;
	free_ptr(type_t *ptr)
		: ptr(ptr)
	{
		ENTER;
	};
	~free_ptr()
	{
		ENTER;
		free(ptr);
		ptr=0;
	};
	type_t *drop()
	{
		ptr=0;
	};
	operator type_t*() const
	{
		ENTER;
		return ptr;
	};
};
struct dirents_t {
	struct ent_t {
		bool dir;
		char name[256];
		ent_t()
			:dir(false)
		{
		};
		ent_t(const char *_name)
			:dir(false)
		{
			strncpy(name,_name,sizeof(name));
		};
	};
	size_t cap;
	size_t cnt;
	ent_t **lst;
	dirents_t()
		: lst(0), cap(0), cnt(0)
	{
	};
	int cmp(ent_t &lhs, ent_t&rhs) {
		if(lhs.dir != rhs.dir) {
			return lhs.dir?1:-1;
		};
		return strcmp(lhs.name,rhs.name);
	};
	void sort() {
		size_t n=size();
		for(int i=0;i<n-2;i++) {
			int m=i;
			for(int j=i+1;j<n;j++) {
				if(cmp(*lst[m],*lst[j])<0){
					m=j;
				};
				if(i!=m) {
					ent_t *tmp=lst[i];
					lst[i]=lst[m];
					lst[m]=tmp;
				};
			};
		};
	};
	~dirents_t() {
		delete[] lst;
	};
	void push_back(const char *name)
	{
		if(cnt==cap) {
			if(cap) {
				ent_t **nlst = new ent_t*[cap+16];
				memcpy(nlst,lst,sizeof(ent_t*)*cap);
				delete[] lst;
				lst=nlst;
			} else {
				lst = new ent_t*[16];
			};
			cap+=16;
		};
		lst[cnt++]=new ent_t(name);
	};
	ent_t &get(size_t pos)
	{
		return *lst[pos];
	};
	size_t size() const {
		return cnt;
	};
};
enum ignore_t {
	normal,
	minimal,
	dot_dot,
} ignore;
void lsdir(int fd) {
	enum { size = 4096 };
	dirents_t ents;
	char buf[size];
	for(;;){
		assert((void*)buf);
		int nread=getdents(fd,(linux_dirent*)(char*)buf,size);
		if(nread<0)
			handle_error(errno_t(-nread), "getdents");
		else if (nread==0)
			break;
		auto beg = reinterpret_cast<linux_dirent*>(&buf[0]);
		auto end = reinterpret_cast<linux_dirent*>(&buf[nread]);
		while(beg!=end) {
			ents.push_back(beg->d_name);
			beg=beg->next();
		};
	};
	ents.sort();
	for(size_t i=0;i<ents.size();i++)
	{
		write(1,ents.get(i).name);
		write(1,L("\n"));
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

static option longopts[]={
	{ "version", 0, 0, 1 },
	{ "help",    0, 0, 2 },
	{ 0, 0, 0, 0}
};
const char help_msg[]=
"Usage: /bin/ls [OPTION]... [FILE]...\n"
"List information about the FILEs (the current directory by default).\n"
"Sort entries alphabetically if none of -cftuvSUX nor --sort is specified.\n"
"\n"
"Mandatory arguments to long options are mandatory for short options too.\n"
"  -a, --all                  do not ignore entries starting with .\n"
"  -A, --almost-all           do not list implied . and ..\n"
"  -b, --escape               print C-style escapes for nongraphic characters\n"
"  -d, --directory            list directories themselves, not their contents\n"
"      --help     display this help and exit\n"
"      --version  output version information and exit\n"
"\n"
"Exit status:\n"
" 0  if OK,\n"
" 1  if minor problems (e.g., cannot access subdirectory),\n"
" 2  if serious trouble (e.g., cannot access command-line argument).\n"
;
int help(int res)
{
	write((res?2:1),L(help_msg));
};
int version() {
	write(1,L("ls (kernpp) 1.0\n"));
	return 0;
};
int main(int argc, char**argv) 
{
	int ch;
	int longidx=0;
	while((ch=getopt_long(argc,argv,"aA",longopts,&longidx))!=-1)
	{
		switch(ch) {
			case 1: return version();
			case 2: return help(0);
			case 'a': ignore=minimal; break;
			case 'A': ignore=dot_dot; break;
			default: return help(1);
		};
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

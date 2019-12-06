#include <syscall.hh>

typedef long unsigned int off64_t;
typedef long unsigned int ino64_t;
typedef long errno_t;
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
struct linux_dirent {
	ino64_t        d_ino;    /* 64-bit inode number */
	off64_t        d_off;    /* 64-bit offset to next structure */
	unsigned short d_reclen; /* Size of this dirent */
	unsigned char  d_type;   /* File type */
	char           d_name[]; /* Filename (null-terminated) */

	linux_dirent *next() {
		return (linux_dirent*)(((char*)this)+this->d_reclen);
	};
};
static union {
	char buffer[4096];
	linux_dirent ent;
};

bool long_list=false;
int lsdir(const char *dirname){
	int fd = open(dirname,o_directory|o_rdonly);
	if(fd<0)
		handle_error(errno_t(-fd), "open");
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
struct options {
	char *prog_name;
	int argc;
	bool l_flag;
	char **argv;
	static options parse(int argc, char **argv)
	{
		options res;
		if(argv && argv[0]){
			res.prog_name=*argv++;
			--argc;
			res.argv=argv;
			res.argc=argc;
		} else {
			static char prog_name[] = "(unknown)";
			static char *empty_v[]={nullptr};
			res.prog_name=prog_name;
			res.argc=0;
			res.argv=empty_v;
			res.l_flag=false;
		};
		return res;
	};
	private:
	bool add_arg(char *arg) {
	};
	options() = default;
};
class fmtbuf_t {
	enum { npos=4000 };
	char buf[npos];
	unsigned short pos;
	unsigned short end;
	public:
	fmtbuf_t()
	: pos(0), end(0)
	{
		memset(buf,0,sizeof(buf));
		const char *msg="this is a test\nthis is only a test\n";
		while(*msg)
			buf[end++]=*msg++;
	};
	bool oflow() {
		if(end>pos) {
			ssize_t res=write(1,buf+pos,end-pos);
			if(res<0) {
				write(2,"write faile\n");
				return false;
			};
			pos+=res;
		};
		return true;
	};
};
fmtbuf_t buf;
int ls_main(const options &opts) {
	return 0;
};
int main(int argc, char**argv) 
{
	buf.oflow();
	return ls_main(options::parse(argc,argv));
};

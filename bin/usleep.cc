#include <syscall.hh>
#include <fmt.hh>


void err_exit(const char *message){
	ssize_t res=write(2,message);
	exit(1);
};

using namespace fmt;
static void     handler(int val){
	write(2,L(__PRETTY_FUNCTION__));
	write(2,L("\n"));	
};

int parse_int(const char *beg) {
	int res=0;
	for(char ch=*beg++;true;ch=*beg++) {
		switch (ch) {
			case '\0':
				return res;
			case '0'...'9':
				res=res*10+ch-'0';
				break;
			default:
				write(2,L("bad digit\n"));
				return 0;
		};
	};
};
int main(int argc, char*argv[]) {
	if(argc!=2) {
		write(2,L("Usage: usleep [microseconds]\n"));
		return 1;
	};
	timespec tm;
	unsigned long usecs=uint64_t(parse_int(argv[1]));
	tm.tv_sec=usecs/1000000;
	tm.tv_nsec=(usecs%1000000)*1000;
	write_tm(2,tm);
	write(2,L("\n"));
	int res;
	{
		sigset_t sig1, sig2;
		memset(&sig1,0,sizeof(sig1));
		memset(&sig2,0,sizeof(sig2));
	};
	{
		sigaction_t act = { handler };
		act.sa_flags=0x04000000;
		act.sa_restorer=&rt_sigreturn;

		write_ptr(1,(void*)handler);
		write(1,L("\n"));
		sigaction_t old = { (void(*)(int))9 };

		res=rt_sigaction(14,&act,&old);

		write_ptr(1,(void*)old.sa_handler);
		write(1,L("\n"));

		write_dec(1,res);
		write(1,L("\n"));
	}
	while(tm.tv_sec || tm.tv_nsec) 
	{
		{
			res=alarm(1);
		}
		timespec tm2;
		res=nanosleep(&tm,&tm2);
		write_dec(1,res);
		write(1,L("\n"));
		if(!res)
			break;
		tm=tm2;
		write(1,L("tm: "));
		write_tm(1,tm);
	};
	return 0;
};

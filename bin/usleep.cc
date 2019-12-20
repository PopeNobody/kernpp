#include <syscall.hh>
#include <fmt.hh>


int write_dec(fd_t fd, size_t val) {
	char buf[sizeof(val)*4];
	return write(fd, fmt::fmt_dec(val,buf,&buf[sizeof(buf)-1]));
};
void err_exit(const char *message){
	ssize_t res=write(2,message);
	exit(1);
};

extern "C" void restorer();
asm volatile("restorer:mov $15,%rax\nsyscall");

typedef uint64_t sigset_t;
struct sigaction_t {
	void     (*sa_handler)(int);
	void     (*sa_sigaction)(int, siginfo_t *, void *);
	sigset_t   sa_mask;
	int        sa_flags;
	void     (*sa_restorer)(void);
};
static void     handler(int val){
};

int write_ptr(fd_t fd, void *ptr) {
	char buf[sizeof(ptr)*4];
	return write(fd, fmt::fmt_ptr((void*)ptr,buf,&buf[sizeof(buf)-1]));
};

int main(int argc, char*argv[]) {
	int res;
	{
		sigaction_t act = { handler };
		act.sa_restorer=&restorer;

		write_ptr(1,(void*)handler);
		write(1,L("\n"));
		sigaction_t old = { (void(*)(int))9 };

		res=rt_sigaction(14,&act,&old);

		write_ptr(1,(void*)old.sa_handler);
		write(1,L("\n"));

		write_dec(1,res);
		write(1,L("\n"));
	}
	{
		res=alarm(1);
		write_dec(1,res);
		write(1,L("\n"));
	}
	{
		timespec tm;
		tm.tv_sec=0;
		tm.tv_nsec=100;
		timespec tm2;
		tm2.tv_sec=3;
		tm2.tv_nsec=9;
		write_dec(1,getpid());
		write(1,L("\n"));
		res=nanosleep(&tm,&tm2);
		write_dec(1,res);
		write(1,L("\n"));
	};
	return 0;
};

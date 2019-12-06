#include <syscall.hh>

#define AAI __attribute__ ((__always_inline__)) \
	\

typedef struct stat statbuf;

#define syscall0(name,rt) \
	inline rt name() AAI

#define syscall1(name,a1t,a1,rt) \
	inline rt name(a1t a1) AAI

#define syscall2(name,a1t,a1,a2t,a2,rt) \
	inline rt name(a1t a1, a2t a2) AAI

#define syscall3(name,a1t,a1,a2t,a2,a3t,a3,rt) \
	inline rt name(a1t a1, a2t a2, a3t a3) AAI

#define syscall4(name,a1t,a1,a2t,a2,a3t,a3,a4t,a4,rt) \
	inline rt name(a1t a1, a2t a2, a3t a3, a4t a4) AAI

#define syscall5(name,a1t,a1,a2t,a2,a3t,a3,a4t,a4,a5t,a5,rt) \
	inline rt name(a1t a1, a2t a2, a3t a3, a4t a4, a5t a5) AAI

#define syscall6(name,a1t,a1,a2t,a2,a3t,a3,a4t,a4,a5t,a5,a6t,a6,rt) \
	inline rt name(a1t a1, a2t a2, a3t a3, a4t a4, a5t a5, a6t a6) AAI

#define syscallX(name)


#define sys_calls \
	syscall3(read,fd_t,fd,str_t,buf,size_t,len,ssize_t); \
	syscall3(write,fd_t,fd,const char*,buf,size_t,len,ssize_t); \
	syscall2(open,cstr_t,path,int,flags,fd_t); \
	syscall1(close,fd_t,fd,int); \
	syscall2(stat,cstr_t,path,stat_p,buf,int); \
	syscall2(fstat,fd_t,fd,stat_p,buf,int); \
	syscall2(lstat,cstr_t,path,stat_p,buf,int); \
	syscall3(poll,pollfd*,ufds,uint32_t,nfds,int64_t,tm,int); \
	syscall3(lseek,fd_t,fd,off_t,off,uint32_t,from,ssize_t); \
	syscall6(mmap,void*,addr,size_t,len,int,prot,int,flags,fd_t,fd,off_t,off,char*); \
	syscall3(mprotect,void*,addr,size_t,len,size_t,prot,int); \
	syscall2(munmap,void*,addr,size_t,len,int); \
	syscall1(brk,void*,addr,int); \
	syscall4(rt_sigaction,int,sig,sigaction*,act,sigaction*,oact,size_t,setsize,int);\
	syscall4(rt_sigprocmask,int,how,sigset_t*,nset,sigset_t*,oset,size_t,size,int); \
	syscall1(rt_sigreturn,size_t,x,int); \
	syscall3(ioctl,fd_t,fd,uint32_t,cmd,uint64_t,arg,int); \
	syscall4(pread64,fd_t,fd,str_t,buf,size_t,len,off_t,pos,ssize_t); \
	syscall4(pwrite64,fd_t,fd,cstr_t,buf,size_t,len,off_t,pos,ssize_t); \
	syscall3(readv,fd_t,fd,iovec*,vec,size_t,vlen,ssize_t); \
	syscall3(writev,fd_t,fd,iovec*,vec,size_t,vlen,ssize_t); \
	syscall2(access,cstr_t,path,int,mode,int); \
	syscall1(pipe,fd_t *,fds,int); \
	syscall5(select,int,n,fd_set *,ip,fd_set *,op,fd_set *,ep,timeval*,tv,int);\
	syscall0(sched_yield,void); \
	syscall5(mremap,void*,addr,size_t,olen,size_t,nlen,uint64_t,flags,void *,naddr,void*); \
	syscall3(msync,void*,addr,size_t,len,int,flags,int); \
	syscall3(mincore,void*,addr,size_t,len,str_t,vec,int); \
	syscall3(madvise,void*,addr,size_t,len,int,behavior,int); \
	syscall3(shmget,key_t,key,size_t,size,int,flags,int); \
	syscall3(shmat,int,id,str_t,shmaddr,int,flags,void*); \
	syscall3(shmctl,int,id,int,cmd,shmid_ds*,buf,int); \
	syscall1(dup,fd_t,fd,fd_t); \
	syscall3(dup2,fd_t,ofd,fd_t,nfd,int,flags,fd_t); \
	syscall0(pause,int); \
	syscall2(nanosleep,timespec*,rqtp,timespec*,rmtp,int); \
	syscall2(getitimer,int,which,itimerval*,val,int); \
	syscall1(alarm,uint32_t,secs,int); \
	syscall3(setitimer,int,which,itimerval*,val,itimerval*,oval,int); \
	syscall0(getpid,pid_t); \
	syscall4(sendfile,fd_t,ofd,fd_t,ifd,off_t*,off,size_t,len,ssize_t); \
	syscall3(socket,int,fam,int,type,int,prot,int); \
	syscall3(connect,fd_t,fd,sockaddr*,addr,size_t,len,int); \
	syscall3(accept,fd_t,fd,sockaddr*,addr,int *,plen,int); \
	syscall6(sendto,fd_t,fd,void*,buf,size_t,len,uint32_t,flags,sockaddr*,addr,int,alen,int); \
	syscall6(recvfrom,fd_t,fd,void*,buf,size_t,len,uint32_t,flags,sockaddr*,addr,int*,plen,int); \
	syscall3(sendmsg,fd_t,fd,msghdr*,msg,uint32_t,flags,int); \
	syscall3(recvmsg,fd_t,fd,msghdr*,msg,uint32_t,flags,int); \
	syscall2(shutdown,fd_t,fd,int,how,int); \
	syscall3(bind,fd_t,fd,sockaddr*,addr,size_t,len,int); \
	syscall2(listen,fd_t,fd,int,backlog,int); \
	syscall3(getsockname,fd_t,fd,sockaddr*,addr,size_t,len,int); \
	syscall3(getpeername,fd_t,fd,sockaddr*,addr,size_t*,len,int); \
	syscall4(socketpair,int,fam,int,type,int,prot,int*,sv,int); \
	syscall5(setsockopt,fd_t,fd,int,level,int,name,str_t,val,int,len,int); \
	syscall5(getsockopt,fd_t,fd,int,level,int,name,str_t,val,int,len,int); \
	syscall4(clone,size_t,flags,size_t,newsp,void*,ptid,void*,ctid,int); \
	syscall0(fork,pid_t); \
	syscall0(vfork,pid_t); \
	syscall3(execve,const char*,path,char*const*,argv,char*const*,envp,int); \
	syscall1(exit,int,err,void); \
	syscall4(wait4,pid_t,pid,int*,stat,int,opts,rusage*,ru,int); \
	syscall2(kill,pid_t,pid,sig_t,sig,int); \
	syscall1(uname,utsname*,name,int); \
	syscall3(semget,key_t,key,int,n,int,flags,int); \
	syscall3(semop,int,id,sembuf*,ops,unsigned,nops,int); \
	syscall3(semctl,int,id,sembuf*,ops,unsigned,nops,int); \
	syscall1(shmdt,str_t,addr,void*); \
	syscall2(msgget,key_t,key,int,flag,int); \
	syscall4(msgsnd,int,id,msgbuf*,msg,size_t,len,int,flag,int); \
	syscall5(msgrcv,int,id,msgbuf*,msg,size_t,len,long,type,int,flag,ssize_t); \
	syscall3(msgctl,int,id,int,cmd,msqid_ds*,buf,int); \
	syscall3(fcntl,fd_t,fd,uint32_t,cmd,uint64_t,arg,int); \
	syscall2(flock,fd_t,fd,uint32_t,cmd,int); \
	syscall1(fsync,fd_t,fd,int); \
	syscall1(fdatasync,fd_t,fd,int); \
	syscall2(truncate,str_t,path,size_t,len,int); \
	syscall2(ftruncate,fd_t,fd,size_t,len,int); \
	syscall3(getdents,fd_t,fd,linux_dirent64*,buf,size_t,len,ssize_t); \
	syscall2(getcwd,str_t,buf,size_t,len,char*); \
	syscall1(chdir,str_t,dir,int); \
	syscall1(fchdir,fd_t,fd,int); \
	syscall2(rename,str_t,oname,str_t,nname,int); \
	syscall2(mkdir,str_t,name,int,mode,int); \
	syscall1(rmdir,str_t,name,int); \
	syscall2(creat,str_t,name,int,mode,int);\
	syscall2(link,str_t,oname,str_t,nname,int); \
	syscall1(unlink,str_t,name,int); \
	syscall2(symlink,str_t,oname,str_t,nname,int); \
	syscall3(readlink,str_t,name,str_t,buf,size_t,len,int); \
	syscall2(chmod,str_t,path,mode_t,mode,int); \
	syscall2(fchmod,fd_t,fd,mode_t,mode,int); \
	syscall3(chown,str_t,path,uid_t,user,gid_t,group,int); \
	syscall3(fchown,fd_t,fd,uid_t,user,gid_t,group,int); \
	syscall3(lchown,str_t,path,uid_t,user,gid_t,group,int); \
	syscall1(umask,int,mask,int); \
	syscall2(gettimeofday,timeval*,tv,timezone*,tz,int); \
	syscall2(getrlimit,uint32_t,res,rlimit*,rlim,int); \
	syscall2(getrusage,int,who,rusage*,ru,int); \
	syscall1(sysinfo,sysinfo_p,info,int); \
	syscall1(times,sysinfo_p,info,int); \
	syscall4(ptrace,long,req,pid_t,pid,void *,addr,void*,data,int); \
	syscall0(getuid,uid_t); \
	syscall3(syslog,int,type,str_t,buf,size_t,len,void); \
	syscall0(getgid,gid_t); \
	syscall1(setuid,uid_t,uid,int); \
	syscall1(setgid,gid_t,gid,int); \
	syscall0(geteuid,uid_t); \
	syscall0(getegid,gid_t); \
	syscall2(setpgid,pid_t,pid,pid_t,pgid,int); \
	syscall0(getppid,pid_t); \
	syscall0(getpgrp,pid_t); \
	syscall0(setsid,pid_t); \
	syscall2(setreuid,uid_t,ruid,uid_t,euid,int); \
	syscall2(getregid,gid_t,gid,gid_t,egid,int); \
	syscall2(getgroups,int,len,gid_t*,list,int); \
	syscall2(setgroups,int,len,gid_t*,list,int); \
	syscall3(setresuid,uid_t*,ruid,uid_t*,euid,uid_t*,suid,int); \
	syscall3(getresuid,uid_t*,ruid,uid_t*,euid,uid_t*,suid,int); \
	syscall3(setresgid,gid_t,rgid,gid_t,egid,gid_t,sgid,int); \
	syscall3(getresgid,gid_t*,rgid,gid_t*,egid,gid_t*,sgid,int); \
	syscall1(getpgid,pid_t,pid,pid_t); \
	syscall1(setfsuid,uid_t,uid,pid_t); \
	syscall1(setfsgid,gid_t,gid,pid_t); \
	syscall1(getsid,pid_t,pid,pid_t); \
	syscall2(capget,cap_user_header_t,head,cap_user_data_t,data,int); \
	syscall2(capset,cap_user_header_t,head,cap_user_data_t,data,int); \
	syscall2(rt_sigpending,sigset_t*,set,size_t,len,int); \
	syscall4(rt_sigtimedwait,sigset_t*,set,siginfo_t*,uinfo,timespec*,uts,size_t,len,int); \
	syscall3(rt_sigqueueinfo,pid_t,pid,int,sig,siginfo_t*,info,int); \
	syscall2(rt_sigsuspend,sigset_t*,set,size_t,len,int); \
	syscall2(sigaltstack,stack_t*,uss,stack_t*,uoss,int); \
	syscall2(utime,str_t,path,utimbuf*,times,int); \
	syscall3(mknod,str_t,path,umode_t,mode,unsigned,dev,int); \
	syscallX(uselib); \
	syscall1(personality,uint32_t,pers,int); \
	syscall2(ustat,unsigned,dev,ustat*,ubuf,int); \
	syscall2(statfs,str_t,path,statfs_p,buf,int); \
	syscall2(fstatfs,fd_t,fd,statfs_p,buf,int); \
	syscall3(sysfs,int,opt,uint64_t,arg1,uint64_t,arg2,int); \
	syscall2(getpriority,int,which,int,who,int); \
	syscall3(setpriority,int,which,int,who,int,val,int); \
	syscall2(sched_setparam,pid_t,pid,sched_param*,param,int); \
	syscall2(sched_getparam,pid_t,pid,sched_param*,param,int); \
	syscall3(sched_setscheduler,pid_t,pid,int,pol,sched_param*,param,int); \
	syscall1(sched_get_priority_max,int,pol,int); \
	syscall1(sched_get_priority_min,int,pol,int); \
	syscall2(sched_rr_get_interval,pid_t,pid,timespec*,ts,int); \
	syscall2(mlock,void*,start,size_t,len,int); \
	syscall2(munlock,void*,start,size_t,len,int); \
	syscall1(mlockall,int,flags,int); \
	syscall0(munlockall,int); \
	syscall0(vhangup,int); \
	syscall3(modify_ldt,int,func,void*,ptr,size_t,len,int); \
	syscall2(pivot_root,str_t,nroot,str_t,oroot,int); \
	syscall1(sysctl,sysctl_args*,args,int); \
	syscall5(prctl,int,opt,uint64_t,arg1,uint64_t,arg2,uint64_t,arg3,uint64_t,arg4,int); \
	syscall3(arch_prctl,task_struct*,task,int,code,size_t*,addr,int); \
	syscall1(adjtimex,timex*,tx,int); \
	syscall2(setrlimit,unsigned,resource,rlimit*,rlim,int); \
	syscall1(chroot,str_t,path,int); \
	syscall0(sync,void); \
	syscall1(acct,str_t,name,int); \
	syscall2(settimeofday,timeval*,tv,timezone*,tz,int); \
	syscall5(mount,str_t,dev,str_t,dir,str_t,type,uint64_t,flags,void*,data,int); \
	syscall2(umount,str_t,name,int,flags,int); \
	syscall2(swapon,str_t,name,int,flags,int); \
	syscall1(swapoff,str_t,name,int); \
	syscall4(reboot,int,m1,int,m2,unsigned,cmd,void*,arg,int); \
	syscall2(sethostname,str_t,name,size_t,len,int); \
	syscall2(setdomainname,str_t,name,size_t,len,int); \
	syscall2(iopl,unsigned,level,pt_regs*,regs,int); \
	syscall3(ioperm,size_t,from,size_t,num,int,turnon,int); \
	syscallX(create_module); \
	syscall3(init_module,void*,umod,size_t,len,str_t,args,int); \
	syscall2(delete_module,str_t,name,unsigned,flags,int); \
	syscallX(get_kernel_syms); \
	syscallX(querry_module); \
	syscall4(quotactl,unsigned,cmd,str_t,special,gid_t,gid,void*,addr,int); \
	syscallX(nfsservctl); \
	syscallX(getpmsg); \
	syscallX(putpmsg); \
	syscallX(afs_syscall); \
	syscallX(tuxcall); \
	syscallX(security); \
	syscall0(gettid,int); \
	syscall3(readahead,fd_t,fd,off_t,off,size_t,len,ssize_t); \
	syscall5(setxattr,str_t,path,str_t,name,vptr_t,value,size_t,size,int,flags,int); \
	syscall5(lsetxattr,str_t,path,str_t,name,vptr_t,value,size_t,size,int,flags,int); \
	syscall5(fsetxattr,int,fd,str_t,name,vptr_t,value,size_t,size,int,flags,int); \
	syscall4(getxattr,str_t,path,str_t,name,vptr_t,value,size_t,size,int); \
	syscall4(lgetxattr,str_t,path,str_t,name,vptr_t,value,size_t,size,int); \
	syscall4(fgetxattr,fd_t,fd,str_t,name,vptr_t,value,size_t,size,int); \
	syscall3(listxattr,str_t,name,str_t,list,size_t,size,int); \
	syscall3(llistxattr,str_t,name,str_t,list,size_t,size,int); \
	syscall3(flistxattr,int,fd,str_t,list,size_t,size,int); \
	syscall2(removexattr,str_t,path,str_t,name,int); \
	syscall2(lremovexattr,str_t,path,str_t,name,int); \
	syscall2(fremovexattr,fd_t,fd,str_t,name,int); \
	syscall2(tkill,pid_t,pid,sig_t,sig,int); \
	syscall1(time,time_t*,loc,time_t); \
	syscallX(futex); \
	syscall3(sched_setaffinity,pid_t,pid,unsigned,len,uint64_t*,ump,int);\
	syscall3(sched_getaffinity,pid_t,pid,unsigned,len,uint64_t*,ump,int);\
	syscallX(set_thread_area); \
	syscall2(io_setup,unsigned,nr_events,aio_context_t*,ctxp,int); \
	syscall1(io_destroy,aio_context_t,ctx,int); \
	syscall4(io_getevents,aio_context_t,ctx_id,long,min_nr,long,nr,io_event*,events,int); \
	syscall3(io_submit,aio_context_t,ctx_id,long,nr,iocb**,iocbpp,int); \
	syscall3(io_cancel,aio_context_t,ctx_id,iocb_p,iocb,io_event*,res,int); \
	syscallX(get_thread_area); \
	syscall3(lookup_dcookie,uint64_t,cookie,long,buf,long,len,int); \
	syscall1(epoll_create,int,size,int); \
	syscallX(epoll_ctl_old); \
	syscallX(epoll_wait_old); \
	syscall5(remap_file_pages,void*,start,size_t,size,size_t,prot,size_t,pgoff,size_t,flags,int); \
	syscall3(getdents64,fd_t,fd,linux_dirent64*,dirent,unsigned,count,int); \
	syscall1(get_tid_address,int*,tid,int); \
	syscall0(restart_syscall,int); \
	syscallX(semtimedop); \
	syscall4(fadvise64,fd_t,fd,off_t,off,size_t,len,int,advise,int); \
	syscall3(timer_create,clockid_t,which,sigevent*,spec,timer_t*,res,int); \
	syscall4(timer_settime,timer_t,id,int,flags,itimerspec*,nspec,itimerspec*,ospec,int); \
	syscall2(timer_gettime,timer_t,id,itimerspec*,res,int); \
	syscall1(timer_getoverrun,timer_t,id,int); \
	syscall1(timer_delete,timer_t,id,int); \
	syscall2(clock_settime,clockid_t,which,timespec*,tp,int); \
	syscall2(clock_gettime,clockid_t,which,timespec*,tp,int); \
	syscall2(clock_getres,clockid_t,which,timespec*,tp,int); \
	syscall4(clock_nanosleep,clockid_t,which,int,flags,timespec*,rqtp,timespec*,rmtp,int); \
	syscall1(exit_group,int,err,void); \
	syscall4(epoll_wait,fd_t,epfd,epoll_event*,events,int,maxev,int,timeout,int);\
	syscall4(epoll_ctl,fd_t,epfd,int,op,int,fd,epoll_event*,event,int); \
	syscall3(tgkill,pid_t,tgid,pid_t,pid,sig_t,sig,int); \
	syscall2(utimes,str_t,path,timeval*,utimes,int); \
	syscallX(vserver); \
	syscall6(mbind,void*,start,size_t,len,size_t,mode,size_t*,mask,size_t,maxnode,unsigned,flags,int); \
	syscall3(set_mempolicy,int,mode,size_t*,nmask,size_t,maxnode,int); \
	syscall5(get_mempolicy,int*,policy,size_t*,nmask,size_t,maxnode,void*,addr,long,flags,int); \
	syscall4(mq_open,str_t,name,int,oflag,mode_t,mode,mq_attr*,u_attr,int); \
	syscall1(mq_unlink,str_t,name,int); \
	syscallX(mq_timedsend); \
	syscallX(mq_timedreceive); \
	syscallX(mq_notify); \
	syscallX(mq_getsetattr); \
	syscallX(kexec_load); \
	syscallX(waitid); \
	syscallX(add_key); \
	syscallX(request_key); \
	syscallX(keyctl); \
	syscallX(ioprio_set); \
	syscallX(ioprio_get); \
	syscallX(inotify_init); \
	syscallX(inotify_add_watch); \
	syscallX(inotify_rm_watch); \
	syscallX(migrate_pages); \
	syscall4(openat,fd_t,fd,cstr_t,path,int,flags,mode_t,mode,fd_t); \
	syscall3(mkdirat,fd_t,fd,cstr_t,path,mode_t,mode,int); \
	syscallX(mknodat); \
	syscallX(fchownat); \
	syscallX(futimesat); \
	syscallX(newfstatat); \
	syscallX(unlinkat); \
	syscallX(renameat); \
	syscallX(linkat); \
	syscallX(symlinkat); \
	syscallX(readlinkat); \
	syscallX(fchmodat); \
	syscallX(faccessat); \
	syscallX(pselect6); \
	syscallX(ppoll); \
	syscallX(unshare); \
	syscallX(set_robust_list); \
	syscallX(get_robust_list); \
	syscallX(splice); \
	syscallX(tee); \
	syscallX(sync_file_range); \
	syscallX(vmsplice); \
	syscallX(move_pages); \
	syscallX(utimensat); \
	syscallX(epoll_pwait); \
	syscallX(signalfd); \
	syscallX(timerfd_create); \
	syscallX(eventfd); \
	syscallX(fallocate); \
	syscallX(timerfd_settime); \
	syscallX(timerfd_gettime); \
	syscallX(accept4); \
	syscallX(signalfd4); \
	syscallX(eventfd2); \
	syscallX(epoll_create1); \
	syscallX(dup3); \
	syscallX(pipe2); \
	syscallX(inotify_init1); \
	syscallX(preadv); \
	syscallX(pwritev); \
	syscallX(rt_tgsigqueueinfo); \
	syscallX(perf_event_open); \
	syscallX(recvmmsg); \
	syscallX(fanotify_init); \
	syscallX(fanotify_mark); \
	syscallX(prlimit64); \
	syscallX(name_to_handle_at); \
	syscallX(open_by_handle_at); \
	syscallX(clock_adjtime); \
	syscallX(syncfs); \
	syscallX(sendmmsg); \
	syscallX(setns); \
	syscallX(getcpu); \
	syscallX(process_vm_readv); \
	syscallX(process_vm_writev); \
	syscallX(kcmp); \
	syscallX(finit_module); \
	syscallX(sched_setattr); \
	syscallX(sched_getattr); \
	syscallX(renameat2); \
	syscallX(seccomp); \
	syscallX(getrandom); \
	syscallX(memfd_create); \
	syscallX(kexec_file_load); \
	syscallX(bpf); \
	syscallX(execveat); \
	syscallX(userfaultfd); \
	syscallX(membarrier); \
	syscallX(mlock2); \
	syscallX(copy_file_range); \
	syscallX(preadv2); \
syscallX(pwritev2); \


extern "C" {

sys_calls;
};

int main(int, char**) {
	char buf[1024];
	ssize_t nr=read(0,buf,sizeof(buf));
	if(nr<0) {
		write(2,"read(0,buf,sizeof(buf)) failed\n");
		return 1;
	};
	char *pos=buf;
	char *end=buf+nr;
	while(pos<end) {
		ssize_t nw=write(1,pos,end-pos);
		if(nw<0) {
			write(2,"write failed");
			return 2;
		};
		pos+=nw;
	};

	return 0;
};

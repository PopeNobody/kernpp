#!/usr/bin/perl
1++;
use strict;
use warnings;
our(%call);

BEGIN {
	%call = (
		'read' => {
			'code' => 0,
			'name' => 'read',
			'args' => [
				[
					'unsigned int',
					'fd'
				],
				[
					'char *',
					'buf'
				],
				[
					'size_t',
					'count'
				]
			],
			'ret' => 'int'
		},
		'write' => {
			'code' => 1,
			'name' => 'write',
			'args' => [
				[
					'unsigned int',
					'fd'
				],
				[
					'const char *',
					'buf'
				],
				[
					'size_t',
					'count'
				]
			],
			'ret' => 'int'
		},
		'open' => {
			'code' => 2,
			'name' => 'open',
			'args' => [
				[
					'const char *',
					'filename'
				],
				[
					'int',
					'flags'
				],
				[
					'int',
					'mode'
				]
			],
			'ret' => 'int'
		},
		'close' => {
			'code' => 3,
			'name' => 'close',
			'args' => [
				[
					'unsigned int',
					'fd'
				]
			],
			'ret' => 'int'
		},
		'stat' => {
			'code' => 4,
			'name' => 'stat',
			'args' => [
				[
					'const char *',
					'filename'
				],
				[
					'struct stat *',
					'statbuf'
				]
			],
			'ret' => 'int'
		},
		'fstat' => {
			'code' => 5,
			'name' => 'fstat',
			'args' => [
				[
					'unsigned int',
					'fd'
				],
				[
					'struct stat *',
					'statbuf'
				]
			],
			'ret' => 'int'
		},
		'lstat' => {
			'code' => 6,
			'name' => 'lstat',
			'args' => [
				[
					'fconst char *',
					'filename'
				],
				[
					'struct stat *',
					'statbuf'
				]
			],
			'ret' => 'int'
		},
		'poll' => {
			'code' => 7,
			'name' => 'poll',
			'args' => [
				[
					'struct poll_fd *',
					'ufds'
				],
				[
					'unsigned int',
					'nfds'
				],
				[
					'long',
					'timeout_msecs'
				]
			],
			'ret' => 'int'
		},
		'lseek' => {
			'code' => 8,
			'name' => 'lseek',
			'args' => [
				[
					'unsigned int',
					'fd'
				],
				[
					'off_t',
					'offset'
				],
				[
					'unsigned int',
					'origin'
				]
			],
			'ret' => 'int'
		},
		'mmap' => {
			'code' => 9,
			'name' => 'mmap',
			'args' => [
				[
					'unsigned long',
					'addr'
				],
				[
					'unsigned long',
					'len'
				],
				[
					'unsigned long',
					'prot'
				],
				[
					'unsigned long',
					'flags'
				],
				[
					'unsigned long',
					'fd'
				],
				[
					'unsigned long',
					'off'
				]
			],
			'ret' => 'int'
		},
		'mprotect' => {
			'code' => 10,
			'name' => 'mprotect',
			'args' => [
				[
					'unsigned long',
					'start'
				],
				[
					'size_t',
					'len'
				],
				[
					'unsigned long',
					'prot'
				]
			],
			'ret' => 'int'
		},
		'munmap' => {
			'code' => 11,
			'name' => 'munmap',
			'args' => [
				[
					'unsigned long',
					'addr'
				],
				[
					'size_t',
					'len'
				]
			],
			'ret' => 'int'
		},
		'brk' => {
			'code' => 12,
			'name' => 'brk',
			'args' => [
				[
					'unsigned long',
					'brk'
				]
			],
			'ret' => 'int'
		},
		'rt_sigaction' => {
			'code' => 13,
			'name' => 'rt_sigaction',
			'args' => [
				[
					'int',
					'sig'
				],
				[
					'const struct sigaction *',
					'act'
				],
				[
					'struct sigaction *',
					'oact'
				],
				[
					'size_t',
					'sigsetsize'
				]
			],
			'ret' => 'int'
		},
		'rt_sigprocmask' => {
			'code' => 14,
			'name' => 'rt_sigprocmask',
			'args' => [
				[
					'int',
					'how'
				],
				[
					'sigset_t *',
					'nset'
				],
				[
					'sigset_t *',
					'oset'
				],
				[
					'size_t',
					'sigsetsize'
				]
			],
			'ret' => 'int'
		},
		'rt_sigreturn' => {
			'code' => 15,
			'name' => 'rt_sigreturn',
			'args' => [
				[
					'unsigned long',
					'__unused'
				]
			],
			'ret' => 'int'
		},
		'ioctl' => {
			'code' => 16,
			'name' => 'ioctl',
			'args' => [
				[
					'unsigned int',
					'fd'
				],
				[
					'unsigned int',
					'cmd'
				],
				[
					'unsigned long',
					'arg'
				]
			],
			'ret' => 'int'
		},
		'pread64' => {
			'code' => 17,
			'name' => 'pread64',
			'args' => [
				[
					'unsigned long',
					'fd'
				],
				[
					'char *',
					'buf'
				],
				[
					'size_t',
					'count'
				],
				[
					'loff_t',
					'pos'
				]
			],
			'ret' => 'int'
		},
		'pwrite64' => {
			'code' => 18,
			'name' => 'pwrite64',
			'args' => [
				[
					'unsigned int',
					'fd'
				],
				[
					'const char *',
					'buf'
				],
				[
					'size_t',
					'count'
				],
				[
					'loff_t',
					'pos'
				]
			],
			'ret' => 'int'
		},
		'readv' => {
			'code' => 19,
			'name' => 'readv',
			'args' => [
				[
					'unsigned long',
					'fd'
				],
				[
					'const struct iovec *',
					'vec'
				],
				[
					'unsigned long',
					'vlen'
				]
			],
			'ret' => 'int'
		},
		'writev' => {
			'code' => 20,
			'name' => 'writev',
			'args' => [
				[
					'unsigned long',
					'fd'
				],
				[
					'const struct iovec *',
					'vec'
				],
				[
					'unsigned long',
					'vlen'
				]
			],
			'ret' => 'int'
		},
		'access' => {
			'code' => 21,
			'name' => 'access',
			'args' => [
				[
					'const char *',
					'filename'
				],
				[
					'int',
					'mode'
				]
			],
			'ret' => 'int'
		},
		'pipe' => {
			'code' => 22,
			'name' => 'pipe',
			'args' => [
				[
					'int *',
					'filedes'
				]
			],
			'ret' => 'int'
		},
		'select' => {
			'code' => 23,
			'name' => 'select',
			'args' => [
				[
					'int',
					'n'
				],
				[
					'fd_set *',
					'inp'
				],
				[
					'fd_set *',
					'outp'
				],
				[
					'fd_set*',
					'exp'
				],
				[
					'struct timeval *',
					'tvp'
				]
			],
			'ret' => 'int'
		},
		'sched_yield' => {
			'code' => 24,
			'name' => 'sched_yield',
			'args' => [],
			'ret' => 'int'
		},
		'mremap' => {
			'code' => 25,
			'name' => 'mremap',
			'args' => [
				[
					'unsigned long',
					'addr'
				],
				[
					'unsigned long',
					'old_len'
				],
				[
					'unsigned long',
					'new_len'
				],
				[
					'unsigned long',
					'flags'
				],
				[
					'unsigned long',
					'new_addr'
				]
			],
			'ret' => 'int'
		},
		'msync' => {
			'code' => 26,
			'name' => 'msync',
			'args' => [
				[
					'unsigned long',
					'start'
				],
				[
					'size_t',
					'len'
				],
				[
					'int',
					'flags'
				]
			],
			'ret' => 'int'
		},
		'mincore' => {
			'code' => 27,
			'name' => 'mincore',
			'args' => [
				[
					'unsigned long',
					'start'
				],
				[
					'size_t',
					'len'
				],
				[
					'unsigned char *',
					'vec'
				]
			],
			'ret' => 'int'
		},
		'madvise' => {
			'code' => 28,
			'name' => 'madvise',
			'args' => [
				[
					'unsigned long',
					'start'
				],
				[
					'size_t',
					'len_in'
				],
				[
					'int',
					'behavior'
				]
			],
			'ret' => 'int'
		},
		'shmget' => {
			'code' => 29,
			'name' => 'shmget',
			'args' => [
				[
					'key_t',
					'key'
				],
				[
					'size_t',
					'size'
				],
				[
					'int',
					'shmflg'
				]
			],
			'ret' => 'int'
		},
		'shmat' => {
			'code' => 30,
			'name' => 'shmat',
			'args' => [
				[
					'int',
					'shmid'
				],
				[
					'char *',
					'shmaddr'
				],
				[
					'int',
					'shmflg'
				]
			],
			'ret' => 'int'
		},
		'shmctl' => {
			'code' => 31,
			'name' => 'shmctl',
			'args' => [
				[
					'int',
					'shmid'
				],
				[
					'int',
					'cmd'
				],
				[
					'struct shmid_ds *',
					'buf'
				]
			],
			'ret' => 'int'
		},
		'dup' => {
			'code' => 32,
			'name' => 'dup',
			'args' => [
				[
					'unsigned int',
					'fildes'
				]
			],
			'ret' => 'int'
		},
		'dup2' => {
			'code' => 33,
			'name' => 'dup2',
			'args' => [
				[
					'unsigned int',
					'oldfd'
				],
				[
					'unsigned int',
					'newfd'
				]
			],
			'ret' => 'int'
		},
		'pause' => {
			'code' => 34,
			'name' => 'pause',
			'args' => [],
			'ret' => 'int'
		},
		'nanosleep' => {
			'code' => 35,
			'name' => 'nanosleep',
			'args' => [
				[
					'struct timespec *',
					'rqtp'
				],
				[
					'struct timespec *',
					'rmtp'
				]
			],
			'ret' => 'int'
		},
		'getitimer' => {
			'code' => 36,
			'name' => 'getitimer',
			'args' => [
				[
					'int',
					'which'
				],
				[
					'struct itimerval *',
					'value'
				]
			],
			'ret' => 'int'
		},
		'alarm' => {
			'code' => 37,
			'name' => 'alarm',
			'args' => [
				[
					'unsigned int',
					'seconds'
				]
			],
			'ret' => 'int'
		},
		'setitimer' => {
			'code' => 38,
			'name' => 'setitimer',
			'args' => [
				[
					'int',
					'which'
				],
				[
					'struct itimerval *',
					'value'
				],
				[
					'struct itimerval *',
					'ovalue'
				]
			],
			'ret' => 'int'
		},
		'getpid' => {
			'code' => 39,
			'name' => 'getpid',
			'args' => [],
			'ret' => 'int'
		},
		'sendfile' => {
			'code' => 40,
			'name' => 'sendfile',
			'args' => [
				[
					'int',
					'out_fd'
				],
				[
					'int',
					'in_fd'
				],
				[
					'off_t *',
					'offset'
				],
				[
					'size_t',
					'count'
				]
			],
			'ret' => 'int'
		},
		'socket' => {
			'code' => 41,
			'name' => 'socket',
			'args' => [
				[
					'int',
					'family'
				],
				[
					'int',
					'type'
				],
				[
					'int',
					'protocol'
				]
			],
			'ret' => 'int'
		},
		'connect' => {
			'code' => 42,
			'name' => 'connect',
			'args' => [
				[
					'int',
					'fd'
				],
				[
					'struct sockaddr *',
					'uservaddr'
				],
				[
					'int',
					'addrlen'
				]
			],
			'ret' => 'int'
		},
		'accept' => {
			'code' => 43,
			'name' => 'accept',
			'args' => [
				[
					'int',
					'fd'
				],
				[
					'struct sockaddr *',
					'upeer_sockaddr'
				],
				[
					'int *',
					'upeer_addrlen'
				]
			],
			'ret' => 'int'
		},
		'sendto' => {
			'code' => 44,
			'name' => 'sendto',
			'args' => [
				[
					'int',
					'fd'
				],
				[
					'void *',
					'buff'
				],
				[
					'size_t',
					'len'
				],
				[
					'unsigned',
					'flags'
				],
				[
					'struct sockaddr *',
					'addr'
				],
				[
					'int',
					'addr_len'
				]
			],
			'ret' => 'int'
		},
		'recvfrom' => {
			'code' => 45,
			'name' => 'recvfrom',
			'args' => [
				[
					'int',
					'fd'
				],
				[
					'void *',
					'ubuf'
				],
				[
					'size_t',
					'size'
				],
				[
					'unsigned',
					'flags'
				],
				[
					'struct sockaddr *',
					'addr'
				],
				[
					'int *',
					'addr_len'
				]
			],
			'ret' => 'int'
		},
		'sendmsg' => {
			'code' => 46,
			'name' => 'sendmsg',
			'args' => [
				[
					'int',
					'fd'
				],
				[
					'struct msghdr *',
					'msg'
				],
				[
					'unsigned',
					'flags'
				]
			],
			'ret' => 'int'
		},
		'recvmsg' => {
			'code' => 47,
			'name' => 'recvmsg',
			'args' => [
				[
					'int',
					'fd'
				],
				[
					'struct msghdr *',
					'msg'
				],
				[
					'unsigned int',
					'flags'
				]
			],
			'ret' => 'int'
		},
		'shutdown' => {
			'code' => 48,
			'name' => 'shutdown',
			'args' => [
				[
					'int',
					'fd'
				],
				[
					'int',
					'how'
				]
			],
			'ret' => 'int'
		},
		'bind' => {
			'code' => 49,
			'name' => 'bind',
			'args' => [
				[
					'int',
					'fd'
				],
				[
					'struct sokaddr *',
					'umyaddr'
				],
				[
					'int',
					'addrlen'
				]
			],
			'ret' => 'int'
		},
		'listen' => {
			'code' => 50,
			'name' => 'listen',
			'args' => [
				[
					'int',
					'fd'
				],
				[
					'int',
					'backlog'
				]
			],
			'ret' => 'int'
		},
		'getsockname' => {
			'code' => 51,
			'name' => 'getsockname',
			'args' => [
				[
					'int',
					'fd'
				],
				[
					'struct sockaddr *',
					'usockaddr'
				],
				[
					'int *',
					'usockaddr_len'
				]
			],
			'ret' => 'int'
		},
		'getpeername' => {
			'code' => 52,
			'name' => 'getpeername',
			'args' => [
				[
					'int',
					'fd'
				],
				[
					'struct sockaddr *',
					'usockaddr'
				],
				[
					'int *',
					'usockaddr_len'
				]
			],
			'ret' => 'int'
		},
		'socketpair' => {
			'code' => 53,
			'name' => 'socketpair',
			'args' => [
				[
					'int',
					'family'
				],
				[
					'int',
					'type'
				],
				[
					'int',
					'protocol'
				],
				[
					'int *',
					'usockvec'
				]
			],
			'ret' => 'int'
		},
		'setsockopt' => {
			'code' => 54,
			'name' => 'setsockopt',
			'args' => [
				[
					'int',
					'fd'
				],
				[
					'int',
					'level'
				],
				[
					'int',
					'optname'
				],
				[
					'char *',
					'optval'
				],
				[
					'int',
					'optlen'
				]
			],
			'ret' => 'int'
		},
		'getsockopt' => {
			'code' => 55,
			'name' => 'getsockopt',
			'args' => [
				[
					'int',
					'fd'
				],
				[
					'int',
					'level'
				],
				[
					'int',
					'optname'
				],
				[
					'char *',
					'optval'
				],
				[
					'int *',
					'optlen'
				]
			],
			'ret' => 'int'
		},
		'clone' => {
			'code' => 56,
			'name' => 'clone',
			'args' => [
				[
					'unsigned long',
					'clone_flags'
				],
				[
					'unsigned long',
					'newsp'
				],
				[
					'void *',
					'parent_tid'
				],
				[
					'void *',
					'child_tid'
				]
			],
			'ret' => 'int'
		},
		'fork' => {
			'code' => 57,
			'name' => 'fork',
			'args' => [],
			'ret' => 'int'
		},
		'vfork' => {
			'code' => 58,
			'name' => 'vfork',
			'args' => [],
			'ret' => 'int'
		},
		'execve' => {
			'code' => 59,
			'name' => 'execve',
			'args' => [
				[
					'const char *',
					'filename'
				],
				[
					'const char * const',
					'argv[]'
				],
				[
					'const char * const',
					'envp[]'
				]
			],
			'ret' => 'int'
		},
		'exit' => {
			'code' => 60,
			'name' => 'exit',
			'args' => [
				[
					'int',
					'error_code'
				]
			],
			'ret' => 'int'
		},
		'wait4' => {
			'code' => 61,
			'name' => 'wait4',
			'args' => [
				[
					'pid_t',
					'upid'
				],
				[
					'int *',
					'stat_addr'
				],
				[
					'int',
					'options'
				],
				[
					'struct rusage *',
					'ru'
				]
			],
			'ret' => 'int'
		},
		'kill' => {
			'code' => 62,
			'name' => 'kill',
			'args' => [
				[
					'pid_t',
					'pid'
				],
				[
					'int',
					'sig'
				]
			],
			'ret' => 'int'
		},
		'uname' => {
			'code' => 63,
			'name' => 'uname',
			'args' => [
				[
					'struct old_utsname *',
					'name'
				]
			],
			'ret' => 'int'
		},
		'semget' => {
			'code' => 64,
			'name' => 'semget',
			'args' => [
				[
					'key_t',
					'key'
				],
				[
					'int',
					'nsems'
				],
				[
					'int',
					'semflg'
				]
			],
			'ret' => 'int'
		},
		'semop' => {
			'code' => 65,
			'name' => 'semop',
			'args' => [
				[
					'int',
					'semid'
				],
				[
					'struct sembuf *',
					'tsops'
				],
				[
					'unsigned',
					'nsops'
				]
			],
			'ret' => 'int'
		},
		'semctl' => {
			'code' => 66,
			'name' => 'semctl',
			'args' => [
				[
					'int',
					'semid'
				],
				[
					'int',
					'semnum'
				],
				[
					'int',
					'cmd'
				],
				[
					'union semun',
					'arg'
				]
			],
			'ret' => 'int'
		},
		'shmdt' => {
			'code' => 67,
			'name' => 'shmdt',
			'args' => [
				[
					'char *',
					'shmaddr'
				]
			],
			'ret' => 'int'
		},
		'msgget' => {
			'code' => 68,
			'name' => 'msgget',
			'args' => [
				[
					'key_t',
					'key'
				],
				[
					'int',
					'msgflg'
				]
			],
			'ret' => 'int'
		},
		'msgsnd' => {
			'code' => 69,
			'name' => 'msgsnd',
			'args' => [
				[
					'int',
					'msqid'
				],
				[
					'struct msgbuf *',
					'msgp'
				],
				[
					'size_t',
					'msgsz'
				],
				[
					'int',
					'msgflg'
				]
			],
			'ret' => 'int'
		},
		'msgrcv' => {
			'code' => 70,
			'name' => 'msgrcv',
			'args' => [
				[
					'int',
					'msqid'
				],
				[
					'struct msgbuf *',
					'msgp'
				],
				[
					'size_t',
					'msgsz'
				],
				[
					'long',
					'msgtyp'
				],
				[
					'int',
					'msgflg'
				]
			],
			'ret' => 'int'
		},
		'msgctl' => {
			'code' => 71,
			'name' => 'msgctl',
			'args' => [
				[
					'int',
					'msqid'
				],
				[
					'int',
					'cmd'
				],
				[
					'struct msqid_ds *',
					'buf'
				]
			],
			'ret' => 'int'
		},
		'fcntl' => {
			'code' => 72,
			'name' => 'fcntl',
			'args' => [
				[
					'unsigned int',
					'fd'
				],
				[
					'unsigned int',
					'cmd'
				],
				[
					'unsigned long',
					'arg'
				]
			],
			'ret' => 'int'
		},
		'flock' => {
			'code' => 73,
			'name' => 'flock',
			'args' => [
				[
					'unsigned int',
					'fd'
				],
				[
					'unsigned int',
					'cmd'
				]
			],
			'ret' => 'int'
		},
		'fsync' => {
			'code' => 74,
			'name' => 'fsync',
			'args' => [
				[
					'unsigned int',
					'fd'
				]
			],
			'ret' => 'int'
		},
		'fdatasync' => {
			'code' => 75,
			'name' => 'fdatasync',
			'args' => [
				[
					'unsigned int',
					'fd'
				]
			],
			'ret' => 'int'
		},
		'truncate' => {
			'code' => 76,
			'name' => 'truncate',
			'args' => [
				[
					'const char *',
					'path'
				],
				[
					'long',
					'length'
				]
			],
			'ret' => 'int'
		},
		'ftruncate' => {
			'code' => 77,
			'name' => 'ftruncate',
			'args' => [
				[
					'unsigned int',
					'fd'
				],
				[
					'unsigned long',
					'length'
				]
			],
			'ret' => 'int'
		},
		'getdents' => {
			'code' => 78,
			'name' => 'getdents',
			'args' => [
				[
					'unsigned int',
					'fd'
				],
				[
					'struct linux_dirent *',
					'dirent'
				],
				[
					'unsigned int',
					'count'
				]
			],
			'ret' => 'int'
		},
		'getcwd' => {
			'code' => 79,
			'name' => 'getcwd',
			'args' => [
				[
					'char *',
					'buf'
				],
				[
					'unsigned long',
					'size'
				]
			],
			'ret' => 'int'
		},
		'chdir' => {
			'code' => 80,
			'name' => 'chdir',
			'args' => [
				[
					'const char *',
					'filename'
				]
			],
			'ret' => 'int'
		},
		'fchdir' => {
			'code' => 81,
			'name' => 'fchdir',
			'args' => [
				[
					'unsigned int',
					'fd'
				]
			],
			'ret' => 'int'
		},
		'rename' => {
			'code' => 82,
			'name' => 'rename',
			'args' => [
				[
					'const char *',
					'oldname'
				],
				[
					'const char *',
					'newname'
				]
			],
			'ret' => 'int'
		},
		'mkdir' => {
			'code' => 83,
			'name' => 'mkdir',
			'args' => [
				[
					'const char *',
					'pathname'
				],
				[
					'int',
					'mode'
				]
			],
			'ret' => 'int'
		},
		'rmdir' => {
			'code' => 84,
			'name' => 'rmdir',
			'args' => [
				[
					'const char *',
					'pathname'
				]
			],
			'ret' => 'int'
		},
		'creat' => {
			'code' => 85,
			'name' => 'creat',
			'args' => [
				[
					'const char *',
					'pathname'
				],
				[
					'int',
					'mode'
				]
			],
			'ret' => 'int'
		},
		'link' => {
			'code' => 86,
			'name' => 'link',
			'args' => [
				[
					'const char *',
					'oldname'
				],
				[
					'const char *',
					'newname'
				]
			],
			'ret' => 'int'
		},
		'unlink' => {
			'code' => 87,
			'name' => 'unlink',
			'args' => [
				[
					'const char *',
					'pathname'
				]
			],
			'ret' => 'int'
		},
		'symlink' => {
			'code' => 88,
			'name' => 'symlink',
			'args' => [
				[
					'const char *',
					'oldname'
				],
				[
					'const char *',
					'newname'
				]
			],
			'ret' => 'int'
		},
		'readlink' => {
			'code' => 89,
			'name' => 'readlink',
			'args' => [
				[
					'const char *',
					'path'
				],
				[
					'char *',
					'buf'
				],
				[
					'int',
					'bufsiz'
				]
			],
			'ret' => 'int'
		},
		'chmod' => {
			'code' => 90,
			'name' => 'chmod',
			'args' => [
				[
					'const char *',
					'filename'
				],
				[
					'mode_t',
					'mode'
				]
			],
			'ret' => 'int'
		},
		'fchmod' => {
			'code' => 91,
			'name' => 'fchmod',
			'args' => [
				[
					'unsigned int',
					'fd'
				],
				[
					'mode_t',
					'mode'
				]
			],
			'ret' => 'int'
		},
		'chown' => {
			'code' => 92,
			'name' => 'chown',
			'args' => [
				[
					'const char *',
					'filename'
				],
				[
					'uid_t',
					'user'
				],
				[
					'gid_t',
					'group'
				]
			],
			'ret' => 'int'
		},
		'fchown' => {
			'code' => 93,
			'name' => 'fchown',
			'args' => [
				[
					'unsigned int',
					'fd'
				],
				[
					'uid_t',
					'user'
				],
				[
					'gid_t',
					'group'
				]
			],
			'ret' => 'int'
		},
		'lchown' => {
			'code' => 94,
			'name' => 'lchown',
			'args' => [
				[
					'const char *',
					'filename'
				],
				[
					'uid_t',
					'user'
				],
				[
					'gid_t',
					'group'
				]
			],
			'ret' => 'int'
		},
		'umask' => {
			'code' => 95,
			'name' => 'umask',
			'args' => [
				[
					'int',
					'mask'
				]
			],
			'ret' => 'int'
		},
		'gettimeofday' => {
			'code' => 96,
			'name' => 'gettimeofday',
			'args' => [
				[
					'struct timeval *',
					'tv'
				],
				[
					'struct timezone *',
					'tz'
				]
			],
			'ret' => 'int'
		},
		'getrlimit' => {
			'code' => 97,
			'name' => 'getrlimit',
			'args' => [
				[
					'unsigned int',
					'resource'
				],
				[
					'struct rlimit *',
					'rlim'
				]
			],
			'ret' => 'int'
		},
		'getrusage' => {
			'code' => 98,
			'name' => 'getrusage',
			'args' => [
				[
					'int',
					'who'
				],
				[
					'struct rusage *',
					'ru'
				]
			],
			'ret' => 'int'
		},
		'sysinfo' => {
			'code' => 99,
			'name' => 'sysinfo',
			'args' => [
				[
					'struct sysinfo *',
					'info'
				]
			],
			'ret' => 'int'
		},
		'times' => {
			'code' => 100,
			'name' => 'times',
			'args' => [
				[
					'struct sysinfo *',
					'info'
				]
			],
			'ret' => 'int'
		},
		'ptrace' => {
			'code' => 101,
			'name' => 'ptrace',
			'args' => [
				[
					'long',
					'request'
				],
				[
					'long',
					'pid'
				],
				[
					'unsigned long',
					'addr'
				],
				[
					'unsigned long',
					'data'
				]
			],
			'ret' => 'int'
		},
		'getuid' => {
			'code' => 102,
			'name' => 'getuid',
			'args' => [],
			'ret' => 'int'
		},
		'syslog' => {
			'code' => 103,
			'name' => 'syslog',
			'args' => [
				[
					'int',
					'type'
				],
				[
					'char *',
					'buf'
				],
				[
					'int',
					'len'
				]
			],
			'ret' => 'int'
		},
		'getgid' => {
			'code' => 104,
			'name' => 'getgid',
			'args' => [],
			'ret' => 'int'
		},
		'setuid' => {
			'code' => 105,
			'name' => 'setuid',
			'args' => [
				[
					'uid_t',
					'uid'
				]
			],
			'ret' => 'int'
		},
		'setgid' => {
			'code' => 106,
			'name' => 'setgid',
			'args' => [
				[
					'gid_t',
					'gid'
				]
			],
			'ret' => 'int'
		},
		'geteuid' => {
			'code' => 107,
			'name' => 'geteuid',
			'args' => [],
			'ret' => 'int'
		},
		'getegid' => {
			'code' => 108,
			'name' => 'getegid',
			'args' => [],
			'ret' => 'int'
		},
		'setpgid' => {
			'code' => 109,
			'name' => 'setpgid',
			'args' => [
				[
					'pid_t',
					'pid'
				],
				[
					'pid_t',
					'pgid'
				]
			],
			'ret' => 'int'
		},
		'getppid' => {
			'code' => 110,
			'name' => 'getppid',
			'args' => [],
			'ret' => 'int'
		},
		'getpgrp' => {
			'code' => 111,
			'name' => 'getpgrp',
			'args' => [],
			'ret' => 'int'
		},
		'setsid' => {
			'code' => 112,
			'name' => 'setsid',
			'args' => [],
			'ret' => 'int'
		},
		'setreuid' => {
			'code' => 113,
			'name' => 'setreuid',
			'args' => [
				[
					'uid_t',
					'ruid'
				],
				[
					'uid_t',
					'euid'
				]
			],
			'ret' => 'int'
		},
		'setregid' => {
			'code' => 114,
			'name' => 'setregid',
			'args' => [
				[
					'gid_t',
					'rgid'
				],
				[
					'gid_t',
					'egid'
				]
			],
			'ret' => 'int'
		},
		'getgroups' => {
			'code' => 115,
			'name' => 'getgroups',
			'args' => [
				[
					'int',
					'gidsetsize'
				],
				[
					'gid_t *',
					'grouplist'
				]
			],
			'ret' => 'int'
		},
		'setgroups' => {
			'code' => 116,
			'name' => 'setgroups',
			'args' => [
				[
					'int',
					'gidsetsize'
				],
				[
					'gid_t *',
					'grouplist'
				]
			],
			'ret' => 'int'
		},
		'setresuid' => {
			'code' => 117,
			'name' => 'setresuid',
			'args' => [
				[
					'uid_t *',
					'ruid'
				],
				[
					'uid_t *',
					'euid'
				],
				[
					'uid_t *',
					'suid'
				]
			],
			'ret' => 'int'
		},
		'getresuid' => {
			'code' => 118,
			'name' => 'getresuid',
			'args' => [
				[
					'uid_t *',
					'ruid'
				],
				[
					'uid_t *',
					'euid'
				],
				[
					'uid_t *',
					'suid'
				]
			],
			'ret' => 'int'
		},
		'setresgid' => {
			'code' => 119,
			'name' => 'setresgid',
			'args' => [
				[
					'gid_t',
					'rgid'
				],
				[
					'gid_t',
					'egid'
				],
				[
					'gid_t',
					'sgid'
				]
			],
			'ret' => 'int'
		},
		'getresgid' => {
			'code' => 120,
			'name' => 'getresgid',
			'args' => [
				[
					'gid_t *',
					'rgid'
				],
				[
					'gid_t *',
					'egid'
				],
				[
					'gid_t *',
					'sgid'
				]
			],
			'ret' => 'int'
		},
		'getpgid' => {
			'code' => 121,
			'name' => 'getpgid',
			'args' => [
				[
					'pid_t',
					'pid'
				]
			],
			'ret' => 'int'
		},
		'setfsuid' => {
			'code' => 122,
			'name' => 'setfsuid',
			'args' => [
				[
					'uid_t',
					'uid'
				]
			],
			'ret' => 'int'
		},
		'setfsgid' => {
			'code' => 123,
			'name' => 'setfsgid',
			'args' => [
				[
					'gid_t',
					'gid'
				]
			],
			'ret' => 'int'
		},
		'getsid' => {
			'code' => 124,
			'name' => 'getsid',
			'args' => [
				[
					'pid_t',
					'pid'
				]
			],
			'ret' => 'int'
		},
		'capget' => {
			'code' => 125,
			'name' => 'capget',
			'args' => [
				[
					'cap_user_header_t',
					'header'
				],
				[
					'cap_user_data_t',
					'dataptr'
				]
			],
			'ret' => 'int'
		},
		'capset' => {
			'code' => 126,
			'name' => 'capset',
			'args' => [
				[
					'cap_user_header_t',
					'header'
				],
				[
					'const cap_user_data_t',
					'data'
				]
			],
			'ret' => 'int'
		},
		'rt_sigpending' => {
			'code' => 127,
			'name' => 'rt_sigpending',
			'args' => [
				[
					'sigset_t *',
					'set'
				],
				[
					'size_t',
					'sigsetsize'
				]
			],
			'ret' => 'int'
		},
		'rt_sigtimedwait' => {
			'code' => 128,
			'name' => 'rt_sigtimedwait',
			'args' => [
				[
					'const sigset_t *',
					'uthese'
				],
				[
					'siginfo_t *',
					'uinfo'
				],
				[
					'const struct timespec *',
					'uts'
				],
				[
					'size_t',
					'sigsetsize'
				]
			],
			'ret' => 'int'
		},
		'rt_sigqueueinfo' => {
			'code' => 129,
			'name' => 'rt_sigqueueinfo',
			'args' => [
				[
					'pid_t',
					'pid'
				],
				[
					'int',
					'sig'
				],
				[
					'siginfo_t *',
					'uinfo'
				]
			],
			'ret' => 'int'
		},
		'rt_sigsuspend' => {
			'code' => 130,
			'name' => 'rt_sigsuspend',
			'args' => [
				[
					'sigset_t *',
					'unewset'
				],
				[
					'size_t',
					'sigsetsize'
				]
			],
			'ret' => 'int'
		},
		'sigaltstack' => {
			'code' => 131,
			'name' => 'sigaltstack',
			'args' => [
				[
					'const stack_t *',
					'uss'
				],
				[
					'stack_t *',
					'uoss'
				]
			],
			'ret' => 'int'
		},
		'utime' => {
			'code' => 132,
			'name' => 'utime',
			'args' => [
				[
					'char *',
					'filename'
				],
				[
					'struct utimbuf *',
					'times'
				]
			],
			'ret' => 'int'
		},
		'mknod' => {
			'code' => 133,
			'name' => 'mknod',
			'args' => [
				[
					'const char *',
					'filename'
				],
				[
					'umode_t',
					'mode'
				],
				[
					'unsigned',
					'dev'
				]
			],
			'ret' => 'int'
		},
		'uselib' => {
			'code' => 134,
			'name' => 'uselib',
			'args' => undef,
			'ret' => 'int'
		},
		'personality' => {
			'code' => 135,
			'name' => 'personality',
			'args' => [
				[
					'unsigned int',
					'personality'
				]
			],
			'ret' => 'int'
		},
		'ustat' => {
			'code' => 136,
			'name' => 'ustat',
			'args' => [
				[
					'unsigned',
					'dev'
				],
				[
					'struct ustat *',
					'ubuf'
				]
			],
			'ret' => 'int'
		},
		'statfs' => {
			'code' => 137,
			'name' => 'statfs',
			'args' => [
				[
					'const char *',
					'pathname'
				],
				[
					'struct statfs *',
					'buf'
				]
			],
			'ret' => 'int'
		},
		'fstatfs' => {
			'code' => 138,
			'name' => 'fstatfs',
			'args' => [
				[
					'unsigned int',
					'fd'
				],
				[
					'struct statfs *',
					'buf'
				]
			],
			'ret' => 'int'
		},
		'sysfs' => {
			'code' => 139,
			'name' => 'sysfs',
			'args' => [
				[
					'int',
					'option'
				],
				[
					'unsigned long',
					'arg1'
				],
				[
					'unsigned long',
					'arg2'
				]
			],
			'ret' => 'int'
		},
		'getpriority' => {
			'code' => 140,
			'name' => 'getpriority',
			'args' => [
				[
					'int',
					'which'
				],
				[
					'int',
					'who'
				]
			],
			'ret' => 'int'
		},
		'setpriority' => {
			'code' => 141,
			'name' => 'setpriority',
			'args' => [
				[
					'int',
					'which'
				],
				[
					'int',
					'who'
				],
				[
					'int',
					'niceval'
				]
			],
			'ret' => 'int'
		},
		'sched_setparam' => {
			'code' => 142,
			'name' => 'sched_setparam',
			'args' => [
				[
					'pid_t',
					'pid'
				],
				[
					'struct sched_param *',
					'param'
				]
			],
			'ret' => 'int'
		},
		'sched_getparam' => {
			'code' => 143,
			'name' => 'sched_getparam',
			'args' => [
				[
					'pid_t',
					'pid'
				],
				[
					'struct sched_param *',
					'param'
				]
			],
			'ret' => 'int'
		},
		'sched_setscheduler' => {
			'code' => 144,
			'name' => 'sched_setscheduler',
			'args' => [
				[
					'pid_t',
					'pid'
				],
				[
					'int',
					'policy'
				],
				[
					'struct sched_param *',
					'param'
				]
			],
			'ret' => 'int'
		},
		'sched_getscheduler' => {
			'code' => 145,
			'name' => 'sched_getscheduler',
			'args' => [
				[
					'pid_t',
					'pid'
				]
			],
			'ret' => 'int'
		},
		'sched_get_priority_max' => {
			'code' => 146,
			'name' => 'sched_get_priority_max',
			'args' => [
				[
					'int',
					'policy'
				]
			],
			'ret' => 'int'
		},
		'sched_get_priority_min' => {
			'code' => 147,
			'name' => 'sched_get_priority_min',
			'args' => [
				[
					'int',
					'policy'
				]
			],
			'ret' => 'int'
		},
		'sched_rr_get_interval' => {
			'code' => 148,
			'name' => 'sched_rr_get_interval',
			'args' => [
				[
					'pid_t',
					'pid'
				],
				[
					'struct timespec *',
					'interval'
				]
			],
			'ret' => 'int'
		},
		'mlock' => {
			'code' => 149,
			'name' => 'mlock',
			'args' => [
				[
					'unsigned long',
					'start'
				],
				[
					'size_t',
					'len'
				]
			],
			'ret' => 'int'
		},
		'munlock' => {
			'code' => 150,
			'name' => 'munlock',
			'args' => [
				[
					'unsigned long',
					'start'
				],
				[
					'size_t',
					'len'
				]
			],
			'ret' => 'int'
		},
		'mlockall' => {
			'code' => 151,
			'name' => 'mlockall',
			'args' => [
				[
					'int',
					'flags'
				]
			],
			'ret' => 'int'
		},
		'munlockall' => {
			'code' => 152,
			'name' => 'munlockall',
			'args' => [],
			'ret' => 'int'
		},
		'vhangup' => {
			'code' => 153,
			'name' => 'vhangup',
			'args' => [],
			'ret' => 'int'
		},
		'modify_ldt' => {
			'code' => 154,
			'name' => 'modify_ldt',
			'args' => [
				[
					'int',
					'func'
				],
				[
					'void *',
					'ptr'
				],
				[
					'unsigned long',
					'bytecount'
				]
			],
			'ret' => 'int'
		},
		'pivot_root' => {
			'code' => 155,
			'name' => 'pivot_root',
			'args' => [
				[
					'const char *',
					'new_root'
				],
				[
					'const char *',
					'put_old'
				]
			],
			'ret' => 'int'
		},
		'_sysctl' => {
			'code' => 156,
			'name' => '_sysctl',
			'args' => [
				[
					'struct __sysctl_args *',
					'args'
				]
			],
			'ret' => 'int'
		},
		'prctl' => {
			'code' => 157,
			'name' => 'prctl',
			'args' => [
				[
					'int',
					'option'
				],
				[
					'unsigned long',
					'arg2'
				],
				[
					'unsigned long',
					'arg3'
				],
				[
					'unsigned long',
					'arg4'
				],
				[
					'unsigned long',
					'arg5'
				]
			],
			'ret' => 'int'
		},
		'arch_prctl' => {
			'code' => 158,
			'name' => 'arch_prctl',
			'args' => [
				[
					'struct task_struct *',
					'task'
				],
				[
					'int',
					'code'
				],
				[
					'unsigned long *',
					'addr'
				]
			],
			'ret' => 'int'
		},
		'adjtimex' => {
			'code' => 159,
			'name' => 'adjtimex',
			'args' => [
				[
					'struct timex *',
					'txc_p'
				]
			],
			'ret' => 'int'
		},
		'setrlimit' => {
			'code' => 160,
			'name' => 'setrlimit',
			'args' => [
				[
					'unsigned int',
					'resource'
				],
				[
					'struct rlimit *',
					'rlim'
				]
			],
			'ret' => 'int'
		},
		'chroot' => {
			'code' => 161,
			'name' => 'chroot',
			'args' => [
				[
					'const char *',
					'filename'
				]
			],
			'ret' => 'int'
		},
		'sync' => {
			'code' => 162,
			'name' => 'sync',
			'args' => [],
			'ret' => 'int'
		},
		'acct' => {
			'code' => 163,
			'name' => 'acct',
			'args' => [
				[
					'const char *',
					'name'
				]
			],
			'ret' => 'int'
		},
		'settimeofday' => {
			'code' => 164,
			'name' => 'settimeofday',
			'args' => [
				[
					'struct timeval *',
					'tv'
				],
				[
					'struct timezone *',
					'tz'
				]
			],
			'ret' => 'int'
		},
		'mount' => {
			'code' => 165,
			'name' => 'mount',
			'args' => [
				[
					'char *',
					'dev_name'
				],
				[
					'char *',
					'dir_name'
				],
				[
					'char *',
					'type'
				],
				[
					'unsigned long',
					'flags'
				],
				[
					'void *',
					'data'
				]
			],
			'ret' => 'int'
		},
		'umount2' => {
			'code' => 166,
			'name' => 'umount2',
			'args' => [
				[
					'const char *',
					'target'
				],
				[
					'int',
					'flags'
				]
			],
			'ret' => 'int'
		},
		'swapon' => {
			'code' => 167,
			'name' => 'swapon',
			'args' => [
				[
					'const char *',
					'specialfile'
				],
				[
					'int',
					'swap_flags'
				]
			],
			'ret' => 'int'
		},
		'swapoff' => {
			'code' => 168,
			'name' => 'swapoff',
			'args' => [
				[
					'const char *',
					'specialfile'
				]
			],
			'ret' => 'int'
		},
		'reboot' => {
			'code' => 169,
			'name' => 'reboot',
			'args' => [
				[
					'int',
					'magic1'
				],
				[
					'int',
					'magic2'
				],
				[
					'unsigned int',
					'cmd'
				],
				[
					'void *',
					'arg'
				]
			],
			'ret' => 'int'
		},
		'sethostname' => {
			'code' => 170,
			'name' => 'sethostname',
			'args' => [
				[
					'char *',
					'name'
				],
				[
					'int',
					'len'
				]
			],
			'ret' => 'int'
		},
		'setdomainname' => {
			'code' => 171,
			'name' => 'setdomainname',
			'args' => [
				[
					'char *',
					'name'
				],
				[
					'int',
					'len'
				]
			],
			'ret' => 'int'
		},
		'iopl' => {
			'code' => 172,
			'name' => 'iopl',
			'args' => [
				[
					'unsigned int',
					'level'
				],
				[
					'struct pt_regs *',
					'regs'
				]
			],
			'ret' => 'int'
		},
		'ioperm' => {
			'code' => 173,
			'name' => 'ioperm',
			'args' => [
				[
					'unsigned long',
					'from'
				],
				[
					'unsigned long',
					'num'
				],
				[
					'int',
					'turn_on'
				]
			],
			'ret' => 'int'
		},
		'create_module' => {
			'code' => 174,
			'name' => 'create_module',
			'args' => [
				[
					'REMOVED IN Linux',
					'2.6'
				]
			],
			'ret' => 'int'
		},
		'init_module' => {
			'code' => 175,
			'name' => 'init_module',
			'args' => [
				[
					'void *',
					'umod'
				],
				[
					'unsigned long',
					'len'
				],
				[
					'const char *',
					'uargs'
				]
			],
			'ret' => 'int'
		},
		'delete_module' => {
			'code' => 176,
			'name' => 'delete_module',
			'args' => [
				[
					'const chat *',
					'name_user'
				],
				[
					'unsigned int',
					'flags'
				]
			],
			'ret' => 'int'
		},
		'get_kernel_syms' => {
			'code' => 177,
			'name' => 'get_kernel_syms',
			'args' => [
				[
					'REMOVED IN Linux',
					'2.6'
				]
			],
			'ret' => 'int'
		},
		'query_module' => {
			'code' => 178,
			'name' => 'query_module',
			'args' => [
				[
					'REMOVED IN Linux',
					'2.6'
				]
			],
			'ret' => 'int'
		},
		'quotactl' => {
			'code' => 179,
			'name' => 'quotactl',
			'args' => [
				[
					'unsigned int',
					'cmd'
				],
				[
					'const char *',
					'special'
				],
				[
					'qid_t',
					'id'
				],
				[
					'void *',
					'addr'
				]
			],
			'ret' => 'int'
		},
		'nfsservctl' => {
			'code' => 180,
			'name' => 'nfsservctl',
			'args' => undef,
			'ret' => 'int'
		},
		'getpmsg' => {
			'code' => 181,
			'name' => 'getpmsg',
			'args' => undef,
			'ret' => 'int'
		},
		'putpmsg' => {
			'code' => 182,
			'name' => 'putpmsg',
			'args' => undef,
			'ret' => 'int'
		},
		'afs_syscall' => {
			'code' => 183,
			'name' => 'afs_syscall',
			'args' => undef,
			'ret' => 'int'
		},
		'tuxcall' => {
			'code' => 184,
			'name' => 'tuxcall',
			'args' => undef,
			'ret' => 'int'
		},
		'security' => {
			'code' => 185,
			'name' => 'security',
			'args' => undef,
			'ret' => 'int'
		},
		'gettid' => {
			'code' => 186,
			'name' => 'gettid',
			'args' => [],
			'ret' => 'int'
		},
		'readahead' => {
			'code' => 187,
			'name' => 'readahead',
			'args' => [
				[
					'int',
					'fd'
				],
				[
					'loff_t',
					'offset'
				],
				[
					'size_t',
					'count'
				]
			],
			'ret' => 'int'
		},
		'setxattr' => {
			'code' => 188,
			'name' => 'setxattr',
			'args' => [
				[
					'const char *',
					'pathname'
				],
				[
					'const char *',
					'name'
				],
				[
					'const void *',
					'value'
				],
				[
					'size_t',
					'size'
				],
				[
					'int',
					'flags'
				]
			],
			'ret' => 'int'
		},
		'lsetxattr' => {
			'code' => 189,
			'name' => 'lsetxattr',
			'args' => [
				[
					'const char *',
					'pathname'
				],
				[
					'const char *',
					'name'
				],
				[
					'const void *',
					'value'
				],
				[
					'size_t',
					'size'
				],
				[
					'int',
					'flags'
				]
			],
			'ret' => 'int'
		},
		'fsetxattr' => {
			'code' => 190,
			'name' => 'fsetxattr',
			'args' => [
				[
					'int',
					'fd'
				],
				[
					'const char *',
					'name'
				],
				[
					'const void *',
					'value'
				],
				[
					'size_t',
					'size'
				],
				[
					'int',
					'flags'
				]
			],
			'ret' => 'int'
		},
		'getxattr' => {
			'code' => 191,
			'name' => 'getxattr',
			'args' => [
				[
					'const char *',
					'pathname'
				],
				[
					'const char *',
					'name'
				],
				[
					'void *',
					'value'
				],
				[
					'size_t',
					'size'
				]
			],
			'ret' => 'int'
		},
		'lgetxattr' => {
			'code' => 192,
			'name' => 'lgetxattr',
			'args' => [
				[
					'const char *',
					'pathname'
				],
				[
					'const char *',
					'name'
				],
				[
					'void *',
					'value'
				],
				[
					'size_t',
					'size'
				]
			],
			'ret' => 'int'
		},
		'fgetxattr' => {
			'code' => 193,
			'name' => 'fgetxattr',
			'args' => [
				[
					'int',
					'fd'
				],
				[
					'const har *',
					'name'
				],
				[
					'void *',
					'value'
				],
				[
					'size_t',
					'size'
				]
			],
			'ret' => 'int'
		},
		'listxattr' => {
			'code' => 194,
			'name' => 'listxattr',
			'args' => [
				[
					'const char *',
					'pathname'
				],
				[
					'char *',
					'list'
				],
				[
					'size_t',
					'size'
				]
			],
			'ret' => 'int'
		},
		'llistxattr' => {
			'code' => 195,
			'name' => 'llistxattr',
			'args' => [
				[
					'const char *',
					'pathname'
				],
				[
					'char *',
					'list'
				],
				[
					'size_t',
					'size'
				]
			],
			'ret' => 'int'
		},
		'flistxattr' => {
			'code' => 196,
			'name' => 'flistxattr',
			'args' => [
				[
					'int',
					'fd'
				],
				[
					'char *',
					'list'
				],
				[
					'size_t',
					'size'
				]
			],
			'ret' => 'int'
		},
		'removexattr' => {
			'code' => 197,
			'name' => 'removexattr',
			'args' => [
				[
					'const char *',
					'pathname'
				],
				[
					'const char *',
					'name'
				]
			],
			'ret' => 'int'
		},
		'lremovexattr' => {
			'code' => 198,
			'name' => 'lremovexattr',
			'args' => [
				[
					'const char *',
					'pathname'
				],
				[
					'const char *',
					'name'
				]
			],
			'ret' => 'int'
		},
		'fremovexattr' => {
			'code' => 199,
			'name' => 'fremovexattr',
			'args' => [
				[
					'int',
					'fd'
				],
				[
					'const char *',
					'name'
				]
			],
			'ret' => 'int'
		},
		'tkill' => {
			'code' => 200,
			'name' => 'tkill',
			'args' => [
				[
					'pid_t',
					'pid'
				],
				[
					'ing',
					'sig'
				]
			],
			'ret' => 'int'
		},
		'time' => {
			'code' => 201,
			'name' => 'time',
			'args' => [
				[
					'time_t *',
					'tloc'
				]
			],
			'ret' => 'int'
		},
		'futex' => {
			'code' => 202,
			'name' => 'futex',
			'args' => [
				[
					'u32 *',
					'uaddr'
				],
				[
					'int',
					'op'
				],
				[
					'u32',
					'val'
				],
				[
					'struct timespec *',
					'utime'
				],
				[
					'u32 *',
					'uaddr2'
				],
				[
					'u32',
					'val3'
				]
			],
			'ret' => 'int'
		},
		'sched_setaffinity' => {
			'code' => 203,
			'name' => 'sched_setaffinity',
			'args' => [
				[
					'pid_t',
					'pid'
				],
				[
					'unsigned int',
					'len'
				],
				[
					'unsigned long *',
					'user_mask_ptr'
				]
			],
			'ret' => 'int'
		},
		'sched_getaffinity' => {
			'code' => 204,
			'name' => 'sched_getaffinity',
			'args' => [
				[
					'pid_t',
					'pid'
				],
				[
					'unsigned int',
					'len'
				],
				[
					'unsigned long *',
					'user_mask_ptr'
				]
			],
			'ret' => 'int'
		},
		'set_thread_area' => {
			'code' => 205,
			'name' => 'set_thread_area',
			'args' => [
				[
					'NOT IMPLEMENTED. Use',
					'arch_prctl'
				]
			],
			'ret' => 'int'
		},
		'io_setup' => {
			'code' => 206,
			'name' => 'io_setup',
			'args' => [
				[
					'unsigned',
					'nr_events'
				],
				[
					'aio_context_t *',
					'ctxp'
				]
			],
			'ret' => 'int'
		},
		'io_destroy' => {
			'code' => 207,
			'name' => 'io_destroy',
			'args' => [
				[
					'aio_context_t',
					'ctx'
				]
			],
			'ret' => 'int'
		},
		'io_getevents' => {
			'code' => 208,
			'name' => 'io_getevents',
			'args' => [
				[
					'aio_context_t',
					'ctx_id'
				],
				[
					'long',
					'min_nr'
				],
				[
					'long',
					'nr'
				],
				[
					'struct io_event *',
					'events'
				]
			],
			'ret' => 'int'
		},
		'io_submit' => {
			'code' => 209,
			'name' => 'io_submit',
			'args' => [
				[
					'aio_context_t',
					'ctx_id'
				],
				[
					'long',
					'nr'
				],
				[
					'struct iocb * *',
					'iocbpp'
				]
			],
			'ret' => 'int'
		},
		'io_cancel' => {
			'code' => 210,
			'name' => 'io_cancel',
			'args' => [
				[
					'aio_context_t',
					'ctx_id'
				],
				[
					'struct iocb *',
					'iocb'
				],
				[
					'struct io_event *',
					'result'
				]
			],
			'ret' => 'int'
		},
		'get_thread_area' => {
			'code' => 211,
			'name' => 'get_thread_area',
			'args' => [
				[
					'NOT IMPLEMENTED. Use',
					'arch_prctl'
				]
			],
			'ret' => 'int'
		},
		'lookup_dcookie' => {
			'code' => 212,
			'name' => 'lookup_dcookie',
			'args' => [
				[
					'u64',
					'cookie64'
				],
				[
					'long',
					'buf'
				],
				[
					'long',
					'len'
				]
			],
			'ret' => 'int'
		},
		'epoll_create' => {
			'code' => 213,
			'name' => 'epoll_create',
			'args' => [
				[
					'int',
					'size'
				]
			],
			'ret' => 'int'
		},
		'epoll_ctl_old' => {
			'code' => 214,
			'name' => 'epoll_ctl_old',
			'args' => undef,
			'ret' => 'int'
		},
		'epoll_wait_old' => {
			'code' => 215,
			'name' => 'epoll_wait_old',
			'args' => undef,
			'ret' => 'int'
		},
		'remap_file_pages' => {
			'code' => 216,
			'name' => 'remap_file_pages',
			'args' => [
				[
					'unsigned long',
					'start'
				],
				[
					'unsigned long',
					'size'
				],
				[
					'unsigned long',
					'prot'
				],
				[
					'unsigned long',
					'pgoff'
				],
				[
					'unsigned long',
					'flags'
				]
			],
			'ret' => 'int'
		},
		'getdents64' => {
			'code' => 217,
			'name' => 'getdents64',
			'args' => [
				[
					'unsigned int',
					'fd'
				],
				[
					'struct linux_dirent64 *',
					'dirent'
				],
				[
					'unsigned int',
					'count'
				]
			],
			'ret' => 'int'
		},
		'set_tid_address' => {
			'code' => 218,
			'name' => 'set_tid_address',
			'args' => [
				[
					'int *',
					'tidptr'
				]
			],
			'ret' => 'int'
		},
		'restart_syscall' => {
			'code' => 219,
			'name' => 'restart_syscall',
			'args' => [],
			'ret' => 'int'
		},
		'semtimedop' => {
			'code' => 220,
			'name' => 'semtimedop',
			'args' => [
				[
					'int',
					'semid'
				],
				[
					'struct sembuf *',
					'tsops'
				],
				[
					'unsigned',
					'nsops'
				],
				[
					'const struct timespec *',
					'timeout'
				]
			],
			'ret' => 'int'
		},
		'fadvise64' => {
			'code' => 221,
			'name' => 'fadvise64',
			'args' => [
				[
					'int',
					'fd'
				],
				[
					'loff_t',
					'offset'
				],
				[
					'size_t',
					'len'
				],
				[
					'int',
					'advice'
				]
			],
			'ret' => 'int'
		},
		'timer_create' => {
			'code' => 222,
			'name' => 'timer_create',
			'args' => [
				[
					'const clockid_t',
					'which_clock'
				],
				[
					'struct sigevent *',
					'timer_event_spec'
				],
				[
					'timer_t *',
					'created_timer_id'
				]
			],
			'ret' => 'int'
		},
		'timer_settime' => {
			'code' => 223,
			'name' => 'timer_settime',
			'args' => [
				[
					'timer_t',
					'timer_id'
				],
				[
					'int',
					'flags'
				],
				[
					'const struct itimerspec *',
					'new_setting'
				],
				[
					'struct itimerspec *',
					'old_setting'
				]
			],
			'ret' => 'int'
		},
		'timer_gettime' => {
			'code' => 224,
			'name' => 'timer_gettime',
			'args' => [
				[
					'timer_t',
					'timer_id'
				],
				[
					'struct itimerspec *',
					'setting'
				]
			],
			'ret' => 'int'
		},
		'timer_getoverrun' => {
			'code' => 225,
			'name' => 'timer_getoverrun',
			'args' => [
				[
					'timer_t',
					'timer_id'
				]
			],
			'ret' => 'int'
		},
		'timer_delete' => {
			'code' => 226,
			'name' => 'timer_delete',
			'args' => [
				[
					'timer_t',
					'timer_id'
				]
			],
			'ret' => 'int'
		},
		'clock_settime' => {
			'code' => 227,
			'name' => 'clock_settime',
			'args' => [
				[
					'const clockid_t',
					'which_clock'
				],
				[
					'const struct timespec *',
					'tp'
				]
			],
			'ret' => 'int'
		},
		'clock_gettime' => {
			'code' => 228,
			'name' => 'clock_gettime',
			'args' => [
				[
					'const clockid_t',
					'which_clock'
				],
				[
					'struct timespec *',
					'tp'
				]
			],
			'ret' => 'int'
		},
		'clock_getres' => {
			'code' => 229,
			'name' => 'clock_getres',
			'args' => [
				[
					'const clockid_t',
					'which_clock'
				],
				[
					'struct timespec *',
					'tp'
				]
			],
			'ret' => 'int'
		},
		'clock_nanosleep' => {
			'code' => 230,
			'name' => 'clock_nanosleep',
			'args' => [
				[
					'const clockid_t',
					'which_clock'
				],
				[
					'int',
					'flags'
				],
				[
					'const struct timespec *',
					'rqtp'
				],
				[
					'struct timespec *',
					'rmtp'
				]
			],
			'ret' => 'int'
		},
		'exit_group' => {
			'code' => 231,
			'name' => 'exit_group',
			'args' => [
				[
					'int',
					'error_code'
				]
			],
			'ret' => 'int'
		},
		'epoll_wait' => {
			'code' => 232,
			'name' => 'epoll_wait',
			'args' => [
				[
					'int',
					'epfd'
				],
				[
					'struct epoll_event *',
					'events'
				],
				[
					'int',
					'maxevents'
				],
				[
					'int',
					'timeout'
				]
			],
			'ret' => 'int'
		},
		'epoll_ctl' => {
			'code' => 233,
			'name' => 'epoll_ctl',
			'args' => [
				[
					'int',
					'epfd'
				],
				[
					'int',
					'op'
				],
				[
					'int',
					'fd'
				],
				[
					'struct epoll_event *',
					'event'
				]
			],
			'ret' => 'int'
		},
		'tgkill' => {
			'code' => 234,
			'name' => 'tgkill',
			'args' => [
				[
					'pid_t',
					'tgid'
				],
				[
					'pid_t',
					'pid'
				],
				[
					'int',
					'sig'
				]
			],
			'ret' => 'int'
		},
		'utimes' => {
			'code' => 235,
			'name' => 'utimes',
			'args' => [
				[
					'char *',
					'filename'
				],
				[
					'struct timeval *',
					'utimes'
				]
			],
			'ret' => 'int'
		},
		'vserver' => {
			'code' => 236,
			'name' => 'vserver',
			'args' => undef,
			'ret' => 'int'
		},
		'mbind' => {
			'code' => 237,
			'name' => 'mbind',
			'args' => [
				[
					'unsigned long',
					'start'
				],
				[
					'unsigned long',
					'len'
				],
				[
					'unsigned long',
					'mode'
				],
				[
					'unsigned long *',
					'nmask'
				],
				[
					'unsigned long',
					'maxnode'
				],
				[
					'unsigned',
					'flags'
				]
			],
			'ret' => 'int'
		},
		'set_mempolicy' => {
			'code' => 238,
			'name' => 'set_mempolicy',
			'args' => [
				[
					'int',
					'mode'
				],
				[
					'unsigned long *',
					'nmask'
				],
				[
					'unsigned long',
					'maxnode'
				]
			],
			'ret' => 'int'
		},
		'get_mempolicy' => {
			'code' => 239,
			'name' => 'get_mempolicy',
			'args' => [
				[
					'int *',
					'policy'
				],
				[
					'unsigned long *',
					'nmask'
				],
				[
					'unsigned long',
					'maxnode'
				],
				[
					'unsigned long',
					'addr'
				],
				[
					'unsigned long',
					'flags'
				]
			],
			'ret' => 'int'
		},
		'mq_open' => {
			'code' => 240,
			'name' => 'mq_open',
			'args' => [
				[
					'const char *',
					'u_name'
				],
				[
					'int',
					'oflag'
				],
				[
					'mode_t',
					'mode'
				],
				[
					'struct mq_attr *',
					'u_attr'
				]
			],
			'ret' => 'int'
		},
		'mq_unlink' => {
			'code' => 241,
			'name' => 'mq_unlink',
			'args' => [
				[
					'const char *',
					'u_name'
				]
			],
			'ret' => 'int'
		},
		'mq_timedsend' => {
			'code' => 242,
			'name' => 'mq_timedsend',
			'args' => [
				[
					'mqd_t',
					'mqdes'
				],
				[
					'const char *',
					'u_msg_ptr'
				],
				[
					'size_t',
					'msg_len'
				],
				[
					'unsigned int',
					'msg_prio'
				],
				[
					'const stuct timespec *',
					'u_abs_timeout'
				]
			],
			'ret' => 'int'
		},
		'mq_timedreceive' => {
			'code' => 243,
			'name' => 'mq_timedreceive',
			'args' => [
				[
					'mqd_t',
					'mqdes'
				],
				[
					'char *',
					'u_msg_ptr'
				],
				[
					'size_t',
					'msg_len'
				],
				[
					'unsigned int *',
					'u_msg_prio'
				],
				[
					'const struct timespec *',
					'u_abs_timeout'
				]
			],
			'ret' => 'int'
		},
		'mq_notify' => {
			'code' => 244,
			'name' => 'mq_notify',
			'args' => [
				[
					'mqd_t',
					'mqdes'
				],
				[
					'const struct sigevent *',
					'u_notification'
				]
			],
			'ret' => 'int'
		},
		'mq_getsetattr' => {
			'code' => 245,
			'name' => 'mq_getsetattr',
			'args' => [
				[
					'mqd_t',
					'mqdes'
				],
				[
					'const struct mq_attr *',
					'u_mqstat'
				],
				[
					'struct mq_attr *',
					'u_omqstat'
				]
			],
			'ret' => 'int'
		},
		'kexec_load' => {
			'code' => 246,
			'name' => 'kexec_load',
			'args' => [
				[
					'unsigned long',
					'entry'
				],
				[
					'unsigned long',
					'nr_segments'
				],
				[
					'struct kexec_segment *',
					'segments'
				],
				[
					'unsigned long',
					'flags'
				]
			],
			'ret' => 'int'
		},
		'waitid' => {
			'code' => 247,
			'name' => 'waitid',
			'args' => [
				[
					'int',
					'which'
				],
				[
					'pid_t',
					'upid'
				],
				[
					'struct siginfo *',
					'infop'
				],
				[
					'int',
					'options'
				],
				[
					'struct rusage *',
					'ru'
				]
			],
			'ret' => 'int'
		},
		'add_key' => {
			'code' => 248,
			'name' => 'add_key',
			'args' => [
				[
					'const char *',
					'_type'
				],
				[
					'const char *',
					'_description'
				],
				[
					'const void *',
					'_payload'
				],
				[
					'size_t',
					'plen'
				]
			],
			'ret' => 'int'
		},
		'request_key' => {
			'code' => 249,
			'name' => 'request_key',
			'args' => [
				[
					'const char *',
					'_type'
				],
				[
					'const char *',
					'_description'
				],
				[
					'const char *',
					'_callout_info'
				],
				[
					'key_serial_t',
					'destringid'
				]
			],
			'ret' => 'int'
		},
		'keyctl' => {
			'code' => 250,
			'name' => 'keyctl',
			'args' => [
				[
					'int',
					'option'
				],
				[
					'unsigned long',
					'arg2'
				],
				[
					'unsigned long',
					'arg3'
				],
				[
					'unsigned long',
					'arg4'
				],
				[
					'unsigned long',
					'arg5'
				]
			],
			'ret' => 'int'
		},
		'ioprio_set' => {
			'code' => 251,
			'name' => 'ioprio_set',
			'args' => [
				[
					'int',
					'which'
				],
				[
					'int',
					'who'
				],
				[
					'int',
					'ioprio'
				]
			],
			'ret' => 'int'
		},
		'ioprio_get' => {
			'code' => 252,
			'name' => 'ioprio_get',
			'args' => [
				[
					'int',
					'which'
				],
				[
					'int',
					'who'
				]
			],
			'ret' => 'int'
		},
		'inotify_init' => {
			'code' => 253,
			'name' => 'inotify_init',
			'args' => [],
			'ret' => 'int'
		},
		'inotify_add_watch' => {
			'code' => 254,
			'name' => 'inotify_add_watch',
			'args' => [
				[
					'int',
					'fd'
				],
				[
					'const char *',
					'pathname'
				],
				[
					'u32',
					'mask'
				]
			],
			'ret' => 'int'
		},
		'inotify_rm_watch' => {
			'code' => 255,
			'name' => 'inotify_rm_watch',
			'args' => [
				[
					'int',
					'fd'
				],
				[
					'__s32',
					'wd'
				]
			],
			'ret' => 'int'
		},
		'migrate_pages' => {
			'code' => 256,
			'name' => 'migrate_pages',
			'args' => [
				[
					'pid_t',
					'pid'
				],
				[
					'unsigned long',
					'maxnode'
				],
				[
					'const unsigned long *',
					'old_nodes'
				],
				[
					'const unsigned long *',
					'new_nodes'
				]
			],
			'ret' => 'int'
		},
		'openat' => {
			'code' => 257,
			'name' => 'openat',
			'args' => [
				[
					'int',
					'dfd'
				],
				[
					'const char *',
					'filename'
				],
				[
					'int',
					'flags'
				],
				[
					'int',
					'mode'
				]
			],
			'ret' => 'int'
		},
		'mkdirat' => {
			'code' => 258,
			'name' => 'mkdirat',
			'args' => [
				[
					'int',
					'dfd'
				],
				[
					'const char *',
					'pathname'
				],
				[
					'int',
					'mode'
				]
			],
			'ret' => 'int'
		},
		'mknodat' => {
			'code' => 259,
			'name' => 'mknodat',
			'args' => [
				[
					'int',
					'dfd'
				],
				[
					'const char *',
					'filename'
				],
				[
					'int',
					'mode'
				],
				[
					'unsigned',
					'dev'
				]
			],
			'ret' => 'int'
		},
		'fchownat' => {
			'code' => 260,
			'name' => 'fchownat',
			'args' => [
				[
					'int',
					'dfd'
				],
				[
					'const char *',
					'filename'
				],
				[
					'uid_t',
					'user'
				],
				[
					'gid_t',
					'group'
				],
				[
					'int',
					'flag'
				]
			],
			'ret' => 'int'
		},
		'futimesat' => {
			'code' => 261,
			'name' => 'futimesat',
			'args' => [
				[
					'int',
					'dfd'
				],
				[
					'const char *',
					'filename'
				],
				[
					'struct timeval *',
					'utimes'
				]
			],
			'ret' => 'int'
		},
		'newfstatat' => {
			'code' => 262,
			'name' => 'newfstatat',
			'args' => [
				[
					'int',
					'dfd'
				],
				[
					'const char *',
					'filename'
				],
				[
					'struct stat *',
					'statbuf'
				],
				[
					'int',
					'flag'
				]
			],
			'ret' => 'int'
		},
		'unlinkat' => {
			'code' => 263,
			'name' => 'unlinkat',
			'args' => [
				[
					'int',
					'dfd'
				],
				[
					'const char *',
					'pathname'
				],
				[
					'int',
					'flag'
				]
			],
			'ret' => 'int'
		},
		'renameat' => {
			'code' => 264,
			'name' => 'renameat',
			'args' => [
				[
					'int',
					'oldfd'
				],
				[
					'const char *',
					'oldname'
				],
				[
					'int',
					'newfd'
				],
				[
					'const char *',
					'newname'
				]
			],
			'ret' => 'int'
		},
		'linkat' => {
			'code' => 265,
			'name' => 'linkat',
			'args' => [
				[
					'int',
					'oldfd'
				],
				[
					'const char *',
					'oldname'
				],
				[
					'int',
					'newfd'
				],
				[
					'const char *',
					'newname'
				],
				[
					'int',
					'flags'
				]
			],
			'ret' => 'int'
		},
		'symlinkat' => {
			'code' => 266,
			'name' => 'symlinkat',
			'args' => [
				[
					'const char *',
					'oldname'
				],
				[
					'int',
					'newfd'
				],
				[
					'const char *',
					'newname'
				]
			],
			'ret' => 'int'
		},
		'readlinkat' => {
			'code' => 267,
			'name' => 'readlinkat',
			'args' => [
				[
					'int',
					'dfd'
				],
				[
					'const char *',
					'pathname'
				],
				[
					'char *',
					'buf'
				],
				[
					'int',
					'bufsiz'
				]
			],
			'ret' => 'int'
		},
		'fchmodat' => {
			'code' => 268,
			'name' => 'fchmodat',
			'args' => [
				[
					'int',
					'dfd'
				],
				[
					'const char *',
					'filename'
				],
				[
					'mode_t',
					'mode'
				]
			],
			'ret' => 'int'
		},
		'faccessat' => {
			'code' => 269,
			'name' => 'faccessat',
			'args' => [
				[
					'int',
					'dfd'
				],
				[
					'const char *',
					'filename'
				],
				[
					'int',
					'mode'
				]
			],
			'ret' => 'int'
		},
		'pselect6' => {
			'code' => 270,
			'name' => 'pselect6',
			'args' => [
				[
					'int',
					'n'
				],
				[
					'fd_set *',
					'inp'
				],
				[
					'fd_set *',
					'outp'
				],
				[
					'fd_set *',
					'exp'
				],
				[
					'struct timespec *',
					'tsp'
				],
				[
					'void *',
					'sig'
				]
			],
			'ret' => 'int'
		},
		'ppoll' => {
			'code' => 271,
			'name' => 'ppoll',
			'args' => [
				[
					'struct pollfd *',
					'ufds'
				],
				[
					'unsigned int',
					'nfds'
				],
				[
					'struct timespec *',
					'tsp'
				],
				[
					'const sigset_t *',
					'sigmask'
				],
				[
					'size_t',
					'sigsetsize'
				]
			],
			'ret' => 'int'
		},
		'unshare' => {
			'code' => 272,
			'name' => 'unshare',
			'args' => [
				[
					'unsigned long',
					'unshare_flags'
				]
			],
			'ret' => 'int'
		},
		'set_robust_list' => {
			'code' => 273,
			'name' => 'set_robust_list',
			'args' => [
				[
					'struct robust_list_head *',
					'head'
				],
				[
					'size_t',
					'len'
				]
			],
			'ret' => 'int'
		},
		'get_robust_list' => {
			'code' => 274,
			'name' => 'get_robust_list',
			'args' => [
				[
					'int',
					'pid'
				],
				[
					'struct robust_list_head * *',
					'head_ptr'
				],
				[
					'size_t *',
					'len_ptr'
				]
			],
			'ret' => 'int'
		},
		'splice' => {
			'code' => 275,
			'name' => 'splice',
			'args' => [
				[
					'int',
					'fd_in'
				],
				[
					'loff_t *',
					'off_in'
				],
				[
					'int',
					'fd_out'
				],
				[
					'loff_t *',
					'off_out'
				],
				[
					'size_t',
					'len'
				],
				[
					'unsigned int',
					'flags'
				]
			],
			'ret' => 'int'
		},
		'tee' => {
			'code' => 276,
			'name' => 'tee',
			'args' => [
				[
					'int',
					'fdin'
				],
				[
					'int',
					'fdout'
				],
				[
					'size_t',
					'len'
				],
				[
					'unsigned int',
					'flags'
				]
			],
			'ret' => 'int'
		},
		'sync_file_range' => {
			'code' => 277,
			'name' => 'sync_file_range',
			'args' => [
				[
					'long',
					'fd'
				],
				[
					'loff_t',
					'offset'
				],
				[
					'loff_t',
					'bytes'
				],
				[
					'long',
					'flags'
				]
			],
			'ret' => 'int'
		},
		'vmsplice' => {
			'code' => 278,
			'name' => 'vmsplice',
			'args' => [
				[
					'int',
					'fd'
				],
				[
					'const struct iovec *',
					'iov'
				],
				[
					'unsigned long',
					'nr_segs'
				],
				[
					'unsigned int',
					'flags'
				]
			],
			'ret' => 'int'
		},
		'move_pages' => {
			'code' => 279,
			'name' => 'move_pages',
			'args' => [
				[
					'pid_t',
					'pid'
				],
				[
					'unsigned long',
					'nr_pages'
				],
				[
					'const void * *',
					'pages'
				],
				[
					'const int *',
					'nodes'
				],
				[
					'int *',
					'status'
				],
				[
					'int',
					'flags'
				]
			],
			'ret' => 'int'
		},
		'utimensat' => {
			'code' => 280,
			'name' => 'utimensat',
			'args' => [
				[
					'int',
					'dfd'
				],
				[
					'const char *',
					'filename'
				],
				[
					'struct timespec *',
					'utimes'
				],
				[
					'int',
					'flags'
				]
			],
			'ret' => 'int'
		},
		'epoll_pwait' => {
			'code' => 281,
			'name' => 'epoll_pwait',
			'args' => [
				[
					'int',
					'epfd'
				],
				[
					'struct epoll_event *',
					'events'
				],
				[
					'int',
					'maxevents'
				],
				[
					'int',
					'timeout'
				],
				[
					'const sigset_t *',
					'sigmask'
				],
				[
					'size_t',
					'sigsetsize'
				]
			],
			'ret' => 'int'
		},
		'signalfd' => {
			'code' => 282,
			'name' => 'signalfd',
			'args' => [
				[
					'int',
					'ufd'
				],
				[
					'sigset_t *',
					'user_mask'
				],
				[
					'size_t',
					'sizemask'
				]
			],
			'ret' => 'int'
		},
		'timerfd_create' => {
			'code' => 283,
			'name' => 'timerfd_create',
			'args' => [
				[
					'int',
					'clockid'
				],
				[
					'int',
					'flags'
				]
			],
			'ret' => 'int'
		},
		'eventfd' => {
			'code' => 284,
			'name' => 'eventfd',
			'args' => [
				[
					'unsigned int',
					'count'
				]
			],
			'ret' => 'int'
		},
		'fallocate' => {
			'code' => 285,
			'name' => 'fallocate',
			'args' => [
				[
					'long',
					'fd'
				],
				[
					'long',
					'mode'
				],
				[
					'loff_t',
					'offset'
				],
				[
					'loff_t',
					'len'
				]
			],
			'ret' => 'int'
		},
		'timerfd_settime' => {
			'code' => 286,
			'name' => 'timerfd_settime',
			'args' => [
				[
					'int',
					'ufd'
				],
				[
					'int',
					'flags'
				],
				[
					'const struct itimerspec *',
					'utmr'
				],
				[
					'struct itimerspec *',
					'otmr'
				]
			],
			'ret' => 'int'
		},
		'timerfd_gettime' => {
			'code' => 287,
			'name' => 'timerfd_gettime',
			'args' => [
				[
					'int',
					'ufd'
				],
				[
					'struct itimerspec *',
					'otmr'
				]
			],
			'ret' => 'int'
		},
		'accept4' => {
			'code' => 288,
			'name' => 'accept4',
			'args' => [
				[
					'int',
					'fd'
				],
				[
					'struct sockaddr *',
					'upeer_sockaddr'
				],
				[
					'int *',
					'upeer_addrlen'
				],
				[
					'int',
					'flags'
				]
			],
			'ret' => 'int'
		},
		'signalfd4' => {
			'code' => 289,
			'name' => 'signalfd4',
			'args' => [
				[
					'int',
					'ufd'
				],
				[
					'sigset_t *',
					'user_mask'
				],
				[
					'size_t',
					'sizemask'
				],
				[
					'int',
					'flags'
				]
			],
			'ret' => 'int'
		},
		'eventfd2' => {
			'code' => 290,
			'name' => 'eventfd2',
			'args' => [
				[
					'unsigned int',
					'count'
				],
				[
					'int',
					'flags'
				]
			],
			'ret' => 'int'
		},
		'epoll_create1' => {
			'code' => 291,
			'name' => 'epoll_create1',
			'args' => [
				[
					'int',
					'flags'
				]
			],
			'ret' => 'int'
		},
		'dup3' => {
			'code' => 292,
			'name' => 'dup3',
			'args' => [
				[
					'unsigned int',
					'oldfd'
				],
				[
					'unsigned int',
					'newfd'
				],
				[
					'int',
					'flags'
				]
			],
			'ret' => 'int'
		},
		'pipe2' => {
			'code' => 293,
			'name' => 'pipe2',
			'args' => [
				[
					'int *',
					'filedes'
				],
				[
					'int',
					'flags'
				]
			],
			'ret' => 'int'
		},
		'inotify_init1' => {
			'code' => 294,
			'name' => 'inotify_init1',
			'args' => [
				[
					'int',
					'flags'
				]
			],
			'ret' => 'int'
		},
		'preadv' => {
			'code' => 295,
			'name' => 'preadv',
			'args' => [
				[
					'unsigned long',
					'fd'
				],
				[
					'const struct iovec *',
					'vec'
				],
				[
					'unsigned long',
					'vlen'
				],
				[
					'unsigned long',
					'pos_l'
				],
				[
					'unsigned long',
					'pos_h'
				]
			],
			'ret' => 'int'
		},
		'pwritev' => {
			'code' => 296,
			'name' => 'pwritev',
			'args' => [
				[
					'unsigned long',
					'fd'
				],
				[
					'const struct iovec *',
					'vec'
				],
				[
					'unsigned long',
					'vlen'
				],
				[
					'unsigned long',
					'pos_l'
				],
				[
					'unsigned long',
					'pos_h'
				]
			],
			'ret' => 'int'
		},
		'rt_tgsigqueueinfo' => {
			'code' => 297,
			'name' => 'rt_tgsigqueueinfo',
			'args' => [
				[
					'pid_t',
					'tgid'
				],
				[
					'pid_t',
					'pid'
				],
				[
					'int',
					'sig'
				],
				[
					'siginfo_t *',
					'uinfo'
				]
			],
			'ret' => 'int'
		},
		'perf_event_open' => {
			'code' => 298,
			'name' => 'perf_event_open',
			'args' => [
				[
					'struct perf_event_attr *',
					'attr_uptr'
				],
				[
					'pid_t',
					'pid'
				],
				[
					'int',
					'cpu'
				],
				[
					'int',
					'group_fd'
				],
				[
					'unsigned long',
					'flags'
				]
			],
			'ret' => 'int'
		},
		'recvmmsg' => {
			'code' => 299,
			'name' => 'recvmmsg',
			'args' => [
				[
					'int',
					'fd'
				],
				[
					'struct msghdr *',
					'mmsg'
				],
				[
					'unsigned int',
					'vlen'
				],
				[
					'unsigned int',
					'flags'
				],
				[
					'struct timespec *',
					'timeout'
				]
			],
			'ret' => 'int'
		},
		'fanotify_init' => {
			'code' => 300,
			'name' => 'fanotify_init',
			'args' => [
				[
					'unsigned int',
					'flags'
				],
				[
					'unsigned int',
					'event_f_flags'
				]
			],
			'ret' => 'int'
		},
		'fanotify_mark' => {
			'code' => 301,
			'name' => 'fanotify_mark',
			'args' => [
				[
					'long',
					'fanotify_fd'
				],
				[
					'long',
					'flags'
				],
				[
					'__u64',
					'mask'
				],
				[
					'long',
					'dfd'
				],
				[
					'long',
					'pathname'
				]
			],
			'ret' => 'int'
		},
		'prlimit64' => {
			'code' => 302,
			'name' => 'prlimit64',
			'args' => [
				[
					'pid_t',
					'pid'
				],
				[
					'unsigned int',
					'resource'
				],
				[
					'const struct rlimit64 *',
					'new_rlim'
				],
				[
					'struct rlimit64 *',
					'old_rlim'
				]
			],
			'ret' => 'int'
		},
		'name_to_handle_at' => {
			'code' => 303,
			'name' => 'name_to_handle_at',
			'args' => [
				[
					'int',
					'dfd'
				],
				[
					'const char *',
					'name'
				],
				[
					'struct file_handle *',
					'handle'
				],
				[
					'int *',
					'mnt_id'
				],
				[
					'int',
					'flag'
				]
			],
			'ret' => 'int'
		},
		'open_by_handle_at' => {
			'code' => 304,
			'name' => 'open_by_handle_at',
			'args' => [
				[
					'int',
					'dfd'
				],
				[
					'const char *',
					'name'
				],
				[
					'struct file_handle *',
					'handle'
				],
				[
					'int *',
					'mnt_id'
				],
				[
					'int',
					'flags'
				]
			],
			'ret' => 'int'
		},
		'clock_adjtime' => {
			'code' => 305,
			'name' => 'clock_adjtime',
			'args' => [
				[
					'clockid_t',
					'which_clock'
				],
				[
					'struct timex *',
					'tx'
				]
			],
			'ret' => 'int'
		},
		'syncfs' => {
			'code' => 306,
			'name' => 'syncfs',
			'args' => [
				[
					'int',
					'fd'
				]
			],
			'ret' => 'int'
		},
		'sendmmsg' => {
			'code' => 307,
			'name' => 'sendmmsg',
			'args' => [
				[
					'int',
					'fd'
				],
				[
					'struct mmsghdr *',
					'mmsg'
				],
				[
					'unsigned int',
					'vlen'
				],
				[
					'unsigned int',
					'flags'
				]
			],
			'ret' => 'int'
		},
		'setns' => {
			'code' => 308,
			'name' => 'setns',
			'args' => [
				[
					'int',
					'fd'
				],
				[
					'int',
					'nstype'
				]
			],
			'ret' => 'int'
		},
		'getcpu' => {
			'code' => 309,
			'name' => 'getcpu',
			'args' => [
				[
					'unsigned *',
					'cpup'
				],
				[
					'unsigned *',
					'nodep'
				],
				[
					'struct getcpu_cache *',
					'unused'
				]
			],
			'ret' => 'int'
		},
		'process_vm_readv' => {
			'code' => 310,
			'name' => 'process_vm_readv',
			'args' => [
				[
					'pid_t',
					'pid'
				],
				[
					'const struct iovec *',
					'lvec'
				],
				[
					'unsigned long',
					'liovcnt'
				],
				[
					'const struct iovec *',
					'rvec'
				],
				[
					'unsigned long',
					'riovcnt'
				],
				[
					'unsigned long',
					'flags'
				]
			],
			'ret' => 'int'
		},
		'process_vm_writev' => {
			'code' => 311,
			'name' => 'process_vm_writev',
			'args' => [
				[
					'pid_t',
					'pid'
				],
				[
					'const struct iovec *',
					'lvec'
				],
				[
					'unsigned long',
					'liovcnt'
				],
				[
					'const struct iovcc *',
					'rvec'
				],
				[
					'unsigned long',
					'riovcnt'
				],
				[
					'unsigned long',
					'flags'
				]
			],
			'ret' => 'int'
		},
		'kcmp' => {
			'code' => 312,
			'name' => 'kcmp',
			'args' => [
				[
					'pid_t',
					'pid1'
				],
				[
					'pid_t',
					'pid2'
				],
				[
					'int',
					'type'
				],
				[
					'unsigned long',
					'idx1'
				],
				[
					'unsigned long',
					'idx2'
				]
			],
			'ret' => 'int'
		},
		'finit_module' => {
			'code' => 313,
			'name' => 'finit_module',
			'args' => [
				[
					'int',
					'fd'
				],
				[
					'const char __user *',
					'uargs'
				],
				[
					'int',
					'flags'
				]
			],
			'ret' => 'int'
		},
		'sched_setattr' => {
			'code' => 314,
			'name' => 'sched_setattr',
			'args' => [
				[
					'pid_t',
					'pid'
				],
				[
					'struct sched_attr __user *',
					'attr'
				],
				[
					'unsigned int',
					'flags'
				]
			],
			'ret' => 'int'
		},
		'sched_getattr' => {
			'code' => 315,
			'name' => 'sched_getattr',
			'args' => [
				[
					'pid_t',
					'pid'
				],
				[
					'struct sched_attr __user *',
					'attr'
				],
				[
					'unsigned int',
					'size'
				],
				[
					'unsigned int',
					'flags'
				]
			],
			'ret' => 'int'
		},
		'renameat2' => {
			'code' => 316,
			'name' => 'renameat2',
			'args' => [
				[
					'int',
					'olddfd'
				],
				[
					'const char __user *',
					'oldname'
				],
				[
					'int',
					'newdfd'
				],
				[
					'const char __user *',
					'newname'
				],
				[
					'unsigned int',
					'flags'
				]
			],
			'ret' => 'int'
		},
		'seccomp' => {
			'code' => 317,
			'name' => 'seccomp',
			'args' => [
				[
					'unsigned int',
					'op'
				],
				[
					'unsigned int',
					'flags'
				],
				[
					'const char __user *',
					'uargs'
				]
			],
			'ret' => 'int'
		},
		'getrandom' => {
			'code' => 318,
			'name' => 'getrandom',
			'args' => [
				[
					'char __user *',
					'buf'
				],
				[
					'size_t',
					'count'
				],
				[
					'unsigned int',
					'flags'
				]
			],
			'ret' => 'int'
		},
		'memfd_create' => {
			'code' => 319,
			'name' => 'memfd_create',
			'args' => [
				[
					'const char __user *',
					'uname_ptr'
				],
				[
					'unsigned
					int',
					'flags'
				]
			],
			'ret' => 'int'
		},
		'kexec_file_load' => {
			'code' => 320,
			'name' => 'kexec_file_load',
			'args' => [
				[
					'int',
					'kernel_fd'
				],
				[
					'int',
					'initrd_fd'
				],
				[
					'unsigned long',
					'cmdline_len'
				],
				[
					'const char __user *',
					'cmdline_ptr'
				],
				[
					'unsigned long',
					'flags'
				]
			],
			'ret' => 'int'
		},
		'bpf' => {
			'code' => 321,
			'name' => 'bpf',
			'args' => [
				[
					'int',
					'cmd'
				],
				[
					'union bpf_attr *',
					'attr'
				],
				[
					'unsigned int',
					'size'
				]
			],
			'ret' => 'int'
		},
		'stub_execveat' => {
			'code' => 322,
			'name' => 'stub_execveat',
			'args' => [
				[
					'int',
					'dfd'
				],
				[
					'const char __user *',
					'filename'
				],
				[
					'const char __user * const __user *',
					'argv'
				],
				[
					'const char __user * const __user *',
					'envp'
				],
				[
					'int',
					'flags'
				]
			],
			'ret' => 'int'
		},
		'userfaultfd' => {
			'code' => 323,
			'name' => 'userfaultfd',
			'args' => [
				[
					'int',
					'flags'
				]
			],
			'ret' => 'int'
		},
		'membarrier' => {
			'code' => 324,
			'name' => 'membarrier',
			'args' => [
				[
					'int',
					'cmd'
				],
				[
					'int',
					'flags'
				]
			],
			'ret' => 'int'
		},
		'mlock2' => {
			'code' => 325,
			'name' => 'mlock2',
			'args' => [
				[
					'unsigned long',
					'start'
				],
				[
					'size_t',
					'len'
				],
				[
					'int',
					'flags'
				]
			],
			'ret' => 'int'
		},
		'copy_file_range' => {
			'code' => 326,
			'name' => 'copy_file_range',
			'args' => [
				[
					'int',
					'fd_in'
				],
				[
					'loff_t __user *',
					'off_in'
				],
				[
					'int',
					'fd_out'
				],
				[
					'loff_t __user * ',
					'off_out'
				],
				[
					'size_t',
					'len'
				],
				[
					'unsigned int',
					'flags'
				]
			],
			'ret' => 'int'
		},
		'preadv2' => {
			'code' => 327,
			'name' => 'preadv2',
			'args' => [
				[
					'unsigned long',
					'fd'
				],
				[
					'const struct iovec __user *',
					'vec'
				],
				[
					'unsigned long',
					'vlen'
				],
				[
					'unsigned long',
					'pos_l'
				],
				[
					'unsigned long',
					'pos_h'
				],
				[
					'int',
					'flags'
				]
			],
			'ret' => 'int'
		},
		'pwritev2' => {
			'code' => 328,
			'name' => 'pwritev2',
			'args' => [
				[
					'unsigned long',
					'fd'
				],
				[
					'const struct iovec __user *',
					'vec'
				],
				[
					'unsigned long',
					'vlen'
				],
				[
					'unsigned long',
					'pos_l'
				],
				[
					'unsigned long',
					'pos_h'
				],
				[
					'int',
					'flags'
				]
			],
			'ret' => 'int'
		}
	);
}

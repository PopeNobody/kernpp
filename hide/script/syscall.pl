%calls = (
  'read' => {
    'code' => 0,
    'name' => 'read',
    'impl' => 1,
    'args' => [
      [
        'fd_t',
        'fd'
      ],
      [
        'ostr_t',
        'buf'
      ],
      [
        'size_t',
        'count'
      ]
    ],
    'ret' => 'ssize_t'
  },
  'sys_write' => {
    'code' => 1,
    'name' => 'write',
    'impl' => 1,
    'args' => [
      [
        'fd_t',
        'fd'
      ],
      [
        'istr_t',
        'buf'
      ],
      [
        'size_t',
        'count'
      ]
    ],
    'ret' => 'ssize_t'
  },
  'open' => {
    'code' => 2,
    'name' => 'open',
    'impl' => 1,
    'args' => [
      [
        'istr_t',
        'path'
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
    'ret' => 'fd_t'
  },
  'close' => {
    'code' => 3,
    'name' => 'close',
    'impl' => 1,
    'args' => [
      [
        'fd_t',
        'fd'
      ]
    ],
    'ret' => 'int'
  },
  'stat' => {
    'code' => 4,
    'name' => 'stat',
    'impl' => 1,
    'args' => [
      [
        'istr_t',
        'path'
      ],
      [
        'stat_p',
        'statbuf'
      ]
    ],
    'ret' => 'int'
  },
  'fstat' => {
    'code' => 5,
    'name' => 'fstat',
    'impl' => 1,
    'args' => [
      [
        'fd_t',
        'fd'
      ],
      [
        'stat_p',
        'statbuf'
      ]
    ],
    'ret' => 'int'
  },
  'lstat' => {
    'code' => 6,
    'name' => 'lstat',
    'impl' => 1,
    'args' => [
      [
        'istr_t',
        'path'
      ],
      [
        'stat_p',
        'statbuf'
      ]
    ],
    'ret' => 'int'
  },
  'poll' => {
    'code' => 7,
    'name' => 'poll',
    'impl' => 1,
    'args' => [
      [
        'pollfd_p',
        'ufds'
      ],
      [
        'unsigned',
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
    'impl' => 1,
    'args' => [
      [
        'fd_t',
        'fd'
      ],
      [
        'off_t',
        'offset'
      ],
      [
        'unsigned',
        'origin'
      ]
    ],
    'ret' => 'int'
  },
  'mmap' => {
    'code' => 9,
    'name' => 'mmap',
    'impl' => 1,
    'args' => [
      [
        'void*',
        'addr'
      ],
      [
        'size_t',
        'len'
      ],
      [
        'int',
        'prot'
      ],
      [
        'int',
        'flags'
      ],
      [
        'fd_t',
        'fd'
      ],
      [
        'off_t',
        'off'
      ]
    ],
    'ret' => 'char*'
  },
  'mprotect' => {
    'code' => 10,
    'name' => 'mprotect',
    'impl' => 1,
    'args' => [
      [
        'uint64_t',
        'start'
      ],
      [
        'size_t',
        'len'
      ],
      [
        'uint64_t',
        'prot'
      ]
    ],
    'ret' => 'int'
  },
  'munmap' => {
    'code' => 11,
    'name' => 'munmap',
    'impl' => 1,
    'args' => [
      [
        'uint64_t',
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
    'impl' => 1,
    'args' => [
      [
        'void_p',
        'brk'
      ]
    ],
    'ret' => 'int'
  },
  'rt_sigaction' => {
    'code' => 13,
    'name' => 'rt_sigaction',
    'impl' => 1,
    'args' => [
      [
        'int',
        'sig'
      ],
      [
        'sigaction_p',
        'act'
      ],
      [
        'sigaction_p',
        'oact'
      ]
    ],
    'ret' => 'int'
  },
  'rt_sigprocmask' => {
    'code' => 14,
    'name' => 'rt_sigprocmask',
    'impl' => 1,
    'args' => [
      [
        'int',
        'how'
      ],
      [
        'sigset_p',
        'nset'
      ],
      [
        'sigset_p',
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
    'impl' => 1,
    'args' => [
      [
        'uint64_t',
        '__unused'
      ]
    ],
    'ret' => 'int'
  },
  'ioctl' => {
    'code' => 16,
    'name' => 'ioctl',
    'impl' => 1,
    'args' => [
      [
        'fd_t',
        'fd'
      ],
      [
        'unsigned',
        'cmd'
      ],
      [
        'uint64_t',
        'arg'
      ]
    ],
    'ret' => 'int'
  },
  'pread64' => {
    'code' => 17,
    'name' => 'pread64',
    'impl' => 1,
    'args' => [
      [
        'fd_t',
        'fd'
      ],
      [
        'ostr_t',
        'buf'
      ],
      [
        'size_t',
        'count'
      ],
      [
        'off_t',
        'pos'
      ]
    ],
    'ret' => 'int'
  },
  'pwrite64' => {
    'code' => 18,
    'name' => 'pwrite64',
    'impl' => 1,
    'args' => [
      [
        'fd_t',
        'fd'
      ],
      [
        'istr_t',
        'buf'
      ],
      [
        'size_t',
        'count'
      ],
      [
        'off_t',
        'pos'
      ]
    ],
    'ret' => 'int'
  },
  'readv' => {
    'code' => 19,
    'name' => 'readv',
    'impl' => 1,
    'args' => [
      [
        'fd_t',
        'fd'
      ],
      [
        'iovec_p',
        'vec'
      ],
      [
        'uint64_t',
        'vlen'
      ]
    ],
    'ret' => 'int'
  },
  'writev' => {
    'code' => 20,
    'name' => 'writev',
    'impl' => 1,
    'args' => [
      [
        'fd_t',
        'fd'
      ],
      [
        'iovec_p',
        'vec'
      ],
      [
        'uint64_t',
        'vlen'
      ]
    ],
    'ret' => 'int'
  },
  'access' => {
    'code' => 21,
    'name' => 'access',
    'impl' => 1,
    'args' => [
      [
        'istr_t',
        'path'
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
    'impl' => 1,
    'args' => [
      [
        'fd_p',
        'filedes'
      ]
    ],
    'ret' => 'int'
  },
  'select' => {
    'code' => 23,
    'name' => 'select',
    'impl' => 1,
    'args' => [
      [
        'int',
        'n'
      ],
      [
        'fd_set_p',
        'inp'
      ],
      [
        'fd_set_p',
        'outp'
      ],
      [
        'fd_set_p',
        'exp'
      ],
      [
        'timeval_p',
        'tvp'
      ]
    ],
    'ret' => 'int'
  },
  'sched_yield' => {
    'code' => 24,
    'name' => 'sched_yield',
    'impl' => 1,
    'args' => [],
    'ret' => 'int'
  },
  'mremap' => {
    'code' => 25,
    'name' => 'mremap',
    'impl' => 1,
    'args' => [
      [
        'uint64_t',
        'addr'
      ],
      [
        'uint64_t',
        'old_len'
      ],
      [
        'uint64_t',
        'new_len'
      ],
      [
        'uint64_t',
        'flags'
      ],
      [
        'uint64_t',
        'new_addr'
      ]
    ],
    'ret' => 'int'
  },
  'msync' => {
    'code' => 26,
    'name' => 'msync',
    'impl' => 1,
    'args' => [
      [
        'uint64_t',
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
    'impl' => 1,
    'args' => [
      [
        'uint64_t',
        'start'
      ],
      [
        'size_t',
        'len'
      ],
      [
        'ostr_t',
        'vec'
      ]
    ],
    'ret' => 'int'
  },
  'madvise' => {
    'code' => 28,
    'name' => 'madvise',
    'impl' => 1,
    'args' => [
      [
        'uint64_t',
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
    'impl' => 1,
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
    'impl' => 1,
    'args' => [
      [
        'int',
        'shmid'
      ],
      [
        'ostr_t',
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
    'impl' => 1,
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
        'shmid_ds_p',
        'buf'
      ]
    ],
    'ret' => 'int'
  },
  'dup' => {
    'code' => 32,
    'name' => 'dup',
    'impl' => 1,
    'args' => [
      [
        'unsigned',
        'fildes'
      ]
    ],
    'ret' => 'int'
  },
  'dup2' => {
    'code' => 33,
    'name' => 'dup2',
    'impl' => 1,
    'args' => [
      [
        'fd_t',
        'oldfd'
      ],
      [
        'fd_t',
        'newfd'
      ]
    ],
    'ret' => 'int'
  },
  'pause' => {
    'code' => 34,
    'name' => 'pause',
    'impl' => 1,
    'args' => [],
    'ret' => 'int'
  },
  'nanosleep' => {
    'code' => 35,
    'name' => 'nanosleep',
    'impl' => 1,
    'args' => [
      [
        'timespec_p',
        'rqtp'
      ],
      [
        'timespec_p',
        'rmtp'
      ]
    ],
    'ret' => 'int'
  },
  'getitimer' => {
    'code' => 36,
    'name' => 'getitimer',
    'impl' => 1,
    'args' => [
      [
        'int',
        'which'
      ],
      [
        'itimerval_p',
        'value'
      ]
    ],
    'ret' => 'int'
  },
  'alarm' => {
    'code' => 37,
    'name' => 'alarm',
    'impl' => 1,
    'args' => [
      [
        'unsigned',
        'seconds'
      ]
    ],
    'ret' => 'int'
  },
  'setitimer' => {
    'code' => 38,
    'name' => 'setitimer',
    'impl' => 1,
    'args' => [
      [
        'int',
        'which'
      ],
      [
        'itimerval_p',
        'value'
      ],
      [
        'itimerval_p',
        'ovalue'
      ]
    ],
    'ret' => 'int'
  },
  'getpid' => {
    'code' => 39,
    'name' => 'getpid',
    'impl' => 1,
    'args' => [],
    'ret' => 'int'
  },
  'sendfile' => {
    'code' => 40,
    'name' => 'sendfile',
    'impl' => 1,
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
        'off_p',
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
    'impl' => 1,
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
    'impl' => 1,
    'args' => [
      [
        'fd_t',
        'fd'
      ],
      [
        'sockaddr_p',
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
    'impl' => 1,
    'args' => [
      [
        'fd_t',
        'fd'
      ],
      [
        'sockaddr_p',
        'upeer_sockaddr'
      ],
      [
        'int32_p',
        'upeer_addrlen'
      ]
    ],
    'ret' => 'int'
  },
  'sendto' => {
    'code' => 44,
    'name' => 'sendto',
    'impl' => 1,
    'args' => [
      [
        'fd_t',
        'fd'
      ],
      [
        'void_p',
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
        'sockaddr_p',
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
    'impl' => 1,
    'args' => [
      [
        'fd_t',
        'fd'
      ],
      [
        'void_p',
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
        'sockaddr_p',
        'addr'
      ],
      [
        'int32_p',
        'addr_len'
      ]
    ],
    'ret' => 'int'
  },
  'sendmsg' => {
    'code' => 46,
    'name' => 'sendmsg',
    'impl' => 1,
    'args' => [
      [
        'fd_t',
        'fd'
      ],
      [
        'msghdr_p',
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
    'impl' => 1,
    'args' => [
      [
        'fd_t',
        'fd'
      ],
      [
        'msghdr_p',
        'msg'
      ],
      [
        'unsigned',
        'flags'
      ]
    ],
    'ret' => 'int'
  },
  'shutdown' => {
    'code' => 48,
    'name' => 'shutdown',
    'impl' => 1,
    'args' => [
      [
        'fd_t',
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
    'impl' => 1,
    'args' => [
      [
        'fd_t',
        'fd'
      ],
      [
        'sockaddr_p',
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
    'impl' => 1,
    'args' => [
      [
        'fd_t',
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
    'impl' => 1,
    'args' => [
      [
        'fd_t',
        'fd'
      ],
      [
        'sockaddr_p',
        'usockaddr'
      ],
      [
        'int32_p',
        'usockaddr_len'
      ]
    ],
    'ret' => 'int'
  },
  'getpeername' => {
    'code' => 52,
    'name' => 'getpeername',
    'impl' => 1,
    'args' => [
      [
        'fd_t',
        'fd'
      ],
      [
        'sockaddr_p',
        'usockaddr'
      ],
      [
        'int32_p',
        'usockaddr_len'
      ]
    ],
    'ret' => 'int'
  },
  'socketpair' => {
    'code' => 53,
    'name' => 'socketpair',
    'impl' => 1,
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
        'int32_p',
        'usockvec'
      ]
    ],
    'ret' => 'int'
  },
  'setsockopt' => {
    'code' => 54,
    'name' => 'setsockopt',
    'impl' => 1,
    'args' => [
      [
        'fd_t',
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
        'ostr_t',
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
    'impl' => 1,
    'args' => [
      [
        'fd_t',
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
        'ostr_t',
        'optval'
      ],
      [
        'int32_p',
        'optlen'
      ]
    ],
    'ret' => 'int'
  },
  'sys_clone' => {
    'code' => 56,
    'name' => 'clone',
    'impl' => 1,
    'args' => [
      [
        'uint64_t',
        'clone_flags'
      ],
      [
        'uint64_t',
        'newsp'
      ],
      [
        'void_p',
        'parent_tid'
      ],
      [
        'void_p',
        'child_tid'
      ]
    ],
    'ret' => 'int'
  },
  'fork' => {
    'code' => 57,
    'name' => 'fork',
    'impl' => 1,
    'args' => [],
    'ret' => 'int'
  },
  'vfork' => {
    'code' => 58,
    'name' => 'vfork',
    'impl' => 1,
    'args' => [],
    'ret' => 'int'
  },
  'execve' => {
    'code' => 59,
    'name' => 'execve',
    'impl' => 1,
    'args' => [
      [
        'const char *',
        'filename'
      ],
      [
        'char *const *',
        'argv'
      ],
      [
        'char *const *',
        'envp'
      ]
    ],
    'ret' => 'int'
  },
  '_exit' => {
    'code' => 60,
    'name' => 'exit',
    'impl' => 1,
    'args' => [
      [
        'int',
        'error_code'
      ]
    ],
    'ret' => 'void'
  },
  'wait4' => {
    'code' => 61,
    'name' => 'wait4',
    'impl' => 1,
    'args' => [
      [
        'pid_t',
        'upid'
      ],
      [
        'int32_p',
        'stat_addr'
      ],
      [
        'int',
        'options'
      ],
      [
        'rusage_p',
        'ru'
      ]
    ],
    'ret' => 'int'
  },
  'kill' => {
    'code' => 62,
    'name' => 'kill',
    'impl' => 1,
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
    'impl' => 1,
    'args' => [
      [
        'utsname_p',
        'name'
      ]
    ],
    'ret' => 'int'
  },
  'semget' => {
    'code' => 64,
    'name' => 'semget',
    'impl' => 1,
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
    'impl' => 1,
    'args' => [
      [
        'int',
        'semid'
      ],
      [
        'sembuf_p',
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
    'impl' => 1,
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
    'impl' => 1,
    'args' => [
      [
        'ostr_t',
        'shmaddr'
      ]
    ],
    'ret' => 'int'
  },
  'msgget' => {
    'code' => 68,
    'name' => 'msgget',
    'impl' => 1,
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
    'impl' => 1,
    'args' => [
      [
        'int',
        'msqid'
      ],
      [
        'msgbuf_p',
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
    'impl' => 1,
    'args' => [
      [
        'int',
        'msqid'
      ],
      [
        'msgbuf_p',
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
    'impl' => 1,
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
        'msqid_ds_p',
        'buf'
      ]
    ],
    'ret' => 'int'
  },
  'fcntl' => {
    'code' => 72,
    'name' => 'fcntl',
    'impl' => 1,
    'args' => [
      [
        'fd_t',
        'fd'
      ],
      [
        'unsigned',
        'cmd'
      ],
      [
        'uint64_t',
        'arg'
      ]
    ],
    'ret' => 'int'
  },
  'flock' => {
    'code' => 73,
    'name' => 'flock',
    'impl' => 1,
    'args' => [
      [
        'fd_t',
        'fd'
      ],
      [
        'unsigned',
        'cmd'
      ]
    ],
    'ret' => 'int'
  },
  'fsync' => {
    'code' => 74,
    'name' => 'fsync',
    'impl' => 1,
    'args' => [
      [
        'fd_t',
        'fd'
      ]
    ],
    'ret' => 'int'
  },
  'fdatasync' => {
    'code' => 75,
    'name' => 'fdatasync',
    'impl' => 1,
    'args' => [
      [
        'fd_t',
        'fd'
      ]
    ],
    'ret' => 'int'
  },
  'truncate' => {
    'code' => 76,
    'name' => 'truncate',
    'impl' => 1,
    'args' => [
      [
        'istr_t',
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
    'impl' => 1,
    'args' => [
      [
        'fd_t',
        'fd'
      ],
      [
        'uint64_t',
        'length'
      ]
    ],
    'ret' => 'int'
  },
  'getdents' => {
    'code' => 78,
    'name' => 'getdents',
    'impl' => 1,
    'args' => [
      [
        'fd_t',
        'fd'
      ],
      [
        'linux_dirent_p',
        'dirent'
      ],
      [
        'size_t',
        'count'
      ]
    ],
    'ret' => 'ssize_t'
  },
  'getcwd' => {
    'code' => 79,
    'name' => 'getcwd',
    'impl' => 1,
    'args' => [
      [
        'ostr_t',
        'buf'
      ],
      [
        'uint64_t',
        'size'
      ]
    ],
    'ret' => 'int'
  },
  'chdir' => {
    'code' => 80,
    'name' => 'chdir',
    'impl' => 1,
    'args' => [
      [
        'istr_t',
        'path'
      ]
    ],
    'ret' => 'int'
  },
  'fchdir' => {
    'code' => 81,
    'name' => 'fchdir',
    'impl' => 1,
    'args' => [
      [
        'fd_t',
        'fd'
      ]
    ],
    'ret' => 'int'
  },
  'rename' => {
    'code' => 82,
    'name' => 'rename',
    'impl' => 1,
    'args' => [
      [
        'istr_t',
        'opath'
      ],
      [
        'istr_t',
        'npath'
      ]
    ],
    'ret' => 'int'
  },
  'mkdir' => {
    'code' => 83,
    'name' => 'mkdir',
    'impl' => 1,
    'args' => [
      [
        'istr_t',
        'path'
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
    'impl' => 1,
    'args' => [
      [
        'istr_t',
        'path'
      ]
    ],
    'ret' => 'int'
  },
  'creat' => {
    'code' => 85,
    'name' => 'creat',
    'impl' => 1,
    'args' => [
      [
        'istr_t',
        'path'
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
    'impl' => 1,
    'args' => [
      [
        'istr_t',
        'opath'
      ],
      [
        'istr_t',
        'npath'
      ]
    ],
    'ret' => 'int'
  },
  'unlink' => {
    'code' => 87,
    'name' => 'unlink',
    'impl' => 1,
    'args' => [
      [
        'istr_t',
        'path'
      ]
    ],
    'ret' => 'int'
  },
  'symlink' => {
    'code' => 88,
    'name' => 'symlink',
    'impl' => 1,
    'args' => [
      [
        'istr_t',
        'opath'
      ],
      [
        'istr_t',
        'npath'
      ]
    ],
    'ret' => 'int'
  },
  'readlink' => {
    'code' => 89,
    'name' => 'readlink',
    'impl' => 1,
    'args' => [
      [
        'istr_t',
        'path'
      ],
      [
        'ostr_t',
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
    'impl' => 1,
    'args' => [
      [
        'istr_t',
        'path'
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
    'impl' => 1,
    'args' => [
      [
        'fd_t',
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
    'impl' => 1,
    'args' => [
      [
        'istr_t',
        'path'
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
    'impl' => 1,
    'args' => [
      [
        'fd_t',
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
    'impl' => 1,
    'args' => [
      [
        'istr_t',
        'path'
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
    'impl' => 1,
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
    'impl' => 1,
    'args' => [
      [
        'timeval_p',
        'tv'
      ],
      [
        'timezone_p',
        'tz'
      ]
    ],
    'ret' => 'int'
  },
  'getrlimit' => {
    'code' => 97,
    'name' => 'getrlimit',
    'impl' => 1,
    'args' => [
      [
        'unsigned',
        'resource'
      ],
      [
        'rlimit_p',
        'rlim'
      ]
    ],
    'ret' => 'int'
  },
  'getrusage' => {
    'code' => 98,
    'name' => 'getrusage',
    'impl' => 1,
    'args' => [
      [
        'int',
        'who'
      ],
      [
        'rusage_p',
        'ru'
      ]
    ],
    'ret' => 'int'
  },
  'sysinfo' => {
    'code' => 99,
    'name' => 'sysinfo',
    'impl' => 1,
    'args' => [
      [
        'sysinfo_p',
        'info'
      ]
    ],
    'ret' => 'int'
  },
  'times' => {
    'code' => 100,
    'name' => 'times',
    'impl' => 1,
    'args' => [
      [
        'sysinfo_p',
        'info'
      ]
    ],
    'ret' => 'int'
  },
  'ptrace' => {
    'code' => 101,
    'name' => 'ptrace',
    'impl' => 1,
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
        'uint64_t',
        'addr'
      ],
      [
        'uint64_t',
        'data'
      ]
    ],
    'ret' => 'int'
  },
  'getuid' => {
    'code' => 102,
    'name' => 'getuid',
    'impl' => 1,
    'args' => [],
    'ret' => 'int'
  },
  'syslog' => {
    'code' => 103,
    'name' => 'syslog',
    'impl' => 1,
    'args' => [
      [
        'int',
        'type'
      ],
      [
        'ostr_t',
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
    'impl' => 1,
    'args' => [],
    'ret' => 'int'
  },
  'setuid' => {
    'code' => 105,
    'name' => 'setuid',
    'impl' => 1,
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
    'impl' => 1,
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
    'impl' => 1,
    'args' => [],
    'ret' => 'int'
  },
  'getegid' => {
    'code' => 108,
    'name' => 'getegid',
    'impl' => 1,
    'args' => [],
    'ret' => 'int'
  },
  'setpgid' => {
    'code' => 109,
    'name' => 'setpgid',
    'impl' => 1,
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
    'impl' => 1,
    'args' => [],
    'ret' => 'int'
  },
  'getpgrp' => {
    'code' => 111,
    'name' => 'getpgrp',
    'impl' => 1,
    'args' => [],
    'ret' => 'int'
  },
  'setsid' => {
    'code' => 112,
    'name' => 'setsid',
    'impl' => 1,
    'args' => [],
    'ret' => 'int'
  },
  'setreuid' => {
    'code' => 113,
    'name' => 'setreuid',
    'impl' => 1,
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
    'impl' => 1,
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
    'impl' => 1,
    'args' => [
      [
        'int',
        'gidsetsize'
      ],
      [
        'gid_p',
        'grouplist'
      ]
    ],
    'ret' => 'int'
  },
  'setgroups' => {
    'code' => 116,
    'name' => 'setgroups',
    'impl' => 1,
    'args' => [
      [
        'int',
        'gidsetsize'
      ],
      [
        'gid_p',
        'grouplist'
      ]
    ],
    'ret' => 'int'
  },
  'setresuid' => {
    'code' => 117,
    'name' => 'setresuid',
    'impl' => 1,
    'args' => [
      [
        'uid_p',
        'ruid'
      ],
      [
        'uid_p',
        'euid'
      ],
      [
        'uid_p',
        'suid'
      ]
    ],
    'ret' => 'int'
  },
  'getresuid' => {
    'code' => 118,
    'name' => 'getresuid',
    'impl' => 1,
    'args' => [
      [
        'uid_p',
        'ruid'
      ],
      [
        'uid_p',
        'euid'
      ],
      [
        'uid_p',
        'suid'
      ]
    ],
    'ret' => 'int'
  },
  'setresgid' => {
    'code' => 119,
    'name' => 'setresgid',
    'impl' => 1,
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
    'impl' => 1,
    'args' => [
      [
        'gid_p',
        'rgid'
      ],
      [
        'gid_p',
        'egid'
      ],
      [
        'gid_p',
        'sgid'
      ]
    ],
    'ret' => 'int'
  },
  'getpgid' => {
    'code' => 121,
    'name' => 'getpgid',
    'impl' => 1,
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
    'impl' => 1,
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
    'impl' => 1,
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
    'impl' => 1,
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
    'impl' => 1,
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
    'impl' => 1,
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
    'impl' => 1,
    'args' => [
      [
        'sigset_p',
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
    'impl' => 1,
    'args' => [
      [
        'const sigset_p',
        'uthese'
      ],
      [
        'siginfo_p',
        'uinfo'
      ],
      [
        'timespec_p',
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
    'impl' => 1,
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
        'siginfo_p',
        'uinfo'
      ]
    ],
    'ret' => 'int'
  },
  'rt_sigsuspend' => {
    'code' => 130,
    'name' => 'rt_sigsuspend',
    'impl' => 1,
    'args' => [
      [
        'sigset_p',
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
    'impl' => 1,
    'args' => [
      [
        'const stack_p',
        'uss'
      ],
      [
        'stack_p',
        'uoss'
      ]
    ],
    'ret' => 'int'
  },
  'utime' => {
    'code' => 132,
    'name' => 'utime',
    'impl' => 1,
    'args' => [
      [
        'ostr_t',
        'path'
      ],
      [
        'utimbuf_p',
        'times'
      ]
    ],
    'ret' => 'int'
  },
  'mknod' => {
    'code' => 133,
    'name' => 'mknod',
    'impl' => 1,
    'args' => [
      [
        'istr_t',
        'path'
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
    'impl' => 0
  },
  'personality' => {
    'code' => 135,
    'name' => 'personality',
    'impl' => 1,
    'args' => [
      [
        'unsigned',
        'personality'
      ]
    ],
    'ret' => 'int'
  },
  'ustat' => {
    'code' => 136,
    'name' => 'ustat',
    'impl' => 1,
    'args' => [
      [
        'unsigned',
        'dev'
      ],
      [
        'ustat_p',
        'ubuf'
      ]
    ],
    'ret' => 'int'
  },
  'statfs' => {
    'code' => 137,
    'name' => 'statfs',
    'impl' => 1,
    'args' => [
      [
        'istr_t',
        'path'
      ],
      [
        'statfs_p',
        'buf'
      ]
    ],
    'ret' => 'int'
  },
  'fstatfs' => {
    'code' => 138,
    'name' => 'fstatfs',
    'impl' => 1,
    'args' => [
      [
        'fd_t',
        'fd'
      ],
      [
        'statfs_p',
        'buf'
      ]
    ],
    'ret' => 'int'
  },
  'sysfs' => {
    'code' => 139,
    'name' => 'sysfs',
    'impl' => 1,
    'args' => [
      [
        'int',
        'option'
      ],
      [
        'uint64_t',
        'arg1'
      ],
      [
        'uint64_t',
        'arg2'
      ]
    ],
    'ret' => 'int'
  },
  'getpriority' => {
    'code' => 140,
    'name' => 'getpriority',
    'impl' => 1,
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
    'impl' => 1,
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
  'sys_sched_setparam' => {
    'code' => 142,
    'name' => 'sched_setparam',
    'impl' => 1,
    'args' => [
      [
        'pid_t',
        'pid'
      ],
      [
        'const void *',
        'param'
      ]
    ],
    'ret' => 'int'
  },
  'sched_getparam' => {
    'code' => 143,
    'name' => 'sched_getparam',
    'impl' => 1,
    'args' => [
      [
        'pid_t',
        'pid'
      ],
      [
        'sched_param_p',
        'param'
      ]
    ],
    'ret' => 'int'
  },
  'sys_sched_setscheduler' => {
    'code' => 144,
    'name' => 'sched_setscheduler',
    'impl' => 1,
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
        'sched_param_p',
        'param'
      ]
    ],
    'ret' => 'int'
  },
  'sched_getscheduler' => {
    'code' => 145,
    'name' => 'sched_getscheduler',
    'impl' => 1,
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
    'impl' => 1,
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
    'impl' => 1,
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
    'impl' => 1,
    'args' => [
      [
        'pid_t',
        'pid'
      ],
      [
        'timespec_p',
        'interval'
      ]
    ],
    'ret' => 'int'
  },
  'mlock' => {
    'code' => 149,
    'name' => 'mlock',
    'impl' => 1,
    'args' => [
      [
        'void_p',
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
    'impl' => 1,
    'args' => [
      [
        'void_p',
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
    'impl' => 1,
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
    'impl' => 1,
    'args' => [],
    'ret' => 'int'
  },
  'vhangup' => {
    'code' => 153,
    'name' => 'vhangup',
    'impl' => 1,
    'args' => [],
    'ret' => 'int'
  },
  'modify_ldt' => {
    'code' => 154,
    'name' => 'modify_ldt',
    'impl' => 1,
    'args' => [
      [
        'int',
        'func'
      ],
      [
        'void_p',
        'ptr'
      ],
      [
        'uint64_t',
        'bytecount'
      ]
    ],
    'ret' => 'int'
  },
  'pivot_root' => {
    'code' => 155,
    'name' => 'pivot_root',
    'impl' => 1,
    'args' => [
      [
        'istr_t',
        'new_root'
      ],
      [
        'istr_t',
        'put_old'
      ]
    ],
    'ret' => 'int'
  },
  '_sysctl' => {
    'code' => 156,
    'name' => '_sysctl',
    'impl' => 1,
    'args' => [
      [
        'sysctl_args_p',
        'args'
      ]
    ],
    'ret' => 'int'
  },
  'prctl' => {
    'code' => 157,
    'name' => 'prctl',
    'impl' => 1,
    'args' => [
      [
        'int',
        'option'
      ],
      [
        'uint64_t',
        'arg2'
      ],
      [
        'uint64_t',
        'arg3'
      ],
      [
        'uint64_t',
        'arg4'
      ],
      [
        'uint64_t',
        'arg5'
      ]
    ],
    'ret' => 'int'
  },
  'arch_prctl' => {
    'code' => 158,
    'name' => 'arch_prctl',
    'impl' => 1,
    'args' => [
      [
        'task_struct_p',
        'task'
      ],
      [
        'int',
        'code'
      ],
      [
        'uint64_t',
        'addr'
      ]
    ],
    'ret' => 'int'
  },
  'adjtimex' => {
    'code' => 159,
    'name' => 'adjtimex',
    'impl' => 1,
    'args' => [
      [
        'timex_p',
        'txc_p'
      ]
    ],
    'ret' => 'int'
  },
  'setrlimit' => {
    'code' => 160,
    'name' => 'setrlimit',
    'impl' => 1,
    'args' => [
      [
        'unsigned',
        'resource'
      ],
      [
        'rlimit_p',
        'rlim'
      ]
    ],
    'ret' => 'int'
  },
  'chroot' => {
    'code' => 161,
    'name' => 'chroot',
    'impl' => 1,
    'args' => [
      [
        'istr_t',
        'path'
      ]
    ],
    'ret' => 'int'
  },
  'sync' => {
    'code' => 162,
    'name' => 'sync',
    'impl' => 1,
    'args' => [],
    'ret' => 'int'
  },
  'acct' => {
    'code' => 163,
    'name' => 'acct',
    'impl' => 1,
    'args' => [
      [
        'istr_t',
        'name'
      ]
    ],
    'ret' => 'int'
  },
  'settimeofday' => {
    'code' => 164,
    'name' => 'settimeofday',
    'impl' => 1,
    'args' => [
      [
        'timeval_p',
        'tv'
      ],
      [
        'timezone_p',
        'tz'
      ]
    ],
    'ret' => 'int'
  },
  'mount' => {
    'code' => 165,
    'name' => 'mount',
    'impl' => 1,
    'args' => [
      [
        'ostr_t',
        'dev_name'
      ],
      [
        'ostr_t',
        'dir_name'
      ],
      [
        'ostr_t',
        'type'
      ],
      [
        'uint64_t',
        'flags'
      ],
      [
        'void_p',
        'data'
      ]
    ],
    'ret' => 'int'
  },
  'umount2' => {
    'code' => 166,
    'name' => 'umount2',
    'impl' => 1,
    'args' => [
      [
        'istr_t',
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
    'impl' => 1,
    'args' => [
      [
        'istr_t',
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
    'impl' => 1,
    'args' => [
      [
        'istr_t',
        'specialfile'
      ]
    ],
    'ret' => 'int'
  },
  'reboot' => {
    'code' => 169,
    'name' => 'reboot',
    'impl' => 1,
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
        'unsigned',
        'cmd'
      ],
      [
        'void_p',
        'arg'
      ]
    ],
    'ret' => 'int'
  },
  'sethostname' => {
    'code' => 170,
    'name' => 'sethostname',
    'impl' => 1,
    'args' => [
      [
        'ostr_t',
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
    'impl' => 1,
    'args' => [
      [
        'ostr_t',
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
    'impl' => 1,
    'args' => [
      [
        'unsigned',
        'level'
      ],
      [
        'pt_regs_p',
        'regs'
      ]
    ],
    'ret' => 'int'
  },
  'ioperm' => {
    'code' => 173,
    'name' => 'ioperm',
    'impl' => 1,
    'args' => [
      [
        'uint64_t',
        'from'
      ],
      [
        'uint64_t',
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
    'impl' => 0,
    'ret' => 'int'
  },
  'init_module' => {
    'code' => 175,
    'name' => 'init_module',
    'impl' => 1,
    'args' => [
      [
        'void_p',
        'umod'
      ],
      [
        'uint64_t',
        'len'
      ],
      [
        'istr_t',
        'uargs'
      ]
    ],
    'ret' => 'int'
  },
  'delete_module' => {
    'code' => 176,
    'name' => 'delete_module',
    'impl' => 1,
    'args' => [
      [
        'istr_t',
        'name_user'
      ],
      [
        'unsigned',
        'flags'
      ]
    ],
    'ret' => 'int'
  },
  'get_kernel_syms' => {
    'code' => 177,
    'name' => 'get_kernel_syms',
    'impl' => 0
  },
  'query_module' => {
    'code' => 178,
    'name' => 'query_module',
    'impl' => 0
  },
  'quotactl' => {
    'code' => 179,
    'name' => 'quotactl',
    'impl' => 1,
    'args' => [
      [
        'unsigned',
        'cmd'
      ],
      [
        'istr_t',
        'special'
      ],
      [
        'qid_t',
        'id'
      ],
      [
        'void_p',
        'addr'
      ]
    ],
    'ret' => 'int'
  },
  'nfsservctl' => {
    'code' => 180,
    'name' => 'nfsservctl',
    'impl' => 0
  },
  'getpmsg' => {
    'code' => 181,
    'name' => 'getpmsg',
    'impl' => 0
  },
  'putpmsg' => {
    'code' => 182,
    'name' => 'putpmsg',
    'impl' => 0
  },
  'afs_syscall' => {
    'code' => 183,
    'name' => 'afs_syscall',
    'impl' => 0
  },
  'tuxcall' => {
    'code' => 184,
    'name' => 'tuxcall',
    'impl' => 0
  },
  'security' => {
    'code' => 185,
    'name' => 'security',
    'impl' => 0
  },
  'gettid' => {
    'code' => 186,
    'name' => 'gettid',
    'impl' => 1,
    'args' => [],
    'ret' => 'int'
  },
  'readahead' => {
    'code' => 187,
    'name' => 'readahead',
    'impl' => 1,
    'args' => [
      [
        'fd_t',
        'fd'
      ],
      [
        'off_t',
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
    'impl' => 1,
    'args' => [
      [
        'istr_t',
        'path'
      ],
      [
        'istr_t',
        'name'
      ],
      [
        'const void_p',
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
    'impl' => 1,
    'args' => [
      [
        'istr_t',
        'path'
      ],
      [
        'istr_t',
        'name'
      ],
      [
        'const void_p',
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
    'impl' => 1,
    'args' => [
      [
        'fd_t',
        'fd'
      ],
      [
        'istr_t',
        'name'
      ],
      [
        'const void_p',
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
    'impl' => 1,
    'args' => [
      [
        'istr_t',
        'path'
      ],
      [
        'istr_t',
        'name'
      ],
      [
        'void_p',
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
    'impl' => 1,
    'args' => [
      [
        'istr_t',
        'path'
      ],
      [
        'istr_t',
        'name'
      ],
      [
        'void_p',
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
    'impl' => 1,
    'args' => [
      [
        'fd_t',
        'fd'
      ],
      [
        'istr_t',
        'name'
      ],
      [
        'void_p',
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
    'impl' => 1,
    'args' => [
      [
        'istr_t',
        'path'
      ],
      [
        'ostr_t',
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
    'impl' => 1,
    'args' => [
      [
        'istr_t',
        'path'
      ],
      [
        'ostr_t',
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
    'impl' => 1,
    'args' => [
      [
        'fd_t',
        'fd'
      ],
      [
        'ostr_t',
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
    'impl' => 1,
    'args' => [
      [
        'istr_t',
        'path'
      ],
      [
        'istr_t',
        'name'
      ]
    ],
    'ret' => 'int'
  },
  'lremovexattr' => {
    'code' => 198,
    'name' => 'lremovexattr',
    'impl' => 1,
    'args' => [
      [
        'istr_t',
        'path'
      ],
      [
        'istr_t',
        'name'
      ]
    ],
    'ret' => 'int'
  },
  'fremovexattr' => {
    'code' => 199,
    'name' => 'fremovexattr',
    'impl' => 1,
    'args' => [
      [
        'fd_t',
        'fd'
      ],
      [
        'istr_t',
        'name'
      ]
    ],
    'ret' => 'int'
  },
  'tkill' => {
    'code' => 200,
    'name' => 'tkill',
    'impl' => 1,
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
  'time' => {
    'code' => 201,
    'name' => 'time',
    'impl' => 1,
    'args' => [
      [
        'time_p',
        'tloc'
      ]
    ],
    'ret' => 'time_t'
  },
  'futex' => {
    'code' => 202,
    'name' => 'futex',
    'impl' => 1,
    'args' => [
      [
        'uint32_p',
        'uaddr'
      ],
      [
        'int',
        'op'
      ],
      [
        'uint32_t',
        'val'
      ],
      [
        'timespec_p',
        'utime'
      ],
      [
        'uint32_p',
        'uaddr2'
      ],
      [
        'uint32_t',
        'val3'
      ]
    ],
    'ret' => 'int'
  },
  'sys_sched_setaffinity' => {
    'code' => 203,
    'name' => 'sched_setaffinity',
    'impl' => 1,
    'args' => [
      [
        'pid_t',
        'pid'
      ],
      [
        'size_t',
        'len'
      ],
      [
        'const void *',
        'user_mask_ptr'
      ]
    ],
    'ret' => 'int'
  },
  'sys_sched_getaffinity' => {
    'code' => 204,
    'name' => 'sched_getaffinity',
    'impl' => 1,
    'args' => [
      [
        'pid_t',
        'pid'
      ],
      [
        'unsigned',
        'len'
      ],
      [
        'uint64_p',
        'user_mask_ptr'
      ]
    ],
    'ret' => 'int'
  },
  'set_thread_area' => {
    'code' => 205,
    'name' => 'set_thread_area',
    'impl' => 0
  },
  'io_setup' => {
    'code' => 206,
    'name' => 'io_setup',
    'impl' => 1,
    'args' => [
      [
        'unsigned',
        'nr_events'
      ],
      [
        'aio_context_p',
        'ctxp'
      ]
    ],
    'ret' => 'int'
  },
  'io_destroy' => {
    'code' => 207,
    'name' => 'io_destroy',
    'impl' => 1,
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
    'impl' => 1,
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
        'io_event_p',
        'events'
      ]
    ],
    'ret' => 'int'
  },
  'io_submit' => {
    'code' => 209,
    'name' => 'io_submit',
    'impl' => 1,
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
        'iocb_p',
        'iocbpp'
      ]
    ],
    'ret' => 'int'
  },
  'io_cancel' => {
    'code' => 210,
    'name' => 'io_cancel',
    'impl' => 1,
    'args' => [
      [
        'aio_context_t',
        'ctx_id'
      ],
      [
        'iocb_p',
        'iocb'
      ],
      [
        'io_event_p',
        'result'
      ]
    ],
    'ret' => 'int'
  },
  'get_thread_area' => {
    'code' => 211,
    'name' => 'get_thread_area',
    'impl' => 0
  },
  'lookup_dcookie' => {
    'code' => 212,
    'name' => 'lookup_dcookie',
    'impl' => 1,
    'args' => [
      [
        'uint64_t',
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
    'impl' => 1,
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
    'impl' => 0
  },
  'epoll_wait_old' => {
    'code' => 215,
    'name' => 'epoll_wait_old',
    'impl' => 0
  },
  'remap_file_pages' => {
    'code' => 216,
    'name' => 'remap_file_pages',
    'impl' => 1,
    'args' => [
      [
        'uint64_t',
        'start'
      ],
      [
        'uint64_t',
        'size'
      ],
      [
        'uint64_t',
        'prot'
      ],
      [
        'uint64_t',
        'pgoff'
      ],
      [
        'uint64_t',
        'flags'
      ]
    ],
    'ret' => 'int'
  },
  'getdents64' => {
    'code' => 217,
    'name' => 'getdents64',
    'impl' => 1,
    'args' => [
      [
        'fd_t',
        'fd'
      ],
      [
        'linux_dirent64_p',
        'dirent'
      ],
      [
        'unsigned',
        'count'
      ]
    ],
    'ret' => 'int'
  },
  'set_tid_address' => {
    'code' => 218,
    'name' => 'set_tid_address',
    'impl' => 1,
    'args' => [
      [
        'int32_p',
        'tidptr'
      ]
    ],
    'ret' => 'int'
  },
  'restart_syscall' => {
    'code' => 219,
    'name' => 'restart_syscall',
    'impl' => 1,
    'args' => [],
    'ret' => 'int'
  },
  'semtimedop' => {
    'code' => 220,
    'name' => 'semtimedop',
    'impl' => 1,
    'args' => [
      [
        'int',
        'semid'
      ],
      [
        'sembuf_p',
        'tsops'
      ],
      [
        'unsigned',
        'nsops'
      ],
      [
        'timespec_p',
        'timeout'
      ]
    ],
    'ret' => 'int'
  },
  'fadvise64' => {
    'code' => 221,
    'name' => 'fadvise64',
    'impl' => 1,
    'args' => [
      [
        'fd_t',
        'fd'
      ],
      [
        'off_t',
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
    'impl' => 1,
    'args' => [
      [
        'const clockid_t',
        'which_clock'
      ],
      [
        'sigevent_p',
        'timer_event_spec'
      ],
      [
        'timer_p',
        'created_timer_id'
      ]
    ],
    'ret' => 'int'
  },
  'timer_settime' => {
    'code' => 223,
    'name' => 'timer_settime',
    'impl' => 1,
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
        'itimerspec_p',
        'new_setting'
      ],
      [
        'itimerspec_p',
        'old_setting'
      ]
    ],
    'ret' => 'int'
  },
  'timer_gettime' => {
    'code' => 224,
    'name' => 'timer_gettime',
    'impl' => 1,
    'args' => [
      [
        'timer_t',
        'timer_id'
      ],
      [
        'itimerspec_p',
        'setting'
      ]
    ],
    'ret' => 'int'
  },
  'timer_getoverrun' => {
    'code' => 225,
    'name' => 'timer_getoverrun',
    'impl' => 1,
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
    'impl' => 1,
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
    'impl' => 1,
    'args' => [
      [
        'const clockid_t',
        'which_clock'
      ],
      [
        'timespec_p',
        'tp'
      ]
    ],
    'ret' => 'int'
  },
  'clock_gettime' => {
    'code' => 228,
    'name' => 'clock_gettime',
    'impl' => 1,
    'args' => [
      [
        'const clockid_t',
        'which_clock'
      ],
      [
        'timespec_p',
        'tp'
      ]
    ],
    'ret' => 'int'
  },
  'clock_getres' => {
    'code' => 229,
    'name' => 'clock_getres',
    'impl' => 1,
    'args' => [
      [
        'const clockid_t',
        'which_clock'
      ],
      [
        'timespec_p',
        'tp'
      ]
    ],
    'ret' => 'int'
  },
  'clock_nanosleep' => {
    'code' => 230,
    'name' => 'clock_nanosleep',
    'impl' => 1,
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
        'timespec_p',
        'rqtp'
      ],
      [
        'timespec_p',
        'rmtp'
      ]
    ],
    'ret' => 'int'
  },
  'exit_group' => {
    'code' => 231,
    'name' => 'exit_group',
    'impl' => 1,
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
    'impl' => 1,
    'args' => [
      [
        'int',
        'epfd'
      ],
      [
        'epoll_event_p',
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
    'impl' => 1,
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
        'fd_t',
        'fd'
      ],
      [
        'epoll_event_p',
        'event'
      ]
    ],
    'ret' => 'int'
  },
  'tgkill' => {
    'code' => 234,
    'name' => 'tgkill',
    'impl' => 1,
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
    'impl' => 1,
    'args' => [
      [
        'ostr_t',
        'path'
      ],
      [
        'timeval_p',
        'utimes'
      ]
    ],
    'ret' => 'int'
  },
  'vserver' => {
    'code' => 236,
    'name' => 'vserver',
    'impl' => 0
  },
  'mbind' => {
    'code' => 237,
    'name' => 'mbind',
    'impl' => 1,
    'args' => [
      [
        'uint64_t',
        'start'
      ],
      [
        'uint64_t',
        'len'
      ],
      [
        'uint64_t',
        'mode'
      ],
      [
        'uint64_p',
        'nmask'
      ],
      [
        'uint64_t',
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
    'impl' => 1,
    'args' => [
      [
        'int',
        'mode'
      ],
      [
        'uint64_p',
        'nmask'
      ],
      [
        'uint64_t',
        'maxnode'
      ]
    ],
    'ret' => 'int'
  },
  'get_mempolicy' => {
    'code' => 239,
    'name' => 'get_mempolicy',
    'impl' => 1,
    'args' => [
      [
        'int32_p',
        'policy'
      ],
      [
        'uint64_p',
        'nmask'
      ],
      [
        'uint64_t',
        'maxnode'
      ],
      [
        'uint64_t',
        'addr'
      ],
      [
        'uint64_t',
        'flags'
      ]
    ],
    'ret' => 'int'
  },
  'mq_open' => {
    'code' => 240,
    'name' => 'mq_open',
    'impl' => 1,
    'args' => [
      [
        'istr_t',
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
        'mq_attr_p',
        'u_attr'
      ]
    ],
    'ret' => 'int'
  },
  'mq_unlink' => {
    'code' => 241,
    'name' => 'mq_unlink',
    'impl' => 1,
    'args' => [
      [
        'istr_t',
        'u_name'
      ]
    ],
    'ret' => 'int'
  },
  'mq_timedsend' => {
    'code' => 242,
    'name' => 'mq_timedsend',
    'impl' => 1,
    'args' => [
      [
        'mqd_t',
        'mqdes'
      ],
      [
        'istr_t',
        'u_msg_ptr'
      ],
      [
        'size_t',
        'msg_len'
      ],
      [
        'unsigned',
        'msg_prio'
      ],
      [
        'timespec_p',
        'u_abs_timeout'
      ]
    ],
    'ret' => 'int'
  },
  'mq_timedreceive' => {
    'code' => 243,
    'name' => 'mq_timedreceive',
    'impl' => 1,
    'args' => [
      [
        'mqd_t',
        'mqdes'
      ],
      [
        'ostr_t',
        'u_msg_ptr'
      ],
      [
        'size_t',
        'msg_len'
      ],
      [
        'uint32_p',
        'u_msg_prio'
      ],
      [
        'timespec_p',
        'u_abs_timeout'
      ]
    ],
    'ret' => 'int'
  },
  'mq_notify' => {
    'code' => 244,
    'name' => 'mq_notify',
    'impl' => 1,
    'args' => [
      [
        'mqd_t',
        'mqdes'
      ],
      [
        'sigevent_p',
        'u_notification'
      ]
    ],
    'ret' => 'int'
  },
  'mq_getsetattr' => {
    'code' => 245,
    'name' => 'mq_getsetattr',
    'impl' => 1,
    'args' => [
      [
        'mqd_t',
        'mqdes'
      ],
      [
        'mq_attr_p',
        'u_mqstat'
      ],
      [
        'mq_attr_p',
        'u_omqstat'
      ]
    ],
    'ret' => 'int'
  },
  'kexec_load' => {
    'code' => 246,
    'name' => 'kexec_load',
    'impl' => 1,
    'args' => [
      [
        'uint64_t',
        'entry'
      ],
      [
        'uint64_t',
        'nr_segments'
      ],
      [
        'kexec_segment_p',
        'segments'
      ],
      [
        'uint64_t',
        'flags'
      ]
    ],
    'ret' => 'int'
  },
  'waitid' => {
    'code' => 247,
    'name' => 'waitid',
    'impl' => 1,
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
        'siginfo_p',
        'infop'
      ],
      [
        'int',
        'options'
      ],
      [
        'rusage_p',
        'ru'
      ]
    ],
    'ret' => 'int'
  },
  'add_key' => {
    'code' => 248,
    'name' => 'add_key',
    'impl' => 1,
    'args' => [
      [
        'istr_t',
        '_type'
      ],
      [
        'istr_t',
        '_description'
      ],
      [
        'const void_p',
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
    'impl' => 1,
    'args' => [
      [
        'istr_t',
        '_type'
      ],
      [
        'istr_t',
        '_description'
      ],
      [
        'istr_t',
        '_callout_info'
      ],
      [
        'uint64_t',
        'destringid'
      ]
    ],
    'ret' => 'int'
  },
  'keyctl' => {
    'code' => 250,
    'name' => 'keyctl',
    'impl' => 1,
    'args' => [
      [
        'int',
        'option'
      ],
      [
        'uint64_t',
        'arg2'
      ],
      [
        'uint64_t',
        'arg3'
      ],
      [
        'uint64_t',
        'arg4'
      ],
      [
        'uint64_t',
        'arg5'
      ]
    ],
    'ret' => 'int'
  },
  'ioprio_set' => {
    'code' => 251,
    'name' => 'ioprio_set',
    'impl' => 1,
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
    'impl' => 1,
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
    'impl' => 1,
    'args' => [],
    'ret' => 'int'
  },
  'inotify_add_watch' => {
    'code' => 254,
    'name' => 'inotify_add_watch',
    'impl' => 1,
    'args' => [
      [
        'fd_t',
        'fd'
      ],
      [
        'istr_t',
        'path'
      ],
      [
        'uint32_t',
        'mask'
      ]
    ],
    'ret' => 'int'
  },
  'inotify_rm_watch' => {
    'code' => 255,
    'name' => 'inotify_rm_watch',
    'impl' => 1,
    'args' => [
      [
        'fd_t',
        'fd'
      ],
      [
        'int32_t',
        'wd'
      ]
    ],
    'ret' => 'int'
  },
  'migrate_pages' => {
    'code' => 256,
    'name' => 'migrate_pages',
    'impl' => 1,
    'args' => [
      [
        'pid_t',
        'pid'
      ],
      [
        'uint64_t',
        'maxnode'
      ],
      [
        'uint64_p',
        'old_nodes'
      ],
      [
        'uint64_p',
        'new_nodes'
      ]
    ],
    'ret' => 'int'
  },
  'openat' => {
    'code' => 257,
    'name' => 'openat',
    'impl' => 1,
    'args' => [
      [
        'fd_t',
        'dfd'
      ],
      [
        'istr_t',
        'path'
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
    'impl' => 1,
    'args' => [
      [
        'fd_t',
        'dfd'
      ],
      [
        'istr_t',
        'path'
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
    'impl' => 1,
    'args' => [
      [
        'fd_t',
        'dfd'
      ],
      [
        'istr_t',
        'path'
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
    'impl' => 1,
    'args' => [
      [
        'fd_t',
        'dfd'
      ],
      [
        'istr_t',
        'path'
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
    'impl' => 1,
    'args' => [
      [
        'fd_t',
        'dfd'
      ],
      [
        'istr_t',
        'path'
      ],
      [
        'timeval_p',
        'utimes'
      ]
    ],
    'ret' => 'int'
  },
  'newfstatat' => {
    'code' => 262,
    'name' => 'newfstatat',
    'impl' => 1,
    'args' => [
      [
        'fd_t',
        'dfd'
      ],
      [
        'istr_t',
        'path'
      ],
      [
        'stat_p',
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
    'impl' => 1,
    'args' => [
      [
        'fd_t',
        'dfd'
      ],
      [
        'istr_t',
        'path'
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
    'impl' => 1,
    'args' => [
      [
        'fd_t',
        'oldfd'
      ],
      [
        'istr_t',
        'opath'
      ],
      [
        'fd_t',
        'newfd'
      ],
      [
        'istr_t',
        'npath'
      ]
    ],
    'ret' => 'int'
  },
  'linkat' => {
    'code' => 265,
    'name' => 'linkat',
    'impl' => 1,
    'args' => [
      [
        'fd_t',
        'oldfd'
      ],
      [
        'istr_t',
        'opath'
      ],
      [
        'fd_t',
        'newfd'
      ],
      [
        'istr_t',
        'npath'
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
    'impl' => 1,
    'args' => [
      [
        'istr_t',
        'opath'
      ],
      [
        'fd_t',
        'newfd'
      ],
      [
        'istr_t',
        'npath'
      ]
    ],
    'ret' => 'int'
  },
  'readlinkat' => {
    'code' => 267,
    'name' => 'readlinkat',
    'impl' => 1,
    'args' => [
      [
        'fd_t',
        'dfd'
      ],
      [
        'istr_t',
        'path'
      ],
      [
        'ostr_t',
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
    'impl' => 1,
    'args' => [
      [
        'fd_t',
        'dfd'
      ],
      [
        'istr_t',
        'path'
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
    'impl' => 1,
    'args' => [
      [
        'fd_t',
        'dfd'
      ],
      [
        'istr_t',
        'path'
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
    'impl' => 1,
    'args' => [
      [
        'int',
        'n'
      ],
      [
        'fd_set_p',
        'inp'
      ],
      [
        'fd_set_p',
        'outp'
      ],
      [
        'fd_set_p',
        'exp'
      ],
      [
        'timespec_p',
        'tsp'
      ],
      [
        'void_p',
        'sig'
      ]
    ],
    'ret' => 'int'
  },
  'ppoll' => {
    'code' => 271,
    'name' => 'ppoll',
    'impl' => 1,
    'args' => [
      [
        'pollfd_p',
        'ufds'
      ],
      [
        'unsigned',
        'nfds'
      ],
      [
        'timespec_p',
        'tsp'
      ],
      [
        'const sigset_p',
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
    'impl' => 1,
    'args' => [
      [
        'int',
        'unshare_flags'
      ]
    ],
    'ret' => 'int'
  },
  'set_robust_list' => {
    'code' => 273,
    'name' => 'set_robust_list',
    'impl' => 1,
    'args' => [
      [
        'robust_list_head_p',
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
    'impl' => 1,
    'args' => [
      [
        'int',
        'pid'
      ],
      [
        'robust_list_head_p',
        'head_ptr'
      ],
      [
        'size_p',
        'len_ptr'
      ]
    ],
    'ret' => 'int'
  },
  'splice' => {
    'code' => 275,
    'name' => 'splice',
    'impl' => 1,
    'args' => [
      [
        'int',
        'fd_in'
      ],
      [
        'off_p',
        'off_in'
      ],
      [
        'int',
        'fd_out'
      ],
      [
        'off_p',
        'off_out'
      ],
      [
        'size_t',
        'len'
      ],
      [
        'unsigned',
        'flags'
      ]
    ],
    'ret' => 'int'
  },
  'tee' => {
    'code' => 276,
    'name' => 'tee',
    'impl' => 1,
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
        'unsigned',
        'flags'
      ]
    ],
    'ret' => 'int'
  },
  'sync_file_range' => {
    'code' => 277,
    'name' => 'sync_file_range',
    'impl' => 1,
    'args' => [
      [
        'fd_t',
        'fd'
      ],
      [
        'off_t',
        'offset'
      ],
      [
        'off_t',
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
    'impl' => 1,
    'args' => [
      [
        'fd_t',
        'fd'
      ],
      [
        'iovec_p',
        'iov'
      ],
      [
        'uint64_t',
        'nr_segs'
      ],
      [
        'unsigned',
        'flags'
      ]
    ],
    'ret' => 'int'
  },
  'move_pages' => {
    'code' => 279,
    'name' => 'move_pages',
    'impl' => 1,
    'args' => [
      [
        'pid_t',
        'pid'
      ],
      [
        'uint64_t',
        'nr_pages'
      ],
      [
        'void_p',
        'pages'
      ],
      [
        'int32_p',
        'nodes'
      ],
      [
        'int32_p',
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
    'impl' => 1,
    'args' => [
      [
        'fd_t',
        'dfd'
      ],
      [
        'istr_t',
        'path'
      ],
      [
        'timespec_p',
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
    'impl' => 1,
    'args' => [
      [
        'int',
        'epfd'
      ],
      [
        'epoll_event_p',
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
        'const sigset_p',
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
    'impl' => 1,
    'args' => [
      [
        'int',
        'ufd'
      ],
      [
        'sigset_p',
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
    'impl' => 1,
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
    'impl' => 1,
    'args' => [
      [
        'unsigned',
        'count'
      ]
    ],
    'ret' => 'int'
  },
  'fallocate' => {
    'code' => 285,
    'name' => 'fallocate',
    'impl' => 1,
    'args' => [
      [
        'fd_t',
        'fd'
      ],
      [
        'long',
        'mode'
      ],
      [
        'off_t',
        'offset'
      ],
      [
        'off_t',
        'len'
      ]
    ],
    'ret' => 'int'
  },
  'timerfd_settime' => {
    'code' => 286,
    'name' => 'timerfd_settime',
    'impl' => 1,
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
        'itimerspec_p',
        'utmr'
      ],
      [
        'itimerspec_p',
        'otmr'
      ]
    ],
    'ret' => 'int'
  },
  'timerfd_gettime' => {
    'code' => 287,
    'name' => 'timerfd_gettime',
    'impl' => 1,
    'args' => [
      [
        'int',
        'ufd'
      ],
      [
        'itimerspec_p',
        'otmr'
      ]
    ],
    'ret' => 'int'
  },
  'accept4' => {
    'code' => 288,
    'name' => 'accept4',
    'impl' => 1,
    'args' => [
      [
        'fd_t',
        'fd'
      ],
      [
        'sockaddr_p',
        'upeer_sockaddr'
      ],
      [
        'int32_p',
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
    'impl' => 1,
    'args' => [
      [
        'int',
        'ufd'
      ],
      [
        'sigset_p',
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
    'impl' => 1,
    'args' => [
      [
        'unsigned',
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
    'impl' => 1,
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
    'impl' => 1,
    'args' => [
      [
        'fd_t',
        'oldfd'
      ],
      [
        'fd_t',
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
    'impl' => 1,
    'args' => [
      [
        'fd_p',
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
    'impl' => 1,
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
    'impl' => 1,
    'args' => [
      [
        'fd_t',
        'fd'
      ],
      [
        'iovec_p',
        'vec'
      ],
      [
        'uint64_t',
        'vlen'
      ],
      [
        'uint64_t',
        'pos_l'
      ],
      [
        'uint64_t',
        'pos_h'
      ]
    ],
    'ret' => 'int'
  },
  'pwritev' => {
    'code' => 296,
    'name' => 'pwritev',
    'impl' => 1,
    'args' => [
      [
        'fd_t',
        'fd'
      ],
      [
        'iovec_p',
        'vec'
      ],
      [
        'uint64_t',
        'vlen'
      ],
      [
        'uint64_t',
        'pos_l'
      ],
      [
        'uint64_t',
        'pos_h'
      ]
    ],
    'ret' => 'int'
  },
  'rt_tgsigqueueinfo' => {
    'code' => 297,
    'name' => 'rt_tgsigqueueinfo',
    'impl' => 1,
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
        'siginfo_p',
        'uinfo'
      ]
    ],
    'ret' => 'int'
  },
  'perf_event_open' => {
    'code' => 298,
    'name' => 'perf_event_open',
    'impl' => 1,
    'args' => [
      [
        'perf_event_attr_p',
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
        'uint64_t',
        'flags'
      ]
    ],
    'ret' => 'int'
  },
  'recvmmsg' => {
    'code' => 299,
    'name' => 'recvmmsg',
    'impl' => 1,
    'args' => [
      [
        'fd_t',
        'fd'
      ],
      [
        'msghdr_p',
        'mmsg'
      ],
      [
        'unsigned',
        'vlen'
      ],
      [
        'unsigned',
        'flags'
      ],
      [
        'timespec_p',
        'timeout'
      ]
    ],
    'ret' => 'int'
  },
  'fanotify_init' => {
    'code' => 300,
    'name' => 'fanotify_init',
    'impl' => 1,
    'args' => [
      [
        'unsigned',
        'flags'
      ],
      [
        'unsigned',
        'event_f_flags'
      ]
    ],
    'ret' => 'int'
  },
  'fanotify_mark' => {
    'code' => 301,
    'name' => 'fanotify_mark',
    'impl' => 1,
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
        'uint64_t',
        'mask'
      ],
      [
        'fd_t',
        'dfd'
      ],
      [
        'istr_t',
        'path'
      ]
    ],
    'ret' => 'int'
  },
  'prlimit64' => {
    'code' => 302,
    'name' => 'prlimit64',
    'impl' => 1,
    'args' => [
      [
        'pid_t',
        'pid'
      ],
      [
        'unsigned',
        'resource'
      ],
      [
        'rlimit64_p',
        'new_rlim'
      ],
      [
        'rlimit64_p',
        'old_rlim'
      ]
    ],
    'ret' => 'int'
  },
  'name_to_handle_at' => {
    'code' => 303,
    'name' => 'name_to_handle_at',
    'impl' => 1,
    'args' => [
      [
        'fd_t',
        'dfd'
      ],
      [
        'istr_t',
        'name'
      ],
      [
        'file_handle_p',
        'handle'
      ],
      [
        'int32_p',
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
    'impl' => 1,
    'args' => [
      [
        'fd_t',
        'dfd'
      ],
      [
        'istr_t',
        'name'
      ],
      [
        'file_handle_p',
        'handle'
      ],
      [
        'int32_p',
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
    'impl' => 1,
    'args' => [
      [
        'clockid_t',
        'which_clock'
      ],
      [
        'timex_p',
        'tx'
      ]
    ],
    'ret' => 'int'
  },
  'syncfs' => {
    'code' => 306,
    'name' => 'syncfs',
    'impl' => 1,
    'args' => [
      [
        'fd_t',
        'fd'
      ]
    ],
    'ret' => 'int'
  },
  'sendmmsg' => {
    'code' => 307,
    'name' => 'sendmmsg',
    'impl' => 1,
    'args' => [
      [
        'fd_t',
        'fd'
      ],
      [
        'msghdr_p',
        'mmsg'
      ],
      [
        'unsigned',
        'vlen'
      ],
      [
        'unsigned',
        'flags'
      ]
    ],
    'ret' => 'int'
  },
  'setns' => {
    'code' => 308,
    'name' => 'setns',
    'impl' => 1,
    'args' => [
      [
        'fd_t',
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
    'impl' => 1,
    'args' => [
      [
        'uint32_p',
        'cpup'
      ],
      [
        'uint32_p',
        'nodep'
      ]
    ],
    'ret' => 'int'
  },
  'process_vm_readv' => {
    'code' => 310,
    'name' => 'process_vm_readv',
    'impl' => 1,
    'args' => [
      [
        'pid_t',
        'pid'
      ],
      [
        'iovec_p',
        'lvec'
      ],
      [
        'uint64_t',
        'liovcnt'
      ],
      [
        'iovec_p',
        'rvec'
      ],
      [
        'uint64_t',
        'riovcnt'
      ],
      [
        'uint64_t',
        'flags'
      ]
    ],
    'ret' => 'int'
  },
  'process_vm_writev' => {
    'code' => 311,
    'name' => 'process_vm_writev',
    'impl' => 1,
    'args' => [
      [
        'pid_t',
        'pid'
      ],
      [
        'iovec_p',
        'lvec'
      ],
      [
        'uint64_t',
        'liovcnt'
      ],
      [
        'iovec_p',
        'rvec'
      ],
      [
        'uint64_t',
        'riovcnt'
      ],
      [
        'uint64_t',
        'flags'
      ]
    ],
    'ret' => 'int'
  },
  'kcmp' => {
    'code' => 312,
    'name' => 'kcmp',
    'impl' => 1,
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
        'uint64_t',
        'idx1'
      ],
      [
        'uint64_t',
        'idx2'
      ]
    ],
    'ret' => 'int'
  },
  'finit_module' => {
    'code' => 313,
    'name' => 'finit_module',
    'impl' => 1,
    'args' => [
      [
        'fd_t',
        'fd'
      ],
      [
        'istr_t',
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
    'impl' => 1,
    'args' => [
      [
        'pid_t',
        'pid'
      ],
      [
        'sched_attr_p',
        'attr'
      ],
      [
        'unsigned',
        'flags'
      ]
    ],
    'ret' => 'int'
  },
  'sched_getattr' => {
    'code' => 315,
    'name' => 'sched_getattr',
    'impl' => 1,
    'args' => [
      [
        'pid_t',
        'pid'
      ],
      [
        'sched_attr_p',
        'attr'
      ],
      [
        'unsigned',
        'size'
      ],
      [
        'unsigned',
        'flags'
      ]
    ],
    'ret' => 'int'
  },
  'renameat2' => {
    'code' => 316,
    'name' => 'renameat2',
    'impl' => 1,
    'args' => [
      [
        'int',
        'olddfd'
      ],
      [
        'istr_t',
        'opath'
      ],
      [
        'int',
        'newdfd'
      ],
      [
        'istr_t',
        'npath'
      ],
      [
        'unsigned',
        'flags'
      ]
    ],
    'ret' => 'int'
  },
  'seccomp' => {
    'code' => 317,
    'name' => 'seccomp',
    'impl' => 1,
    'args' => [
      [
        'unsigned',
        'op'
      ],
      [
        'unsigned',
        'flags'
      ],
      [
        'istr_t',
        'uargs'
      ]
    ],
    'ret' => 'int'
  },
  'getrandom' => {
    'code' => 318,
    'name' => 'getrandom',
    'impl' => 1,
    'args' => [
      [
        'ostr_t',
        'buf'
      ],
      [
        'size_t',
        'count'
      ],
      [
        'unsigned',
        'flags'
      ]
    ],
    'ret' => 'int'
  },
  'memfd_create' => {
    'code' => 319,
    'name' => 'memfd_create',
    'impl' => 1,
    'args' => [
      [
        'istr_t',
        'uname_ptr'
      ],
      [
        'unsigned',
        'flags'
      ]
    ],
    'ret' => 'int'
  },
  'kexec_file_load' => {
    'code' => 320,
    'name' => 'kexec_file_load',
    'impl' => 1,
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
        'size_t',
        'cmdline_len'
      ],
      [
        'istr_t',
        'cmdline_ptr'
      ],
      [
        'uint64_t',
        'flags'
      ]
    ],
    'ret' => 'int'
  },
  'bpf' => {
    'code' => 321,
    'name' => 'bpf',
    'impl' => 1,
    'args' => [
      [
        'int',
        'cmd'
      ],
      [
        'bpf_attr_p',
        'attr'
      ],
      [
        'unsigned',
        'size'
      ]
    ],
    'ret' => 'int'
  },
  'stub_execveat' => {
    'code' => 322,
    'name' => 'stub_execveat',
    'impl' => 1,
    'args' => [
      [
        'fd_t',
        'dfd'
      ],
      [
        'istr_t',
        'path'
      ],
      [
        'istr_v',
        'argv'
      ],
      [
        'istr_v',
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
    'impl' => 1,
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
    'impl' => 1,
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
    'impl' => 1,
    'args' => [
      [
        'uint64_t',
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
    'impl' => 1,
    'args' => [
      [
        'fd_t',
        'fd_in'
      ],
      [
        'off_p',
        'off_in'
      ],
      [
        'fd_t',
        'fd_out'
      ],
      [
        'off_p',
        'off_out'
      ],
      [
        'size_t',
        'len'
      ],
      [
        'unsigned',
        'flags'
      ]
    ],
    'ret' => 'int'
  },
  'preadv2' => {
    'code' => 327,
    'name' => 'preadv2',
    'impl' => 1,
    'args' => [
      [
        'fd_t',
        'fd'
      ],
      [
        'iovec_p',
        'vec'
      ],
      [
        'uint64_t',
        'vlen'
      ],
      [
        'uint64_t',
        'pos_l'
      ],
      [
        'uint64_t',
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
    'impl' => 1,
    'args' => [
      [
        'fd_t',
        'fd'
      ],
      [
        'iovec_p',
        'vec'
      ],
      [
        'uint64_t',
        'vlen'
      ],
      [
        'uint64_t',
        'pos_l'
      ],
      [
        'uint64_t',
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


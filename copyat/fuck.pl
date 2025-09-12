

require 'syscall.ph';
#syscall(SYS_write(), fileno(STDOUT), $s, length $s);

#// __NR__ rt_sigaction = 13
#int rt_sigaction(int sig, sigaction_p act, sigaction_p oact, size_t sigsetsize, errhand_t hand = err_log)
#  __attribute__((__always_inline__));


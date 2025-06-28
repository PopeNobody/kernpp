/* gen_all_syscall_constants.c */

#include <stdio.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <termios.h>
#include <signal.h>
#include <sys/syscall.h>
#include <sys/socket.h>
#include <sys/stat.h>
#include <poll.h>
#include <sys/epoll.h>
#include <netinet/in.h>
#include <netinet/tcp.h>
#include <linux/if.h>
#include <linux/if_tun.h>
#include <linux/sockios.h>
#include <unistd.h>

#define P(name) printf("#define %s %ld\n", #name, (long)(name));

int main() {
    /* termios */
    P(ICANON); P(ECHO); P(ISIG); P(ICRNL); P(INPCK); P(ISTRIP); P(OPOST);
    P(VINTR); P(VQUIT); P(VERASE); P(VKILL); P(VEOF); P(VTIME); P(VMIN);
    P(TCSANOW);

    /* ioctl */
    P(TCGETS); P(TCSETS); P(TIOCGWINSZ); P(TIOCSWINSZ);

    /* fcntl */
    P(O_RDONLY); P(O_WRONLY); P(O_RDWR); P(O_NONBLOCK); P(O_APPEND); P(O_CREAT); P(O_EXCL); P(O_TRUNC);

    /* syscall numbers */
    P(SYS_read); P(SYS_write); P(SYS_open); P(SYS_close); P(SYS_stat); P(SYS_fstat); P(SYS_lseek); P(SYS_mmap); P(SYS_munmap); P(SYS_brk); P(SYS_exit); P(SYS_fork);

    /* signal */
    P(SIGINT); P(SIGTERM); P(SIGKILL); P(SIGQUIT); P(SIGCHLD); P(SIGPIPE);

    /* socket */
    P(AF_INET); P(AF_INET6); P(AF_UNIX); P(SOCK_STREAM); P(SOCK_DGRAM); P(SOCK_RAW);
    P(SOL_SOCKET); P(SO_REUSEADDR); P(SO_KEEPALIVE); P(SO_RCVBUF); P(SO_SNDBUF);
    P(IPPROTO_TCP); P(IPPROTO_UDP); P(TCP_NODELAY);

    /* stat */
    P(S_IFREG); P(S_IFDIR); P(S_IRUSR); P(S_IWUSR); P(S_IXUSR); P(S_IRGRP); P(S_IWGRP); P(S_IXGRP); P(S_IROTH); P(S_IWOTH); P(S_IXOTH);

    /* poll/epoll */
    P(POLLIN); P(POLLOUT); P(POLLERR); P(POLLHUP); P(EPOLLIN); P(EPOLLOUT); P(EPOLLERR); P(EPOLLHUP); P(EPOLLET);

    /* net/if */
    P(IFF_UP); P(IFF_BROADCAST); P(IFF_RUNNING); P(IFF_MULTICAST);

    /* linux tun */
    P(IFF_TUN); P(IFF_TAP); P(IFF_NO_PI);

    return 0;
}

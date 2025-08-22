//#include "syscall.hh"
//#include "bitset.hh"
//
//using namespace sys;
//using enum errno_t;
//static constexpr int TIOCNOTTY = 5422;
//static constexpr int TIOCGRANTPT = 5403;
//static constexpr int TIOCUNLKPT = 5401;
//static constexpr int TIOCGPTPEER = 5441;
//
//
//fd_t openpt(open_flags flags, errhand_t onerr = err_fatal) {
//  return sys::open("/dev/ptmx", flags, onerr);
//}
//
//
//int grantpt(fd_t fd, errhand_t onerr = err_fatal) {
//    return sys::ioctl(fd, TIOCGRANTPT, 0, onerr);
//}

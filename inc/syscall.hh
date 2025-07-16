#pragma once

#include "errno.hh"
#include "types.hh"
#include "attrs.hh"


namespace sys
{
#define linux_dirent64 linux_dirent
  enum open_mode
  {
    o_default= 0664

  };
  // these are octal, not hex, dont panic
  enum open_flags
  {
    o_rdonly   = 0000,
    o_wronly   = 0001,
    o_rdwr     = 0002,
    o_mask     = 0003,
    o_creat    = 00000100,
    o_excl     = 00000200,
    o_noctty   = 00000400,
    o_trunc    = 00001000,
    o_append   = 00002000,
    o_nonblock = 00004000,
    o_dsync    = 00010000,
    o_fasync   = 00020000,
    o_direct   = 00040000,
    o_largefile= 00100000,
    o_directory= 00200000,
    o_nofollow = 00400000,
    o_noatime  = 01000000,
    o_cloexec  = 02000000,
  };
  inline open_flags operator|(open_flags lhs, open_flags rhs)
  {
    return open_flags(int(lhs) | int(rhs));
  }
  inline open_flags operator&(open_flags lhs, open_flags rhs)
  {
    return open_flags(int(lhs) & int(rhs));
  }
  void err_log(errno_t err);
  void err_ignore(errno_t err);
  void err_retry_on_trans_error(errno_t err);
  void err_fatal(errno_t err);

  typedef void (*errhand_t)(errno_t);
  void set_errno(errno_t val, errhand_t hand=err_log);
  inline void set_errno(int32_t val, errhand_t hand=err_log){
    set_errno((errno_t)val,hand);
  };
  template<class res_t>
    res_t chk_return(uint64_t val, errhand_t hand=err_log)
    {
      if(val>uint64_t(-4096))
        set_errno(int64_t(val),hand);
      return res_t(val);
    };
  constexpr auto UTIME_NOW = (((1<<30)-1));
  constexpr auto UTIME_OMIT = (((1<<30)-2));
  constexpr auto AT_FDCWD=-100;

  enum origin_t
  {
    set= 0,
    cur= 1,
    end= 2
  };
  enum mmap_prot_t
  {
    // For MMAP.
    prot_none = 0x0,
    prot_read = 0x1,
    prot_write= 0x2,
    prot_exec = 0x4,
  };
  enum mmap_flag_t
  {
    map_private  = 0x02,
    map_shared   = 0x01,
    map_fixed    = 0x10,
    map_anon     = 0x20,
    map_anonymous= map_anon,
    map_growsdown= 0x00100,
    map_noreserve= 0x04000,
    map_nonblock = 0x10000,
    map_populate = 0x08000,
    map_stack    = 0x20000,
  };
//     inline int sleep(time_t secs)
//     {
//       uint64_t res= 0xfeebdaed;
//       timespec_t rqtp, rmtp;
//   
//       rqtp.tv_sec=secs;
//       rqtp.tv_nsec=0;
//       rmtp.tv_sec=0;
//       rmtp.tv_nsec=0;
//       asm("\tsyscall;\n"
//           : "=a"(res)
//           : "0"(35), "D"(&rqtp), "S"(&rmtp)
//           : "rcx", "r11", "memory");
//       return chk_return<int>(res);
//     }
//   namespace sys
//   {

}
#include "syscall.gen.hh"

namespace sys {
  inline fd_t open(istr_t path, open_flags flags, mode_t mode, errhand_t hand=err_log) {
    return open(path,flags,mode,hand);
  };
  inline fd_t open(istr_t path, open_flags flags, errhand_t hand=err_log) {
    return open(path,flags,0,hand);
  };

  inline pid_t waitpid(pid_t pid, int *status, int flags, errhand_t hand=err_log) AIL;
  inline pid_t waitpid(pid_t pid, int *status, int flags, errhand_t hand) {
    return wait4(pid,status,flags,0,hand);
  };

  inline ssize_t write(fd_t fd, const char* buf, const char* end)
  {
    return write(fd, buf, end - buf);
  }
  inline ssize_t write(fd_t fd, iovec val)
  {
    return write(fd, (const char*)val.iov_base, val.iov_len);
  }

  inline ssize_t write(fd_t fd, const char* buf)
  {
    const char* end= buf;
    while(*end)
      ++end;
    return write(fd, buf, end - buf);
  }
  inline ssize_t full_write(fd_t fd, const char* const beg, size_t len)
    AIL;
  inline const char* full_write(int               fd,
                                const char* const beg,
                                const char*       end)
    AIL;

  inline const char* full_write(int               fd,
                                const char* const beg,
                                const char*       end,
                                errhand_t hand=err_fatal
                                )
  {
    const char* pos= beg;
    while(pos != end)
    {
      ssize_t res= write(fd, pos, end - pos, err_fatal);
      pos+= res;
    }
    return pos;
  }
  inline ssize_t full_write(fd_t fd, const char* const beg, size_t len, 
      errhand_t hand=err_fatal)
  {
    return full_write(fd, beg, beg + len, hand=err_fatal) - beg;
  }
  void assert_fail(const char *, const char *, unsigned) NOR;
  bool isatty(fd_t fd);
  void drop_ctty(fd_t fd, errhand_t hand=err_log);
  int system(const char *cmd);
} // namespace sys

#define L(x) x, sizeof(x) - 1


namespace std
{
  void        abort() __attribute__((__noreturn__));
  inline void abort()
  {
    do
    {
      asm("int3");
    } while(true);
  }
  void terminate() noexcept __attribute__((__noreturn__));
  enum nothrow_t
  {
  };
  extern const nothrow_t nothrow;
  typedef void (*new_handler)();


}

namespace sys {
  struct termios;
  struct winsize;
  int login_tty(fd_t fd);
  fd_t openpty(fd_t &mpty, fd_t &spty, const termios &term, const winsize &size);
  pid_t forkpty(fd_t &mpty, fd_t &spty, const termios &term, const winsize &size);
  fd_t openpt(int flags, sys::errhand_t=sys::err_log);
  int unlockpt(fd_t fd,bool ilock,sys::errhand_t hand=sys::err_log);
  int grantpt(fd_t fd,sys::errhand_t hand=sys::err_log);
  fd_t getpt_peer(fd_t fd,sys::open_flags flags,sys::errhand_t hand=sys::err_log);
};

#include "attrs.hh"
#define _GLIBCXX_NOEXCEPT noexcept
#ifndef _GLIBCXX_NOTHROW
#define _GLIBCXX_NOTHROW
#endif
extern "C" {
  void *memcpy(void *d, void *s, size_t n);
  void memset(void *b, char v, size_t n);
  size_t strlen(const char *);
}
#define assert(x) do{\
  if(!(x)){\
    sys::assert_fail(#x,__FILE__,__LINE__);\
  }\
} while(0)
#include "bitset.hh"


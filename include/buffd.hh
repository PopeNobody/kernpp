#ifndef buffd_hh
#define  buffd_hh buffd_hh

#include <syscall.hh>
#include <fmt.hh>

using fmt::write_ptr;
// This is a very rough cut.
class bufferfd_t
{
  int fd;
  public:
  size_t writes;
  bufferfd_t( int fd=-1 )
    : fd(fd), writes(0)
  {
  }
  bufferfd_t(const bufferfd_t &rhs)
    : fd(dup(rhs.fd)), writes(0)
  {
    if(fd<0)
      sys_write(2,L("failed to dup!\n"));
  };
  ~bufferfd_t()
  {
    flush();
    close();
  };
  void close()
  {
    sys_close(fd);
  };
  void flush()
  {
  };
  ssize_t write(const char *buf, ssize_t size)
  {
    ++writes;
    sys_write(fd, buf, size);
  };
  template<typename buf_t>
    size_t write( buf_t &&buf )
    {
      ++writes;
      const char *pos=buf.pos();
      size_t len=buf.len();
      auto res = sys_write(fd, pos, len);
      if(res<0)
        sys_write(2,L("write:<msg>\n"));
      return res;
    };
};

struct temp_t {
  const char * const _beg;
  const char * const end;

  temp_t(const char *beg, size_t size)
    : _beg(beg), end(size+beg)
  {
  };
  const char *pos() const{
    return _beg;
  };
  size_t len() const{
    return end-_beg;
  };
};
struct decfmt_t {
  char buf[127];
  char end[1];
  size_t npos;
  decfmt_t(size_t val)
    :npos(0)
  {
    if(!val)
      end[-(++npos)]='0';
    else while(val){
      end[-(++npos)]='0'+(val%10);
      val/=10;
    };
  };
  ~decfmt_t()
  {
  };
  const char *pos() const {
    return end-npos;
  };
  size_t len() const {
    return npos;
  };
};

#endif

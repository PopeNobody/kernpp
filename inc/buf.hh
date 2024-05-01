#ifndef buf_hh
#define buf_hh buf_hh

#include <dbg.hh>
#include <fmt.hh>

namespace buf_ns
{
  using namespace fmt;
  struct buf_t {
    int fd;
    buf_t(int fd=1)
      :fd(fd)
    {
    };
    ssize_t __write(const char *text, ssize_t len)
    {
      xassert(len>=0);
      sys::write(fd,text,len);
      return 0;
    };
    ssize_t write(const char *arg)
    {
      if(arg==0)
        arg="(null)";
      return __write(arg,strlen(arg));
    };
    ssize_t write(char &arg)
    {
      return __write(&arg,1);
    };
    ssize_t write(int arg)
    {
      if(arg<0)
        return write(true,arg);
      else
        return write(false,arg);
    };
    ssize_t write(void *ptr)
    {
      struct {
        char buf[1023];
        char end[1];
      } dat;
      char *pos=fmt_ptr(ptr,dat.buf,dat.end);
      write(pos);
      return pos-dat.buf;
    };
    ssize_t write(bool neg, unsigned long val)
    {
      struct {
        char buf[1023];
        char end[1];
      } dat;
      char *pos=fmt_dec(neg,val,dat.buf,dat.end);
      write(pos);
      return pos-dat.buf;
    };
    ssize_t println()
    {
      return write("\n");
    };
    template<typename arg0_t, typename ...argn_t>
      ssize_t println(arg0_t arg, argn_t... tail)
      {
        return print(arg,tail...,"\n");
      };
    ssize_t print()
    {
      return 0;
    };
    template<typename arg0_t, typename ...argn_t>
      ssize_t print(arg0_t arg, argn_t... tail)
      {
        return write(arg)+print(tail...);
      };
  };

};
#endif

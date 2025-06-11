#ifndef write_buf_hh
#define write_buf_hh write_buf_ff

#include <c_str.hh>
#include <fmt.hh>
namespace write_buf {
  using c_str::c_str;
  void check_print(const c_str& str);
  void call_write(fd_t fd, const c_str& str);
  template<typename val_t>
    void swap( val_t &lhs, val_t &rhs)
    {
      val_t tmp(lhs);
      lhs=rhs;
      rhs=tmp;
    };
  using algo::set;
  template <size_t pages= 1, size_t page_size= 4096>
    struct write_buf
    {
      typedef fmt::fmt_t fmt_t;
      enum
      {
        size= pages * page_size
      };
      fd_t   fd;
      size_t pos;
      size_t tot;
      char   buf[size - 1];
      char   end[1];

      write_buf(int fd)
        : fd(fd)
          , pos(0)
          , tot(0)
      {
        set(buf, end, 0);
      };
      ~write_buf()
      {
        close();
      };
      void close()
      {
        flush();
        fd_t tmp=-1;
        swap(tmp,fd);
        //sys::close(tmp);
      }
      void flush()
      {
        if(!pos)
          return;
        tot+=pos;
        sys::full_write(fd,buf,pos);
        pos=0;
        set(buf,end,0);
      }
      size_t room() const
      {
        return size - pos;
      };
      bool between(char min, char val, char max)
      {
        return min <= val && val <= max;
      };
      write_buf &put(c_str str)
      {
        // this while will repeat if there are zeroes in the str.
        while(str)
        {
          size_t room= this->room();
          if(!room)
          {
            flush();
          }
          else if(str.len() > room)
          {
            char ch;
            while(str && room--)
              if((ch= *str++))
                buf[pos++]= ch;
          }
          else
          {
            char ch;
            while(str)
              if((ch= *str++))
                buf[pos++]= ch;
          };
        };
        if(!room())
          flush();
        return *this;
      };
      write_buf &putln(c_str str)
      {
        put(str);
        switch(room())
        {
          case 0:
            flush();
            // fall through
          case 1:
            buf[pos++]= '\n';
            flush();
            break;
          default:
            buf[pos++]= '\n';
            break;
        };
        return *this;
      };
      write_buf &putln(const fmt_t& fmt)
      {
        c_str str= fmt.get();
        return putln(str);
      };
      write_buf &put(const fmt_t& fmt)
      {
        c_str str= fmt.get();
        return put(str);
      };
      template <size_t n>
        write_buf &putln(const char (&str)[n])
        {
          return putln(c_str(str, n - 1));
        };
      template <size_t n>
        write_buf &put(const char (&str)[n])
        {
          return put(c_str(str, n - 1));
        };
      write_buf &put(const char* str)
      {
        return put(c_str(str));
      };
      write_buf &put(char* str)
      {
        return put(c_str(str));
      };
      template <typename val_t>
        write_buf &fmtln(const val_t& val)
        {
          fmt_t fmt(val);
          return putln(fmt.get());
        };
      template <typename val_t>
        write_buf &fmt(const val_t& val)
        {
          fmt_t fmt(val);
          return put(fmt.get());
        };
    };
}
#endif

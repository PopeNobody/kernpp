#ifndef write_buf_hh
#define write_buf_hh write_buf_ff

#include <fmt.hh>
#include <c_str.hh>

void check_print(const c_str &str);
void call_write(fd_t fd, const c_str &str);
template<size_t pages=1, size_t page_size=4096>
struct write_buf
{
  typedef fmt::fmt_t fmt_t;
  enum { size = pages * page_size };
  int fd;
  size_t pos;
  size_t tot;
  char buf[size-1];
  char end[1];

  write_buf(int fd)
    : fd(fd), pos(0), tot(0)
  {
    memset(buf,0,end-buf);
  };
  ~write_buf()
  {
    flush();
  };
  void flush();
  size_t room() const {
    return size-pos;
  };
  bool between(char min, char val, char max) {
    return min<=val && val<=max;
  };
  void put(c_str str)
  {
    // this while will repeat if there are zeroes in the str.
    while(str) {
      size_t room=this->room();
      if(!room) {
        flush();
      } else if ( str.len() > room ) {
        char ch;
        while(str && room--)
          if(ch=*str++)
            buf[pos++]=ch;
      } else {
        char ch;
        while(str)
          if(ch=*str++)
            buf[pos++]=ch;
      };
    };
    if(!room())
      flush();
  };
  void putln(c_str str)
  {
    put(str);
    switch(room()) {
      case 0:
        flush();
        // fall through
      case 1:
        buf[pos++]='\n';
        flush();
        break;
      default:
        buf[pos++]='\n';
        break;
    };
  };
  void putln(const fmt_t &fmt) {
    c_str str=fmt.get();
    putln(str);
  };
  void put(const fmt_t &fmt) {
    c_str str=fmt.get();
    put(str);
  };
  template<size_t n>
    void putln(const char (&str)[n]){
      putln(c_str(str,n-1));
    };
  template<size_t n>
    void put(const char (&str)[n]){
      put(c_str(str,n-1));
    };
  void put(const char *str)
  {
    put(c_str(str));
  };
  void put(char *str)
  {
    put(c_str(str));
  };
  template <typename val_t>
    void fmtln(const val_t &val)
    {
      fmt_t fmt(val);
      putln(fmt.get());
    };
  template <typename val_t>
    void fmt(const val_t &val)
    {
      fmt_t fmt(val);
      put(fmt.get());
    };
};
#endif

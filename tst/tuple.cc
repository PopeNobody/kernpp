#include "syscall.hh"
template<typename type>
  ssize_t timmy(fd_t fd, const type &t)
  {
    return sys::write(fd,__PRETTY_FUNCTION__)+
      sys::write(fd,"\n");
  };

template<typename val_t>
char *fmt_f(char *beg, char *end, const val_t &val)
{
  return beg;
};
struct fmt_t : public iovec
{
  template<class val_t>
    fmt_t(const val_t&val)
    :iovec{0,0}
  {
  };
  fmt_t()
    :iovec{0,0}
  {
  };
  ssize_t write(fd_t fd) const
  {
    return sys::write(fd,*this);
  };
};
template<class val_t>
ssize_t write(fd_t fd, const val_t &val)
{
  return val.write(fd);
};
template<class val_t>
fmt_t pad_r(const val_t &val, size_t width)
{
  return fmt_t();
};

extern "C" {
  int main() {
    using sys::write;
    if constexpr(std::is_same_v<int,int>){
      write(1,fmt_t(true));
    } else {
      write(1,fmt_t(false));
    };
    write(1,"\n");
    if constexpr(std::is_same_v<int,float>){
      write(1,fmt_t(true));
    } else {
      write(1,fmt_t(false));
    };
    write(1,"\n");
    auto tup = std::make_tuple(42, 'x', 3.14);
    tuple_for_each(
        tup, 
        [](const auto& elem)
        {
        fd_t fd(1);
        using T = std::remove_cv<decltype(elem)>;
        bool is_int=std::is_same_v<T,int>;
        timmy(fd,T());
        timmy(fd,elem);
        if constexpr(std::is_same_v<T,int>){
          write(fd,fmt_t(true));
        } else {
          write(fd,fmt_t(false));
        };
        write(fd,"\n");
        bool is_char=std::is_same_v<T,char>;
        bool is_float=std::is_same_v<T,float>;
        write(fd,pad_r("int",6));
        write(fd,fmt_t(is_int));
        write(fd,pad_r("char",6));
        write(fd,fmt_t(is_char));
        write(fd,pad_r("float",6));
        write(fd,fmt_t(is_float));
        write(fd,"\n");
        }
        );
    tuple_for_each(
        tup, 
        [](auto& elem)
        {
        fd_t fd(1);
        using T = std::remove_cv<decltype(elem)>;
        bool is_int=std::is_same_v<T,int>;
        timmy(fd,T());
        timmy(fd,elem);
        if constexpr(std::is_same_v<T,int>){
          write(fd,fmt_t(true));
        } else {
          write(fd,fmt_t(false));
        };
        bool is_char=std::is_same_v<T,char>;
        bool is_float=std::is_same_v<T,float>;
        write(fd,"int");
        write(fd,fmt_t(is_int));
        write(fd,"char");
        write(fd,fmt_t(is_char));
        write(fd,"float");
        write(fd,fmt_t(is_float));
        write(fd,"\n");
        }
        );
    return 0;
  };
}
//   #endif

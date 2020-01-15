#include <syscall.hh>
#include <array.hh>

struct lit_str {
  const char *str;
  size_t len;
  template<size_t n>
    lit_str(const char (&str)[n])
    : len(n), str(str)
    {
    };
};
ssize_t write(fd_t fd, const lit_str &str) {
  return sys::write(fd_t, str.str, str.len);
};

//   template<size_t pages=1, size_t page_size=4096>
//   struct write_buf
//   {
//     enum { size = pages * page_size };
//     int fd;
//     size_t pos;
//     typedef array<char,size> data_t;
//     data_t data;
//   
//     write_buf(int fd)
//       : fd(fd), pos(0)
//     {
//     };
//     void flush()
//     {
//       // No virtual table, baby!  :) 
//       ssize_t res=write(fd,this,pos);
//       if(res<0)
//         pexit("write");
//       pos=0;
//       memset(&data_t,0,sizeof(data_t));
//     };
//     void put(char ch)
//     {
//       // this is test. Allows one to write into a zero filled buffer and
//       // send the whole thing.
//       if(!ch)
//         return;
//       data[pos++]=ch;
//       if(pos==size)
//         flush();
//     };
//     void put(lit_str str)
//     {
//       while(str)
//         put(str++);
//     };
//   
//   };
//   
int main(int argc, char **argv) {
  lit_str str("Hello, world!");
  write(1,str);
//     write_buf buf;
//  buf.putln(L("Hello, World!")); 
  return 0;
};

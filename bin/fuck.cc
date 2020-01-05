#include <syscall.hh>

//   open_flags operator|(open_flags lhs, open_flags rhs){
//     return open_flags(int(lhs)|int(rhs));
//   };

#define L(x) x,sizeof(x)-1
typedef signed long ssize_t;
typedef unsigned long size_t;
typedef uint32_t fd_t;
ssize_t xwrite( fd_t fd,  const char *buf,  size_t len)
{
  ssize_t res;
  asm (
      "syscall\n"
      : "=a"(res)
      : "a"(1), "D"(fd), "S"(buf),"d"(len)
      : "rcx", "r11", "memory"
      );
  return res;
};
template<typename t>
void test(t v) {
  xwrite(1,L(__PRETTY_FUNCTION__));
  xwrite(1,L("\n"));
};

int main(int, char**) {
  open_flags flag1=o_rdonly;
  test(flag1);
  open_flags flag2=o_wronly;
  test(flag2);
  open_flags flag3=open_flags(flag1|flag2);
  test(flag3);
  test(flag1|flag2);
  return 0;
};

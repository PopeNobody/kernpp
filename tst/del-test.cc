#include "syscall.hh"
#include "iostream.hh"
#include "source_location.hh"
using namespace stream;
struct loc_t : public std::source_location {
  loc_t(const void *vp=__builtin_source_location())
  {
    impl=(__impl*)vp;
  };
};
ostream &operator <<(ostream &lhs, const loc_t &rhs) {
  lhs << rhs.file() << ":" << rhs.line() << ":" << rhs.func() << endl;

  return lhs;
};
int main(int, char**, char**) {
  loc_t loc;
  cout << loc << endl;
  return 0;
};

//   std::source_location::source_location(const void *impl)
//     : impl(impl)
//   {
//     using sys::write;
//     write(1,fmt::fmt_t(sizeof(*this)));
//     write(1,"\n");
//     write(1,_M_file_name);
//     write(1,":");
//     write(1,fmt::fmt_t(_M_line));
//     write(1,":");
//     write(1,_M_function_name);
//     write(1,"\n");
//   //     write(1,":");
//   //     write(1,fmt::fmt_t(impl._M_column));
//   
//   };
//   struct loc_t {
//     loc_type loc;
//     loc_t(const loc_type &arg=__builtin_source_location())
//       :loc(arg)
//     {
//     };
//   };
#if 0
void x(const loc_t &loc=loc_t());
void x(const char *str, const loc_t loc=loc_t());
using namespace std;
void test(const char *from=__PRETTY_FUNCTION__);
template<class T>
void swap( T &lhs, T&rhs ) {
  x();
  T tmp(lhs);
  lhs=rhs;
  rhs=tmp;
};
const char *funcs[1024];
size_t nfunc=0;
void x(const loc_t &loc) {
  funcs[nfunc++]="";
};
void x(const char *str, const loc_t &loc) {
  cout << nfunc << "  " << str << endl;
  funcs[nfunc++]=str;
};
struct test_t {
  test_t()
  {
    x();
  };
  test_t(const test_t &rhs)
  {
    x();
  };
  ~test_t()
  {
    x();
  };
  void say_hello() const {
    x();
  };
};
template<class T, bool A=false>
struct del_ptr {
  constexpr static bool array=A;
  T *ptr;
  del_ptr(T *ptr)
    : ptr(ptr)
  {
    x();
  };
  del_ptr(const del_ptr &rhs)
    :ptr(rhs.ptr)
  {
    x();
    ptr=new T(*rhs.ptr);
  };
  virtual ~del_ptr()
  {
    x();
    if(array) {
      delete[] ptr;
    } else {
      delete ptr;
    }
  }
  T *get() {
    x();
    return ptr;
  }
  del_ptr<T,A> &operator=(const del_ptr<T,A> &rhs){
    x();
    del_ptr tmp(ptr);
    ptr=new T(*rhs.ptr);
    return *this;
  };
  T &operator*() {
    x();
    return *get();
  };
  T *operator->() {
    x();
    return get();
  };
};
int strcmp(const char *lhs, const char *rhs) {
  int i=0;
  int res;
  while(lhs[i]) {
    if(res=rhs[i]-lhs[i])
      return res;
    ++i;
  };
  return 0;
};
int xmain(int argc, char **argv) {
  x();
  test_t * val=new test_t[0];
  delete val;
  del_ptr<test_t> ptr1 = new test_t;
  del_ptr<test_t> ptr2 = new test_t;
  ptr1 = new test_t;
  ptr2 = new test_t;
  ptr1 = ptr2;
  del_ptr<test_t> test1=new test_t;
  del_ptr<test_t> test2=new test_t;
  test2=test1;
  test1=test2;
  del_ptr<test_t,true> test3=new test_t[5];
  del_ptr test4 = new test_t;
  x();
  return 0;
}
void test(const char *str) {
  x(str);
};
int main(int argc, char**argv) {
  test();
  x();
  xmain(argc,argv);
  x();
  for(int i=0;i<nfunc-1;i++){
    for(int j=i+1;j<nfunc;j++){
      int cmp=0;
      if((cmp=strcmp(funcs[i],funcs[j]))<0){
        cout << "<0: " << funcs[i] << endl;
        cout << "    " << funcs[j] << endl;
        swap(funcs[i],funcs[j]);
      } else if (!cmp) {
        funcs[i]=funcs[j];
      };
    };
  };
  int i=0;
  cout << "nfunc: " << nfunc << endl;
  for(int i=0;i<nfunc-1;i++){
    cout << nfunc << " " << i << " " << funcs[i] << endl;
    int j=i+1;
    while(funcs[j]==funcs[i]) {
      cout << nfunc << " " << j << " " << funcs[i] << endl;
      j++;
    };
    cout << j-i << endl;
    i=j-1;
  };
  cout << "nfunc: " << nfunc << endl;
  return 0;
};
#endif

#include <syscall.hh>
#include <itr-ops.hh>
#include <vector.hh>

//   using sys::write;
//   char *getenv(const char *name, char **envp){
//     size_t len=itr::len(name);
//     for(size_t idx=0;envp[idx];idx++) {
//       if(itr::str_cmp(envp[idx],name,len))
//         continue;
//       if(envp[idx][len]!='=')
//         continue;
//       return envp[idx]+len+1;
//     };
//     return 0;
//   };
//   using str::c_str;
//   using cont::vector_t;
//   auto split(const char *beg, const char *end, char del, bool zero)
//   {
//     int n=end-beg;
//     const char *pos;
//     vector_t<c_str> res;
//     while(true){
//       pos=itr::find_val(beg,end,del);
//       if(zero || pos!=beg) {
//         char *str=new char[pos-beg+1];
//         size_t i;
//         for(i=0;i<pos-beg;i++){
//           str[i]=beg[i];
//         };
//         str[i]=0;
//         res.push_back(str);
//       };
//       if(pos==end)
//         break;
//       beg=pos+1;
//     };
//     return 0;
//   };
int main(int argc, char**argv,char **envp) {
  {
    cont::vector_t<char *> vec;
    using sys::write;
    assert(vec.cap()==0);
    assert(vec.len()==0);
  }
  {
    cont::vector_t<char *> vec(5);
    using sys::write;
    assert(vec.cap()==5);
    assert(vec.len()==0);
  }
  {
    const char *pos="help";
    cont::vector_t<char> vec(pos,pos+4);
    using sys::write;
    assert(vec.cap()==4);
    assert(vec.len()==4);
    for(int i=0;i<vec.len();i++) {
      assert(vec[i]==pos[i]);
    };
  }
  {
    const char *pos[]={
      "this", "is", "a", "test"
    };
    cont::vector_t<char*> vec(pos+0,pos+4);
    using sys::write;
    write(2,fmt::fmt_t(vec.cap()));
    write(2,"\n");
    write(2,fmt::fmt_t(vec.len()));
    write(2,"\n");
    for(int i=0;i<vec.len();i++) {
      write(2,fmt::fmt_t(i));
      write(2," ");
      write(2,vec[i]);
      write(2,"\n");
    };
    write(2,"\n");
  }
  return 0;
};

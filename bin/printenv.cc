extern "C" {
  int main(int,char**,char**);
};
int main(int, char**, char **) {
  return 0;
};

//   #include <syscall.hh>
//   #include <itr.hh>
//   #include <cmp.hh>
//   #include <c_str.hh>
//   using sys::write;
//   using sys::full_write;
//   using sys::exit;
//   
//   
//   template<size_t _val>
//   struct log10;
//   template<>
//   struct log10<0> {
//     static constexpr size_t val=0;
//   };
//   template<size_t _val>
//   struct log10 {
//     static constexpr size_t val=log10<_val/10>::val+1;
//   };
//   template<size_t _val>
//   struct wid10 {
//     static constexpr size_t pow=log10<_val>::val;
//     static constexpr size_t val=pow<1?1:pow;
//   };
//   extern "C" {
//     int main(int argc, char**argv, char**envp);
//   };
//   
//   template<class val1_t, class val2_t>
//   struct pair {
//     val1_t first;
//     val2_t second;
//     pair() = default;
//   };
//   template<class val_t>
//   class fmt_t;
//   template<unsigned char _N>
//   struct buf_t {
//     constexpr static size_t N=_N;
//     char arr[N];
//     char end[1];
//     char off;
//     char len;
//     buf_t()
//       : arr{}, off(0), len(0), end(0)
//       {
//       };
//     pair<const char *,size_t> data() const {
//       return {arr+off,len};
//     };
//   };
//   template<class val_t>
//   struct fmt_t : public buf_t<3> {
//     fmt_t(val_t val=0)
//     {
//       off=3; 
//       do {
//         arr[--off]=(val%10)+'0';
//       } while(val/=10);
//       len=end-arr+off;
//     }
//   };
//   template<class val_t>
//   ssize_t write(fd_t fd, const fmt_t<val_t> &fmt) {
//     auto data=fmt.data();
//     return write(fd,data.first,data.second);
//   }
//   //   int main(int argc, char**argv, char**envp) {
//   //     write(2,fmt_t<int>(argc));
//   //     write(2,argv[0]); write(2,"\n");
//   //     char *last;
//   //     for(char *res=argv[0]; res=next(1+(last=res),'/',0); )
//   //     {
//   //       write(2,res); write(2,"\n");
//   //     };
//   //     return 0;
//   //   };
//   static int dumpvec(fd_t fd, c_str beg, char sep, c_str term)
//   {
//     char *pos=beg.beg();
//     while(*pos){
//       while(*pos){
//         ++pos;
//       };
//       *pos++=sep;
//     };
//     c_str buf(beg.beg(),pos);
//     ssize_t res1=write(fd, buf);
//     ssize_t res2=write(fd, term);
//     if(res1<0 or res2<0)
//       sys::pexit(8,c_str("dumpvec()"));
//     return res1+res2;
//   };
//   int main(int argc, char**argv, char **envp) {
//     char *base=0; 
//     for(char *pos=argv[0];*pos;pos++){
//       if(*pos=='/'){
//         write(2,pos);
//         base=pos;
//       };
//     }
//     fd_t efd=2;
//     char id=base?base[0]:0;
//     //     char id=basename(*argv++)[0];
//     switch(id) {
//       case 'e':
//       case 'E':
//         dumpvec(efd,argv[1],' ',"\n\n");
//         break;
//       case 'p':
//       case 'P':
//         dumpvec(efd,envp[0],'\n',"\n\n");
//         break;
//       default:
//         sys::pexit(3,"I have no identify, I don't know what to do!");
//         break;
//     };
//     return 0;
//   };
//   //   template<class val_t>
//   //   struct max_t {
//   //     static constexpr size_t max_v=256^sizeof(val_t);
//   //     static constexpr size_t max_w=log10<max_v>::val;
//   //   };
//   //   template<class val_t, size_t width=max_t<val_t>::max_w>
//   //   struct fmt_t : public buf_t<width>
//   //   {
//   //     using super_t = buf_t<width>;
//   //     fmt_t(val_t val)
//   //     {
//   //       char *pos=super_t::end;
//   //       do {
//   //         *--pos=(val/10)+'0';
//   //         val/=10;
//   //       } while(val);    
//   //     };
//   //   };
//   //   char *next(char *buf, char tgt, char end)
//   //   {
//   //     while(*buf!=tgt && !buf!=end)
//   //       ++buf;
//   //     return buf;
//   //   };
//   //   char *last(char *buf, char tgt, char end) {
//   //     char *res=buf;
//   //     while(*buf!=end) {
//   //       write(2,"  ",2);
//   //       write(2,buf);
//   //       write(2,"\n");
//   //       buf=next(buf,tgt,end);
//   //       if(*buf==tgt)
//   //         res=++buf;
//   //     };
//   //     write(2,"--",2);
//   //     write(2,buf);
//   //     write(2,"\n");
//   //     return res;
//   //   };
//   //   char *basename(char *name){
//   //     return last(name,'/',0);
//   //   };
//   //   void die( int res, const char *msg ) {
//   //     write(2,msg);
//   //     exit(res);
//   //   };
//   //   int main(int argc, char**argv, char **envp) {
//   //     write(2,fmt_t<int>(argc));
//   //     write(2,argv[0]); write(2,"\n");
//   //     char *last;
//   //     for(char *res=argv[0]; res=next(1+(last=res),'/',0); )
//   //     {
//   //       write(2,res); write(2,"\n");
//   //     };
//   //     return 0;
//   //   };
//   //     char id=basename(*argv++)[0];
//   //     switch(id) {
//   //       case 'e':
//   //       case 'E':
//   //         dumpvec(argv[1],' ','\n');
//   //         break;
//   //       case 'p':
//   //       case 'P':
//   //         dumpvec(envp[0],'\n','\n');
//   //         break;
//   //       default:
//   //         die(3,"I have no identify, I don't know what to do!");
//   //         break;
//   //     };
//   //     return 0;
//   //   };

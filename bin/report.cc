#include<syscall.hh>

//   #define wifexited(res) (wtermsig(res)==0)
//   #define wtermsig(res) (res&0x7f)
//   #define wexitstatus(res) ((res&0xff00)>>8)
//   
//   
//   typedef char * str_t;
//   typedef const char *str_c;
//   
//   int main(int argc, char** argv, char **envp)
//   {
//     if(argc<2) {
//       write(2,"usage: ");
//       write(2,argv[0]);
//       write(2," <command>\n");
//       return 2;
//     };
//     pid_t opid=sys::getpid();
//     pid_t npid=xfork();
//     int res;
//     if(npid) {
//       if(sys::wait(&res)<0){
//         write(2,"wait: ");
//         write(2,sys::strerror(sys::errno));
//         write(2,"\n");
//         return 1;
//       };
//   
//       auto pos=argv;
//       if(pos){
//         if(*pos){
//           write(2,*pos);
//           while(*++pos){
//             write(2," ");
//             write(2,*pos);
//           };
//           write(2," returned ");
//           write_dec(2,res);
//           write(2,"\n");
//           exit(res);
//         };
//       };
//       if( wifexited(res) ) {
//         res=wexitstatus(res);
//         write(2,"returned ");
//         write_dec(2,res);
//         write(2,"\n");
//         exit(res);
//       } else {
//         write(2,"sig: ");
//         write_dec(2,wtermsig(res));
//         write(2,"\n\n");
//       };
//     } else {
//       ++argv;
//       sys::execve(argv[0],argv, envp);
//       return 0;
//     };
//     return res;
//   };

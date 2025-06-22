#include "vpipe.hh"

void vpipe::setup_term_and_pty(bool use_vt) {
  
}
//   #include <vterm.hxx>
//   #include <calls.hxx>
//   #include <termios.h>
//   #include <sys/ioctl.h>
//   #include "fdset.hxx"
//   using namespace x;
//   using namespace vterm_ns;
//   static termios ior_orig;
//   static termios ior_raw;
//   timeval_t x::def_timeout = 10;
//   fdset_t x::all_fds;
//   x::fd_t x::mpty;
//   x::fd_t x::spty;
//   VTerm *x::vterm;
//   struct winsize ws;
//   uint16_t &x::rows=ws.ws_row;
//   uint16_t &x::cols=ws.ws_col;
//   pid_t x::pid;
//   state_t x::state = starting;
//   static fd_t save_in;
//   void reset_tty() {
//   };
//   static void sig_chld(int sig){
//     int res=waitpid(pid, 0, WNOHANG);
//     if(res==pid || (res==-1 && errno==ECHILD) ) {
//       signal(SIGCHLD,SIG_DFL);
//       write(spty,"\4",1); 
//       state=draining;
//       reset_tty();
//       def_timeout=0.1;
//     } else if ( res==-1 ) {
//       perror("waitpid");
//     };
//   };
//   static void sig_winch(int sig) {
//     dprintf(2,"%s\n",__PRETTY_FUNCTION__);
//     dprintf(1,"\r\nwinch\n");
//     winsize ws;
//     xtcgetwinsize(0,&ws);
//     xtcsetwinsize(mpty,&ws);
//   };
//   static char bash[] = "/bin/bash" ;
//   static char noprof[] = "--noprofile";
//   static char *args[]={
//     bash,
//     noprof,
//     0
//   };
//   pid_t x::start_child(char **argv, char **envp) {
//     if(!argv||!*argv||!**argv){
//       argv=args;
//     };
//     pid_t pid=fork();
//     if(pid)
//       return pid;
//   
//     xclose(mpty);
//     mpty=-1;
//     char **ptr;
//     ptr=(char**)argv;
//     while(*ptr)
//       dprintf(2,"%s\n",*ptr++);
//     xlogin_tty(spty);
//     ptr=(char**)argv;
//     while(*ptr)
//       dprintf(2,"%s\n",*ptr++);
//     execve(argv[0],argv,envp);
//     pexit("execve");
//   }
//   void vpipe::setup_term_and_pty(bool use_vt) {
//     dprintf(2,"%s\n",__PRETTY_FUNCTION__);
//     if(isatty(0)) {
//       forkex("/bin/stty","sane");
//       save_in=xdup(0);
//       xtcgetwinsize(0,&ws);
//       xtcgetattr(0,&ior_orig);
//       ior_raw=ior_orig;
//       if(xopenpty(mpty,spty,0,&ior_orig,&ws)<0)
//         pexit("openpty");
//       termios tmp=ior_orig;
//       cfmakeraw(&ior_raw);
//       while(memcmp(&tmp,&ior_raw,sizeof(ior_raw))) {
//         xtcsetattr(0,TCIOFLUSH,&ior_raw);
//         xtcgetattr(0,&tmp);
//       };
//       xtcgetattr(spty,&tmp);
//       if(memcmp(&tmp,&ior_orig,sizeof(ior_orig))) {
//         dprintf(2,"\rmismatch\n");
//       }
//       atexit(reset_tty);
//     } else {
//       if(xopenpty(mpty,spty,0,0,0)<0)
//         pexit("openpty");
//     };
//     signal(SIGCHLD,sig_chld);
//     signal(SIGWINCH,sig_winch);
//     if(use_vt) {
//       xtcgetwinsize(spty,&ws);
//       dprintf(2,"\rrows: %d cols: %d\n", rows, cols);
//       vterm = vterm_new(rows,cols);
//     }
//   }
//   int skip;
//   void x::vpipe(void (*cb)()) {
//     dprintf(2,"%s\n",__PRETTY_FUNCTION__);
//     timeval_t def=def_timeout;
//     while(all_fds) {
//       int res;
//       while(true) {
//         timeval_t to=def;
//         fdset_t tmp=all_fds;
//         res = tmp.select(to);
//         if(!res)
//           break;
//         char buf[1];
//         if(tmp.is_set(0)){
//           int res = xread(0,buf,1);
//           if(res==0 || (res==1 && buf[0]==4)) {
//             dprintf(2,"\reof\r\n");
//           } else if ( buf[0]==(1+'z'-'a' )) {
//             dprintf(2,"\r<c-z>\r\n"); 
//             return;
//           } else {
//             write(mpty,buf,res);
//           }
//         } 
//         if(tmp.is_set(mpty)) {
//           int res = xread(mpty,buf,sizeof(buf));
//           if(res<=0)
//             continue;
//           for(int i=0;i<res;i++) {
//             if(buf[i]!=skip) {
//               if(buf[i]==10 || buf[1]==13)
//               {
//                 skip=23-buf[i];
//                 vterm_input_write(vterm,"\r\n",2);
//                 cb();
//               };
//             } else {
//               vterm_input_write(vterm,buf+i,1);
//             }
//             skip=0;
//           };
//         }
//       };
//     }
//   };

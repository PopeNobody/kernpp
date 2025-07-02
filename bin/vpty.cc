extern "C" { int main(int argc,char *const*argv,char *const*envp); };
#include "die.hh"
#include "vpipe.hh"
#include "fmt.hh"
#include "bitset.hh"
using vpipe::setup_term_and_pty;
const int TIOCGPTPEER = 0x5441;
const int  TIOCSPTLCK = 0x40045431;
using fmt::fmt_t;

struct fdset_t : public collect::bitset_t<32> {
  fdset_t select(timeval_t);
};
struct fd_act {
  typedef void(*act_t)(fd_t &);
  act_t act;
  fd_t fd;
  bool operator()(const fdset_t &set);
};
using enum sys::open_flags;
using sys::ioctl;
using sys::read;
using sys::write;
using sys::close;
using sys::dup2;
using sys::getpid;
using sys::open_flags;

size_t strlen(const char* const str){
  size_t pos=0;
  while(str[pos])
    ++pos;
  return pos;
};
char *fmt_int(char *beg, char *end, size_t num)
{
  char buf[63];
  char nul[1]={0};
  char *pos=nul-1;
  do {
    *--pos='0'+num%10;
    num/=10;
  } while(num);
  while(*pos) {
    *beg++=*pos++;
    if(beg==end)
      std::abort();
  };
  *beg++=0;
  return beg;
};
void show_fds(int maxfd=64) {
  char fd_dir[128]="/proc/self/fd/";
  char * const pos=fd_dir+strlen(fd_dir);
  char * const end=fd_dir+sizeof(fd_dir)-1;
  char buf[4096];
  char text[4096];
  char *tpos=text;
  char *tend=tpos+sizeof(text)-1;
  *tend=0;
  int i;
  while(i<maxfd) {
    while(i<maxfd) {
      fmt_int(pos,end,i++);
      size_t max=sizeof(buf)-2;
      memset(buf,0,sizeof(buf));
      ssize_t len=sys::readlink(fd_dir,buf,max);
      if(len<0)
        continue;
      buf[len]=0;
      if(len==max)
        std::abort();
      char *bpos=tpos;
      bool done=false;
      do {
        if(!(tpos=itr::copy(tpos,tend,fd_dir)))
          break;
        if(!(tpos=itr::copy(tpos,tend," => ")))
          break;
        if(!(tpos=itr::copy(tpos,tend,buf)))
          break;
        if(!(tpos=itr::copy(tpos,tend,"\n")))
          break;
        done=true;
      } while(0);
      if(!done)
        break;
    }
    write(1,text);
    memset(text,0,sizeof(text));
    tpos=text;
  };
};
int main(int argc,char *const*argv,char *const*envp) {
  const char mname[]="/dev/pts/ptmx";
  const char sname[]="             ";
  fd_t mpty,spty;
  int res;
  open_flags flags=o_rdwr|o_noctty|o_cloexec|o_nonblock;
  fd_t pipefds[2];
  sys::pipe(pipefds);
  mpty=open(mname,flags);
  uint64_t lock=0;
  write(1,"call ioctl 1\n");
  res=ioctl(mpty,TIOCSPTLCK,uint64_t(&lock));
  write(1,"call ioctl 2\n");
  spty=ioctl(mpty,TIOCGPTPEER,(size_t)flags);
  show_fds(10); 
  fdset_t set;
  set.set(0);
  set.set(mpty);
  timeval_t tv={1,0};
  fdset_t rset;
  timeval_t rtv;
  if(!sys::fork()){
    dup2(spty,0);
    dup2(spty,1);
    close(spty);
    close(mpty);
    char const * const argv[]= {
      "/bin/cat",
      0
    };
    sys::execve(argv[0],(char*const*)argv,envp);
    sys::pexit(2,"exec");
  };
  close(spty);
  struct fd_stuff_t {
    fd_t rfd;
    fd_t wfd;
    char buf[1024*16];
    int pos;
  };
  fd_stuff_t fd_stuff[2];
  fd_stuff[0].rfd=0;
  fd_stuff[0].wfd=mpty;
  fd_stuff[0].pos=0;
  fd_stuff[1].rfd=mpty;
  fd_stuff[1].wfd=1;
  fd_stuff[1].pos=0;

  while(set.any()){
    rset=set;
    rtv=tv;
    int highest=rset.find_highest()+1;
    int res = sys::select(highest,&rset,0,0,&rtv);
    if(res) {
      fd_t fds[2]={mpty,0};
      for(fd_t i : fds) {
        fd_stuff_t &stuff=fd_stuff[i?1:0];
        if(rset.test(i)){
          res=read(stuff.rfd,stuff.buf+stuff.pos,1);
          if(res<0) {
            if(sys::errno==EAGAIN)
              continue;
            sys::pexit(1,"read");
            std::abort();
          } else if (res) {
            stuff.pos++;
            res=write(stuff.wfd,stuff.buf,stuff.pos);
            if(res<0) {
              if(sys::errno==EAGAIN)
                continue;
              sys::pexit(1,"write");
              std::abort();
            } else if(res==0) {
              // should not happen, but ...
              continue;
            } else if(res<stuff.pos) {
              memcpy(stuff.buf,stuff.buf+res,sizeof(stuff.buf)-res);
              stuff.pos-=res; 
            } else if(res==stuff.pos) {
              memset(stuff.buf,0,sizeof(stuff.buf));
              stuff.pos=0;
            } else {
              memset(stuff.buf,0,sizeof(stuff.buf));
              stuff.pos=0;
            };
          } else {
            if(i==0) {
              close(i);
              set.clear(i);
              char ten4[]={ 10, 4 };
              write(mpty,ten4,2);
            } else {
              close(1);
              close(mpty);
              set.clear(0);
              set.clear(mpty);
            };
          };
        };
      };
    }
  };
  return 0;
};

void close_fds() {
  for(int i=3;i<64;i++) {
    close(i);
  };
};

//   using namespace std;
//   using namespace x;
//   using namespace vterm_ns;
//   
//   static timeval tv_full={10,0};
//   static timeval tv;
//   static char buf[8192];
//   static fdset_t eof;
//   static ssize_t copy_byte(fd_t src, fd_t dst);
//   static void handle_status(fd_t fd);
//   
//   extern "C" {
//     void cygprofile_enable();
//   }
//   
//   static int next_signal(int tries);
//   static int child_loop();
//   static int child_reap();
//   static timeval_t  timeout;
//   static fd_t save_in;
//   void close_fds();
//   int main(int argc, char **argv)
//   {
//     close_fds();
//     if(getenv("CYGPROFILE")){
//       cygprofile_enable();
//     };
//     setup_term_and_pty(false);
//     dprintf(1,"mpty: %d spty: %d\n", mpty, spty);
//     setenv("VPTY",xreadlink("/proc/self/exe"),1);
//     pid = start_child(argv+1);
//     save_in=xdup(0);
//     dprintf(2,"saved fd0 to %d\r\n", save_in);
//     int res = child_loop();
//     res = child_reap();
//     return 0;
//   }
//   static int child_loop() {
//     while(true) {
//       fdset_t set;
//       if(!eof.is_set(0)) {
//         set.set(0);
//       };
//       timeout=def_timeout;
//       if(!eof.is_set(mpty))
//         set.set(mpty);
//       if(!set.num())
//         break;
//       int num = set.select(timeout);
//       if(state==starting) {
//         state=waiting_to1;
//       } else if(num==0) {
//         if ( state==waiting_to1 ) {
//           state=waiting_to2;
//         } else if ( state==waiting_to2 ) {
//           state=running;
//         } else if ( state==draining ) {
//           if(ioctl(mpty,FIONREAD)<0)
//             break;
//           xprintf(2,"ioctl(%d,FIONREAD)=>%d\r\n",mpty,ioctl(mpty,FIONREAD));
//           xprintf(2,"ioctl(%d,TIOCOUTQ)=>%d\r\n",mpty,ioctl(mpty,TIOCOUTQ));
//           static int start=time(0);
//           if(time(0)-start>1)
//             break;
//         } else if ( state == running ) {
//           def_timeout=10;
//         };
//       };
//       if(set.is_set(0)) {
//         copy_byte(0,mpty);
//       }
//       if(set.is_set(mpty)){
//         copy_byte(mpty,1);
//       }
//     };
//     return 0;
//   }
//   static int child_reap() {
//     int sigs=0;
//     int res;
//     while(true) {
//       int status=0;
//       res=waitpid(pid,&status,WNOHANG);
//       if(res==-1) {
//         dprintf(2,"waitpid: %d, errno: %d\n", res, errno);
//         //         dprintf(2,"\rno kids, we done.\r\n");
//         return true;
//       } else {
//         dprintf(2,"waitpid: pid=%d, code=%d\r\n",res,status);
//       };
//       int sig=next_signal(sigs++);
//       if( kill(pid,sig) ) {
//         return true;
//       };
//     };
//   };
//   static int _next_signal(int tries) {
//     if(!tries%4)
//       return SIGTERM;
//     if(!tries%2)
//       return SIGHUP;
//     return SIGCONT;
//   };
//   static int next_signal(int tries) {
//     int sig=_next_signal(tries);
//     dprintf(2,"signal: %d %d\n");
//     return sig;
//   };
//   static bool err_ioe_ignore(const char *func){
//     if(errno==-EIO)
//       return true;
//     return err_fail(func);
//   };
//   
//   //   void  vterm_state_set_callbacks(VTermState *state, const VTermStateCallbacks *callbacks, void *user);
//   //   void  vterm_state_set_unrecognised_fallbacks(VTermState *state, const VTParserCallbacks *fallbacks, void *user);
//   //   void  vterm_screen_set_callbacks(VTermScreen *screen, const VTermScreenCallbacks *callbacks, void *user);
//   //   void *vterm_screen_get_cbdata(VTermScreen *screen);
//   //   void  vterm_screen_set_unrecognised_fallbacks(VTermScreen *screen, const VTParserCallbacks *fallbacks, void *user);
//   //   void *vterm_screen_get_unrecognised_fbdata(VTermScreen *screen);
//   //   void vterm_parser_set_callbacks(VTerm *vt, const VTParserCallbacks *callbacks, void *user);
//   //   void *vterm_parser_get_cbdata(VTerm *vt);
//   
//   VTermStateCallbacks state_cb = {
//   //     int (*putglyph)(VTermGlyphInfo *info, VTermPos pos, void *user);
//   //     int (*movecursor)(VTermPos pos, VTermPos oldpos, int visible, void *user);
//   //     int (*scrollrect)(VTermRect rect, int downward, int rightward, void *user);
//   //     int (*moverect)(VTermRect dest, VTermRect src, void *user);
//   //     int (*erase)(VTermRect rect, int selective, void *user);
//   //     int (*initpen)(void *user);
//   //     int (*setpenattr)(VTermAttr attr, VTermValue *val, void *user);
//   //     int (*settermprop)(VTermProp prop, VTermValue *val, void *user);
//   //     int (*bell)(void *user);
//   //     int (*resize)(int rows, int cols, VTermPos *delta, void *user);
//   //     int (*setlineinfo)(int row, const VTermLineInfo *newinfo, const VTermLineInfo *oldinfo, void *user);
//   } ;
//   struct VTermScreenCallbacks screen_cb = {
//   //     int (*damage)(VTermRect rect, void *user);
//   //     int (*moverect)(VTermRect dest, VTermRect src, void *user);
//   //     int (*movecursor)(VTermPos pos, VTermPos oldpos, int visible, void *user);
//   //     int (*settermprop)(VTermProp prop, VTermValue *val, void *user);
//   //     int (*bell)(void *user);
//   //     int (*resize)(int rows, int cols, void *user);
//   //     int (*sb_pushline)(int cols, const VTermScreenCell *cells, void *user);
//   //     int (*sb_popline)(int cols, VTermScreenCell *cells, void *user);
//   };
//   ssize_t vterm_write_full(char *buf, ssize_t nr)
//   {
//     ssize_t nw=0;
//     while(nw<nr) {
//       ssize_t res = vterm_input_write(vterm,buf,nr);
//       if(res<0)
//         return res;
//       else
//         nw+=res;
//     };
//     return nw;
//   };
//   ssize_t copy_byte(fd_t src, fd_t dst) {
//     char buf[4096];
//     ssize_t nr = xread(src,buf,sizeof(buf));
//   
//     if(nr>0) {
//       if(src==0 && vterm) {
//         vterm_write_full(buf,nr);
//       } else {
//         ssize_t res=write_full(dst,buf,nr);
//         if(res<nr)
//           pexit("xwrite_full did not");
//       };
//     } else if (nr < 0 || nr > sizeof(buf) ) {
//       perror("write");
//       nr = -1;
//     } else if( nr == 0 ) {
//       eof.set(src);
//       if(src==0) {
//         buf[0]=4;
//         write(mpty,buf,1);
//       };
//     } else {
//       dprintf(2,"we read >1 char, need to adjust logic\r\n");
//     };
//     return nr;
//   };
//   void close_fds() {
//   //     for(int i=3;i<64;i++) {
//   //       close(i);
//   //     };
//   } 

#include "syscall.hh"
#include "bitset.hh"

using namespace sys;

static collect::bitset_t<128> transient = {
    EINTR,
    EAGAIN,
    EWOULDBLOCK
};

inline bool err_retry_on_transient(errno_t err) {
    return transient.get(err);
}

namespace sys {
  void err_die_if_stdin_tty(sys::errno_t err);
};
void terminate_ctty() {
  int tty = sys::open("/dev/tty", o_rdwr,err_die_if_stdin_tty);
  if (tty >= 0) {
    drop_ctty(tty,err_fatal);
    sys::close(tty,err_fatal);
  }  
}
fdset_t fds;
void _write2(const char *file, unsigned line, fd_t fd, const char *lab, fmt::fmt_t val){
  c_str strs[]={
    file,
    ":",
    (iovec)fmt::fmt_t(line),
    ":",
    lab,
    "  ---  ",
    (iovec)fmt::fmt_t(val),
    "  ---  ",
    "\n\n"
  };
  int len=0;
  for(auto str: strs) {
    len+=str.len();
  };
  char buf[len+256];
  for(auto str: strs) {
  };
  char *end=buf+sizeof(buf)-1;
  *--end=0;
  char *pos=itr::copy(buf,end,file); 
  pos=itr::copy(pos,end,":");
  pos=itr::copy(pos,end,fmt::fmt_t(line));
  pos=itr::copy(pos,end,":");
  pos=itr::copy(pos,end,lab);
  pos=itr::copy(pos,end," => ");
  pos=itr::copy(pos,end,val);
  pos=itr::copy(pos,end,"\n");
  full_write(fd,buf,pos-buf,err_fatal);
};
#define write2(fd,lab,val) do { \
  _write2(__FILE__,__LINE__,fd,lab,val); \
} while(0);

ssize_t do_copy(int rfd, int wfd) {
  char buf[16];
  ssize_t nr=read(rfd,buf,sizeof(buf),err_fatal);
  if(nr==0) {
    fds.clear(rfd);
    return 0;
  }
  ssize_t nw=0;
  while(nw<nr) {
    write2(2,"nr=",fmt::fmt_t(nr));
    write2(2,"nw=",fmt::fmt_t(nw));
    ssize_t res=write(wfd,buf+nw,nr-nw,err_fatal);
    if(res<0)
      sys::pexit(99,"write should have exited");
    nw+=res;
  };
  return nw;
};
bool select_loop(int mpty) {
    fds.set(0);
    fds.set(mpty);

    while (fds.any()) {
      fdset_t cur = fds;
      int nfds = cur.find_highest() + 1;

      int ready = sys::select(nfds, &cur, nullptr, nullptr, nullptr, err_fatal);
      assert(ready>=0);
      if(cur.get(0)){
        int res=do_copy(0,mpty);
        write2(2,"res=",fmt::fmt_t(res));
      };
      if(cur.get(mpty)){
        int res=do_copy(mpty,1);
        write2(2,"res=",fmt::fmt_t(res));
      };
    }
    return true;
}
extern "C" {
  int main(int argc, char** argv, char**envp) {
    using fmt::fmt_t;
    fd_t master = openpt(o_rdwr | o_noctty);
    int res=0;
    res=unlockpt(master,true);

    pid_t pid = fork(err_fatal);
    if (pid == 0) {
      drop_ctty(0,err_fatal);
      setsid(err_fatal);
      fd_t spty = getpt_peer(master, o_rdwr);
      close(master,err_fatal);
      dup2(spty,0);
      dup2(spty,1);
      close(spty);
      spty=0;
      //dup2(spty,2);
      char buf[12];
      while(true) {
//        write(2,"spty:  ");
//        write(2,fmt::fmt_t(spty));
//        write(2,"\n");
        int nr=read(spty,buf,sizeof(buf),err_fatal);
        assert(nr>=0);
        if(nr==0) {
          write(2,"\n\nEND OF FUCKING FILE!!!!!\n\n");
        } else {
          //        write(2,"nr: ");
          //        write(2,fmt::fmt_t(nr));
          //        write(2,"\n");
          for(int nw=0;nw<nr;){
            int res=write(spty,buf+nw,nr-nw,err_fatal);
            //          write(2,"res=");
            //          write(2,fmt::fmt_t(res));
            //          write(2,"\n");
            assert(res>=0);
            nw+=res;
            //          write(2,"nw=");
            //          write(2,fmt::fmt_t(nw));
            //          write(2,"\n");
          };
        };
      };
        
//      dup2(spty, 1);
//      dup2(spty, 2);
//      char const *args[]={
//        "bin/cat",
//        0
//      };
//      sys::execve(args[0], (char*const*)args, envp);
//      exit(127);
    }

    select_loop(master);
    return 0;
  }
}

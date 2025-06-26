
static fd_t run_xxd() {
  fd_t fds[2];
  pipe(fds);
  if(fork()){
    close(fds[0]);
    return fds[1];
  }
  dup2(fds[0],0);
  close(fds[0]);
  close(fds[1]);
  const char *argv[3]={
    "/opt/bin/xxd","xxd",0
  }; 
  execve(argv[0],(char*const*)argv,envv);
  pexit(3,"exec:xxd");
};


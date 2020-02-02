#include <unistd.h>
#include <stdio.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(int, char**) {
  int res;
  struct stat buf;
  res=openat(AT_FDCWD, "mvit", O_RDONLY);
  dprintf(2,"openat => %d\n\n",res);

  res=stat("mvit",&buf);
  dprintf(2,"stat => %d\n\n",res);

  res=rename("x x","y y");
  dprintf(2,"rename => %d\n\n",res);

  res=rename("y y","x x");
  dprintf(2,"rename => %d\n\n",res);

  return 0;
};

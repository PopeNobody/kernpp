#include <fcntl.h>	     /* Definition of AT_* constants */
#include <sys/stat.h>
#include <stdio.h>


#define SHOW(name,fmt) dprintf(1,"%s=" fmt "\n", #name, name)
int main(int, char**){
  SHOW(AT_FDCWD,"%d");
  SHOW(UTIME_NOW,"%d");
  SHOW(UTIME_OMIT,"%d");
  return 0;
};

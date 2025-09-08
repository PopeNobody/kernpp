#include <dirent.h>     /* Defines DT_* constants */
#include <err.h>
#include <fcntl.h>
#include <ctype.h>
#include <string.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/syscall.h>
#include <unistd.h>

struct linux_dirent {
  unsigned long  d_ino;
  off_t	  d_off;
  unsigned short d_reclen;
  char		  d_name[];
};

#define BUF_SIZE 1024

  int
main(int argc, char *argv[])
{
  int			fd;
  char			d_type;
  char			buf[BUF_SIZE];
  long			nread;
  struct linux_dirent	*d;

  fd = open(argc > 1 ? argv[1] : ".", O_RDONLY | O_DIRECTORY);
  if (fd == -1)
    err(EXIT_FAILURE, "open");

  for (;;) {
    nread = syscall(SYS_getdents, fd, buf, BUF_SIZE);
    if (nread == -1)
      err(EXIT_FAILURE, "getdents");

    if (nread == 0)
      break;

    typedef const char *ccp;
    ccp  fmts[]={  "lu",  "d",  "s",  "d",  "d",  "s"  };
    int  lens[]={  10,    4,    4,    4,   20,   20   };
    char fmt1[256]="";
    char fmt2[256]="";
    char *pos1=fmt1;
    char *pos2=fmt2;
    memset(fmt2,0,sizeof(fmt2));
    memset(fmt1,0,sizeof(fmt2));
    dprintf(2,"%d\n", (sizeof(lens)/sizeof(lens[0])));
    dprintf(2,"%d\n", (sizeof(fmts)/sizeof(fmts[0])));
    for(int i=0;i<(sizeof(lens)/sizeof(lens[0]));i++) { 
      *pos1++=*pos2++='%';
      *pos2++='-';
      pos1+=sprintf(pos1,"%d",-abs(lens[i]));
      pos2+=sprintf(pos2,"%d",lens[i]);
      *pos1++='s';
      for(int j=0;fmts[i][j];j++){
        *pos2++=fmts[i][j];
      };
      *pos1++=*pos2++=' ';
    };
    --pos1; --pos2;
    *pos1++=*pos2++='\n';
    printf(fmt1,"ino", "type", "typestr", "len", "off", "name");
    for (size_t bpos = 0; bpos < nread;) {
      d = (struct linux_dirent *) (buf + bpos);
      ino64_t ino=d->d_ino;
      d_type = *(buf + bpos + d->d_reclen - 1);
      bpos += d->d_reclen;
      if(!strcmp(d->d_name,"."))
        continue;
      if(!strcmp(d->d_name,".."))
        continue;
      const char *typestr=
          (d_type == DT_REG) ?  "regular" :
          (d_type == DT_DIR) ?  "direct" :
          (d_type == DT_FIFO) ? "FIFO" :
          (d_type == DT_SOCK) ? "socket" :
          (d_type == DT_LNK) ?  "symlink" :
          (d_type == DT_BLK) ?  "block dev" :
          (d_type == DT_CHR) ?  "char dev" : "???"
          ;
      printf(fmt2, ino, d_type, typestr, d->d_reclen, d->d_off, d->d_name);
//         printf("%8lu	 %-10s %4d %20llx  %s\n",
//             ino, typestr, d->d_reclen, d->d_off, d->d_name);
    }
  }

  exit(EXIT_SUCCESS);
}

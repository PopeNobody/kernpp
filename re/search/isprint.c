#include <alloca.h>

int dprintf(int, char *,...);
int main(int argc, char** argv){
  for(int i=0;i<256;i++) {
    char str[]="  ";
    str[0]=i;
    str[1]=0;
    dprintf(1,"%5d %s\n",i,str);
  };
  return 0;
};

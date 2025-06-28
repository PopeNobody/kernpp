#include <ctype.h>

int dprintf(int, char *,...);
int main(int argc, char** argv){
  const char ip[]="isprint";
  const char IP[]="       ";
  const char is[]="isspace";
  const char IS[]="       ";
  dprintf(1,"isprint: ");
  for(int i=0;i<255;i++){
    int print=isprint(i)?1:0;
    int space=isspace(i)?1:0;
    if(isprint(i)!=isprint(i-1)) {
      dprintf(1, "%03d ", i);
    };
  };
  dprintf(1,"\nisspace: ");
  for(int i=0;i<256;i++){
    if(isspace(i))
      dprintf(1, "%03d %c\n", i, i);
//       if(isprint(i) || isspace(i)){
//         dprintf(1,"%4d: %s %s\n",isprint(i)?ip:IP,isspace(i)?is:IS);
//       }
  };
  return 0;
};

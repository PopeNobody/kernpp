#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>

#define show_int(x) dprintf(2,"// %s: %d\n",#x,(x))

int main(int, char**) {
  int last=99;
  int curr=0;
  int res[512];
  show_int(sizeof(res[0]));
  show_int(sizeof(res));
  for(int i=0;i<sizeof(res)/sizeof(res[0]);i++){
    res[i]=(bool)isprint(i);
  };
  for(int i=0;i<sizeof(res)/sizeof(res[0]);i++) {
    curr=res[i];
    if(curr==last)
      continue;
    last=curr;
    dprintf(1,"// %d: %d\n",i, curr,last);
  };
  dprintf(1,"const char escape[]=\"");
  for(int i='a'; i<='z'; i++){
    switch(i) {
      case 'u':
      case 'x': case 'b': case 'o': case 'a':
      case 'r': case 'n': case 'e': case 'f': case 't': case 'v':
        dprintf(1,"  ");
                break;
      default: dprintf(1,"\\%c%c",i,i); break;
    };
    dprintf(1,"(%3d)",i);
    if(i==106 || i==116)
      dprintf(1,"\\n\"\n\"");
  };
  dprintf(1,"\";\n");
  dprintf(1,"int write(int, const char*, int);\n");
  dprintf(1,"int main(){ write(1,escape,sizeof(escape)); return 0; };\n");
  return 0;
};

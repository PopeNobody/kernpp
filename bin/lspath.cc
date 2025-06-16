#include <syscall.hh>
using sys::write;

bool str_eq(const char *lhs,int len, const char *rhs) {
  for(int i=0;i<len;i++){
    if(lhs[i]!=rhs[i])
      return false;
  };
  return true;
};
int main(int argc, char**argv,char **envp) {
  while(*envp){
    if(str_eq(*envp,5,"PATH=")){
      char *pos;
      for(pos=5+*envp;*pos;pos++){
        if(*pos==':')
          *pos='\n';
      };
      *pos='\n';
      *pos=0;
      write(2,*envp+5);
      return 0;
    } else {
      envp++;
    };
  };
  return 0;
};

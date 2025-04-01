
unsigned index(const char *str, char del){
  unsigned idx=0;
  while(*str){
    if(del==str[idx++])
      return idx;
  };
  return 0;
};
unsigned index(const char *str, const char *dels){
  unsigned idx=0;
  while(*str) {
    if(index(dels,str[idx++]))
      return idx;
  }
  return 0;
};
bool contains(const char *str, char ch){
  return index(str,ch)>0;
};
int count(const char *str, char del){
  int cnt=0;
  while(*str)
    if(*str++==del)
      ++cnt;
  return cnt;
};
int count(const char *str, const char *del){
  int cnt=0;
  while(*del)
    cnt+=count(str,*del++);
  return cnt;
};
int split_path(const char *path, char const ***parts) {
  int num=count(path,'/')+2;
  *parts=(char const **)malloc(sizeof(char const **)*num);
  return num-1;
};

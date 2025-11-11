#pragma once

inline size_t str_len(const char *arg) {
  size_t res=0;
  while(arg[res])
    res++;
  return res;
};
inline size_t str_vec_len(const char **argv, const char *sep=" "){
  size_t sep_len=str_len(sep);
  size_t res=0;
  while(argv && *argv)
    res+=str_len(*argv++)+sep_len;
  return res-sep_len;
};
inline char *str_cpy(char *pos, const char *str){
  while(*str)
    *pos++=*str++;
  return pos;
};
inline char *str_vec_cpy(char *pos, const char ** argv, const char *sep=" ") {
  *pos=0;
  if(*argv)
    pos=str_cpy(pos,*argv++);
  while(*argv)
    pos=str_cpy(str_cpy(pos,sep),*argv++);
  return pos;
};

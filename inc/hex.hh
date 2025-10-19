#pragma once
struct hex_t {
  static constexpr char dig[]="0123456789abcdef";
  char buf[256*4];
  hex_t() 
  {
    char *pos=buf;
    for(int i=0;i<16;i++){
      for(int j=0;j<16;j++) {
        *pos++=dig[i];
        *pos++=dig[j];
        *pos++=0;
        *pos++=0;
      };
    };
  };
  char *get(short val)
  {
    return buf+val*4;
  };
} hex;

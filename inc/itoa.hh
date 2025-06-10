namespace sys {
  const char *itoa(unsigned long val, bool beg);
  inline const char *itoa(long val) {
    return itoa(val<0?-val:val,val<0);
  };
  long atoi(const char *val);
};

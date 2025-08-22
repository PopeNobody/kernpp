#include "itr-ops.hh"
#include "fmt.hh"

char *itr::copy(char *db, char *de, const fmt::fmt_t &str)
{
  if(db+str.len()>=de)
    return 0;
  for(int i=0;i<str.len();i++)
    *db++=str[i];
  return db;
};
char *itr::copy(char *db, char *de, const str::c_str &str)
{
  if(db+str.len()>=de)
    return 0;
  for(int i=0;i<str.len();i++)
    *db++=str[i];
  return db;
};

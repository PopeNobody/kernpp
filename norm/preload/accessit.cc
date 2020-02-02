#include <unistd.h>
#include <stdio.h>

int main(int, char**) {
  int res;
  res=access("datehack.so",X_OK);
  return 0;
};

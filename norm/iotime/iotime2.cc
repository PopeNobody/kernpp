#include <iostream>
#include <time.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include "atime.hh"

using namespace std;

int main() {
  int line_count=0;
  struct stat sb;
  if (fstat (0, &sb) == -1) {
    perror ("fstat");
    return 1;
  }
  const char *beg=(const char*)mmap(nullptr,sb.st_size,PROT_READ,MAP_POPULATE|MAP_SHARED,0,0);
  const char *pos=beg;
  const char *end=pos+sb.st_size;
   
  while(pos!=end) {
    if(*pos++=='\n')
      ++line_count;
  };
  cout << line_count << endl;

  return 0;
}

// Compiled with:
// g++ -O3 -o readline_test_cpp foo.cpp

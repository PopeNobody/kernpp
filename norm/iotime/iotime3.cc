#include <iostream>
#include <time.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <array>
#include <unistd.h>
#include "atime.hh"

using namespace std;

std::array<char,1024*16> buf;
int main() {
  int line_count=0;

  int res=0;
  while((res=read(0,buf.begin(),buf.size()))>0) {
    auto beg(buf.begin()), end(beg+res);
    while(beg!=end)
      if(*beg++=='\n')
        ++line_count;
  };
  cout << line_count << endl;

  return 0;
}

// Compiled with:
// g++ -O3 -o readline_test_cpp foo.cpp

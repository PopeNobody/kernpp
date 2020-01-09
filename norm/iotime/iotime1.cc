#include <iostream>
#include <time.h>
#include "atime.hh"

using namespace std;

int main() {
  std::ios_base::sync_with_stdio(false);
  static char buffer[1];
  cin.rdbuf()->pubsetbuf(buffer,sizeof(buffer));
  cin.tie(nullptr);
  string input_line;
  long line_count = 0;
  
  while (cin) {
    if ( getline(cin, input_line) )
      line_count++;
  };
  cout << line_count << endl;
  return 0;
}

// Compiled with:
// g++ -O3 -o readline_test_cpp foo.cpp

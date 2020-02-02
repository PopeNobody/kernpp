#include <iostream>
#include <string.h>
#include <iomanip>
#include <regex>

using namespace std;

int main(int, char **) {
  int i = 0;
  while(++i<1000) {
    const char *err= strerror(i);
    if (std::regex_match (err, std::regex("Unknown") ))
      std::cout << "string literal matched\n";
    cout << setw(8) << i << " " << err << "\n";
  };
  cout << "loop broke." << endl;
  return 0;
};

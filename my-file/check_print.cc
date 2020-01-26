#include <iostream>
#include <cctype>
#include <iomanip>

using namespace std;
int main(int, char**)
{
  cout << boolalpha << left;
  cout << '"';
  int pos=0;
  for(unsigned char c=1;c;c++)
  {
    if(isprint(c)) {
      cout << c;
      if(++pos == 48)
        cout << '"' << endl << '"';
    }
  };
  cout << '"'<<endl;
};

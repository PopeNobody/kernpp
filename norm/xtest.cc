#include <iostream>
using namespace std;


template<typename t>
void showme(t && x)
{
  cout << __PRETTY_FUNCTION__ << endl;
};
auto testfunc(int i){
  cout << __PRETTY_FUNCTION__ << endl;
  long l;
  double d;
  if(i)
    ; //return d;
  else
    return l;
};
int main(int argc, char**){
  showme(testfunc(argc));
  return 0;
};

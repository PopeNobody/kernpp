#include <iostream>
#include <string.h>
#include <iomanip>

using namespace std;

short seen[256];
int main(int, char **) {
  int i = 0;
  memset(seen,0,sizeof(seen));
  while(++i<1000) {
    const char *err= strerror(i);
    const char *pos=err;
    while(*pos) {
      seen[*pos]++;
      ++pos;
    };
    cout << setw(8) << i << " " << err << "\n";
  };
  cout << "loop broke." << endl;
  i=0;
  cout << '"';
  for(int j = 0; j<(sizeof(seen)/sizeof(seen[0]));j++){
    if(seen[j]){
      cout << char(j);
      seen[j]=0;
      if(!(++i%40))
        cout << "\"\n\"";
    };
  };
  cout << "\"" << endl;
  return 0;
};
